#include <Wire.h>
#include <RTClib.h>
#include <LiquidCrystal_I2C.h>

#define LCD_ADDR 0x27
LiquidCrystal_I2C lcd(LCD_ADDR, 16, 2);
RTC_DS1307 rtc;

/* ---- Botões ---- */
const uint8_t PIN_MODE  = 7;
const uint8_t PIN_UP    = 6;
const uint8_t PIN_DOWN  = 5;
const uint8_t PIN_SET   = 4;

/* ---- Estados ---- */
enum Screen   { CLOCK, METEO } screen = CLOCK;
enum EditStep { NONE, EDIT_HH, EDIT_MM } edit = NONE;

bool isEditing() { return (edit != NONE); }

/* ---- Debounce ---- */
const unsigned long DEBOUNCE = 200;
unsigned long lastBtn = 0;

/* ---- Alarme ---- */
uint8_t alarmHH = 6, alarmMM = 30;
bool alarmFiredToday = false;
unsigned long lastAlarmMillis = 0;

/* ---- Meteo (Serial) ---- */
float tempC = 0;
int   hum   = 0;
int   rainP = 0;

/* ============================ SETUP ================================== */
void setup() {
  Serial.begin(115200);
  Wire.begin();
  lcd.init(); lcd.backlight();
  lcd.print("Iniciando...");
  Serial.println("Iniciando sistema...");

  if (!rtc.begin()) {
    lcd.clear(); lcd.print("RTC erro!");
    Serial.println("Erro: RTC não detectado!");
    while (1);
  }

  // rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));  // use 1x se quiser ajustar

  uint8_t btns[] = {PIN_MODE, PIN_UP, PIN_DOWN, PIN_SET};
  for (uint8_t p : btns) pinMode(p, INPUT);

  delay(800); lcd.clear();
  Serial.println("Sistema pronto.");
}

/* ============================ LOOP =================================== */
void loop() {
  parseSerial();
  handleButtons();
  updateDisplay();
  checkAlarm();
  delay(80);
}

/* ---------------- Serial (T=..;H=..;R=..) ---------------- */
void parseSerial() {
  static char buffer[64];
  static uint8_t idx = 0;

  while (Serial.available()) {
    char c = Serial.read();
    if (c == '\n') {
      buffer[idx] = '\0';
      Serial.print("Recebido: ");
      Serial.println(buffer);

      char* token = strtok(buffer, ";");
      while (token != NULL) {
        if (strncmp(token, "T=", 2) == 0) {
          tempC = atof(token + 2);
        } else if (strncmp(token, "H=", 2) == 0) {
          hum = atoi(token + 2);
        } else if (strncmp(token, "R=", 2) == 0) {
          rainP = atoi(token + 2);
        }
        token = strtok(NULL, ";");
      }

      Serial.print("Dados atualizados => ");
      Serial.print("Temp: "); Serial.print(tempC);
      Serial.print("C | Umidade: "); Serial.print(hum);
      Serial.print("% | Chuva: "); Serial.print(rainP);
      Serial.println("%");

      idx = 0;
    } else {
      if (idx < sizeof(buffer) - 1) {
        buffer[idx++] = c;
      }
    }
  }
}

/* ---------------- Botões ---------------- */
bool pressed(uint8_t pin) {
  return digitalRead(pin) == HIGH;
}

void handleButtons() {
  if (millis() - lastBtn < DEBOUNCE) return;

  if (alarmFiredToday && millis() - lastAlarmMillis < 1000) return;

  if (pressed(PIN_MODE) && !isEditing()) {
    screen = (screen == CLOCK) ? METEO : CLOCK;
    Serial.print("Mudança de tela: ");
    Serial.println(screen == CLOCK ? "CLOCK" : "METEO");
    lastBtn = millis();
  }

  if (pressed(PIN_SET) && screen == CLOCK) {
    if      (edit == NONE)     { edit = EDIT_HH; Serial.println("Edição: Hora do alarme"); }
    else if (edit == EDIT_HH)  { edit = EDIT_MM; Serial.println("Edição: Minuto do alarme"); }
    else                       { edit = NONE; alarmFiredToday = false; Serial.println("Edição finalizada."); }
    lastBtn = millis();
  }

  if (isEditing()) {
    if (pressed(PIN_UP)) {
      if (edit == EDIT_HH) { alarmHH = (alarmHH + 1) % 24; Serial.print("Hora +1: "); Serial.println(alarmHH); }
      if (edit == EDIT_MM) { alarmMM = (alarmMM + 1) % 60; Serial.print("Minuto +1: "); Serial.println(alarmMM); }
      lastBtn = millis();
    }
    if (pressed(PIN_DOWN)) {
      if (edit == EDIT_HH) { alarmHH = (alarmHH + 23) % 24; Serial.print("Hora -1: "); Serial.println(alarmHH); }
      if (edit == EDIT_MM) { alarmMM = (alarmMM + 59) % 60; Serial.print("Minuto -1: "); Serial.println(alarmMM); }
      lastBtn = millis();
    }
  }
}

/* ---------------- Display ---------------- */
void updateDisplay() {
  static unsigned long last = 0;
  if (millis() - last < 400) return;
  last = millis();

  char ln[17];
  DateTime now = rtc.now();

  if (screen == CLOCK) {
    snprintf(ln, sizeof(ln), "Hora %02d:%02d  ", now.hour(), now.minute());
    lcd.setCursor(0,0); lcd.print(ln);

    snprintf(ln, sizeof(ln), "Al %02d:%02d  ", alarmHH, alarmMM);
    lcd.setCursor(0,1); lcd.print(ln);

    if (edit == EDIT_HH)       { lcd.setCursor(3,1); lcd.blink(); }
    else if (edit == EDIT_MM)  { lcd.setCursor(6,1); lcd.blink(); }
    else lcd.noBlink();

  } else {
    lcd.noBlink();
    lcd.setCursor(0, 0);
    lcd.print("T=");
    lcd.print(tempC, 1);  // ← Imprime corretamente 1 casa decimal
    lcd.print("C U=");
    lcd.print(hum);
    lcd.print("%");

    lcd.setCursor(0, 1);
    lcd.print("Chuva ");
    lcd.print(rainP);
    lcd.print("%   ");
  }
}

/* ---------------- Alarme ---------------- */
static int lastAlarmHour   = -1;
static int lastAlarmMinute = -1;

void checkAlarm() {
  if (isEditing()) return;

  DateTime now = rtc.now();

  // Remover a lógica de alarmFiredToday
  // if (now.hour() == 0 && now.minute() == 0 && now.second() == 0)
  //     alarmFiredToday = false;

  // Substituir esse if por verificação de lastAlarmHour/Minute
  if (now.hour() == alarmHH && now.minute() == alarmMM) {
    if (lastAlarmHour != now.hour() || lastAlarmMinute != now.minute()) {
      lastAlarmHour   = now.hour();
      lastAlarmMinute = now.minute();

      // Dispara alarme
      lastAlarmMillis = millis();
      Serial.println("===> Alarme disparado!");

      while (digitalRead(PIN_SET) == LOW) {
        lcd.clear();
        lcd.setCursor(0, 0); lcd.print("** ALARME **");

        char ln[17];
        sprintf(ln, "%02d:%02d ", alarmHH, alarmMM);
        lcd.setCursor(0, 1); lcd.print(ln);
        lcd.print(tempC, 1);
        lcd.print("C");

        delay(300);
        digitalWrite(LED_BUILTIN, HIGH);
        lcd.clear();
        delay(200);
        digitalWrite(LED_BUILTIN, LOW);
      }

      Serial.println("[OK] Alarme interrompido por botão SET.");
      lcd.clear();
      lcd.setCursor(0, 0); lcd.print("Alarme parado!");
      delay(1000);
      edit = NONE;
    }
  } else {
    // Se a hora ou minuto mudar, zera as variáveis
    lastAlarmHour   = -1;
    lastAlarmMinute = -1;
  }
}


// 3- Ao pressionar: 
// - botão 2 os leds devem "correr" em um sentido.
// - botão 3 os leds devem "correr em sentido contrario.

const int ledPins[] = {13, 12, 11};
const int buttonUp = 2;
const int buttonDown = 3;

void setup() {
  for (int i = 0; i < 3; i++) {
    pinMode(ledPins[i], OUTPUT);
  }
  pinMode(buttonUp, INPUT_PULLUP);
  pinMode(buttonDown, INPUT_PULLUP);
}

void loop() {
    bool btn1 = digitalRead(buttonUp) == LOW;   // LOW significa que o botão está pressionado
    bool btn2 = digitalRead(buttonDown) == LOW;

    if (btn1) {
      delay(300); // Debounce
      for (int i = 0; i < 3; i++) {
        digitalWrite(ledPins[i], HIGH);
        delay(350);
      }
      delay(500); // Dá tempo para visualizar todos os LEDs ligados
      for (int i = 0; i < 3; i++) {
        digitalWrite(ledPins[i], LOW);
      }
    }

    if (btn2) {
      delay(300); // Debounce
      for (int i = 2; i >= 0; i--) { // Corrigido para i >= 0
        digitalWrite(ledPins[i], HIGH);
        delay(350);
      }
      delay(500); // Dá tempo para visualizar todos os LEDs ligados
      for (int i = 0; i < 3; i++) {
        digitalWrite(ledPins[i], LOW);
      }
    }
}
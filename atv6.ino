const int LM35_PIN = A1;  // Pino do sensor LM35
const int POT_PIN = A0;   // Pino do potenciômetro
const int LED_PIN = 13;   // Pino do LED

void setup() {
    Serial.begin(9600);  // Inicializa a comunicação serial
    pinMode(LED_PIN, OUTPUT);  // Define o LED como saída
}

void loop() {
    // Leitura do LM35 (Temperatura real)
    int leituraADC = analogRead(LM35_PIN);
    float tensao = leituraADC * (5.0 / 1023.0);
    float temperaturaLM35 = tensao * 100.0;

    // Leitura do Potenciômetro (Conversão de 0-1023 para 15-35°C)
    int leituraPot = analogRead(POT_PIN);
    float tempPot = map(leituraPot, 0, 1023, 15, 35);

    // Definição da margem de erro para proximidade
    float margem = 1.5;  // Tolerância de ±1.5°C

    // Controle do LED
    if (abs(temperaturaLM35 - tempPot) <= margem) {
        digitalWrite(LED_PIN, LOW);  // Desliga o LED
    } else {
        digitalWrite(LED_PIN, HIGH); // Liga o LED
    }

    // Exibir valores no Monitor Serial
    Serial.print("Temperatura LM35: ");
    Serial.print(temperaturaLM35);
    Serial.print(" °C | ");

    Serial.print("Temperatura Ajustada (Pot): ");
    Serial.print(tempPot);
    Serial.print(" °C | ");

    Serial.print("LED: ");
    Serial.println(digitalRead(LED_PIN) == HIGH ? "LIGADO" : "DESLIGADO");

    delay(50); 
}

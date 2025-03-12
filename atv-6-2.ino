const int ledPins[] = {13, 12}; // LEDs nos pinos 13 e 12
const int buttonUp = 2;  // Botão 1
const int buttonDown = 3; // Botão 2

void setup() {
    for (int i = 0; i < 2; i++) {
        pinMode(ledPins[i], OUTPUT); // Configura os LEDs como saída
    }
    pinMode(buttonUp, INPUT_PULLUP);   // Usa pull-up interno para evitar leituras flutuantes
    pinMode(buttonDown, INPUT_PULLUP);
}

void loop() {
    bool btn1 = digitalRead(buttonUp) == LOW;   // LOW significa que o botão está pressionado
    bool btn2 = digitalRead(buttonDown) == LOW;

    if (btn1 || btn2) {
        digitalWrite(ledPins[0], HIGH); // Liga o LED 13
    } else {
        digitalWrite(ledPins[0], LOW);  // Desliga o LED 13 se nenhum botão estiver pressionado
    }

    if (btn1 && btn2) {
        digitalWrite(ledPins[1], HIGH); // Liga o LED 12 se ambos os botões estiverem pressionados
    } else {
        digitalWrite(ledPins[1], LOW);  // Desliga o LED 12 se apenas um botão estiver pressionado
    }

    delay(50); // Pequeno atraso para evitar debounce
}

// Exercício 6: Controle de Servo com LDR e Botão

// Enunciado:
// Monte um circuito onde o servo motor é controlado pela luz ambiente somente quando um botão é pressionado. Se o botão não estiver pressionado, o servo deve permanecer na posição atual.

// O que será avaliado:

//     Uso combinado de sensor analógico (LDR) e entrada digital (botão).

//     Controle condicional do servo.

#include <Servo.h>

Servo meuServo;
int pinoLDR = A2;
const int pinoBotao = 2;

void setup() {
  meuServo.attach(9);
  pinMode(pinoBotao, INPUT_PULLUP);
  Serial.begin(9600);
}

void loop() {
  if (digitalRead(pinoBotao) == LOW) {
    int valorLDR = analogRead(pinoLDR);
    int angulo = map(valorLDR, 0, 1023, 0, 180);
    meuServo.write(angulo);

    Serial.print("LDR: ");
    Serial.print(valorLDR);
    Serial.print(" -> Ângulo: ");
    Serial.println(angulo);
    delay(100); // Ajuda a reduzir "saltos" rápidos
  }
}

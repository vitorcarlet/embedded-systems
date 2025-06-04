// Exercício 10: Servo que segue faixa de valores de um sensor

// Enunciado:
// Monte um sistema em que o servo só se move se a leitura do LDR estiver dentro de um intervalo específico, por exemplo, entre 300 e 700. Fora disso, ele permanece travado na última posição.

// O que será avaliado:

//     Condicionais com faixa (if (valor > 300 && valor < 700)).

//     Lógica de travamento de posição.



#include <Servo.h>

Servo meuServo;
const int pinoLDR = A0;
int valorLDR;
int angulo = 90; // Posição inicial

void setup() {
  meuServo.attach(9);
  meuServo.write(angulo);
  Serial.begin(9600);
}

void loop() {
  valorLDR = analogRead(pinoLDR);

  if (valorLDR >= 300 && valorLDR <= 700) {
    angulo = map(valorLDR, 300, 700, 0, 180);
    meuServo.write(angulo);

    Serial.print("Luz ok - LDR: ");
    Serial.print(valorLDR);
    Serial.print(" -> Ângulo: ");
    Serial.println(angulo);
  } else {
    // Fora da faixa, mantém posição
    Serial.print("Fora da faixa - LDR: ");
    Serial.println(valorLDR);
  }

  delay(100);
}

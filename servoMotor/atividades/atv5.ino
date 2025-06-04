
// Exercício 5: Controle de dois servos com um potenciômetro
// Enunciado:
// Utilize dois servo motores e um potenciômetro. Ambos os servos devem ser controlados pelo
// mesmo potenciômetro. Ao girar o potenciômetro, apenas o primeiro servo deve aumentar o ângulo
// até atingir 180 graus. A partir daí, o segundo servo começa a aumentar seu ângulo. No movimento
// inverso, o segundo servo reduz seu ângulo primeiro; quando atingir 0 graus, o primeiro servo
// começa a diminuir seu ângulo.
// Resposta e Explicação:
// Explicação do circuito:
// - Conecte o terminal central do potenciômetro ao pino analógico A0 do Arduino.
// - Conecte um dos terminais do potenciômetro ao 5V e o outro ao GND.
// - Conecte o fio de sinal do primeiro servo ao pino digital 9 e do segundo servo ao pino digital 10.
// - Conecte fios de alimentação dos servos ao 5V e terra ao GND.
// Explicação do código:
// - Lê o valor do potenciômetro (0 a 1023) e mapeia em 0 a 360.
// - Se o valor mapeado for de 0 a 180, ajusta apenas o primeiro servo.
// - Se for de 180 a 360, define o primeiro servo a 180 graus e mapeia o valor restante (180 a 360)
// para 0 a 180 para o segundo servo.
// - No movimento inverso, reduz primeiro o segundo servo até zero, e depois reduz o primeiro.
// Código Exemplo:

#include <Servo.h>
Servo servo1;
Servo servo2;
int pinoPot = A0;
int valorPot;
void setup() {
servo1.attach(9);
servo2.attach(10);
Serial.begin(9600);
}
void loop() {
valorPot = analogRead(pinoPot); // 0 a 1023
int valorMapeado = map(valorPot, 0, 1023, 0, 360);
if (valorMapeado <= 180) {
servo1.write(valorMapeado);
servo2.write(0);
} else {
servo1.write(180);
int valorSegundo = map(valorMapeado, 180, 360, 0, 180);
servo2.write(valorSegundo);
}
Serial.print("Pot: "); Serial.print(valorPot);
Serial.print(" -> Servo1: "); Serial.print(servo1.read());
Serial.print(" | Servo2: "); Serial.println(servo2.read());
delay(50);
}
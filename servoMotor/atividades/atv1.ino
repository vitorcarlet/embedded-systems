// Exercício 1: Controle de um servo motor com potenciômetro
// Enunciado:
// Monte o circuito e escreva a programação para que a posição de um servo motor seja controlada
// por um potenciômetro.
// Resposta e Explicação:
// Explicação do circuito:
// - Conecte o terminal central do potenciômetro (pino do meio) ao pino analógico A0 do Arduino.
// - Conecte um dos outros terminais do potenciômetro ao GND do Arduino e o outro terminal ao 5V.
// - Conecte o fio de sinal do servo ao pino digital 9 (PWM) do Arduino.
// - Conecte o fio de alimentação do servo ao 5V e o fio de terra ao GND do Arduino.
// Explicação do código:
// - Utiliza a biblioteca Servo para controlar o servo.
// - Lê o valor analógico do potenciômetro (0 a 1023).
// - Mapeia esse valor para o ângulo do servo (0 graus a 180 graus).
// - Envia o ângulo ao servo para posicioná-lo.
// Código Exemplo:

#include <Servo.h>
Servo meuServo;
int pinoPot = A0;
int valorPot;
void setup() {
meuServo.attach(9);
Serial.begin(9600);
}
void loop() {
valorPot = analogRead(pinoPot); // Lê valor do potenciômetro
int angulo = map(valorPot, 0, 1023, 0, 180); // Mapeia para ângulo em graus
meuServo.write(angulo); // Ajusta posição do servo
Serial.print("Potenciômetro: ");
Serial.print(valorPot);
Serial.print(" -> Ângulo: ");
Serial.println(angulo);
delay(15);
}
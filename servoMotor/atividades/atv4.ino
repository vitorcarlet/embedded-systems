
// Exercício 4: Controle de servo com sensor LDR
// Enunciado:
// Utilize um LDR e um servo motor. O ângulo do servo deve ser controlado pela intensidade de luz
// detectada pelo LDR.
// Resposta e Explicação:
// Explicação do circuito:
// - Conecte o LDR em série com um resistor de 10k Ohm para formar um divisor de tensão.
// - Conecte a junção LDR-resistor ao pino analógico A0.
// - Conecte o fio de sinal do servo ao pino digital 9 (PWM).
// - Conecte servo e divisor ao 5V e GND adequadamente.
// Explicação do código:
// - Lê valor analógico do divisor de tensão onde o LDR varia conforme luz.
// - Mapeia esse valor para ângulo do servo (0 graus a 180 graus).
// - Ajusta o servo constantemente conforme a leitura do LDR.
// Código Exemplo:
#include <Servo.h>
Servo meuServo;
int pinoLDR = A0;
int valorLDR;
void setup() {
meuServo.attach(9);
Serial.begin(9600);
}
void loop() {
valorLDR = analogRead(pinoLDR); // 0 a 1023
int angulo = map(valorLDR, 0, 1023, 0, 180); // Converte para ângulo em graus
meuServo.write(angulo);
Serial.print("LDR: ");
Serial.print(valorLDR);
Serial.print(" -> Ângulo: ");
Serial.println(angulo);
delay(100);
}
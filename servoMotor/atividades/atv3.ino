
// Exercício 3: Controle de ângulo com dois botões
// Enunciado:
// Monte um sistema com um servo motor e dois botões. Um botão deve aumentar o ângulo do servo,
// enquanto o outro botão deve diminuir esse ângulo.
// Resposta e Explicação:
// Explicação do circuito:
// - Conecte o botão de aumento entre o pino digital 2 e o GND, usando INPUT_PULLUP.
// - Conecte o botão de diminuição entre o pino digital 3 e o GND, usando INPUT_PULLUP.
// - Conecte o servo ao pino digital 9 (sinal), 5V e GND.
// Explicação do código:
// - Utiliza a biblioteca Servo.
// - Define variáveis para o ângulo atual e incrementos.
// - No loop, verifica pressão dos botões e ajusta o ângulo respeitando limites (0 graus a 180 graus).
// Ao mudar o ângulo, envia ao servo.
// Código Exemplo:
#include <Servo.h>
Servo meuServo;
const int pinoBotaoMais = 2;
const int pinoBotaoMenos = 3;
int anguloAtual = 90;
void setup() {
meuServo.attach(9);
pinMode(pinoBotaoMais, INPUT_PULLUP);
pinMode(pinoBotaoMenos, INPUT_PULLUP);
meuServo.write(anguloAtual);
Serial.begin(9600);
}
void loop() {
if (digitalRead(pinoBotaoMais) == LOW) {
if (anguloAtual < 180) {
anguloAtual++;
meuServo.write(anguloAtual);
Serial.print("Angulo: ");
Serial.println(anguloAtual);
delay(200); // Debounce e controle de velocidade
}
}
if (digitalRead(pinoBotaoMenos) == LOW) {
if (anguloAtual > 0) {
anguloAtual--;
meuServo.write(anguloAtual);
Serial.print("Angulo: ");
Serial.println(anguloAtual);
delay(200);
}
}
}
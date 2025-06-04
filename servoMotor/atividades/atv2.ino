
// Exercício 2: Sistema de cancela com botão e servo motor
// Enunciado:
// Monte um sistema utilizando um botão e um servo motor que simule a cancela de um
// estacionamento. O servo deve iniciar com ângulo em 0 graus. Ao pressionar o botão, o ângulo do
// servo deve ir para 90 graus, aguardar 5 segundos e retornar à posição inicial. No monitor serial,
// deve ser exibida a quantidade de vezes que o servo foi acionado.
// Resposta e Explicação:
// Explicação do circuito:
// - Conecte um botão momentâneo entre o pino digital 2 e o GND.
// - Use um resistor pull-up interno no código para evitar flutuação.
// - Conecte o fio de sinal do servo ao pino digital 9 (PWM).
// - Conecte o fio de alimentação do servo ao 5V e o fio de terra ao GND.
// Explicação do código:
// - Utiliza a biblioteca Servo para controlar o servo.
// - Inicializa a variável contagemAcionamentos em zero.
// - No loop, verifica se o botão foi pressionado (estado LOW com pull-up).
// - Ao detectar a pressão, incrementa contagemAcionamentos, move o servo para 90 graus, aguarda
// 5 segundos, retorna a 0 graus e exibe no Serial a contagem.
// Código Exemplo:

#include <Servo.h>
Servo meuServo;
const int pinoBotao = 2;
int contagemAcionamentos = 0;
bool estadoAnteriorBotao = HIGH;
void setup() {
meuServo.attach(9);
pinMode(pinoBotao, INPUT_PULLUP);
meuServo.write(0); // Inicia com ângulo 0 graus
Serial.begin(9600);
}
void loop() {
bool estadoAtualBotao = digitalRead(pinoBotao);
if (estadoAnteriorBotao == HIGH && estadoAtualBotao == LOW) {
// Botão pressionado
contagemAcionamentos++;
meuServo.write(90); // Abre a cancela (90 graus)
delay(5000); // Aguarda 5 segundos
meuServo.write(0); // Fecha a cancela (0 graus)
Serial.print("Cancela acionada: ");
Serial.println(contagemAcionamentos);
}
estadoAnteriorBotao = estadoAtualBotao;
delay(50); // Debounce simples
}
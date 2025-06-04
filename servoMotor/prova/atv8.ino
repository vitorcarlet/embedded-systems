// Exercício 8: Servo com tempo de abertura configurável

// Enunciado:
// Monte um sistema de cancela semelhante ao Exercício 2, mas com tempo de abertura configurável por um potenciômetro (entre 1s e 10s). O botão ainda aciona o servo para abrir, e o tempo de espera será baseado no valor do potenciômetro.

// O que será avaliado:

//     Leitura analógica e uso como temporizador.

//     Integração lógica entre entrada analógica e digital.

#include <Servo.h>

Servo meuServo;

const int pinoBotao = 2;
int contagemAcionamentos = 0;
bool estadoAnteriorBotao = HIGH;

int pinoPot = A0;
int valorPot;

void setup() {
  meuServo.attach(9);
  pinMode(pinoBotao, INPUT_PULLUP);
  meuServo.write(0); // Cancela fechada inicialmente
  Serial.begin(9600);
}

void loop() {
  bool estadoAtualBotao = digitalRead(pinoBotao);

  if (estadoAnteriorBotao == HIGH && estadoAtualBotao == LOW) {
    // Botão foi pressionado
    valorPot = analogRead(pinoPot);
    int valorMapeado = map(valorPot, 0, 1023, 1, 10); // de 1 a 10 segundos

    contagemAcionamentos++;
    meuServo.write(90); // Abre a cancela
    delay(valorMapeado * 1000); // Espera configurada
    meuServo.write(0); // Fecha a cancela

    // Exibe informações no Serial
    Serial.print("Cancela acionada por ");
    Serial.print(valorMapeado);
    Serial.println(" segundos!");
    Serial.print("Total de acionamentos: ");
    Serial.println(contagemAcionamentos);
  }

  estadoAnteriorBotao = estadoAtualBotao;
  delay(50); // Debounce simples
}

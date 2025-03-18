// 13- Faça um sistema com dois leds,
//  sendo que cada um deles representará qual de duas entradas 
// analógicas está maior.

int analogPin1 = A0;  // Pino da primeira entrada analógica
int analogPin2 = A1;  // Pino da segunda entrada analógica
int ledPin1 = 9;      // Pino do LED 1 (representa A0 > A1)
int ledPin2 = 10;     // Pino do LED 2 (representa A1 > A0)

int valor1 = 0;  // Variável para armazenar a leitura do pino A0
int valor2 = 0;  // Variável para armazenar a leitura do pino A1

void setup() {
  pinMode(ledPin1, OUTPUT);  // Configura o LED 1 como saída
  pinMode(ledPin2, OUTPUT);  // Configura o LED 2 como saída
  Serial.begin(9600);        // Inicializa a comunicação serial
}

void loop() {
  // Lê os valores das duas entradas analógicas
  valor1 = analogRead(analogPin1);
  valor2 = analogRead(analogPin2);

  // Compara os valores lidos e acende o LED correspondente
  if (valor1 > valor2) {
    digitalWrite(ledPin1, HIGH);  // Acende LED 1
    digitalWrite(ledPin2, LOW);   // Apaga LED 2
  } else if (valor2 > valor1) {
    digitalWrite(ledPin1, LOW);   // Apaga LED 1
    digitalWrite(ledPin2, HIGH);  // Acende LED 2
  } else {
    digitalWrite(ledPin1, LOW);   // Apaga ambos os LEDs se os valores forem iguais
    digitalWrite(ledPin2, LOW);
  }

  // Exibe os valores no monitor serial
  Serial.print("Valor A0: ");
  Serial.print(valor1);
  Serial.print(" | Valor A1: ");
  Serial.print(valor2);
  Serial.print(" | LED 1: ");
  Serial.print((valor1 > valor2) ? "ON" : "OFF");
  Serial.print(" | LED 2: ");
  Serial.println((valor2 > valor1) ? "ON" : "OFF");

  delay(200);  // Pequena pausa para estabilizar as leituras
}

// 6- O objeivo deste exercício é criar um programa para 
// Arduino que lê os valores de duas entradas 
// analógicas e exibe o resultado no monitor serial. 

int analogPin1 = A0;   // Pino analógico 1
int analogPin2 = A1;   // Pino analógico 2
int valor1 = 0;         // Variável para armazenar o valor lido do pino analógico 1
int valor2 = 0;         // Variável para armazenar o valor lido do pino analógico 2

void setup() {
  // Inicializa a comunicação serial para monitoramento
  Serial.begin(9600); 
}

void loop() {
  // Lê os valores dos pinos analógicos
  valor1 = analogRead(analogPin1);  // Lê o valor do pino A0
  valor2 = analogRead(analogPin2);  // Lê o valor do pino A1
  
  // Exibe os valores lidos no monitor serial
  Serial.print("Valor do pino A0: ");
  Serial.print(valor1);
  Serial.print(" | Valor do pino A1: ");
  Serial.println(valor2);
  
  // Aguarda um curto tempo antes de fazer a próxima leitura
  delay(500);  // Ajuste o tempo de delay conforme necessário
}

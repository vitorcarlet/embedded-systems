// 10- Faça um led que piscará com um intervalo
//  correspondente a leitura de uma porta analógica. 

int analogPin = A0;  // Pino da entrada analógica
int ledPin = 9;      // Pino do LED
int valorAnalogico = 0;  // Variável para armazenar o valor lido da porta analógica
int intervalo = 0;       // Tempo de delay baseado na leitura da porta analógica

void setup() {
  pinMode(ledPin, OUTPUT);  // Configura o pino do LED como saída
  Serial.begin(9600);       // Inicializa a comunicação serial (opcional)
}

void loop() {
  // Lê o valor da entrada analógica (0 a 1023)
  valorAnalogico = analogRead(analogPin);
  
  // Mapeia o valor lido (0-1023) para um intervalo de tempo adequado (100ms a 2000ms)
  intervalo = map(valorAnalogico, 0, 1023, 100, 2000);

  // Acende o LED
  digitalWrite(ledPin, HIGH);
  delay(intervalo); // Mantém o LED ligado pelo tempo calculado

  // Apaga o LED
  digitalWrite(ledPin, LOW);
  delay(intervalo); // Mantém o LED desligado pelo tempo calculado

  // Imprime os valores no monitor serial
  Serial.print("Valor Analogico: ");
  Serial.print(valorAnalogico);
  Serial.print(" | Intervalo de Piscar: ");
  Serial.print(intervalo);
  Serial.println(" ms");
}

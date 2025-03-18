// 7- Faça um sistema com dois potenciômetros, 
// em que cada um deles controle o brilho de um led 
// diferente. 

int potPin1 = A0;    // Pino do primeiro potenciômetro
int potPin2 = A1;    // Pino do segundo potenciômetro
int ledPin1 = 9;     // Pino do LED 1 (com PWM)
int ledPin2 = 10;    // Pino do LED 2 (com PWM)

int valorPot1 = 0;    // Variável para armazenar o valor do primeiro potenciômetro
int valorPot2 = 0;    // Variável para armazenar o valor do segundo potenciômetro
int brilhoLed1 = 0;   // Brilho do LED 1
int brilhoLed2 = 0;   // Brilho do LED 2

void setup() {
  pinMode(ledPin1, OUTPUT);  // Configura o pino do LED 1 como saída
  pinMode(ledPin2, OUTPUT);  // Configura o pino do LED 2 como saída
  Serial.begin(9600);        // Inicializa a comunicação serial (opcional)
}

void loop() {
  // Lê os valores dos potenciômetros (de 0 a 1023)
  valorPot1 = analogRead(potPin1);  
  valorPot2 = analogRead(potPin2);  
  
  // Mapeia os valores lidos dos potenciômetros para a faixa de PWM (0-255)
  brilhoLed1 = map(valorPot1, 0, 1023, 0, 255);  
  brilhoLed2 = map(valorPot2, 0, 1023, 0, 255);  
  
  // Atualiza o brilho dos LEDs com PWM
  analogWrite(ledPin1, brilhoLed1);
  analogWrite(ledPin2, brilhoLed2);
  
  // Imprime os valores dos potenciômetros e os brilhos no monitor serial
  Serial.print("Valor do Potenciômetro 1: ");
  Serial.print(valorPot1);
  Serial.print(" | Brilho do LED 1: ");
  Serial.print(brilhoLed1);
  Serial.print(" | Valor do Potenciômetro 2: ");
  Serial.print(valorPot2);
  Serial.print(" | Brilho do LED 2: ");
  Serial.println(brilhoLed2);

  delay(100);  // Aguarda 100ms antes de ler novamente
}

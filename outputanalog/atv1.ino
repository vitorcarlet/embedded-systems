//14- Faça um sistema onde um potenciômetro controla o brilho de um led. (lembre de usar as portas apropriadas)

int potPin = A0;     // Pino analógico onde o potenciômetro está conectado
int ledPin = 9;      // Pino PWM onde o LED está conectado
int valorPot = 0;     // Variável para armazenar o valor lido do potenciômetro
int brilhoLed = 0;   // Variável para armazenar o valor de brilho do LED

void setup() {
  // Configura o pino do LED como saída
  pinMode(ledPin, OUTPUT);
  
  // Inicializa a comunicação serial (opcional)
  Serial.begin(9600);
}

void loop() {
  // Lê o valor do potenciômetro (de 0 a 1023)
  valorPot = analogRead(potPin);
  
  // Mapeia o valor lido (0-1023) para a faixa PWM (0-255)
  brilhoLed = map(valorPot, 0, 1023, 0, 255);
  
  // Ajusta o brilho do LED com PWM
  analogWrite(ledPin, brilhoLed);
  
  // Imprime o valor do potenciômetro e o brilho do LED no monitor serial
  Serial.print("Valor do Potenciômetro: ");
  Serial.print(valorPot);
  Serial.print(" | Brilho do LED: ");
  Serial.println(brilhoLed);
  
  // Aguarda um curto tempo antes de ler novamente
  delay(100);
}
// 17- Dois leds terão o brilho controlado por um único potenciômetro.
//  Porem enquanto um led aumentará o seu brilho, 
// um segundo led deverá diminuir o brilho. (gangorra)
// (lembre de usar as portas apropriadas)  

int potPin = A0;     // Pino do potenciômetro
int ledPin1 = 9;     // Pino do LED 1 (vai aumentar o brilho)
int ledPin2 = 10;    // Pino do LED 2 (vai diminuir o brilho)

int valorPot = 0;     // Variável para armazenar o valor lido do potenciômetro
int brilhoLed1 = 0;   // Variável para o brilho do LED 1 (aumentando)
int brilhoLed2 = 0;   // Variável para o brilho do LED 2 (diminuindo)

void setup() {
  pinMode(ledPin1, OUTPUT);  // Configura o pino do LED 1 como saída
  pinMode(ledPin2, OUTPUT);  // Configura o pino do LED 2 como saída
  Serial.begin(9600);        // Inicializa a comunicação serial (opcional)
}

void loop() {
  valorPot = analogRead(potPin);       // Lê o valor do potenciômetro (de 0 a 1023)
  
  // Mapeia o valor lido do potenciômetro para a faixa de PWM (0-255)
  brilhoLed1 = map(valorPot, 0, 1023, 0, 255);  // LED 1 (aumentando)
  brilhoLed2 = map(valorPot, 0, 1023, 255, 0);  // LED 2 (diminuindo)

  // Atualiza o brilho dos LEDs com os valores calculados
  analogWrite(ledPin1, brilhoLed1);
  analogWrite(ledPin2, brilhoLed2);

  // Imprime os valores do potenciômetro e os brilhos no monitor serial
  Serial.print("Valor do Potenciômetro: ");
  Serial.print(valorPot);
  Serial.print(" | Brilho do LED 1: ");
  Serial.print(brilhoLed1);
  Serial.print(" | Brilho do LED 2: ");
  Serial.println(brilhoLed2);

  delay(100);  // Aguarda 100ms antes de ler novamente
}

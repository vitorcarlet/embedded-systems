// 9- Faça um sistema em que um potenciômetro controle
//  o brilho de um led utilizando um potenciômetro, 
// porém o brilho do led só deve ser atualizado quando 
// um botão for pressionado.

int potPin = A0;     // Pino do potenciômetro
int botaoPin = 2;    // Pino do botão
int ledPin = 9;      // Pino do LED (com PWM)

int valorPot = 0;     // Variável para armazenar o valor lido do potenciômetro
int brilhoLed = 0;   // Variável para armazenar o brilho do LED
int estadoBotao = 0; // Variável para armazenar o estado do botão
int ultimoEstadoBotao = HIGH; // Variável para armazenar o último estado do botão (para detectar transição)

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(botaoPin, INPUT); // O botão é configurado como entrada
  Serial.begin(9600);
}

void loop() {
  estadoBotao = digitalRead(botaoPin); // Lê o estado do botão

  // Lê o valor do potenciômetro (de 0 a 1023)
  valorPot = analogRead(potPin);

  // Mapeia o valor lido do potenciômetro para a faixa de PWM (0-255)
  int novoBrilho = map(valorPot, 0, 1023, 0, 255);

  // Se o botão foi pressionado (detecção de pulso)
  if (estadoBotao == LOW && ultimoEstadoBotao == HIGH) {
    brilhoLed = novoBrilho;  // Atualiza o brilho do LED com o novo valor
    analogWrite(ledPin, brilhoLed);
    
    // Imprime o valor do potenciômetro e o brilho do LED no monitor serial
    Serial.print("Potenciômetro: ");
    Serial.print(valorPot);
    Serial.print(" | Brilho do LED: ");
    Serial.println(brilhoLed);
    
    delay(200); // Pequeno delay para evitar múltiplas leituras com um único pressionamento (debounce)
  }

  // Atualiza o último estado do botão para verificar a transição
  ultimoEstadoBotao = estadoBotao;

  // Aguarda um curto tempo antes de ler novamente
  delay(100);
}

//15- Faça um sistema onde um potenciômetro 
// controla o brilho de um led. Porem a atualização 
// do brilho do led deve ocorrer somente quando 1 
// botão for pressionado.

int potPin = A0;     // Pino do potenciômetro
int botaoPin = 2;    // Pino do botão
int ledPin = 9;      // Pino do LED (com PWM)

int valorPot = 0;     // Variável para armazenar o valor lido do potenciômetro
int brilhoLed = 0;   // Variável para o brilho do LED
int estadoBotao = 0; // Variável para armazenar o estado do botão
int ultimoEstadoBotao = HIGH; // Variável para armazenar o último estado do botão (para detectar transição)

void setup() {
  // Configura o pino do LED como saída
  pinMode(ledPin, OUTPUT);
  
  // Configura o pino do botão como entrada
  pinMode(botaoPin, INPUT_PULLUP);
  
  // Inicializa a comunicação serial (opcional)
  Serial.begin(9600);
}

void loop() {
  // Lê o estado do botão
  estadoBotao = digitalRead(botaoPin);
  
  // Lê o valor do potenciômetro (de 0 a 1023)
  valorPot = analogRead(potPin);
  
  // Mapeia o valor lido do potenciômetro (0-1023) para a faixa de PWM (0-255)
  brilhoLed = map(valorPot, 0, 1023, 0, 255);
  
  // Se houve uma transição de HIGH para LOW (botão pressionado)
  if (estadoBotao == LOW && ultimoEstadoBotao == HIGH) {
    // Atualiza o brilho do LED com o valor do potenciômetro
    analogWrite(ledPin, brilhoLed);
    
    // Imprime o valor do potenciômetro e o brilho do LED no monitor serial
    Serial.print("Valor do Potenciômetro: ");
    Serial.print(valorPot);
    Serial.print(" | Brilho do LED: ");
    Serial.println(brilhoLed);
    
    // Aguarda um pequeno tempo para evitar múltiplas leituras com um único pressionamento
    delay(200);  // Ajuste conforme necessário para o debounce do botão
  }

  // Atualiza o último estado do botão para verificar a transição
  ultimoEstadoBotao = estadoBotao;
  
  // Aguarda um curto tempo antes de ler novamente
  delay(100);
}

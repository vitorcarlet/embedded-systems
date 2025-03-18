// 18- O funcionamento dos leds deve ser parecido
//  com o do exercício acima, porem o controle do 
//  brilho se dara por dois botões.

int botao1Pin = 2;    // Pino do botão 1 (controla o LED 1)
int botao2Pin = 3;    // Pino do botão 2 (controla o LED 2)
int ledPin1 = 9;      // Pino do LED 1 (com PWM)
int ledPin2 = 10;     // Pino do LED 2 (com PWM)

int brilhoLed1 = 0;   // Brilho do LED 1 (aumenta com o botão 1)
int brilhoLed2 = 0;   // Brilho do LED 2 (aumenta com o botão 2)

int incremento = 51;  // Incremento de brilho por pressionamento do botão

void setup() {
  pinMode(botao1Pin, INPUT);  // Configura o pino do botão 1 como entrada
  pinMode(botao2Pin, INPUT);  // Configura o pino do botão 2 como entrada
  pinMode(ledPin1, OUTPUT);   // Configura o pino do LED 1 como saída
  pinMode(ledPin2, OUTPUT);   // Configura o pino do LED 2 como saída
  
  Serial.begin(9600);         // Inicializa a comunicação serial (opcional)
}

void loop() {
  // Lê o estado dos botões
  int estadoBotao1 = digitalRead(botao1Pin);
  int estadoBotao2 = digitalRead(botao2Pin);

  // Verifica se o botão 1 foi pressionado (aumenta o brilho do LED 1 e diminui o brilho do LED 2)
  if (estadoBotao1 == LOW) { // Botão 1 pressionado (HIGH quando não pressionado)
    brilhoLed1 += incremento;  // Aumenta o brilho do LED 1
    if (brilhoLed1 > 255) brilhoLed1 = 255;  // Limita o brilho máximo
    brilhoLed2 -= incremento;  // Diminui o brilho do LED 2
    if (brilhoLed2 < 0) brilhoLed2 = 0;  // Limita o brilho mínimo
    delay(200);  // Delay para debounce
  }

  // Verifica se o botão 2 foi pressionado (aumenta o brilho do LED 2 e diminui o brilho do LED 1)
  if (estadoBotao2 == LOW) { // Botão 2 pressionado (HIGH quando não pressionado)
    brilhoLed2 += incremento;  // Aumenta o brilho do LED 2
    if (brilhoLed2 > 255) brilhoLed2 = 255;  // Limita o brilho máximo
    brilhoLed1 -= incremento;  // Diminui o brilho do LED 1
    if (brilhoLed1 < 0) brilhoLed1 = 0;  // Limita o brilho mínimo
    delay(200);  // Delay para debounce
  }

  // Atualiza o brilho dos LEDs com PWM
  analogWrite(ledPin1, brilhoLed1);
  analogWrite(ledPin2, brilhoLed2);
  
  // Imprime os valores no monitor serial para acompanhamento
  Serial.print("Brilho do LED 1: ");
  Serial.print(brilhoLed1);
  Serial.print(" | Brilho do LED 2: ");
  Serial.println(brilhoLed2);

  // Aguarda um curto tempo antes de ler novamente
  delay(50);  // Ajuste conforme necessário para estabilizar as leituras
}


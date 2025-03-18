// 8- Faça um sistema com um led que deve ligar toda a 
// vez que um botão for pressionado. Esse led 
// deverá desligar quando a leitura de uma porta 
// analógica seja menor que 10. 

int botaoPin = 2;      // Pino do botão
int ledPin = 9;        // Pino do LED (com PWM)
int analogaPin = A0;   // Pino da entrada analógica
int estadoBotao = 0;   // Variável para armazenar o estado do botão
int leituraAnalogica = 0; // Variável para armazenar a leitura da porta analógica

void setup() {
  pinMode(botaoPin, INPUT);   // Configura o pino do botão como entrada
  pinMode(ledPin, OUTPUT);    // Configura o pino do LED como saída
  Serial.begin(9600);         // Inicializa a comunicação serial (opcional)
}

void loop() {
  estadoBotao = digitalRead(botaoPin);  // Lê o estado do botão (HIGH ou LOW)

  // Lê o valor da porta analógica (de 0 a 1023)
  leituraAnalogica = analogRead(analogaPin);

  // Se o botão for pressionado, liga o LED
  if (estadoBotao == LOW) { // LOW quando pressionado (botão conectado ao GND)
    digitalWrite(ledPin, HIGH);  // Liga o LED
  }

  // Se o valor da entrada analógica for menor que 10, desliga o LED
  if (leituraAnalogica < 10) {
    digitalWrite(ledPin, LOW);   // Desliga o LED
  }

  // Imprime os valores da leitura analógica e o estado do LED no monitor serial
  Serial.print("Leitura analógica: ");
  Serial.print(leituraAnalogica);
  Serial.print(" | Estado do LED: ");
  if (digitalRead(ledPin) == HIGH) {
    Serial.println("Ligado");
  } else {
    Serial.println("Desligado");
  }

  delay(100);  // Aguarda um curto tempo antes de ler novamente
}

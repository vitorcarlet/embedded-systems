// 12- Um led que deverá piscar quando um botão for
//  pressionado, a quantidade de vezes conforme o 
// valor lido em uma porta analógica (0 a 1023). 

int analogPin = A0;  // Pino da entrada analógica
int botaoPin = 2;    // Pino do botão
int ledPin = 9;      // Pino do LED
int estadoBotao = 0; // Variável para armazenar o estado do botão
int ultimoEstadoBotao = HIGH; // Para detectar transição de estado do botão

void setup() {
  pinMode(ledPin, OUTPUT);   // Configura o pino do LED como saída
  pinMode(botaoPin, INPUT);  // Configura o botão como entrada
  Serial.begin(9600);        // Inicializa a comunicação serial
}

void loop() {
  estadoBotao = digitalRead(botaoPin);  // Lê o estado do botão

  // Verifica se o botão foi pressionado (transição HIGH -> LOW)
  if (estadoBotao == LOW && ultimoEstadoBotao == HIGH) {
    int valorAnalogico = analogRead(analogPin);  // Lê o valor da porta analógica

    // Mapeia o valor lido (0-1023) para um número razoável de piscadas (0-20)
    int numPiscadas = map(valorAnalogico, 0, 1023, 0, 20);

    // Imprime no monitor serial
    Serial.print("Valor da porta analogica: ");
    Serial.print(valorAnalogico);
    Serial.print(" | Numero de piscadas: ");
    Serial.println(numPiscadas);

    // Faz o LED piscar conforme o valor lido
    for (int i = 0; i < numPiscadas; i++) {
      digitalWrite(ledPin, HIGH);  // Acende o LED
      delay(200);  // Aguarda 200ms
      digitalWrite(ledPin, LOW);   // Apaga o LED
      delay(200);
    }
    
    delay(200);  // Pequeno delay para evitar leituras múltiplas do botão
  }

  // Atualiza o último estado do botão
  ultimoEstadoBotao = estadoBotao;

  delay(50);  // Pequeno delay para estabilizar a leitura
}

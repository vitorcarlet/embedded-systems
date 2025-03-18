// 11- Faça um sistema que leia o valor da porta 
// analógica e quando um botão for pressionado o valor da 
// porta analógica deve ser mostrada uma única 
// vez no monitor serial.

int analogPin = A0;  // Pino da entrada analógica
int botaoPin = 2;    // Pino do botão
int estadoBotao = 0; // Variável para armazenar o estado do botão
int ultimoEstadoBotao = HIGH; // Variável para armazenar o último estado do botão

void setup() {
  pinMode(botaoPin, INPUT);   // Configura o botão como entrada
  Serial.begin(9600);         // Inicializa a comunicação serial
}

void loop() {
  estadoBotao = digitalRead(botaoPin);  // Lê o estado do botão

  // Se houve uma transição de HIGH para LOW (botão pressionado)
  if (estadoBotao == LOW && ultimoEstadoBotao == HIGH) {
    int valorAnalogico = analogRead(analogPin);  // Lê o valor da porta analógica

    // Exibe o valor da entrada analógica uma única vez no monitor serial
    Serial.print("Valor da porta analogica: ");
    Serial.println(valorAnalogico);
    
    delay(200);  // Delay para evitar múltiplas leituras com um único pressionamento (debounce)
  }

  // Atualiza o último estado do botão
  ultimoEstadoBotao = estadoBotao;

  delay(50);  // Pequeno delay para estabilizar as leituras
}

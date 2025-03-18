//4- Faça um sistema com um led e três botões. Um led deve iniciar piscando com um intervalo de 1s. Esse intervalo pode ser alterado por dois botões, sendo um deles para aumentar o intervalo em 100ms e o outro para diminuir esse intervalo em 100ms. Ao pressionar o terceiro botão o intervalo deve ser reiniciado para 1s.

const int led4 = 13, buttonInc = 2, buttonDec = 3, buttonReset = 4;
int intervalo = 1000;

void setup(){

pinMode(led4,OUTPUT);
  pinMode(buttonInc,INPUT_PULLUP);
  pinMode(buttonDec,INPUT_PULLUP);
  pinMode(buttonReset,INPUT_PULLUP);
        }

void loop() {
  if (digitalRead(buttonInc) == LOW) { intervalo += 100; delay(200); }
  if (digitalRead(buttonDec) == LOW) { intervalo -= 100; delay(200); }
  if (digitalRead(buttonReset) == LOW) { intervalo = 1000; delay(200); }
  
  digitalWrite(led4, HIGH);
  delay(intervalo);
  digitalWrite(led4, LOW);
  delay(intervalo);
}
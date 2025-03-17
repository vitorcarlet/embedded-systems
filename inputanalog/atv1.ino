// 5- Faça um sistema que leia o valor de uma porta analógica e ligue ou desligue um led conforme a 
// tensão lida, sendo menor que 2,5V desliga o led e maior ou igual a 2,5V ligue o led. 

const int pot = A0;
const int led = 13;   // Pino do LED

void setup() {
  Serial.begin(9600);
  
  pinMode(led, OUTPUT);
}

void loop() {
  int leitura = analogRead(pot);
  float tensao = leitura * ( 5.0 / 1023.0);
   Serial.print("Tensão lida: ");
  Serial.println(tensao);

  digitalWrite(led,LOW);
  
  if(tensao > 2.5){
    digitalWrite(led,HIGH);
  }
  
  delay(100);
}

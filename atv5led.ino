int cont;

void setup() {
	pinMode(2,INPUT);  
	pinMode(3,INPUT);  
	
	pinMode(13,OUTPUT);
	pinMode(12,OUTPUT);
	pinMode(11,OUTPUT);
	pinMode(10,OUTPUT);
	pinMode(9,OUTPUT);
	pinMode(8,OUTPUT);
	pinMode(7,OUTPUT);
}



void loop() {
  //aumenta
  
  if(digitalRead(2)==HIGH){
    cont++;
	if(cont>9) cont=9;
	while(digitalRead(2)==HIGH){delay(10);}
  }
  
  if(digitalRead(3)==HIGH){
    cont--;
	if(cont<0) cont=0;
	while(digitalRead(3)==HIGH){delay(10);}
  }
  
  if(conta==0){
	digitalWrite(13,HIGH); //a
	digitalWrite(12,HIGH); //b
	digitalWrite(11,HIGH); //c
	digitalWrite(10,HIGH); //d
	digitalWrite(9,HIGH); //e
	digitalWrite(8,HIGH); //f
	digitalWrite(7,LOW); //g
  }
  

}
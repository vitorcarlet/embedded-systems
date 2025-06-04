
//     Exercício 9: Dois Servos em movimento oposto

// Enunciado:
// Monte um sistema com dois servos. Quando um botão for pressionado, um servo deve girar de 0 a 180 graus enquanto o outro gira de 180 a 0 graus, simultaneamente. Ao soltar o botão, eles voltam às posições originais.

// O que será avaliado:

//     Movimento simultâneo e inverso de servos.

//     Resposta imediata a eventos digitais.


    #include <Servo.h>

Servo servo1;
Servo servo2;

const int pinoBotao = 2;

void setup() {
  servo1.attach(9);    // Servo que sobe
  servo2.attach(10);   // Servo que desce
  pinMode(pinoBotao, INPUT_PULLUP);

  // Posições iniciais
  servo1.write(0);
  servo2.write(180);
}

void loop() {
  if (digitalRead(pinoBotao) == LOW) {
    // Botão pressionado: movimento oposto
    for (int i = 0; i <= 180; i++) {
      servo1.write(i);
      servo2.write(180 - i);
      delay(10);
    }
  } else {
    // Botão solto: volta para posições iniciais
    servo1.write(0);
    servo2.write(180);
  }
}

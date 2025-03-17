// 1 - Faça um sistema com dois botões e três leds, 
// o primeiro deve aumentar a quantidade de leds acesos 
// e o segundo deve diminuir a quantidade de leds acesos. 

const int ledPins[] = {13, 12, 11, 10}; // 4 LEDs
const int buttonUp = 5;
const int buttonDown = 4;
int count = 0;  // Tracks active LEDs

void setup() {
  for (int i = 0; i < 4; i++) { // Fix LED count
    pinMode(ledPins[i], OUTPUT);
  }
  pinMode(buttonUp, INPUT_PULLUP);
  pinMode(buttonDown, INPUT_PULLUP);
}

void loop() {
  bool btn1 = digitalRead(buttonUp) == LOW; // Button pressed
  bool btn2 = digitalRead(buttonDown) == LOW;

  // Turn OFF all LEDs first
  for (int i = 0; i < 4; i++) {
    digitalWrite(ledPins[i], LOW);
  }

  // Turn ON only required LEDs
  for (int i = 0; i < count; i++) {
    digitalWrite(ledPins[i], HIGH);
  }

  // Button press logic with debounce
  if (btn1) {
    delay(200); // Debounce delay
    if (count < 4) { count++; } // Correct max limit
  }

  if (btn2) {
    delay(200); // Debounce delay
    if (count > 0) { count--; }
  }
}

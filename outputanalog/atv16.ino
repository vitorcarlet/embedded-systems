// 16- O brilho de um led deve aumentar a cada pulso de um
//  botão. Após o led atingir o brilho máximo, no próximo pulso
// o led deve apagar.

const int ledPin = 9;      // Pino PWM do LED
const int buttonPin = 2;   // Pino do botão

int brightness = 0;        // Brilho inicial do LED
const int maxBrightness = 255; // Brilho máximo
int step = 51;             // Passo do brilho
bool buttonState = LOW;    // Estado atual do botão
bool lastButtonState = LOW; // Estado anterior do botão

void setup() {
    pinMode(ledPin, OUTPUT);
    pinMode(buttonPin, INPUT_PULLUP); // Ativa o pull-up interno
}

void loop() {
    buttonState = digitalRead(buttonPin);
    
    // Detecta a transição de LOW para HIGH (pressionamento do botão)
    if (buttonState == HIGH && lastButtonState == LOW) {
        brightness += step;
        if (brightness > maxBrightness) {
            brightness = 0; // Reinicia o brilho
        }
        analogWrite(ledPin, brightness);
        delay(200); // Debounce
    }
    
    lastButtonState = buttonState;
}

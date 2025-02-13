
const int segmentPins[] = { 13, 12, 11, 10, 9, 8, 7 };

const int objNumber[][5] = {
  {},                    // 0 index is not used
  { 13, 12 },            // 1
  { 13, 12, 7, 9, 10 },  // 2
  { 13, 12, 7, 11, 10 }  // 3
};

void setup() {
  // Set all the segment pins as outputs
  for (int i = 0; i < 7; i++) {
    pinMode(segmentPins[i], OUTPUT);
  }
}

void loop() {
  // Example: Display number 2
  for (int number = 0; number < 3; number++) {
    delay(400);
    for (int i = 0; i < sizeof(objNumber[number]); i++) {
      digitalWrite(objNumber[number][i], HIGH);
    
    }
  delay(400);
  for (int i = 0; i < 7; i++) {
        digitalWrite(segmentPins[i], LOW);
      }


    // Turn on the segments for the number
  }
}
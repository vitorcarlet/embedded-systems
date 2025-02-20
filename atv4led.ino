
const int segmentPins[] = { 13, 12, 11, 10, 9, 8, 7 };
//B=12, C=7 A=13 F=10 G==11 D=8 E=9
const int objNumber[][10] = {
  {13,12,10,9,8,7}, //0,                    // 0 index is not used
  { 12, 7 },            // 1 AB
  { 13, 12, 7, 9, 10 },  // 2 ABGED
  { 13, 12, 7, 11, 10 },  // 3 ABGCD
  { 10, 11,12,7},// 4 FGBC
 {13,10,11,7,8}, // 5 AFGCD
  {13,10,11,9,8,7},//6 AFGEDC
  {13,12,7},//7 ABC
  {13,12,11,10,9,8,7},//8 ABFGCDE
  {13,10,11,12,7,8},//9 AFGBCD
};

void setup() {
  // Set all the segment pins as outputs
   pinMode(2,INPUT);
   pinMode(3,INPUT);
  for (int i = 0; i < 7; i++) {
    pinMode(segmentPins[i], OUTPUT);
  }
}

void loop() {
  // Example: Display number 2
  for (int number = 0; number < 10; number++) {
    delay(400);
    for (int i = 0; i < 7; i++) {
      if(objNumber[number][i] != 0) {
          digitalWrite(objNumber[number][i], HIGH);
      }
    
    }
  delay(400);
  for (int i = 0; i < 7; i++) {
        digitalWrite(segmentPins[i], LOW);
      }


    // Turn on the segments for the number
  }
}
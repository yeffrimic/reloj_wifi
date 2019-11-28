#ifndef segments_h
#define segments_h
#define displayOn HIGH
#define displayOFF LOW
#define anodo
#ifdef anodo
#define segmentOn LOW
#define segmentOFF HIGH
#endif
#ifdef catodo
#define segmentOn HIGH
#define segmentOFF LOW
#endif
uint8_t segments[] = {22, 23, 24, 25, 26, 27, 28};
uint8_t numbers[] = {29, 30, 31, 32};

void initSegments() {
  for (int i = 22; i < 33; i ++) {
    pinMode(i, OUTPUT);
  }
}

void showNumbers(uint16_t number, uint8_t numberPosition) {
  //Serial.println(number);
  //Serial.println(numberPosition);
  switch (numberPosition) {
    case 0:
      digitalWrite(numbers[0], displayOn);
      digitalWrite(numbers[1], displayOFF);
      digitalWrite(numbers[2], displayOFF);
      digitalWrite(numbers[3], displayOFF);
      break;
    case 1:
      digitalWrite(numbers[0], displayOFF);
      digitalWrite(numbers[1], displayOn);
      digitalWrite(numbers[2], displayOFF);
      digitalWrite(numbers[3], displayOFF);
      break;
    case 2:
      digitalWrite(numbers[0], displayOFF);
      digitalWrite(numbers[1], displayOFF);
      digitalWrite(numbers[2], displayOn);
      digitalWrite(numbers[3], displayOFF);
      break;
    case 3:
      digitalWrite(numbers[0], displayOFF);
      digitalWrite(numbers[1], displayOFF);
      digitalWrite(numbers[2], displayOFF);
      digitalWrite(numbers[3], displayOn);
      break;
  }

  switch (number) {
    case 0:
      digitalWrite(segments[0], segmentOn);
      digitalWrite(segments[1], segmentOn);
      digitalWrite(segments[2], segmentOn);
      digitalWrite(segments[3], segmentOn);
      digitalWrite(segments[4], segmentOn);
      digitalWrite(segments[5], segmentOn);
      digitalWrite(segments[6], segmentOFF);
      break;
    case 1:

      digitalWrite(segments[0], segmentOFF);
      digitalWrite(segments[1], segmentOn);
      digitalWrite(segments[2], segmentOn);
      digitalWrite(segments[3], segmentOFF);
      digitalWrite(segments[4], segmentOFF);
      digitalWrite(segments[5], segmentOFF);
      digitalWrite(segments[6], segmentOFF);
      break;
    case 2:

      digitalWrite(segments[0], segmentOn);
      digitalWrite(segments[1], segmentOn);
      digitalWrite(segments[2], segmentOFF);
      digitalWrite(segments[3], segmentOn);
      digitalWrite(segments[4], segmentOn);
      digitalWrite(segments[5], segmentOFF);
      digitalWrite(segments[6], segmentOn);
      break;
    case 3:

      digitalWrite(segments[0], segmentOn);
      digitalWrite(segments[1], segmentOn);
      digitalWrite(segments[2], segmentOn);
      digitalWrite(segments[3], segmentOn);
      digitalWrite(segments[4], segmentOFF);
      digitalWrite(segments[5], segmentOFF);
      digitalWrite(segments[6], segmentOn);
      break;
    case 4:

      digitalWrite(segments[0], segmentOFF);
      digitalWrite(segments[1], segmentOn);
      digitalWrite(segments[2], segmentOn);
      digitalWrite(segments[3], segmentOFF);
      digitalWrite(segments[4], segmentOFF);
      digitalWrite(segments[5], segmentOn);
      digitalWrite(segments[6], segmentOn);
      break;
    case 5:

      digitalWrite(segments[0], segmentOn);
      digitalWrite(segments[1], segmentOFF);
      digitalWrite(segments[2], segmentOn);
      digitalWrite(segments[3], segmentOn);
      digitalWrite(segments[4], segmentOFF);
      digitalWrite(segments[5], segmentOn);
      digitalWrite(segments[6], segmentOn);
      break;
    case 6:
      digitalWrite(segments[0], segmentOn);
      digitalWrite(segments[1], segmentOFF);
      digitalWrite(segments[2], segmentOn);
      digitalWrite(segments[3], segmentOn);
      digitalWrite(segments[4], segmentOn);
      digitalWrite(segments[5], segmentOn);
      digitalWrite(segments[6], segmentOn);
      break;
    case 7:

      digitalWrite(segments[0], segmentOn);
      digitalWrite(segments[1], segmentOn);
      digitalWrite(segments[2], segmentOn);
      digitalWrite(segments[3], segmentOFF);
      digitalWrite(segments[4], segmentOFF);
      digitalWrite(segments[5], segmentOFF);
      digitalWrite(segments[6], segmentOFF);
      break;
    case 8:

      digitalWrite(segments[0], segmentOn);
      digitalWrite(segments[1], segmentOn);
      digitalWrite(segments[2], segmentOn);
      digitalWrite(segments[3], segmentOn);
      digitalWrite(segments[4], segmentOn);
      digitalWrite(segments[5], segmentOn);
      digitalWrite(segments[6], segmentOn);
      break;
    case 9:

      digitalWrite(segments[0], segmentOn);
      digitalWrite(segments[1], segmentOn);
      digitalWrite(segments[2], segmentOn);
      digitalWrite(segments[3], segmentOn);
      digitalWrite(segments[4], segmentOFF);
      digitalWrite(segments[5], segmentOn);
      digitalWrite(segments[6], segmentOn);
      break;
  }

}

void toIntArray(int numberIn) {
  int numberArray[4];
  for (int i = 3; i >= 0; i--) {
    numberArray[i] = numberIn % 10;
    numberIn /= 10;
  }
  for (int i = 0; i < 4; i++) {
    showNumbers(numberArray[i], i);
    delay(1);
  }
}
#endif

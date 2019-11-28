#include "segments.h"

String inputString = "";         // a String to hold incoming data
bool stringComplete = false;  // whether the string is complete
int number  ;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  Serial.println("Inicializando");
  initSegments();
  inputString.reserve(5);
}

void loop() {
  if (stringComplete) {
    Serial.println(inputString);
    // clear the string:
    //inputString.toCharArray(numberArray, 5);
    //Serial.println(numberArray);
    number = inputString.toInt();
    inputString = "";

    stringComplete = false;
  }
  toIntArray(number);
}

void serialEvent() {
  while (Serial.available()) {
    // get the new byte:
    char inChar = (char)Serial.read();
    // add it to the inputString:
    inputString += inChar;

    // if the incoming character is a newline, set a flag so the main loop can
    // do something about it:
    if (inChar == '\n') {
      stringComplete = true;
    }
  }
}

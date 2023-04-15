#include <SoftwareSerial.h>
#include "SevSeg.h"
SevSeg sevseg;
#define type 1 // 0 for common cathode and 1 for common acode
SoftwareSerial mySerial(2, 3); // RX, TX

int potPin = A0;    // The analog pin the potentiometer is attached to
int buzzerPin = A1; // The analog pin the buzzer is attached to
int buzzerFrequency = 1000; // The frequency of the buzzer sound in hertz
int buzzerDuration = 200;   // The duration of the buzzer sound in milliseconds
int joystickPin = A4;
int joystickThreshold = 512; // Change this value to adjust sensitivity
String inputStringNumber = "";         // a String to hold incoming data
bool stringCompleteNumber = false;  // whether the string is complete
String inputStringBuzzSignal = "";         // a String to hold incoming data
bool stringCompleteBuzzSignal = false;  // whether the string is complete

void setup() {
    int two=2;
  byte numDigits = 1;
  //defines common pins while using multi-digit display. Left for single digit display
  byte digitPins[] = {};
  //Defines Arduino pin connections in order: A, B, C, D, E, F, G, DP
  byte segmentPins[] = {11,10, 9, 8, 7, 6, 5, 4};
  byte displayType = COMMON_CATHODE; //Use COMMON_ANODE for Common Anode display
  bool resistorsOnSegments = true; //‘false’ if resistors are connected to common pin
  //Initialize sevseg object. Use COMMON_ANODE instead of COMMON_CATHODE for CA display
  sevseg.begin(displayType, numDigits, digitPins, segmentPins, resistorsOnSegments);
  sevseg.setBrightness(90);
  
  //pinMode(dp, OUTPUT); // Set decimal point pin as an output
  Serial.begin(9600);
  mySerial.begin(9600);
}

void loop() {
  int sensorValue = analogRead(potPin);
  int outputValue = map(sensorValue, 0, 1023, 1, 10);
  
  if (outputValue == 7) { // If the mapped value is 7
    tone(buzzerPin, buzzerFrequency, buzzerDuration); // Play the buzzer sound
  } else {
    noTone(buzzerPin); // Stop the buzzer sound
  }
  //Display numbers 0-9 with 1 seconds delay
  Serial.println(outputValue);
  sevseg.setNumber(outputValue);
  sevseg.refreshDisplay();

  stringCompleteNumber=false;
  stringCompleteBuzzSignal=false;
  
 
  int joystickValue = analogRead(joystickPin);

  if (joystickValue < 400) {
    // Joystick pushed up
    mySerial.println("up");
    Serial.println("up");
  } else if (joystickValue> 600) {
    // Joystick pushed down
    mySerial.println("down");
    Serial.println("down");
  }
  
  
  //port is /dev/ttyACM0
  //on linux
  
  delay(10); // Add a short delay to prevent spamming the serial port
}
void serialEvent() {
  while (Serial.available()) {
    // get the new byte:
    char inChar = (char)Serial.read();
    // add it to the inputString:
    inputStringNumber += inChar;
    // if the incoming character is a newline, set a flag so the main loop can
    // do something about it:
    if (inChar == '\n') {
      stringCompleteNumber = true;
    }
  }
}

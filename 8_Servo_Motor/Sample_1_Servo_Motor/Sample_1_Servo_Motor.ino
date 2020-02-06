//******************************************************//
// Servo Motor
// Sample Code 1 [Control the servo motor]
//                                      - Kyung-Sik Jang//
//******************************************************//

// Servo Motor
//  - Servo motor is different from general motor,
//    and since it is fixed in rotation, it is used when accurate
//    movement is needed.
// How to use
// VCC Pin - Red
// GND Pin - Brown
// PWM Pin - PWM

// What is PWM?
//  - Abbreviation for pulse width modulation, a method of controlling
//    the average voltage by varying the Duty ratio within a certain period.
//
//        (t1)       (t2)
//      ┌------┐           ┌------
// -----┘      └-----------┘
//    t1 : High state of waveform
//    t2 : Low state of waveform
//
//  - duty cycle calculation
//      duty ratio : t1 / (t1 + t2)

#include <Servo.h>
Servo myServo;
int angle = 0;

void setup() {
  Serial.begin(9600);
  myServo.attach(3);
}

void loop() {
  // scan from 0 to 180 degrees
  for(angle = 0; angle < 180; angle++) 
  { 
    myServo.write(angle); 
    delay(15); 
  } 
  // now scan back from 180 to 0 degrees
  for(angle = 180; angle > 0; angle--) 
  { 
    myServo.write(angle); 
    delay(15); 
  } 
}

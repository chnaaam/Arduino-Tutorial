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
  // Start Time
  long start_time = millis();

  // Forward
//  for(int i =0 ; i < 180 ; i+=20)
//  {
//    myServo.write(i);
//    delay(100);
//  }
  myServo.write(0);
  delay(500);

  // Backward
  myServo.write(180);
  delay(500);

  // End Time
  long end_time = millis();

  long measurement_time = end_time - start_time;
  Serial.print("Total Time : ");
  Serial.print(measurement_time);
  Serial.print("\tAverage Time : ");
  Serial.println(measurement_time / 2);

  delay(1000); 
}

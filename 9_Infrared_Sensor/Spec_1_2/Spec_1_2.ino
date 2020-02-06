//******************************************************//
// Infrared Sensor
// Practice Code
//  - Program the system satisfying the following specification
//    * Spec-1 : Measure the distance between IR sensor and obstacles
//               at every 0.5 sec.
//    * Spec-2 : (optional)
//               Calibrate the measurement by adjusting the coefficient
//               of equation.
//                                      - Kyung-Sik Jang//
//******************************************************//

#define SIGNAL_PIN    A0

int distance = 0; 

void setup() {
  Serial.begin(9600);

  pinMode(SIGNAL_PIN, INPUT);
}

void loop() {
  int volt = map(analogRead(SIGNAL_PIN), 0, 1023, 0, 5000); 

  // Spec-2
  distance = (27.61 / (volt - 0.1696)) * 1000; 

  Serial.print(distance);
  Serial.print(" cm");
  if(distance < 30)
    Serial.println("\tObstacles");
  else
    Serial.println("\tNo Obstacles");
  delay(500);
}

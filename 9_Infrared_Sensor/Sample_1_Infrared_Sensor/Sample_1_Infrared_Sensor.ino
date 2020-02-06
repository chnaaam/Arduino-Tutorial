//******************************************************//
// Infrared Sensor
// Sample Code 1
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
  distance = (27.61 / (volt - 0.1696)) * 1000; 

  Serial.print(distance);
  Serial.println(" cm");
  delay(500);
}

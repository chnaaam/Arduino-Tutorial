#define VIB_SENSOR A0
#define TOUCH 10

void setup() {
  
  Serial.begin(9600);
  pinMode(VIB_SENSOR, INPUT);
}

void loop() {
  int isTouch = analogRead(VIB_SENSOR);
  if(isTouch > TOUCH)
    Serial.print("Touch, Analog Value : ");
    Serial.println(isTouch);
  
  delay(100);
}

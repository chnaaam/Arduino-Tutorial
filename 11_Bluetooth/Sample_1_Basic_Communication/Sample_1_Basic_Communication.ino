//******************************************************//
// Bluetooth (HC-06)
// Sample Code 1
//                                      - Kyung-Sik Jang//
//******************************************************//

//******************************************************//
// Hardware Configuration
//  - Connect IoT Starter Kit and Bluetooth module
//  Arduino      Bluetooth module
//    5V       -        VCC
//    GND      -        GND
//     2       -         Tx
//     3       -        Rx
//******************************************************//

#include <SoftwareSerial.h>
 
int blueTx=2;
int blueRx=3;
SoftwareSerial bluetooth(blueTx, blueRx);
 
void setup() 
{
  Serial.begin(9600);
  bluetooth.begin(9600);
}
void loop()
{
  if (bluetooth.available()) {       
    Serial.write(bluetooth.read());  
  }
  if (Serial.available()) {         
    bluetooth.write(Serial.read());  
  }
}

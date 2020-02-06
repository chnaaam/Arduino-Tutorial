//******************************************************//
// Temperature Sensor
// Sample Code 1 [Control the temperature sensor]
//                                      - Kyung-Sik Jang//
//******************************************************//

//******************************************************//
// Hardware Configuration
//  - Connect IoT Starter Kit and Temperature Sensor
//******************************************************//

// Temperature sensor
// Hardware Spec
// Temperatue range  : -55 ~ +125 ('C)
// Accuracy          : ±0.5

// DS18B20 Function Commands
// Address    Name             Explain
// 0x44       Convert T        This command initiates a single temperature conversion
// 0xBE       Read Scratchpad  This command allows the master to read the contents of
//                             the scratchpad. (9 bytes = data byte 8 + CRC byte 1)
//                                                      CRC : Cyclic Redundancy Check

#include <OneWire.h>  

OneWire ds(2); // 2번 핀에 연결된 OneWire 개체 생성

void setup() {
  Serial.begin(9600);
}

void loop() {
  byte i;
  byte present = 0;

  byte data[12];
  byte addr[8];
  float Temp;

  if (!ds.search(addr)) {
    ds.reset_search();
    return;
  }
  
  ds.reset();
  ds.select(addr);
  ds.write(0x44,1); // start conversion, with parasite power on at the end
  delay(1000);

  present = ds.reset();
  ds.select(addr);
  ds.write(0xBE); // Read Scratchpad

  for (i = 0; i < 9; i++) { // 센서에서 가져온 값을 정리하고 난 후 배열에 순서대로 넣어 둔다.
    data[i] = ds.read();
  }

  // From the values obtained above, multiply the value in array 1 by 256 (2 powers of 8)
  // and add it with the value in array 0.
  // Divide the value by 16 to get Celsius.
  // 
  // Shift Operator
  // Example 
  // data = 0x04
  // Current State : | 0 | 0 | 0 | 0 | 0 | 1 | 0 | 0 |
  // Shift : data = data << 2
  // Current State : | 0 | 0 | 0 | 1 | 0 | 0 | 0 | 0 |
  Temp=(data[1]<<8)+data[0];
  Temp=Temp/16;
  
  // Celsius
  Serial.print("C=");
  Serial.print(Temp);
  Serial.print(", ");
  // 섭씨 출력

  // Convert "Celsius" to "Fahrenheit"
  Temp=Temp*1.8+32;

  // Celsius
  Serial.print("F=");
  Serial.print(Temp);
  Serial.println(" ");  
}

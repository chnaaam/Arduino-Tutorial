#include "ESP8266.h"
#include <SoftwareSerial.h>

#define SSID        "jangLab"
#define PASSWORD    "emsys2019"
#define HOST_NAME   "192.168.0.20"
#define HOST_PORT   (9997)

#define LIGHT A3

#define MY_ID       "JANG %d"

SoftwareSerial mySerial(8, 9);
ESP8266 wifi(mySerial);

void setup(void)
{
    Serial.begin(9600);
    Serial.print("setup begin\r\n");

    pinMode(LIGHT, INPUT);
             
    if (wifi.setOprToStationSoftAP()) {
        Serial.print("to station + softap ok\r\n");
    } else {
        Serial.print("to station + softap err\r\n");
    }

    if (wifi.joinAP(SSID, PASSWORD)) {
        Serial.print("Join AP success\r\n");
        Serial.print("IP:");
        Serial.println( wifi.getLocalIP().c_str());       
    } else {
        Serial.print("Join AP failure\r\n");
    }
    
    if (wifi.disableMUX()) {
        Serial.print("single ok\r\n");
    } else {
        Serial.print("single err\r\n");
    }
    
    Serial.print("setup end\r\n");

    if (wifi.createTCP(HOST_NAME, HOST_PORT)) {
        Serial.print("create tcp ok\r\n");
    } else {
        Serial.print("create tcp err\r\n");
    }
}
 
void loop(void)
{
    uint8_t buffer[128] = {0};

    int value = analogRead(LIGHT);
    int data = map(value, 0, 1023, 1023, 0);

    char _data[10] = "123";
    sprintf(_data, MY_ID, data);
    Serial.println(data);
    Serial.println(_data);

    wifi.send((const uint8_t*)_data, strlen(_data));
    
//      uint32_t len = wifi.recv(buffer, sizeof(buffer), 10000);
//      if (len > 0) {
//          Serial.print("Received:[");
//          for(uint32_t i = 0; i < len; i++) {
//              Serial.print((char)buffer[i]);
//          }
//          Serial.print("]\r\n");
//      }
    
//    if (wifi.releaseTCP()) {
//        Serial.print("release tcp ok\r\n");
//    } else {
//        Serial.print("release tcp err\r\n");
//    }
//    delay(100);
    delay(2000);
}

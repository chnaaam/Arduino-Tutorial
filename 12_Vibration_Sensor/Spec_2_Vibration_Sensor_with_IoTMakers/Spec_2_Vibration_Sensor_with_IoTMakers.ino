//******************************************************//
// Ambient Light Sensor
// Sample Code 3
//                                      - Kyung-Sik Jang//
//******************************************************//

#include <WiFi.h>
#include <IoTStarterKit_WiFi.h>
#include <OneWire.h>

IoTMakers g_im;

// For example...
 #define deviceID    "nch207D1566398498413"
 #define authnRqtNo  "m3yi1o9q3"
 #define extrSysID   "OPEN_TCP_001PTL001_1000007578"

 #define WIFI_SSID   "ICT-LAB-2.4G"
 #define WIFI_PASS   "12345678"

//#define deviceID    "{YOUR_DEVICE_ID}"
//#define authnRqtNo  "{YOUR_DEVICE_PASSWORD}"
//#define extrSysID   "{YOUR_GATEWAY_ID}"
//
//#define WIFI_SSID   "{WIFI_NAME}"
//#define WIFI_PASS   "{WIFI_PASSWORD}"

#define VIB_SENSOR A0

// ************************************************************************ //
// Very Important!!!!
// IoTMakers tag stream id must be the same below !!!
#define TAG_ID "VIBRATION"
// ************************************************************************ //

void init_iotmakers()
{
  while(1)
  {
    Serial.print(F("Connect to AP..."));
    while(g_im.begin(WIFI_SSID, WIFI_PASS) < 0)
    {
      Serial.println(F("retrying"));
      delay(100);
    }

    Serial.println(F("Success"));

    g_im.init(deviceID, authnRqtNo, extrSysID);
  
    Serial.print(F("Connect to platform..."));
    while(g_im.connect() < 0)
    {
      Serial.println(F("retrying."));
      delay(100);
    }
    Serial.println(F("Success"));
  
    Serial.print(F("Auth..."));
    if(g_im.auth_device() >= 0)
    {
      Serial.println(F("Success..."));
      return;
    }
  }
}

void setup() {
  Serial.begin(9600);

  pinMode(VIB_SENSOR, INPUT);
  
  init_iotmakers();
}

void loop() {
  static unsigned long tick = millis();

  if(g_im.isServerDisconnected() == 1)
  {
    init_iotmakers();
  }

  if((millis() - tick) > 1000)
  {
    send_vib_value();
    tick = millis();
  }

  g_im.loop();
}

int send_vib_value()
{
  int isTouch = analogRead(VIB_SENSOR);
  
  if(g_im.send_numdata(TAG_ID, (double)isTouch) < 0)
  {
    Serial.println(F("fail"));
    return -1;
  }
  
  return 0;
}

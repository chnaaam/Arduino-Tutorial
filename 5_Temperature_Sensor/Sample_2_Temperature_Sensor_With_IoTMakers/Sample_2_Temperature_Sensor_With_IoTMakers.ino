//******************************************************//
// Temperature Sensor
// Sample Code 2 [Control the temperature sensor]
//                                      - Kyung-Sik Jang//
//******************************************************//

#include <WiFi.h>
#include <IoTStarterKit_WiFi.h>
#include <OneWire.h>
#include <DallasTemperature.h>

IoTMakers g_im;

// For example...
// #define deviceID    "nch207D1565936279095"
// #define authnRqtNo  "6hhkxlhrq"
// #define extrSysID   "OPEN_TCP_001PTL001_1000007578"
//
// #define WIFI_SSID   "jangLab"
// #define WIFI_PASS   "emsys2019"

#define deviceID    "{YOUR_DEVICE_ID}"
#define authnRqtNo  "{YOUR_DEVICE_PASSWORD}"
#define extrSysID   "{YOUR_GATEWAY_ID}"

#define WIFI_SSID   "{WIFI_NAME}"
#define WIFI_PASS   "{WIFI_PASSWORD}"

#define ONE_WIRE_BUS 2

// ************************************************************************ //
// Very Important!!!!
// IoTMakers tag stream id must be the same below !!!
#define TAG_ID "Temperature"
// ************************************************************************ //

OneWire ourWire(ONE_WIRE_BUS);
DallasTemperature sensors(&ourWire);

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

  sensors.begin();
  
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
    send_temperature();
    tick = millis();
  }

  g_im.loop();
}

int send_temperature()
{
  // This Scope is package of temperature sensor
  // Raw coding (with register address) look at "5_Temperature_Sensor Project"
  sensors.requestTemperatures();
  int data = sensors.getTempCByIndex(0);

  Serial.print("Temperature : ");
  Serial.print(data);
  Serial.println(" Celsius");
  
  if(g_im.send_numdata(TAG_ID, (double)data) < 0)
  {
    Serial.println(F("fail"));
    return -1;
  }

  return 0;
}

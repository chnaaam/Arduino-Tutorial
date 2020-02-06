//******************************************************//
// Bluetooth (HC-06)
// Sample Code 2
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

// Your Packet
typedef struct{
  char startByte;
  char endByte;
  char * data;
}Packet;
 
void setup() 
{
  Serial.begin(9600);
  bluetooth.begin(9600);
}

void loop()
{
  Packet packet = init_packet();
  packet.data = (char *)malloc(sizeof(char) * 10);

  // Real Data (value type : char [])
  strcpy(packet.data, "Hello");

  char * charArrayPacket = packetToCharArray(packet);
  
  bluetooth.write((const char *)charArrayPacket);

  // Shorter delays can cause packets to break.
  delay(2000);
}

// Packet structure initialization
Packet init_packet()
{
  Packet packet;

  // Start Byte
  //  - Hex : 0x55
  //  - Bin : 0b01010101
  packet.startByte = 0b01010101;

  // End Byte
  //  - Hex : 0xA5
  //  - Bin : 0b01011010
  packet.endByte = 0b01011010;
  
  return packet;
}

// Packet structure convert to char array
char* packetToCharArray(Packet packet)
{
  char * charPacket = (char *)malloc(sizeof(char) * 12);
  charPacket[0] = packet.startByte;
  charPacket[11] = packet.endByte;

  // for measuring packet data length
  int data_len = strlen(packet.data);
  
  // Data
  for(int i = 0 ; i < data_len ; i++)
    charPacket[i + 1] = packet.data[i];

  // Fill the empty space with "0xFF"
  for(int i = data_len ; i < 10 ; i++)
    charPacket[i + 1] = 0xFF;
 
  return charPacket;
}

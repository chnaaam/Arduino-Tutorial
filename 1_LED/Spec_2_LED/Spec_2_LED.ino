//******************************************************//
// LED
// Practice Code
//  - Program the system satisfying the following specification
//    * Spec-1 : Change the color sequence of f-LED to any favorite
//               color pattern at every second.
//    * Spec-2 : (optional)
//               1. Make a rainbow of 7 f-LED's
//               2. Careful for connecting 7 LED's.
//               3. Which connection type is more preferable ? Serial or Parallel?
//
//                                      - Kyung-Sik Jang//
//******************************************************//

int redPin = 11; 
int greenPin = 10; 
int bluePin = 9;

// Define LED color array [R, G, B]
// Rainbow = RED, ORANGE, YELLOW, GREEN, BLUE, INDOGO(AQUA), PULPLE
// Example
//  - [255,     0,     0]
//     RED, GREEN,  BLUE
//      ON,   OFF,   OFF
int LED_RED[3]    = {255, 0, 0};
int LED_ORANGE[3] = {255, 165, 0};
int LED_YELLOW[3] = {255, 255, 0};
int LED_GREEN[3]  = {255, 0, 0};
int LED_BLUE[3]   = {0, 0, 255};
int LED_AQUA[3]   = {0, 255, 255};
int LED_PULPLE[3] = {80, 0, 80};

void setup() 
{ 
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT); 
  pinMode(bluePin, OUTPUT); 
} 

void loop() 
{ 
  // LAB-1 Control Fullcolor LED
  // Spec-2
  //  - Make a rainbow of 7-LED's.
  setColor(LED_RED);
  delay(1000);
  setColor(LED_ORANGE);
  delay(1000);
  setColor(LED_YELLOW);
  delay(1000);
  setColor(LED_GREEN);
  delay(1000);
  setColor(LED_BLUE);
  delay(1000);
  setColor(LED_AQUA);
  delay(1000);
  setColor(LED_PULPLE);
  delay(1000);
}

// This function parameter receive predefine R, G, B value.
void setColor(int color[3])
{
  analogWrite(redPin,   color[0]); 
  analogWrite(greenPin, color[1]); 
  analogWrite(bluePin,  color[2]); 
}

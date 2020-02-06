//******************************************************//
// LED + SWITCH
// Practice Code
//  - Program the system satisfying the following specification
//    * Spec-1 : Change the way of lighting LED in sample code.
//               (if LED is on when switch is pushed, reverse it!)
//    * Spec-2 : (optional)
//               Modify the result of LAB-1 with switch (interrupted)
//               * Change the color of f-LED if switch is pushed.

//                                      - Kyung-Sik Jang//
//******************************************************//

//******************************************************//
// Hardware Configuration
//  - Connect IoT Starter Kit and LED, Switch
//  - Configure your own circuits without using LED modules...
//******************************************************//

#define SWITCH 3

int redPin = 11; 
int greenPin = 10; 
int bluePin = 9;

// Define LED color array [R, G, B]
// Rainbow = RED, ORANGE, YELLOW, GREEN, BLUE, INDOGO(AQUA), PULPLE
// Example
//  - [255,     0,     0]
//     RED, GREEN,  BLUE
//      ON,   OFF,   OFF
#define LED_CONF_RED    0
#define LED_CONF_ORANGE 1
#define LED_CONF_YELLOW 2
#define LED_CONF_GREEN  3
#define LED_CONF_BLUE   4
#define LED_CONF_AQUA   5
#define LED_CONF_PULPLE 6

int LED_RED[3]    = {255, 0, 0};
int LED_ORANGE[3] = {255, 165, 0};
int LED_YELLOW[3] = {255, 255, 0};
int LED_GREEN[3]  = {255, 0, 0};
int LED_BLUE[3]   = {0, 0, 255};
int LED_AQUA[3]   = {0, 255, 255};
int LED_PULPLE[3] = {80, 0, 80};

int ledToggle = 0;

void setup() {
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT); 
  pinMode(bluePin, OUTPUT); 
  
  // Switch Configuration - Interrupt
  pinMode(SWITCH, INPUT_PULLUP);

  // attachInterrupt(pin_number, handler_function, interrupt_mode)
  // - Parameter 1 [pin_number]       : Interrupt pin number
  // - Parameter 2 [handler_function] : ISR(Interrupt Service Routine) Function
  // - Parameter 3 [interrupt_mode]   : Interrupt Mode
  //    * LOW : to trigger the interrupt whenever the pin is low
  //    * HIGH : to trigger the interrupt whenever the pin is high
  //    * CHANGE : to trigger the interrupt whenever the pin changes value
  //    * RISING : to trigger when the pin goes from low to high
  //    * FALLING : for when the pin goes from high to low
  attachInterrupt(digitalPinToInterrupt(SWITCH), interrupt_handler, CHANGE);
}

void loop() {
  switch(ledToggle)
  {
    case LED_CONF_RED:
      setColor(LED_RED);
      break;
    case LED_CONF_ORANGE:
      setColor(LED_ORANGE);
      break;
    case LED_CONF_YELLOW:
      setColor(LED_YELLOW);
      break;
    case LED_CONF_GREEN: 
      setColor(LED_GREEN);
      break;
    case LED_CONF_BLUE: 
      setColor(LED_BLUE);
      break;
    case LED_CONF_AQUA: 
      setColor(LED_AQUA);
      break;
    case LED_CONF_PULPLE: 
      setColor(LED_PULPLE);
      break;
    default:
      setColor(LED_RED); 
      break;
  }
} 

// Spec-2
// Interrupt Handler Function
void interrupt_handler()
{
  // Current State ->  Next State
  //      true     ->   false
  //      false    ->   true
  ledToggle++;

  if(ledToggle == 7)
    ledToggle = 0;
}

// This function parameter receive predefine R, G, B value.
void setColor(int color[3])
{
  analogWrite(redPin,   color[0]); 
  analogWrite(greenPin, color[1]); 
  analogWrite(bluePin,  color[2]); 
}

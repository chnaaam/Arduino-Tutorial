//******************************************************//
// LED + SWITCH Practice (Interrupt)    - Kyung-Sik Jang//
//******************************************************//

//******************************************************//
// Hardware Configuration
//  - Connect IoT Starter Kit and LED, Switch
//  - Configure your own circuits without using LED modules...
//******************************************************//

#define LED 2
#define SWITCH 3

boolean isLedOn = false;

void setup() {
  pinMode(LED, OUTPUT);
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
  attachInterrupt(digitalPinToInterrupt(SWITCH), interrupt, CHANGE);
  
  digitalWrite(LED, LOW);
}

void loop() {
//******************************************************//
  // Sample Code
  // If the switch is pressed, then led is on
  digitalWrite(LED, !isLedOn);
} 

// Interrupt Handler Function
void interrupt()
{
  // Current State ->  Next State
  //      true     ->   false
  //      false    ->   true
  isLedOn = !isLedOn;
}

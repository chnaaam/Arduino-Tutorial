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

// Spec-1
#define LED 2
#define SWITCH 3

// LED toggle variable (ON or OFF)
boolean isLedOn = false;

void setup() {
  pinMode(LED, OUTPUT);
  digitalWrite(LED, LOW);
  
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
//******************************************************//
  // Sample Code
  // If the switch is pressed, then led is on
  // Spec-1
  // If you want to execute spec-1 problem,
  // Remove below comment and spec-1 interrupt handler function
   digitalWrite(LED, !isLedOn);
} 

// Interrupt Handler Function
void interrupt_handler()
{
  // Current State ->  Next State
  //      true     ->   false
  //      false    ->   true
  isLedOn = !isLedOn;
}

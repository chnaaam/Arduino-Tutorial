//******************************************************//
// LED
// Sample Code 1 [Control the one color LED]
//                                      - Kyung-Sik Jang//
//******************************************************//

//******************************************************//
// Hardware Configuration
//  - Connect IoT Starter Kit and LED Module
//******************************************************//


// Pin Setting : digital pin 2
// alternate code 
//  - int LED = 2;
#define LED 2

// This function is initilaization section of arduino
// In general, this is used to initialize the module
// for example module is included variable, pin mode, initialization other sensor / library
void setup() {
  // Pin Mode Function : pinMode(pin_number, pin_mode)
  // - Parameter 1 [pin_number] : Pin Number
  // - Parameter 2 [pin_mode]   : Pin Mode Setting (Output or Input)
  pinMode(LED, OUTPUT);

  // Digital Write Function : digitalWrite(pin_number, pin_state)
  // - Paramter 1 [pin_number] : Pin Number
  // - Paramter 2 [pin_state]  : Pin State Setting (HIGH or LOW)
  //   - HIGH : Pin output voltage is 5v
  //   - LOW  : Pin output voltage is 0v
  digitalWrite(LED, HIGH);
}

// This function is execution section of arduino
// So, if you want to run module control repeatably
// Put the your custom or library code
void loop() {
  // Sample Code
  led_on();
  delay_1s();

  led_off();
  delay_1s();
}

// LED ON
// In general, LED is on that pin state is "HIGH"  (5V)
// But this parameter set "LOW" Because the resister is maded pull-up
void led_on()
{
  digitalWrite(LED, LOW);
}

// LED OFF
void led_off()
{
  digitalWrite(LED, HIGH);
}

// delay (1 second)
// the delay function have parameter that number of delay time
// this standard unit is 1ms (millisecond)
// - 1000ms = 1s
void delay_1s()
{
  delay(1000);
}

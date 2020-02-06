//******************************************************//
// LED + SWITCH Practice (Polling)      - Kyung-Sik Jang//
//******************************************************//

//******************************************************//
// Hardware Configuration
//  - Connect IoT Starter Kit and LED, Switch
//  - Configure your own circuits without using LED modules...
//******************************************************//

#define LED 2
#define SWITCH 3

void setup() {
  pinMode(LED, OUTPUT);
  // Pin Mode Function : pinMode(pin_number, pin_mode)
  // - Parameter 1 [pin_number] : Pin Number
  // - Parameter 2 [pin_mode]   : Pin Mode Setting (Output or Input)
  //   - This value "INPUT_PULLUP" is set of input state in software
  //   - If you write "INPUT" value, arduino is read value as HIGH whenever input voltage state is HIGH (5V)
  //   - In the opposite case, arduino is read as "LOW" (input voltage state : HIGH -> arduino is read LOW)

  // Q : Why use pull-up?
  // A : One of the case, LED is used with pull-up state.
  //     Let's assume that LED consume electric current as much as 20mA and Arduino output electric current is 100mA.
  //     If you use less then 5 LED, then directly connect between Arduino and LED.
  //     that the plus line connect Arduino output pin and minus line connect ground(GND).
  //     But if you want to use many LED more then 6, there is a lack of Arduino output electric current. 
  //     (LED current : 120mA > Arduino output current : 100mA)
  //     In this case, One of the method is using other power (like PC or battery) and pull-up state.
  //     LED Plus line connect power and minus line connect arduino output pin to use pull-up state.
  //      ( No pull-up )             ( Pull-up )
  //        ┌-----┐         │       ┌-----┐
  //        │ LED │         │       │ LED │
  //        ├-----┤         │       ├-----┤
  //        │(-)  │(+)      │       │(-)  │(+)
  //       GND   Arduino            Arduino Power
  
  pinMode(SWITCH, INPUT_PULLUP);
  
  digitalWrite(LED, LOW);
}

void loop() {
//******************************************************//
  // Sample Code
  // If the switch is pressed, then led is on
  if(digitalRead(SWITCH) == 0)    digitalWrite(LED, HIGH);
  else                            digitalWrite(LED, LOW); 
} 

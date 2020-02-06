//******************************************************//
// FND
// Practice Code     
//  - Program the system satisfying the following specification
//    * Spec-1 : Make a down-counting timer.
//               1) the initial value is '9'
//               2) Count down every 0.5 second.
//               3) If FND reaches to '0', blink all LED's 5 times.
//               4) Blink a dot at the lower light corner of FND.
//    * Spec-2 : (optional)
//               Modify the result of Spec-1 with wrap-around function.
//               * If the value of FND becomes '0', the next will be '9'.
//                                      - Kyung-Sik Jang//
//******************************************************//

//******************************************************//
// Hardware Configuration
//  - Connect IoT Starter Kit and FND Module
//******************************************************//

// 7 segment
//  - This module has 8 LEDs and can represent 1 number (0~9)
//  - Each LED is controlled Arduino output pin state (HIGH or LOW)
// Output Pin Setting
//  - IoT Starter Kit is assiged FND module pin (2, 3, 4, 5, A2, A3, A4, A5)
//  ┌--------┐(2)
//  │        │
//  │ (A3)   │(3)
//  │        │
//  ├--------┤(A4)
//  │        │
//  │(A3)    │(4) 
//  │        │
//  └--------┘(A2)   .(dot) (A5)

int fnd_pin[8] = {2, 3, 4, 5, A2, A3, A4, A5};
int fnd_digits[10][8] = {
  {1, 1, 1, 1, 1, 1, 0, 0},   // 0
  {0, 1, 1, 0, 0, 0, 0, 0},   // 1
  {1, 1, 0, 1, 1, 0, 1, 0},   // 2
  {1, 1, 1, 1, 0, 0, 1, 0},   // 3
  {0, 1, 1, 0, 0, 1, 1, 0},   // 4
  {1, 0, 1, 1, 0, 1, 1, 0},   // 5
  {1, 0, 1, 1, 1, 1, 1, 0},   // 6
  {1, 1, 1, 0, 0, 0, 0, 0},   // 7
  {1, 1, 1, 1, 1, 1, 1, 0},   // 8
  {1, 1, 1, 1, 0, 1, 1, 0}    // 9
};

void setup() {
  for(int i = 0 ; i < 8 ; i++)
    pinMode(fnd_pin[i], OUTPUT);
}

void loop() {
  // 1) the initial value is '9'
  display(9);
  
  // 2) Count down every 0.5 second.
  for(int i = 0 ; i < 10 ; i++)
  {
    display(9 - i);
    delay(500);
  }
  
  // 3) If FND reaches to '0', blink all LED's 5 times.
  for(int i = 0 ; i < 5; i++)
  {
    fnd_all_on();
    delay(200);
    fnd_all_off();
    delay(200);  
  }
  
  // 4) Blink a dot at the lower light corner of FND.
  for(int i = 0 ; i < 10 ; i++)
  {
    digitalWrite(fnd_pin[7], HIGH);
    delay(200);
    digitalWrite(fnd_pin[7], LOW);
    delay(200);
  }
}

void display(int num)
{
  if(num < 0) num = 0;
  else if(num >= 10) num = 9;

  for(int i = 0 ; i < 8 ; i++)
  {
    digitalWrite(fnd_pin[i], fnd_digits[num][i]);
  }
}

// This funciton is FND LED all on
void fnd_all_on()
{
  for(int i = 0 ; i < 8 ; i++)
    digitalWrite(fnd_pin[i], HIGH);
}

// This funciton is FND LED all off
void fnd_all_off()
{
  for(int i = 0 ; i < 8 ; i++)
    digitalWrite(fnd_pin[i], LOW);
}

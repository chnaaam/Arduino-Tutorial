//******************************************************//
// FND
// Sample Code 2 [Control the FND(7-segment) without library]
//                                      - Kyung-Sik Jang//
//******************************************************//

//******************************************************//
// Hardware Configuration
//  - Connect IoT Starter Kit and FND Module
//******************************************************//

int fnd_digits[10][2] = {
  {B00111100, B00001100},     // 0
  {B00011000, B00000000},     // 1
  {B00101100, B00010100},     // 2
  {B00111100, B00010000},     // 3
  {B00011000, B00011000},     // 4
  {B00110100, B00011000},     // 5
  {B00110100, B00011100},     // 6
  {B00011100, B00000000},     // 7
  {B00111100, B00011100},     // 8
  {B00111100, B00011000},     // 9
};

void setup() {
  DDRD |= B00111100;    // digital 2, 3, 4, 5
  DDRC |= B00111100;    // digital A2, A3, A4, A5
}

void loop() {
  for(int i = 0 ; i < 10 ; i++)
  {
    display(i);
    delay(1000);
  }
}

void display(int num)
{
  if(num < 0) num = 0;
  else if(num >= 10) num = 9;

  PORTD = fnd_digits[num][0];
  PORTC = fnd_digits[num][1];
}

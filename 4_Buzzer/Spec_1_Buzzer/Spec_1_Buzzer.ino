//******************************************************//
// Buzzer
// Practice Code
//  - Program the system satisfying the following specification
//    * Spec-1 : Change the sound(tone) if the switch is pushed.
//               * More than 3 types of tones.
//    * Spec-2 : (optional)
//               Modify the melody up by 1 octave.
//               * The melody (Super Mario) is uploaded in Github.
//                                      - Kyung-Sik Jang//
//******************************************************//

#define SWITCH 3
#define BUZZER 6

#define SWITCH_PRESSED 1

int buzzerToggle = 0;

#define toneC 0
#define toneD 1
#define toneE 2
#define toneF 3
#define toneG 4
#define toneA 5
#define toneB 6

// Piezo Buzzer
//  - Piezo buzzer is a small module that can make a simple sound when using Arduino.
//    The peizo buzzer makes a sound using the piezo effect.
//    Although the principle of piezo buzzer is simple,
//    it can be used in various ways because it can output ultrasonic waves above 20,000Hz.
//
//    If the piezo buzzer is signaled according to the frequency below,
//    the piezo buzzer will output an octave scale.

//    Example (Octave 2)
//    │  C   │  65.4064 │
//    │  D   │  73.4162 │
//    │  E   │  82.7817 │
//    │  F   │  87.3071 │
//    │  G   │  97.9989 │
//    │  A   │ 110.0000 │
//    │  B   │ 123.4708 │

void setup() {
  Serial.begin(9600);
  pinMode(BUZZER, OUTPUT);
  pinMode(SWITCH, INPUT_PULLUP);
}

void loop() {
  //******************************************************//
  // Sample Code
  // - Piezo Buzzer On
  
  // tone function : tone(pin_number, frequency)
  //   - Parameter 1 [pin_number]   : Arduino pin number
  //   - Parameter 2 [frequency]    : freqeuncy of tone

  // If switch is pressed, then buzzer tone change
  if(digitalRead(SWITCH) == SWITCH_PRESSED)  
  {
    buzzerToggle++;
    delay(100);
  }
  
  if(buzzerToggle == 7)         buzzerToggle = 0;
  
  switch(buzzerToggle)
  {
    case toneC:
      tone(BUZZER, 65.4064);
      break;
    case toneD:
      tone(BUZZER, 73.4162);
      break;
    case toneE:
    tone(BUZZER, 82.7817);
    break;
    case toneF:
    tone(BUZZER, 87.3071);
    break;
    case toneG:
    tone(BUZZER, 97.9989);
    break;
    case toneA:
    tone(BUZZER, 110.0000);
    break;
    case toneB:
    tone(BUZZER, 123.4708);
    break;
    default:
    noTone(BUZZER);
    break;
  }
}

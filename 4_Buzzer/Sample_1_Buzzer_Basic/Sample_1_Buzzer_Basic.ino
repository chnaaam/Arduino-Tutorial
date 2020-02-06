//******************************************************//
// Buzzer
// Sample Code 1 [Control the buzzer]
//                                      - Kyung-Sik Jang//
//******************************************************//

int BUZZER = 6;

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
  pinMode(BUZZER, OUTPUT);
}

void loop() {
  //******************************************************//
  // Sample Code
  // - Piezo Buzzer On
  
  // tone function : tone(pin_number, frequency)
  //   - Parameter 1 [pin_number]   : Arduino pin number
  //   - Parameter 2 [frequency]    : freqeuncy of tone
  tone(BUZZER, 400);
  delay(1000);

  // - Piezo Buzzer Off
  Serial.println("OFF");
  noTone(BUZZER);
  delay(1000);
}

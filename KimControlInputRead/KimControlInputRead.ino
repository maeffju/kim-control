
#include<stdio.h>
#define FADER_OFFSET 69   // analog offset when fader is in zero-position
#define COUNT_ANALOG_INPUTS 8
#define COUNT_DIGITAL_INPUTS 4

typedef struct {
  int value;
  char pin;
  String name;
} input;

// Globale Values
input analogInputs[COUNT_ANALOG_INPUTS];
input digitalInputs[COUNT_DIGITAL_INPUTS];


// Code
void setup() {
  defineAnalogInputs();
  defineDigitalInputs();
  
  Serial.begin(9600);
  for (int i = 0; i < COUNT_ANALOG_INPUTS; i++) {
    pinMode(analogInputs[i].pin, INPUT);
  }
  
  for (int i = 0; i < COUNT_DIGITAL_INPUTS; i++) {
    // Pullup required. When pressed, buttons pull signal to ground.
    pinMode(digitalInputs[i].pin, INPUT_PULLUP);
  }
}

void loop() {
  int newValue = 0;
  for (int i = 0; i < COUNT_ANALOG_INPUTS; i++) {
    newValue = analogRead(analogInputs[i].pin);
    if (newValue != analogInputs[i].value) {
      analogInputs[i].value = newValue;
      Serial.print(analogInputs[i].name);
      Serial.print(": ");
      Serial.println(analogInputs[i].value);
    }
  }
  for (int i = 0; i < COUNT_DIGITAL_INPUTS; i++) {
    newValue = digitalRead(digitalInputs[i].pin);
    if (newValue != digitalInputs[i].value) {
      digitalInputs[i].value = newValue;
      Serial.print(digitalInputs[i].name);
      Serial.print(": ");
      Serial.println(digitalInputs[i].value);
    }
  }
  delay(100);
}

void defineAnalogInputs(){
  //Analog Inputs
  analogInputs[0].value = 0;
  analogInputs[0].pin = A8;
  analogInputs[0].name = String("Fader 1");

  analogInputs[1].value = 0;
  analogInputs[1].pin = A11;
  analogInputs[1].name = String("Fader 2");

  analogInputs[2].value = 0;
  analogInputs[2].pin = A10;
  analogInputs[2].name = String("Fader 3");

  analogInputs[3].value = 0;
  analogInputs[3].pin = A13;
  analogInputs[3].name = String("Fader 4");

  analogInputs[4].value = 0;
  analogInputs[4].pin = A15;
  analogInputs[4].name = String("Fader 5");

  analogInputs[5].value = 0;
  analogInputs[5].pin = A9;
  analogInputs[5].name = String("Fader 6");

  analogInputs[6].value = 0;
  analogInputs[6].pin = A14;
  analogInputs[6].name = String("Joystick X");

  analogInputs[7].value = 0;
  analogInputs[7].pin = A12;
  analogInputs[7].name = String("Joystick Y");
}

void defineDigitalInputs(){
  // Digital Inputs
  digitalInputs[0].value = 0;
  digitalInputs[0].pin = 32;
  digitalInputs[0].name = String("Joystick Button");

  digitalInputs[0].value = 0;
  digitalInputs[0].pin = 31;
  digitalInputs[0].name = String("Button 1");

  digitalInputs[0].value = 0;
  digitalInputs[0].pin = 33;
  digitalInputs[0].name = String("Button 2");

  digitalInputs[0].value = 0;
  digitalInputs[0].pin = 34;
  digitalInputs[0].name = String("Button 3");
}

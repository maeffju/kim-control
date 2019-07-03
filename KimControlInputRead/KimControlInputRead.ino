
#define FADER_OFFSET 69   // analog offset when fader is in zero-position

char fader1 = A8;
char fader2 = A11;
char fader3 = A10;
char fader4 = A13;
char fader5 = A15;
char fader6 = A9;
char joystickX = A14;
char joystickY = A12;
char joystickButton = 32;
char button1pin = 31;
char button2pin = 33;
char button3pin = 34;


int fader1A = 0;
int fader1APrev = 0;
int fader2A = 0;
int fader2APrev = 0;
int fader3A = 0;
int fader3APrev = 0;
int joystickXA = 0;
int joystickXAPrev = 0;
int button1 = 0;



void setup() {
  Serial.begin(9600);
  pinMode(fader1, INPUT);
  pinMode(fader2, INPUT);
  pinMode(fader3, INPUT);
  pinMode(fader4, INPUT);
  pinMode(fader5, INPUT);
  pinMode(fader6, INPUT);
  pinMode(joystickX, INPUT);
  pinMode(joystickY, INPUT);
  pinMode(joystickButton, INPUT_PULLUP);    // Pullup required. When pressed, buttons pull signal to ground.
  pinMode(button1pin, INPUT_PULLUP);
  pinMode(button2pin, INPUT_PULLUP);
  pinMode(button3pin, INPUT_PULLUP);
}

void loop() {
  // put your main code here, to run repeatedly:
  //joystickXA = analogRead(joystickX);
  //fader1A = analogRead(fader1);
  button1 = !digitalRead(button1pin);
  Serial.println(button1);
  delay(200);
}

int readFader(char faderNo){
  int ret = analogRead(faderNo);
}

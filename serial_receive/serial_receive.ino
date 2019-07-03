const char psuPin = 12;
const char loadPin = 8;
const String IDN = "Arduino Load Switch rev 1.0";

String inputString = "";
boolean commandReceived = false;

void switchPSU(int output){
  if(output == 0){
    digitalWrite(psuPin, LOW);
    Serial.println("OK PSU is off");
  }
  if(output == 1){
    digitalWrite(psuPin, HIGH);
    Serial.println("OK PSU is on");
  }
}

void switchLOAD(int output){
  if(output == 0){
    digitalWrite(loadPin, LOW);
    Serial.println("OK Load is off");
  }
  if(output == 1){
    digitalWrite(loadPin, HIGH);
    Serial.println("OK Load is on");
  }
  }


void setup() {
  Serial.begin(9600);
  pinMode(psuPin, OUTPUT);
  pinMode(loadPin, OUTPUT);
}

void loop() {
  if(commandReceived){     
    if (inputString == "SWITCH:PSU:ON")
      switchPSU(1);
    if (inputString == "SWITCH:PSU:OFF")
      switchPSU(0);
    if (inputString == "SWITCH:LOAD:ON")
      switchLOAD(1);
    if (inputString == "SWITCH:LOAD:OFF")
      switchLOAD(0);    
    if (inputString == "*IDN?")
      Serial.println(IDN);
  }
  commandReceived = false;
}

void serialEvent(){
  commandReceived = false;
  while(Serial.available()){
    //long startReceive=millis(); 
    inputString = Serial.readStringUntil('\n');
    inputString.trim(); //remove whitespace from the end
    inputString.toUpperCase(); // get upper-case version of the string
    //Serial.println("read duration: " + String((millis() - startReceive), DEC));
    commandReceived = true;
    }
  }

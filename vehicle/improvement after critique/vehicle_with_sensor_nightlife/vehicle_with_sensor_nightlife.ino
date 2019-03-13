/*
  AnalogReadSerial
  Reads an analog input on pin 0, prints the result to the serial monitor.
  Graphical representation is available using serial plotter (Tools > Serial Plotter menu)
  Attach the center pin of a potentiometer to pin A0, and the outside pins to +5V and ground.

  This example code is in the public domain.
*/

//Left Sensor
int trigPinL = 11;    // Trigger
int echoPinL = 12;    // Echo
long durationL, cmL, inchesL;

//Right Sensor
int trigPinR = 5;    // Trigger
int echoPinR = 4;    // Echo
long durationR, cmR, inchesR;

//Front Sensor
int trigPinF = 3;    // Trigger
int echoPinF = 2;    // Echo
long durationF, cmF, inchesF;

int RF = 9;
int RR = 6;
int LF = 8;
int LR = 7;

int  reverseState = 0;

unsigned long startMillis;  //some global variables available anywhere in the program
unsigned long currentMillis;
const unsigned long period = 2000;  //the value is a number of milliseconds

// the number of the pushbutton pin
//const int buttonPin = 13;
// variables will change:
//  int buttonState = 0;

// the setup routine runs once when you press reset:
void setup() {
  //PIN SWITCH ON 13
  //pinMode(buttonPin, INPUT);

  //PIN WHEEL ON HBRIGE
  pinMode(RF, OUTPUT); //HPIN1 right wheel
  pinMode(RR, OUTPUT); //HPIN2 right wheel

  pinMode(LF, OUTPUT); //HPIN3 left wheel
  pinMode(LR, OUTPUT); //HPIN4 left wheel

  //Serial Port begin
  Serial.begin (9600);
  //Define inputs and outputs
  pinMode(trigPinL, OUTPUT);
  pinMode(echoPinL, INPUT);

  pinMode(trigPinR, OUTPUT);
  pinMode(echoPinR, INPUT);

  pinMode(trigPinF, OUTPUT);
  pinMode(echoPinF, INPUT);

  startMillis = millis();  //initial start time
}


// the loop routine runs over and over again forever:
void loop() {

  ReadLsensor();
  ReadRsensor();
  ReadFsensor();

  // read the state of the pushbutton value:
  // buttonState = digitalRead(buttonPin);

  //use a button to turn on
  //if (buttonState == HIGH) {

  //nothing in front of vehicle
  if (inchesF > 6) {

    if (inchesL >= 6 && inchesR < 6) {
      Serial.println("R Triggered");
      Rturn();
    }

    if (inchesL < 6 && inchesR >= 6) {
      Serial.println("L Triggered");
      Lturn();
    }

    if (inchesL >= 6 && inchesR >= 6) {
      Serial.println("BOTH Triggered");
      Allforward();
    }

    if (inchesL <= 6 && inchesR <= 6) {
      Serial.println("NONE Triggered");
      Allforward();
    }
  } else {
    //something in front of vehicle
    //if (inchesF <= 6) {

    //Allreverse();


    if (inchesL >= 6 && inchesR < 6) {
      Serial.println("Blocked,R Triggered");
      Rturn();
    }

    if (inchesL < 6 && inchesR >= 6) {
      Serial.println("Blocked,L Triggered");
      Lturn();
    }

    if (inchesL >= 6 && inchesR >= 6) {
      Serial.println("Blocked,BOTH Triggered");
      Rturn();
    }

    if (inchesL <= 6 && inchesR <= 6) {
      Serial.println("Blocked,NONE Triggered");
      Allreverse();
    }
  }

  if (reverseState = 1) {
    currentMillis = millis();  //get the current "time" (actually the number of milliseconds since the program started)
    if (currentMillis - startMillis >= period) { //test whether the period has elapsed
      if (inchesL >= 6 && inchesR < 6) {
        Serial.println("Blocked,R Triggered");
        Rturn();
      }

      if (inchesL < 6 && inchesR >= 6) {
        Serial.println("Blocked,L Triggered");
        Lturn();
      }

      if (inchesL >= 6 && inchesR >= 6) {
        Serial.println("Blocked,BOTH Triggered");
        Rturn();
      }

      if (inchesL <= 6 && inchesR <= 6) {
        Serial.println("Blocked,NONE Triggered");
        Allreverse();
      }
      startMillis = currentMillis;  //IMPORTANT to save the start time of the current LED state.
    }
  }


} // Lo0p END ++++++++++++++++++++++++++++++++++++++++++++++++++





//sensoevaulue detection end
/*
  Rforward();
  delay(1000);
  Stop();
  delay(1000);
  Rreverse();
  delay(1000);
  Stop();
  delay(1000);
  Lforward();
  delay(1000);
  Stop();
  delay(1000);
  Lreverse();
  delay(1000);
  Stop();
  delay(1000);
  Allforward();
  delay(1000);
  Stop();
  delay(1000);
  Allreverse();
  delay(1000);
  Stop();
  delay(1000);
*/





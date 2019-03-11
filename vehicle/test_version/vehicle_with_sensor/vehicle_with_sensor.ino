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
int trigPinR = 3;    // Trigger
int echoPinR = 4;    // Echo
long durationR, cmR, inchesR;

// the setup routine runs once when you press reset:
void setup() {


  //PIN SWITCH ON 13
  pinMode(13, INPUT);

  //PIN WHEEL ON HBRIGE
  pinMode(9, OUTPUT); //HPIN1 right wheel
  pinMode(8, OUTPUT); //HPIN2 right wheel
  pinMode(7, OUTPUT); //HPIN3 left wheel
  pinMode(6, OUTPUT); //HPIN4 left wheel

  //Serial Port begin
  Serial.begin (9600);
  //Define inputs and outputs
  pinMode(trigPinL, OUTPUT);
  pinMode(echoPinL, INPUT);

  pinMode(trigPinR, OUTPUT);
  pinMode(echoPinR, INPUT);
}



// the loop routine runs over and over again forever:
void loop() {

  // The sensor is triggered by a HIGH pulse of 10 or more microseconds.
  // Give a short LOW pulse beforehand to ensure a clean HIGH pulse:
  digitalWrite(trigPinL, LOW);
  delayMicroseconds(5);
  digitalWrite(trigPinL, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPinL, LOW);

  // Read the signal from the sensor: a HIGH pulse whose
  // duration is the time (in microseconds) from the sending
  // of the ping to the reception of its echo off of an object.
  pinMode(echoPinL, INPUT);
  durationL = pulseIn(echoPinL, HIGH);

  // Convert the time into a distance
  cmL = (durationL / 2) / 29.1;   // Divide by 29.1 or multiply by 0.0343
  inchesL = (durationL / 2) / 74; // Divide by 74 or multiply by 0.0135

  Serial.print(inchesL);
  Serial.print("in, ");
  Serial.print(cmL);
  Serial.print("cm");
  Serial.println();

  delay(250);

  // The sensor is triggered by a HIGH pulse of 10 or more microseconds.
  // Give a short LOW pulse beforehand to ensure a clean HIGH pulse:
  digitalWrite(trigPinR, LOW);
  delayMicroseconds(5);
  digitalWrite(trigPinR, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPinR, LOW);

  // Read the signal from the sensor: a HIGH pulse whose
  // duration is the time (in microseconds) from the sending
  // of the ping to the reception of its echo off of an object.
  pinMode(echoPinR, INPUT);
  durationR = pulseIn(echoPinR, HIGH);

  // Convert the time into a distance
  cmR = (durationR / 2) / 29.1;   // Divide by 29.1 or multiply by 0.0343
  inchesR = (durationR / 2) / 74; // Divide by 74 or multiply by 0.0135

  Serial.print(inchesR);
  Serial.print("in, ");
  Serial.print(cmR);
  Serial.print("cm");
  Serial.println();

  delay(250);

  if (inchesL > 6 and inchesR > 6) {
    digitalWrite(8, HIGH); //HPIN1 R
    digitalWrite(7, LOW); //HPIN1 R
    digitalWrite(9, HIGH); //HPIN1 L
    digitalWrite(6, LOW); //HPIN1 L
  } else {

    if (inchesL < 6 and inchesR < 6) {
      digitalWrite(8, LOW); //HPIN1 R
      digitalWrite(7, LOW); //HPIN1 R
      digitalWrite(9, LOW); //HPIN1 L
      digitalWrite(6, LOW); //HPIN1 L
      
    } else {

      if (inchesL <= 6 and inchesR >= 6) {
        //if there is something on then it turn
        Serial.println("turn right ");


        digitalWrite(8, HIGH); //HPIN1 R
        digitalWrite(7, LOW); //HPIN1 R
        digitalWrite(9, LOW); //HPIN1 L
        digitalWrite(6, LOW); //HPIN1 L

      } else {

        if ( inchesR <= 6 and inchesL >= 6) {
          //press 8(right button) to go right
          Serial.println("turn left ");

          digitalWrite(8, LOW); //HPIN1 R
          digitalWrite(7, LOW); //HPIN1 R
          digitalWrite(9, HIGH); //HPIN1 L
          digitalWrite(6, LOW); //HPIN1 L
        }
      }
    }
  };
}

#include <Servo.h>

Servo myservo1;  // create servo object to control a servo
Servo myservo2;  // create servo object to control a servo

// for sensor status
int newArray[6];
int downArray[3];
int sensorStatus = 0;

int sensorPin = A0;
int sensorValue = 0;
int fadeValue = 0;
int scaleValue = 4;

//Smoothing: to find max and min and average value of sensor
int numReadings = 10;
int readings[10];
int index = 0;
int indexBegin = 0; //to set the begining point to calculate the max and min number of average

int sensorMax = 0;
int sensorMin = 0;

//for  output
int servoValue = 0;
int servoValueMax = 0;
int servoValueMin = 0;
int servoValueAve = 0;







void setup()
{

  Serial.begin(9600);

  //for smoothing, calculate the average, max and min value of sensor
  sensorMax = analogRead(A0);
  sensorMin = sensorMax;

  //pinMode(LED, OUTPUT);
  myservo1.attach(9);  // attaches the servo on pin 9 to the servo object
  myservo2.attach(10);  // attaches the servo on pin 9 to the servo object


}

void loop()
{

  //--------------------------------------------------------------------------------------------------------------------------------------------
  //Sensor Value Status

  // read the value from the sensor:
  sensorValue = analogRead(sensorPin);
  // divide it into a value from 0-255
  fadeValue = sensorValue / scaleValue;
  //write these values to Serial Window
  //Serial.write(fadeValue);
  //Serial.print("fadeValue - ");
  //Serial.println(fadeValue);

  // define status of senor
  downArray [2] = downArray [1];
  downArray [1] = downArray [0];

  newArray [5] = newArray [4];
  newArray [4] = newArray [3];
  newArray [3] = newArray [2];
  newArray [2] = newArray [1];
  newArray [1] = newArray [0];
  newArray [0] = fadeValue;
  if (((newArray [0] > newArray [2]) && (newArray[2] > newArray[4])) || ((newArray [1] > newArray [3]) && (newArray[3] > newArray[5])))
  {
    downArray [0] = 1;
    int sensorStatus = -1;
    //Serial.println("down");
  }
  if (((newArray [0] < newArray [2]) && (newArray[2] < newArray[4])) || ((newArray [1] < newArray [3]) && (newArray[3] < newArray[5])))
  {
    downArray [0] = 0;
    int sensorStatus = 1;
    //Serial.println("up");
  }
  if (((newArray [0] == newArray [2]) && (newArray[2] == newArray[4])) || ((newArray [1] == newArray [3]) && (newArray[3] == newArray[5])))
  {
    downArray [0] = 0;
    sensorStatus = 0;
    //Serial.println("hold");
  }
  else {
    // Serial.println(".");
  }



  //--------------------------------------------------------------------------------------------------------------------------------------------
  //Smoothing

  // MEASUREMENTS
  // every iteration of loop makes one additional measurement,
  // so the first 10 readings will display too low average
  int value = analogRead(A0);
  readings[index] = value;
  index++;
  indexBegin++;
  if (index >= numReadings) index = 0;

  // DO SOME MATH
  //if (value > sensorMax) sensorMax = value;
  //if (value < sensorMin) sensorMin = value;

  //running average
  float total = 0;
  for (int i = 0; i < numReadings; i++) total += readings[i];
  float average = total / numReadings;

  // DO SOME MATH after the 20th value from A0
  if (indexBegin > 20) {
    if (average > sensorMax) sensorMax = average;
    if (average < sensorMin) sensorMin = average;
  }
  // OUTPUT TO SERIAL
  //Serial.print("\tMIN:\t");
  //Serial.print(sensorMin);
  //Serial.print("\tMAX:\t");
  //Serial.print(sensorMax);
  //Serial.print("\tAVG:\t");
  //Serial.println(average, 1);  // 1 decimal




  //--------------------------------------------------------------------------------------------------------------------------------------------
  //write to servo

  //map average sensor value to servo degree
  servoValueMax = sensorMax;
  servoValueMin = sensorMin;

  servoValue = map(average, servoValueMax, servoValueMin, 0, 90);
  Serial.print("servoValue - ");
  Serial.println(servoValue);

  //write the degree to servo with sweep method
  if (sensorStatus != 0) {
    // if (sensorStatus > 0)
    //{
    for (servoValue; sensorStatus > 0; servoValue += 1) { // goes from 0 degrees to 180 degrees
      // in steps of 1 degree
      myservo1.write(servoValue);              // tell servo to go to position in variable 'pos'
      myservo2.write(servoValue);              // tell servo to go to position in variable 'pos'
      delay(15);                       // waits 15ms for the servo to reach the position
    }
    //  } else if (sensorStatus < 0)
    //{
    for (servoValue; sensorStatus < 0; servoValue -= 1) { // goes from 180 degrees to 0 degrees
      myservo1.write(servoValue);              // tell servo to go to position in variable 'pos'
      myservo2.write(servoValue);              // tell servo to go to position in variable 'pos'
      delay(15);                       // waits 15ms for the servo to reach the position
    }
    //}
  } else {
    myservo1.write(servoValue);
    myservo2.write(servoValue);              // tell servo to go to position in variable 'pos'
    delay(15);
  }



}

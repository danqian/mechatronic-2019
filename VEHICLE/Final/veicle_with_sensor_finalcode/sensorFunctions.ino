void ReadLsensor() {

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
  //Serial.print("Raw sensor L data: ");
  //Serial.print(durationL);
  //Serial.print("\t");

  // Convert the time into a distance
  cmL = (durationL / 2) / 29.1;   // Divide by 29.1 or multiply by 0.0343
  inchesL = (durationL / 2) / 74; // Divide by 74 or multiply by 0.0135

  //Serial.print(inchesR);
  //Serial.println(" in, ");
  // Serial.print(cmR);
  //Serial.print("cm");
  //delay(250);
}

void ReadRsensor() {

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
  //Serial.print("Raw sensor R data: ");
  //Serial.print(durationR);
  //Serial.print("\t");

  // Convert the time into a distance
  cmR = (durationR / 2) / 29.1;   // Divide by 29.1 or multiply by 0.0343
  inchesR = (durationR / 2) / 74; // Divide by 74 or multiply by 0.0135

  //Serial.print(inchesR);
  //Serial.println(" in, ");
  // Serial.print(cmR);
  //Serial.print("cm");
  //delay(250);
}

void ReadFsensor() {

  // The sensor is triggered by a HIGH pulse of 10 or more microseconds.
  // Give a short LOW pulse beforehand to ensure a clean HIGH pulse:
  digitalWrite(trigPinF, LOW);
  delayMicroseconds(5);
  digitalWrite(trigPinF, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPinF, LOW);

  // Read the signal from the sensor: a HIGH pulse whose
  // duration is the time (in microseconds) from the sending
  // of the ping to the reception of its echo off of an object.
  pinMode(echoPinF, INPUT);
  durationF = pulseIn(echoPinF, HIGH);
  //Serial.print("Raw sensor F data: ");
  //Serial.print(durationF);
  //Serial.print("\t");

  // Convert the time into a distance
  cmF = (durationF / 2) / 29.1;   // Divide by 29.1 or multiply by 0.0343
  inchesF = (durationF / 2) / 74; // Divide by 74 or multiply by 0.0135

  //Serial.print(inchesR);
  //  Serial.println(" in, ");
  // Serial.print(cmF);
  //Serial.print("cm");
  //delay(250);
}


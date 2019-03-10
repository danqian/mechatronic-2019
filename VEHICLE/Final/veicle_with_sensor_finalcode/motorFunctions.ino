void Stop(){
    digitalWrite(RF, LOW);
    digitalWrite(RR, LOW);
    digitalWrite(LF, LOW);
    digitalWrite(LR, LOW);
    //Serial.print("STOP");
}

void Rforward(){
    digitalWrite(RF, HIGH);
    digitalWrite(RR, LOW);
    digitalWrite(LF, LOW);
    digitalWrite(LR, LOW);
}

void Rreverse(){
    digitalWrite(RF, LOW);
    digitalWrite(RR, HIGH);
    digitalWrite(LF, LOW);
    digitalWrite(LR, LOW);
}

void Lforward(){
    digitalWrite(RF, LOW);
    digitalWrite(RR, LOW);
    digitalWrite(LF, HIGH);
    digitalWrite(LR, LOW);
}

void Lreverse(){
    digitalWrite(RF, LOW);
    digitalWrite(RR, LOW);
    digitalWrite(LF, LOW);
    digitalWrite(LR, HIGH);
}

void Allforward(){
    digitalWrite(RF, HIGH);
    digitalWrite(RR, LOW);
    digitalWrite(LF, HIGH);
    digitalWrite(LR, LOW);
}

void Allreverse(){
    digitalWrite(RF, LOW);
    digitalWrite(RR, HIGH);
    digitalWrite(LF, LOW);
    digitalWrite(LR, HIGH);
}

void Rturn(){
    digitalWrite(RF, HIGH);
    digitalWrite(RR, LOW);
    digitalWrite(LF, LOW);
    digitalWrite(LR, HIGH);
}

void Lturn(){
    digitalWrite(RF, LOW);
    digitalWrite(RR, HIGH);
    digitalWrite(LF, HIGH);
    digitalWrite(LR, LOW);
}


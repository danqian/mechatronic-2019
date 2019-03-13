void Stop(){
    digitalWrite(RF, LOW);
    digitalWrite(RR, LOW);
    digitalWrite(LF, LOW);
    digitalWrite(LR, LOW);
    reverseState = 0;
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
    reverseState = 0;

}

void Allreverse(){
    digitalWrite(RF, LOW);
    digitalWrite(RR, HIGH);
    digitalWrite(LF, LOW);
    digitalWrite(LR, HIGH);
    reverseState = 1;

}

void Rturn(){
    digitalWrite(RF, HIGH);
    digitalWrite(RR, LOW);
    digitalWrite(LF, LOW);
    digitalWrite(LR, HIGH);
    reverseState = 0;

}

void Lturn(){
    digitalWrite(RF, LOW);
    digitalWrite(RR, HIGH);
    digitalWrite(LF, HIGH);
    digitalWrite(LR, LOW);
    reverseState = 0;

}


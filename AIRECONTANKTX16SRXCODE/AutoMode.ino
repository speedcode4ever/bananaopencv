void AutoMode() {
//Serial.print("F: ");
//Serial.print(FSense());
//Serial.print(" B: ");
//Serial.print(BSense());
//Serial.print(" BL: ");
//Serial.print(BLSense());
//Serial.print(" BR: ");
//Serial.print(BRSense());
//Serial.print(" FL: ");
//Serial.print(FLSense());
//Serial.print(" FR: ");
//Serial.print(FRSense());
//Serial.println();
if (Serial.available() > 0) {
  data = Serial.readStringUntil('\n');
}
if (data.equals("On target")) {
    Ontarget();
  }
else if (data.equals("Stop x")) {
    Stop();
  }
else if (data.equals("move right")) {
    RotateRightAuto();
  }
else if (data.equals("move left")) {
    RotateLeftAuto();
  }
else if (data.equals("Stop y")) {
    stopy();
  }
else if (data.equals("move up")) {
    moveup();
  }
else if (data.equals("move down")) {
    movedown();
  }
else if (data.equals("found nothing")) {
    foundnothing();
  }
//Serial.print("F: ");
//Serial.print(FdistanceIncm);
//Serial.print(" B: ");
//Serial.print(BdistanceIncm);
//Serial.print(" BL: ");
//Serial.print(BLdistanceIncm);
//Serial.print(" BR: ");
//Serial.print(BRdistanceIncm);
//Serial.print(" FL: ");
//Serial.print(FLdistanceIncm);
//Serial.print(" FR: ");
//Serial.print(FRdistanceIncm);
//Serial.println();
}
void FcheckDistance(){
  digitalWrite(FtrigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(FtrigPin, HIGH);
  delayMicroseconds(4);
  digitalWrite(FtrigPin, LOW);
  pinMode(FechoPin, INPUT);
  Fduration = pulseIn(FechoPin, HIGH);
  FdistanceIncm = (Fduration / 2) * 0.034895;
}
void BcheckDistance(){
  digitalWrite(BtrigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(BtrigPin, HIGH);
  delayMicroseconds(4);
  digitalWrite(BtrigPin, LOW);
  pinMode(BechoPin, INPUT);
  Bduration = pulseIn(BechoPin, HIGH);
  BdistanceIncm = (Bduration / 2) * 0.034895;
}
void BLcheckDistance(){
  digitalWrite(BLtrigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(BLtrigPin, HIGH);
  delayMicroseconds(4);
  digitalWrite(BLtrigPin, LOW);
  pinMode(BLechoPin, INPUT);
  BLduration = pulseIn(BLechoPin, HIGH);
  BLdistanceIncm = (BLduration / 2) * 0.034895;
}
void BRcheckDistance(){
  digitalWrite(BRtrigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(BRtrigPin, HIGH);
  delayMicroseconds(4);
  digitalWrite(BRtrigPin, LOW);
  pinMode(BRechoPin, INPUT);
  BRduration = pulseIn(BRechoPin, HIGH);
  BRdistanceIncm = (BRduration / 2) * 0.034895;
}
void FLcheckDistance(){
  digitalWrite(FLtrigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(FLtrigPin, HIGH);
  delayMicroseconds(4);
  digitalWrite(FLtrigPin, LOW);
  pinMode(FLechoPin, INPUT);
  FLduration = pulseIn(FLechoPin, HIGH);
  FLdistanceIncm = (FLduration / 2) * 0.034895;
}
void FRcheckDistance(){
  digitalWrite(FRtrigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(FRtrigPin, HIGH);
  delayMicroseconds(4);
  digitalWrite(FRtrigPin, LOW);
  pinMode(FRechoPin, INPUT);
  FRduration = pulseIn(FRechoPin, HIGH);
  FRdistanceIncm = (FRduration / 2) * 0.034895;
}

boolean FRSense(){
   FRcheckDistance();
   if (FRdistanceIncm <= 15.00) {
        return true;
   }
   else {
        return false;
    }
}
boolean BRSense(){
   BRcheckDistance();
   if (BRdistanceIncm <= 15.00) {
        return true;
   }
   else {
        return false;
    }
}
boolean FLSense(){
   FLcheckDistance();
   if (FLdistanceIncm <= 15.00) {
        return true;
   }
   else {
        return false;
    }
}
boolean BLSense(){
   BLcheckDistance();
   if (BLdistanceIncm <= 15.00) {
        return true;
   }
    else {
        return false;
    }
}
boolean FSense(){
   FcheckDistance();
   if (FdistanceIncm <= 15.00) {
        return true;
   }
   else {
        return false;
    }
}
boolean BSense(){
   BcheckDistance();
   if (BdistanceIncm <= 15.00) {
        return true;
   }
   else {
        return false;
    }
}
void moveup() {
  if (val < 180) {
      val = val + 1;
      myservo.write(val);
    }
  }
void movedown() {
  if (val > 0) {
      val = val - 1;
      myservo.write(val);
    }
  }
void stopy() {
  myservo.write(val);
  }
void Ontarget() {
    //FcheckDistance();
    //calculateangles();
    //if (val >= 90) {
   // distancefromrobot = FdistanceIncm * cos(radianang);
    //}
    //else if (val < 90) {
     // distancefromrobot = FdistanceIncm * sin((3.14/2) - (-1 * (radianang)));  
      //}
    if (val > 10) {
      ForwardAuto();
      }
    else if (val <= 10) {
      Stop();
      PickPlace();
      normalpos();
      }
  }
//void calculateangles() {
    //degreeang = map(val,0,180,-45,30);
    //radianang = degreeang * (3.14/180);
  //}

void foundnothing() {
  randal = random(1,3);
    if (randal == 1) {
    RotateLeftAuto();
    delay(2000);
    obstacleavoid();
    }
    else if (randal == 2) {
    RotateRightAuto();
    delay(2000);
    obstacleavoid();
    }
  ForwardAuto();
  obstacleavoid();
  }

void obstacleavoid() {
  if (FSense()) {
    BackwardAuto();
    }
  if (BSense()) {
    ForwardAuto();
    }
  if (FLSense()) {
    RotateRightAuto();
    }
  if (FRSense()) {
    RotateLeftAuto();
    }
  if (BLSense()) {
    RotateLeftAuto();
    }
  if (BRSense()) {
    RotateRightAuto();
    }
}

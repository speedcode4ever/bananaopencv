void DriveMode() {
  ch1 = pulseIn(10, HIGH);
  ch2 = pulseIn(9, HIGH);
  ms1();
  ms2();
  xcord = map(ch1, 983, 2001, -255, 255);
  ycord = map(ch2, 983, 2001, -255, 255);  
  if (xcord <= 11 && xcord >= -11) {
    xcord = 0;
    }
  if (ycord <= 7 && ycord >= -7) {
    ycord = 0;
    }
  if ((xcord != 0 && ycord!= 0)) {
    radang = atan(ycord/xcord);
    degang = radang*57296/1000; 
  }  
  if ((xcord > 0 && xcord <= 260) && (ycord > 0 && ycord <= 260)) {
      ForwardRight();
    }
  else if ((xcord < 0 && xcord >= -260) && (ycord > 0 && ycord <= 260)) {
      ForwardLeft();
    }
  else if ((xcord < 0 && xcord >= -260) && (ycord < 0 && ycord >= -260)) {
      BackwardLeft();
    }
  else if ((xcord > 0 && xcord <= 260) && (ycord < 0 && ycord >= -260)) {
      BackwardRight();
    }
  else {
   if (ycord > 0 && xcord == 0) {
        Forward();
      }
   if (ycord < 0 && xcord == 0) {
        Backward();
      }
   if (ycord == 0 && xcord > 0) {
        RotateRight();
      }
   if (ycord == 0 && xcord < 0) {
        RotateLeft();
      }
    if (xcord == 0 && ycord == 0) {
        Stop();
    } 
  }
//Serial.print("L: ");
//Serial.print(lefttrack);
//Serial.print(" R: ");
//Serial.println(righttrack);  
}

void ForwardRight() {
    if (degang < 45 && degang > 0) {
      lefttrack = xcord;
      righttrack = degang/90 * xcord;
      }
    else if (degang >= 45 && degang < 90) {
      lefttrack = ycord;
      righttrack = degang/90 * ycord;    
      }
    analogWrite(enA, lefttrack);
    analogWrite(enB, righttrack);
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
    digitalWrite(in3, LOW);
    digitalWrite(in4, HIGH); 
  }
void ForwardLeft() {
    degang = 180 + degang;
    if (degang < 135 && degang > 90) {
      lefttrack = (180 - degang)/90 * ycord;
      righttrack = ycord;
      }
    else if (degang >= 135 && degang < 180) {
      lefttrack = -1 * (180 - degang)/90 * xcord;
      righttrack = -1 * xcord;    
      }
    analogWrite(enA, lefttrack);
    analogWrite(enB, righttrack);
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
    digitalWrite(in3, LOW);
    digitalWrite(in4, HIGH);
  }
void Forward() {
    lefttrack = ycord;
    righttrack = ycord;
    analogWrite(enA, lefttrack);
    analogWrite(enB, righttrack);
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
    digitalWrite(in3, LOW);
    digitalWrite(in4, HIGH);
  }
void Backward() {
    lefttrack = -1 * ycord;
    righttrack = -1 * ycord;
    analogWrite(enA, lefttrack);
    analogWrite(enB, righttrack);
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);
  }
void BackwardRight() {
    degang = 360 + degang;
    if (degang < 315 && degang > 270) {
      lefttrack = -1 * ycord;
      righttrack = -1 * (360 - degang)/90 * ycord;
      }
    else if (degang >= 315 && degang < 360) {
      lefttrack = xcord;
      righttrack = (360 - degang)/90 * xcord;    
      }
    analogWrite(enA, lefttrack);
    analogWrite(enB, righttrack);
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);
  }
void BackwardLeft() {
    degang = 180 + degang;
    if (degang < 225 && degang > 180) {
      lefttrack = -1 * (degang - 180)/90 * xcord;
      righttrack = -1 * xcord;
      }
    else if (degang >= 225 && degang < 270) {
      lefttrack = (180 - degang)/90 * ycord;
      righttrack = -1 * ycord;    
      }
    analogWrite(enA, lefttrack);
    analogWrite(enB, righttrack);
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);
  }
void RotateRight() {
    lefttrack = xcord;
    righttrack = xcord;
    analogWrite(enA, lefttrack);
    analogWrite(enB, righttrack);
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    digitalWrite(in3, LOW);
    digitalWrite(in4, HIGH);
  }
void RotateLeft() {
    lefttrack = -1 * xcord;
    righttrack = -1 * xcord;
    analogWrite(enA, lefttrack);
    analogWrite(enB, righttrack);
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);
  }
void Stop() {
    lefttrack = 0;
    righttrack = 0;
    analogWrite(enA, lefttrack);
    analogWrite(enB, righttrack);
  }
void ForwardAutoSlow() {
    lefttrack = 110;
    righttrack = 110;
    analogWrite(enA, lefttrack);
    analogWrite(enB, righttrack);
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
    digitalWrite(in3, LOW);
    digitalWrite(in4, HIGH);
  }
void ForwardAuto() {
    lefttrack = 125;
    righttrack = 125;
    analogWrite(enA, lefttrack);
    analogWrite(enB, righttrack);
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
    digitalWrite(in3, LOW);
    digitalWrite(in4, HIGH);
  }
void BackwardAuto() {
    lefttrack = -1 * -160;
    righttrack = -1 * -160;
    analogWrite(enA, lefttrack);
    analogWrite(enB, righttrack);
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);
  }
void RotateRightAuto() {
    lefttrack = 160;
    righttrack = 160;
    analogWrite(enA, lefttrack);
    analogWrite(enB, righttrack);
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    digitalWrite(in3, LOW);
    digitalWrite(in4, HIGH);
  }
void RotateLeftAuto() {
    lefttrack = -1 * -160;
    righttrack = -1 * -160;
    analogWrite(enA, lefttrack);
    analogWrite(enB, righttrack);
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);
  }
void TurnLeftAuto() {
    lefttrack = 1 * -110;
    righttrack = -1 * -160;
    analogWrite(enA, lefttrack);
    analogWrite(enB, righttrack);
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);
  }
void TurnRightAuto() {
    lefttrack = -1 * -160;
    righttrack = 1 * -110;
    analogWrite(enA, lefttrack);
    analogWrite(enB, righttrack);
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);
  }

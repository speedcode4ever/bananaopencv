void ArmandBucketMode() {
  ch1 = pulseIn(10, HIGH);
  ch2 = pulseIn(9, HIGH);
  ch3 = pulseIn(31, HIGH);
  ch4 = pulseIn(33, HIGH);
  ch5 = pulseIn(35, HIGH);
  ch6 = pulseIn(37, HIGH);
  //Serial.print("ch1: ");
  //Serial.println(ch1);
  //Serial.print("ch2: ");
  //Serial.println(ch2);
  //Serial.print("ch3: ");
  //Serial.println(ch3);
  //Serial.print("ch4: ");
  //Serial.println(ch4);
  //Serial.print("ch5: ");
  //Serial.println(ch5);
  //Serial.print("ch6: ");
  //Serial.println(ch6);
  ms3();
  ms5();
  ms6();
  //ch7 = pulseIn(39, HIGH);
  id3pos = map(ch5, 985, 1990, 870, 140);
  myArm.setPosition(3, id3pos, 300, false);
  id4pos = map(ch6, 985, 1990, 120, 880);
  myArm.setPosition(4, id4pos, 300, false);
  id5pos = map(ch3, 985, 1990, 880, 125);
  myArm.setPosition(5, id5pos, 300, false);
  if (ch4 < 1300) {
  id6pos = id6pos + 25;
  myArm.setPosition(6, id6pos, 100, false);
  }
  else if (ch4 >  1650) {
  id6pos = id6pos - 25;
  myArm.setPosition(6, id6pos, 100, false);
  }
  if (ch1 >  1650) {
  id2pos = id2pos + 25;
  myArm.setPosition(2, id2pos, 100, false);
  }
  else if (ch1 < 1300) {
  id2pos = id2pos - 25;
  myArm.setPosition(2, id2pos, 100, false);
  } 
  if (ch2 >  1650) {
  id1pos = id1pos + 25;
  myArm.setPosition(1, id1pos, 100, false);
  }
  else if (ch2 < 1300) {
  id1pos = id1pos - 25;
  myArm.setPosition(1, id1pos, 100, false);
  } 
  Serial.print("id1pos: ");
  Serial.println(id1pos);
  Serial.print("id2pos: ");
  Serial.println(id2pos);
  Serial.print("id3pos: ");
  Serial.println(id3pos);
  Serial.print("id4pos: ");
  Serial.println(id4pos);
  Serial.print("id5pos: ");
  Serial.println(id5pos);
  Serial.print("id6pos: ");
  Serial.println(id6pos);
}
void PickPlace() {
   myArm.setPosition(2, 120, 1000, true);
   myArm.setPosition(1, 120, 1000, true);
   myArm.setPosition(3, 351, 1000, true);
   myArm.setPosition(4, 807, 1000, true);
   myArm.setPosition(5, 251, 1000, true);
   myArm.setPosition(6, 495, 1000, true);
   delay(1000);
   myArm.setPosition(1, 595, 1000, true);
   delay(1000);
   myArm.setPosition(3, 765, 1000, true);
   myArm.setPosition(4, 277, 1000, true);
   myArm.setPosition(5, 516, 1000, true);
   myArm.setPosition(6, 495, 1000, true);
   myArm.setPosition(2, 95, 1000, true);
   myArm.setPosition(1, 595, 1000, true);
   delay(1000);
   myArm.setPosition(1, 120, 1000, true);
   delay(1000);
  //id1pos: 595.00
  //id2pos: 495.00
  //id3pos: 212.00
  //id4pos: 663.00
  //id5pos: 213.00
  //id6pos: 495.00
  }
void normalpos() {
   myArm.setPosition(2, 495, 1000, true);
   myArm.setPosition(3, 136, 1000, true);
   myArm.setPosition(4, 886, 1000, true);
   myArm.setPosition(5, 723, 1000, true);
   myArm.setPosition(6, 495, 1000, true);
   myArm.setPosition(1, 495, 1000, true);
  }

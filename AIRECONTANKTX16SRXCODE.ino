#include <Servo.h>
#include <xArmServoController.h>
int FtrigPin = 44;
int FechoPin = 45;
long Fduration;
float FdistanceIncm;
int BtrigPin = 24;
int BechoPin = 25;
long Bduration;
float BdistanceIncm;
int BLtrigPin = 22;
int BLechoPin = 23;
long BLduration;
float BLdistanceIncm;
int BRtrigPin = 26;
int BRechoPin = 27;
long BRduration;
float BRdistanceIncm;
int FLtrigPin = 42;
int FLechoPin = 43;
long FLduration;
float FLdistanceIncm;
int FRtrigPin = 28;
int FRechoPin = 29;
long FRduration;
float FRdistanceIncm;
int enA = 2;
int in1 = 6;
int in2 = 7;
int enB = 5;
int in3 = 3;
int in4 = 4;
float ch1;
float ch2;
int lefttrack;
int righttrack;
double degang;
double ycord;
double xcord;
double radang;
float ch3;
float ch4;
float ch5;
float ch6;
float ch7;
int ch8;
float id1pos;
float id2pos;
float id3pos;
float id4pos;
float id5pos;
float id6pos;
float val = 90;
String data;
Servo myservo;
int rand1;
xArmServoController myArm = xArmServoController(xArm, Serial1);
void setup() {
  Serial1.begin(9600);
  pinMode(31, INPUT);
  pinMode(33, INPUT);
  pinMode(35, INPUT);
  pinMode(37, INPUT);
  pinMode(39, INPUT);
  pinMode(41, INPUT);
  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  pinMode(10, INPUT);
  pinMode(9, INPUT);
  pinMode(FtrigPin,OUTPUT);
  pinMode(FechoPin,INPUT);
  pinMode(BtrigPin,OUTPUT);
  pinMode(BechoPin,INPUT);
  pinMode(BLtrigPin,OUTPUT);
  pinMode(BLechoPin,INPUT);
  pinMode(BRtrigPin,OUTPUT);
  pinMode(BRechoPin,INPUT);
  pinMode(FLtrigPin,OUTPUT);
  pinMode(FLechoPin,INPUT);
  pinMode(FRtrigPin,OUTPUT);
  pinMode(FRechoPin,INPUT);
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
  id6pos = 495;
  id2pos = 495;
  id1pos = 495;
  Serial.begin(9600);
  myservo.attach(49);
}
void loop() {
  ch8 = pulseIn(41, HIGH);
  if (ch8 >= 1995 && ch8 <= 2005) {
    DriveMode();
    }
  else if (ch8 >= 1480 && ch8 <= 1500) {
    ArmandBucketMode();
    }
  else if (ch8 >= 975 && ch8 <= 990) {
    AutoMode();
    }
}

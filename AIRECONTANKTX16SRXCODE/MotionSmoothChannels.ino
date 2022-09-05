float smch1;
float smch2;
float smch3;
float smch4;
float smch5;
float smch6;
float smch7;
float prch1 = 1496;
float prch2 = 1495;
float prch3 = 1221;
float prch4 = 1468;
float prch5 = 1965;
float prch6 = 1958;
float prch7;
void ms1() {
  smch1 = (ch1 * 0.15) + (prch1 * 0.85);
  prch1 = smch1;
  ch1 = smch1;
  }
void ms2() {
  smch2 = (ch2 * 0.15) + (prch2 * 0.85);
  prch2 = smch2;
  ch2 = smch2;
  }
void ms3() {
  smch3 = (ch3 * 0.25) + (prch3 * 0.75);
  prch3 = smch3;
  ch3 = smch3; 
  }
void ms4() {
  smch4 = (ch4 * 0.15) + (prch4 * 0.85);
  prch4 = smch4;
  ch4 = smch4;   
  }
void ms5() {
  smch5 = (ch5 * 0.25) + (prch5 * 0.75);
  prch5 = smch5;
  ch5 = smch5;   
  }
void ms6() {
  smch6 = (ch6 * 0.25) + (prch6 * 0.75);
  prch6 = smch6;
  ch6 = smch6;  
  }
void ms7() {
  smch7 = (ch7 * 0.15) + (prch7 * 0.85);
  prch7 = smch7;
  ch7 = smch7;  
  }

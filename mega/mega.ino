#include <Servo.h>

Servo Servo1;
Servo Servo2;


#define RLED 32
#define GLED 30
#define YLED 28
#define WLED 26


#define SA1  A11
#define SA2  A8
#define SA3  A5
#define SA4  A2

#define SB1  A9
#define SB2  A6
#define SB3  A3
#define SB4  A0

#define SC1  A10
#define SC2  A7
#define SC3  A4
#define SC4  A1


#define wLED 26


int b = 0;


String s1;
String s2;
String s3;
String s4;
String s5;
String s6;
String s7;
String s8;
String s9;
String sa;
String sb;
String sc;

String control;
String fence;
String danger;


String ConAp;
String ConAr;
String ConCo;

bool bog;

int ServoStart = 0;
int ServoEnd = 180;


void setup() {

  Servo1.attach(44);
  Servo2.attach(45);
  
  Serial.begin(9600);//컴
  Serial1.begin(9600);//esp-01
  /*
  pinMode(RLED,OUTPUT);
  pinMode(GLED,OUTPUT);
  pinMode(YLED,OUTPUT);
  */
  pinMode(wLED,OUTPUT);
  
}

void loop() {
  String s = "";

  s1 = String(analogRead(SA1));
  s2 = String(analogRead(SA2));
  s3 = String(analogRead(SA3));
  s4 = String(analogRead(SA4));
  
  s5 = String(analogRead(SB1));
  s6 = String(analogRead(SB2));
  s7 = String(analogRead(SB3));
  s8 = String(analogRead(SB4));
  
  s9 = String(analogRead(SC1));
  sa = String(analogRead(SC2));
  sb = String(analogRead(SC3));
  sc = String(analogRead(SC4));

  s = s1+"."+s2+"."+s3+"."+s4+"."+s5+"."+s6+"."+s7+"."+s8+"."+s9+"."+sa+"."+sb+"."+sc;

  
  
  Serial1.println(s);
  Serial.println(s);
  Serial.println("??");

/*

  if()
*/

  if(bog){
    Servo1.write(ServoEnd);
    Servo2.write(ServoEnd);
  }
  else{
    Servo1.write(ServoStart);
    Servo2.write(ServoStart);
  }


  /*
  digitalWrite(wLED, HIGH);
  delay(300);
  digitalWrite(wLED, LOW);
  
  */
  delay(3000);
}

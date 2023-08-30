#include <Servo.h>

Servo SerL;  // create a servo object
Servo SerR;


int amount = 70;
int a = 0;

void setup() {
  SerL.attach(9); // attaches the servo on pin 9 to the servo object
  SerR.attach(10);
  
  Serial.begin(9600); // open a serial connection to your computer
  SerR.write(170);
  SerL.write(170);
}
char c;
bool s = 0;
int i;

void loop() {
  c = '0';
  if(Serial.available()){
    c = Serial.read();
    if(c=='U' && s == 0){
      Serial.println("U");
      s = 1;
      for(i=0; i<amount; i++){
        SerR.write(170-i);
        SerL.write(170-i);
        delay(20);
      }
    }
    if(c=='D' && s == 1){
      Serial.println("D");
      s = 0;
      for(i=amount; i>0; i--){
        SerR.write(170-i);
        SerL.write(170-i);
        delay(20);
      }
    }
  }
}

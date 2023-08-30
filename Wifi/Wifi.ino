#include "FirebaseESP8266.h" 
#include <ESP8266WiFi.h>
 
#define WIFI_SSID "Vars (2)"
#define WIFI_PASSWORD "!@#!@#!@#"

#define FIREBASE_HOST "team-imbed-arduino-test.firebaseio.com"
#define FIREBASE_AUTH "5qNw9w6IbXLss4mPltKQNoHHeBd7oUVFhqgv7wYm"


 
FirebaseData firebaseData;
FirebaseJson json;
 
void printResult(FirebaseData &data);
void setup() // wifi 접속 과정.
{
  Serial.begin(9600);
 
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
  }
 
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
  Firebase.reconnectWiFi(true);
 
  firebaseData.setBSSLBufferSize(1024, 1024);
  firebaseData.setResponseSize(1024);
  Firebase.setReadTimeout(firebaseData, 1000 * 60);
  Firebase.setwriteSizeLimit(firebaseData, "tiny");
  Serial.println("start");
}

void loop()
{
  if(Serial.available()){
    delay(20);
    String s = Serial.readString();
    //String s = "0.0.0.0.0.0.0.0.0.0.0.0";
    //Serial.println("hi");

    
    int s1 = s.indexOf('.');
    int s2 = s.indexOf('.',s1+1);
    int s3 = s.indexOf('.',s2+1);
    int s4 = s.indexOf('.',s3+1);
    int s5 = s.indexOf('.',s4+1);
    int s6 = s.indexOf('.',s5+1);
    int s7 = s.indexOf('.',s6+1);
    int s8 = s.indexOf('.',s7+1);
    int s9 = s.indexOf('.',s8+1);
    int sa = s.indexOf('.',s9+1);
    int sb = s.indexOf('.',sa+1);
    int sc = s.length();

    Serial.println(s1);
    Serial.println(s2);
    Serial.println(s3);
    Serial.println(s4);
    Serial.println(s5);
    Serial.println(s6);
    Serial.println(s7);
    Serial.println(s8);
    Serial.println(s9);
    Serial.println(sa);
    Serial.println(sb);
    Serial.println(sc);
    Serial.println(s.lastIndexOf('.'));

    
    if(sb == s.lastIndexOf('.')){
      Serial.println("wow");
      Firebase.setInt(firebaseData, "realtime/A1", s.substring(0,s1-1).toInt());
      Firebase.setInt(firebaseData, "realtime/A2", s.substring(s1+1,s2-1).toInt());
      Firebase.setInt(firebaseData, "realtime/A3", s.substring(s2+1,s3-1).toInt());
      Firebase.setInt(firebaseData, "realtime/A4", s.substring(s3+1,s4-1).toInt());
      
      Firebase.setInt(firebaseData, "realtime/B1", s.substring(s4+1,s5-1).toInt());
      Firebase.setInt(firebaseData, "realtime/B2", s.substring(s5+1,s6-1).toInt());
      Firebase.setInt(firebaseData, "realtime/B3", s.substring(s6+1,s7-1).toInt());
      Firebase.setInt(firebaseData, "realtime/B4", s.substring(s7+1,s8-1).toInt());
      
      Firebase.setInt(firebaseData, "realtime/C1", s.substring(s8+1,s9-1).toInt());
      Firebase.setInt(firebaseData, "realtime/C2", s.substring(s9+1,sa-1).toInt());
      Firebase.setInt(firebaseData, "realtime/C3", s.substring(sa+1,sb-1).toInt());
      Firebase.setInt(firebaseData, "realtime/C4", s.substring(sb+1,sc-1).toInt());
    }
    
      
  }
  
  String a = "";
  String Rcon;  
  String Rfen;
  String Rdan;
  String Rsta;
  
  if(Firebase.getString(firebaseData, "remote/control")){
  Rcon = firebaseData.stringData();
  }
  if(Firebase.getString(firebaseData, "remote/fence")){
  Rfen = firebaseData.stringData();
  }
  if(Firebase.getString(firebaseData, "result/danger")){
  Rdan = firebaseData.stringData();
  }
  if(Firebase.getString(firebaseData, "result/state")){
  Rsta = firebaseData.stringData();
  }

  a = Rcon+"."+Rfen+"."+Rdan+"."+Rsta;
  
  Serial.println(a);

  
  //Firebase.setBool(firebaseData, "BoolData", /*Bool Data*/);
  //Firebase.setInt(firebaseData, "Brightness", analogRead(pinCDS));
  //Firebase.setFloat(firebaseData, "FloatData", /*Float Data*/);
  //Firebase.setString(firebaseData, "StringData", /*String Data*/);반복
  
  
}

/*
  
  
 if(Firebase.getBool(firebaseData,"LED1")) {
  bool valLED1 = firebaseData.boolData();
  digitalWrite(pinLED1, valLED1);
 } 

 if(Firebase.getBool(firebaseData, "LED2")) {
  bool valLED2 = firebaseData.boolData();
  digitalWrite(pinLED2, valLED2);
 } 
 */
/* if(Firebase.getInt(firebaseData, "Int Data Tag")){
  int valInt = firebaseData.intData();
  // write Code...
 }
 if(Firebase.getFloat(firebaseData, "Float Data Tag")){
  float valFloat = firebaseData.floatData();
  // write Code...
 }
 if(Firebase.getString(firebaseData, "String Data Tag")){
  String valStr = firebaseData.stringData();
  // write Code...
 }*/

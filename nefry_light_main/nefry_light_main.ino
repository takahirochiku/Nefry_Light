#include <Time.h>
#include <TimeLib.h>

#include <Nefry.h>
#include <NefryIFTTT.h>
String Event, SecretKey;


int sensorValueNow;
int sensorValueBefore = 0;

void setup() {
  Nefry.setStoreTitle("SecretKey",0); //Nefry DataStoreのタイトルを指定
  Nefry.setStoreTitle("Event",1);     //Nefry DataStoreのタイトルを指定
  SecretKey = Nefry.getStoreStr(0);   //Nefry DataStoreからデータを取得
  Event = Nefry.getStoreStr(1);       //Nefry DataStoreからデータを取得
  
  Nefry.println("Grove Light sensor SETUP");
  
  Nefry.setLed(0,0,0);
  pinMode(A2,INPUT_PULLUP);//入力モード切り替え
}

void loop() {
  sensorValueNow = analogRead(A2);
  
  Nefry.print("sensorValueBefore=");
  Nefry.println(sensorValueBefore);
  Nefry.print("sensorValueNow=");
  Nefry.println(sensorValueNow);
  
  if(sensorValueBefore < 500){
    if(sensorValueNow > 500){
      bool sendData = IFTTT.send(Event, SecretKey,"Nefry_LightON",(String)(micros()/1000000)+"秒",(String)(now()));//IFTTTにデータを送信
                                 //Value1:Nefry,Value2:Nefryが起動してからの秒数,Value3:日時
       }
      }
  
  sensorValueBefore = sensorValueNow;
  Nefry.print("sensorValueBefore=");
  Nefry.println(sensorValueBefore);
  Nefry.println("");
  
  Nefry.ndelay(10000);
}

//参照：https://qiita.com/n0bisuke/items/0abe67b0d293e24a5628
//参照2：https://dotstud.io/blog/nefry-ifttt-push-line/
//閾値は500に設定
//5秒間隔に変更

#include <Time.h>
#include <TimeLib.h>

#include <Nefry.h>
#include <NefryIFTTT.h>
String Event, SecretKey;

int sensorValue;

void setup() {
  Nefry.setStoreTitle("SecretKey",0); //Nefry DataStoreのタイトルを指定
  Nefry.setStoreTitle("Event",1);     //Nefry DataStoreのタイトルを指定
  SecretKey = Nefry.getStoreStr(0);   //Nefry DataStoreからデータを取得
  Event = Nefry.getStoreStr(1);       //Nefry DataStoreからデータを取得
  Nefry.print("Grove Light sensor SETUP");
  
  Nefry.setLed(0,0,0);
  pinMode(A2,INPUT_PULLUP);//入力モード切り替え
}

void loop() {
  sensorValue = analogRead(A2);
  if(sensorValue > 500){
   bool sendData = IFTTT.send(Event, SecretKey,"Nefry_LightON",(String)(micros()/1000000)+"秒",(String)(now()));//IFTTTにデータを送信
                                      //Value1:Nefry,Value2:Nefryが起動してからの秒数,Value3:日時
   Nefry.print("sensor = " );
   Nefry.println(sensorValue);
  }
  Nefry.ndelay(5000);
}

#include <Time.h>
#include <TimeLib.h>

#include <Nefry.h>


int sensorValueNow;
int sensorValueBefore = 0;

void setup() {
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
      Nefry.println("send message");
       }
      }
  
  sensorValueBefore = sensorValueNow;
  Nefry.print("sensorValueBefore=");
  Nefry.println(sensorValueBefore);
  Nefry.println("");
  
  Nefry.ndelay(10000);
}

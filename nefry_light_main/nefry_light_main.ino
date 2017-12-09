//参照：https://qiita.com/n0bisuke/items/0abe67b0d293e24a5628

#include <Nefry.h>

int sensorValue;

void setup() {
  Nefry.print("Grove Light sensor SETUP");
  Nefry.setLed(0,0,0);
   pinMode(A2,INPUT_PULLUP);//入力モード切り替え
}

void loop() {
  sensorValue = analogRead(A2);
  Nefry.print("sensor = " );
  Nefry.println(sensorValue);
  delay(1000);
}

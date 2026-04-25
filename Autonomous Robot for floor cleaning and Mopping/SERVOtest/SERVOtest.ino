#include <ESP32Servo.h>
// `                    
// #include <Esp32Servo.h>
Servo s;
void setup(){
  s.attach(14); // change pin as needed
  delay(500);
}
void loop(){
  // sweep 0->180
  for(int p=0; p<=180; p+=10){
    s.write(p);
    delay(10); // 20ms per step -> smooth sweep
  }
  delay(300);
  for(int p=180; p>=0; p-=10){
    s.write(p);
    delay(10);
  }
  delay(1000);
}
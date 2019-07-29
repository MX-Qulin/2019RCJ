//舵机
#include <Servo.h>//加载舵机库
Servo s1;//命名舵机
void setup() {
  // put your setup code here, to run once:
  s1.attach(11);//定义舵机接口
  s1.write(5);//写入舵机角度
}

void loop() {
  // put your main code here, to run repeatedly:
  s1.write(95);
  delay(1000);
  s1.write(5);
  delay(1000);
}

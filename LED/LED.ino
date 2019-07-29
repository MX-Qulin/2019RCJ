//点亮板载LED
void setup() {
  // put your setup code here, to run once:
  pinMode(13,OUTPUT);//定义13号口输出
  digitalWrite(13,LOW);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(13,HIGH);//令13号口为高电平
  delay(1000);//等待1秒
  digitalWrite(13,LOW);//令13号口为低电平
  delay(1000);//等待1秒
}

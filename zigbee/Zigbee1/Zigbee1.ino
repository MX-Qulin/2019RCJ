//Zigbee1
int n=0;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);//设置波特率为9600
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println("hello world");//串口输出字符
  Serial.println(n);//串口输出数字
  delay(1000);
  n=n+1;
}


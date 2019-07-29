//made by MX-Qulin,copywrite by MX-Qulin.
//NO COPY WITHOUT PERMITION!
//See everything at github.com/MX-Qulin
//only for studying and learning.
//coding is a kind of art.
//99 little bugs in the code,
//99 bugs in the code,
//fix one bug, compile it again,
//101 little bugs in the code.
//101 little bugs in the code….
//(Repeat until BUGS = 0)
#include "SevSeg.h"
#include <IRremote.h>
SevSeg sevseg;
byte numDigits = 4,digitPins[] = {2, 3, 12, 13}; //数码管公共极连接Arduino的引脚
byte segmentPins[] = {7, 6, 5, 10, 11, 8, 9, 4}; //数码管a,b,c,d,e,f,g,dp对应引脚
byte hardwareConfig = COMMON_CATHODE ; // 共阴极数码管
int rec[20]={},starter=0;//the Hex code of keys on the board
int Spank_times=0,Spank_time=7777;//Spank_time:the time that one spank costs
int Spank_motor=1,RECV_PIN=0;//Spank_motor on pin 1 ,Receiver on pin 0
IRrecv irrecv(RECV_PIN);
decode_results results;
void setup() {
  // Serial.begin(9600);
  pinMode(Spank_motor, OUTPUT);
  sevseg.begin(hardwareConfig, numDigits, digitPins, segmentPins); //初始化数码管
  irrecv.enableIRIn(); // Start the receiver
}
void loop() {
    //get the Spank_times and perpare to start spanking
   for(int i=1,flag=0;i<=4;flag=0){
     if (irrecv.decode(&results)) {
       //Serial.println(results.value, HEX);
       int sign=results.value;
       for(int j=0;j<=9;j++) if(sign==rec[j]){Spank_times=(Spank_times+j)*10; flag=1; break;}
       if(flag==1) i++;
       if(sign==starter)break;//!!!later-fill!!! if "start" pressed, break and start spanking!!!
       irrecv.resume(); // Receive the next value
     }
     //?delay(100);
   }
  Spank_times/=10;
  for(int i=1;i<=5000;i++){
    sevseg.setNumber(Spank_times, -1); 
    sevseg.refreshDisplay(); //刷新数码管显示
  }
  delay(2222);
  //digitalWrite(Spank_motor, HIGH);//Start Spanking!!
  for(;Spank_times>0;Spank_times--){
    for(int i=1;i<=Spank_time;i++) {
      sevseg.setNumber(Spank_times,-1);
      sevseg.refreshDisplay();
    }
    //delay the time for [Spank_time](!!!later-fill!!!)
  }
  //digitalWrite(Spank_motor, Low);//Spanking Ended.
  for(;;){//let the 'End.' move on the screen
     for(int i=1;i<=9999;i++)sevseg.setChars(" End."),sevseg.refreshDisplay();
     for(int i=1;i<=9999;i++)sevseg.setChars("End."),sevseg.refreshDisplay();
  }
}

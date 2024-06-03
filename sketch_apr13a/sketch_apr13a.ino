#include<Servo.h>
#define emg A0
Servo index;
Servo middle;
Servo thumb;
Servo ring;
Servo pinky;

void setup()
{
  Serial.begin(115200);
  index.attach(6);
  middle.attach(5);
  thumb.attach(9);
  ring.attach(11);
  pinky.attach(10);
}

void loop()
{
   int avg=0;
int sum=0;
  // put your main code here, to run repeatedly:
for(int i=0;i<30;i++){
  int value=analogRead(emg);
  sum+=value;
  }
avg=sum/30;
Serial.println(avg);


  
if (avg>=90){
  index.write(180);
  pinky.write(180);
  middle.write(180);
  thumb.write(0);
  ring.write(180);
  
  delay(400);
}
else if(avg<=70)
{
index.write(0);
pinky.write(0);
  middle.write(0);
  thumb.write(180);
  ring.write(0);
  
  delay(400);
}
}
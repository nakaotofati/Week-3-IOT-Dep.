#include <Servo.h>
Servo myservo;
int pos=0;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  myservo.attach(9);
}

void loop() {
  // put your main code here, to run repeatedly:
  while(Serial.available()>0){
    String value =Serial.readString();
    if(value == "Left"){
      for(pos=180; pos>=0; pos-=1){
        myservo.write(pos);
        delay(15);
      }
    }
    else if(value == "right"){
      for(pos=0; pos<=180; pos+=1){
        myservo.write(pos);
        delay(15);
      }
    }
  }

}

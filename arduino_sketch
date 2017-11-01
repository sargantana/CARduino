/*
Bluetooth controled Arduino Car
*/
#include "IOconfig.h"

char charreceive;

void goforward();
void goleft();
void goright();
void goback();
void stopcommand();

void setup() {
  
  pinMode(dir1,OUTPUT);
  pinMode(dir2,OUTPUT);
  pinMode(LED,OUTPUT);
  
  for (int i=0; i<=5; i++) { //blink LED 5 times to show car is ready
  digitalWrite(LED, HIGH);   
  delay(200);              
  digitalWrite(LED, LOW);    
  delay(200);              
  }
  
  Serial.begin(9600);
  Serial.println("Car control established");
  delay(500);
}

void loop() {
  // put your main code here, to run repeatedly:
  
  if(Serial.available())
   {
    charreceive=char(Serial.read());
    Serial.println("get:"+charreceive);     
    switch(charreceive)
    {
      case '8':goforward();break;
      case '4':goleft();break;
      case '6':goright();break;
      case '2':goback();break;
      case '5':stopcommand();break;
      default:Serial.println("error");
     }
    }

}
void goforward(){
 digitalWrite(dir1,0);
 digitalWrite(dir2,0);
 analogWrite(pwm1,speed1);
 analogWrite(pwm2,speed1);
}
void goback(){
 digitalWrite(dir1,1);
 digitalWrite(dir2,1);
 analogWrite(pwm1,speed1);
 analogWrite(pwm2,speed1);
}
void goleft(){
 digitalWrite(dir1,0);
 digitalWrite(dir2,1);
 analogWrite(pwm1,speed1);
 analogWrite(pwm2,speed1);
}
void goright(){
 digitalWrite(dir1,1);
 digitalWrite(dir2,0);
 analogWrite(pwm1,speed1);
 analogWrite(pwm2,speed1);
}

void stopcommand(){
 analogWrite(pwm1,0);
 analogWrite(pwm2,0);
}


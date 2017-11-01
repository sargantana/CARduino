/*
Bluetooth controled Arduino Car
*/
#include "IOconfig.h"

int PWM_SLOW 50;  
int PWM_FAST 200;
int DIR_DELAY 1000;

char charreceive;

void goforward();
void goleft();
void goright();
void goback();
void stopcommand();

void setup() {
  
  pinMode(MOTOR_A_LEFT_DIR,OUTPUT);
  pinMode(MOTOR_A_LEFT_PWM,OUTPUT);
  pinMode(MOTOR_B_RIGHT_DIR,OUTPUT);
  pinMode(MOTOR_B_RIGHT_PWM,OUTPUT);
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
    //else{stopcommand();}
  }

}
if(digitalRead(BT_STATE)==LOW){stopcommand();} //stop car if Bluetooth connection is lost

void goforward(){
        Serial.println( "Forward" );
        // always stop motors briefly before abrupt changes
        digitalWrite( MOTOR_A_LEFT_DIR, LOW );
        digitalWrite( MOTOR_A_LEFT_PWM, LOW );
        digitalWrite( MOTOR_B_RIGHT_DIR, LOW );
        digitalWrite( MOTOR_B_RIGHT_PWM, LOW );
        delay( DIR_DELAY );
        // set the motor speed and direction
        digitalWrite( MOTOR_A_LEFT_DIR, HIGH ); // direction = forward
        analogWrite( MOTOR_A_LEFT_PWM, 255-PWM_FAST );
        digitalWrite( MOTOR_B_RIGHT_DIR, HIGH ); // direction = forward
        analogWrite( MOTOR_B_RIGHT_PWM, 255-PWM_FAST );
    
}
void goback(){
        Serial.println( "Reverse" );
        // always stop motors briefly before abrupt changes
        digitalWrite( MOTOR_A_LEFT_DIR, LOW );
        digitalWrite( MOTOR_A_LEFT_PWM, LOW );
        digitalWrite( MOTOR_B_RIGHT_DIR, LOW );
        digitalWrite( MOTOR_B_RIGHT_PWM, LOW );
        delay( DIR_DELAY );
        // set the motor speed and direction
        digitalWrite( MOTOR_A_LEFT_DIR, LOW ); // direction = reverse
        analogWrite( MOTOR_A_LEFT_PWM, 255-PWM_FAST );
        digitalWrite( MOTOR_B_RIGHT_DIR, LOW ); // direction = reverse
        analogWrite( MOTOR_B_RIGHT_PWM, 255-PWM_FAST );
  
}
void goleft(){
        Serial.println( "Left" );
        // always stop motors briefly before abrupt changes
        digitalWrite( MOTOR_A_LEFT_DIR, LOW );
        digitalWrite( MOTOR_A_LEFT_PWM, LOW );
        digitalWrite( MOTOR_B_RIGHT_DIR, LOW );
        digitalWrite( MOTOR_B_RIGHT_PWM, LOW );
        delay( DIR_DELAY );
        // set the motor speed and direction
        digitalWrite( MOTOR_A_LEFT_DIR, LOW ); // direction = reverse
        analogWrite( MOTOR_A_LEFT_PWM, 255-PWM_FAST );
        digitalWrite( MOTOR_B_RIGHT_DIR, HIGH ); // direction = forward
        analogWrite( MOTOR_B_RIGHT_PWM, 255-PWM_FAST );
  
}
void goright(){
        Serial.println( "Right" );
        // always stop motors briefly before abrupt changes
        digitalWrite( MOTOR_A_LEFT_DIR, LOW );
        digitalWrite( MOTOR_A_LEFT_PWM, LOW );
        digitalWrite( MOTOR_B_RIGHT_DIR, LOW );
        digitalWrite( MOTOR_B_RIGHT_PWM, LOW );
        delay( DIR_DELAY );
        // set the motor speed and direction
        digitalWrite( MOTOR_A_LEFT_DIR, HIGH ); // direction = forward
        analogWrite( MOTOR_A_LEFT_PWM, 255-PWM_FAST );
        digitalWrite( MOTOR_B_RIGHT_DIR, LOW ); // direction = reverse
        analogWrite( MOTOR_B_RIGHT_PWM, 255-PWM_FAST );
}

void stopcommand(){
        Serial.println( "Stop" );
        // always stop motors briefly before abrupt changes
        digitalWrite( MOTOR_B_DIR, LOW );
        digitalWrite( MOTOR_B_PWM, LOW );
}


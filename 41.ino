// C++ code
//
/*
  Sweep

  by BARRAGAN <http://barraganstudio.com>
  This example code is in the public domain.

  modified 8 Nov 2013  by Scott Fitzgerald
  http://www.arduino.cc/en/Tutorial/Sweep
*/

#include <Servo.h>

#define echo 2
#define trig 3

float duration;
float distance;

int pos = 0;

Servo servo_9;

void setup()
{
  
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  Serial.begin(9600);
  
  servo_9.attach(9, 500, 2500);
  servo_9.write(45);
}

void loop()
{

  	time_Measurement();
    distance = duration * (0.0343) / 2;   
    display_distance();  
  
}

void press(){

  for (pos = 45; pos <= 120; pos += 3) {
    servo_9.write(pos);
    delay(15);
  }
  for (pos = 120; pos >= 45; pos -= 3) {
    servo_9.write(pos);
    delay(15);
  }
  
}


void time_Measurement(){
    digitalWrite(trig, LOW);
    delayMicroseconds(2);
  
    digitalWrite(trig, HIGH);
    delayMicroseconds(10);
    digitalWrite(trig, LOW);
  
    duration = pulseIn(echo, HIGH);
  }

void display_distance(){
	Serial.print("Distance in Cm: ");
    Serial.println(distance);
  
  if(distance<100.00){
  	press();
    delay(2000);
  }
  
  
}
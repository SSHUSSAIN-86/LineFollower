/*
Code Name: Arduino Line Follower Robotic Car
Author: SSHUssain
Link: https://eceprojecthub.blogspot.com/
Description: This code is developed for line follower robotic car based on Arduino.
Notes: You can choose any value between 0 to 255 for Motor speed and RotationSpeed.
0 is the Lowest speed and 255 is for highest speed.
License: For educational purposes. Commercial use is not allowed.
*/

#include <Arduino.h>

//Arduino I/O pin map
#define enA 10
#define enB 5 
#define in1 9
#define in2 8
#define in3 7
#define in4 6

 
 
 int MotorSpeed = 125; // speed of motor
 int RotationSpeed = 250; // Fast Rotation Speed
 
 //Declaring car operations
 void moveBack();
 void moveForward();
 void moveRight();
 void moveLeft();
 void Stop();

 //Setup() describes the initialization parameters
 void setup() {
   pinMode(in1,OUTPUT);
   pinMode(in2,OUTPUT);
   pinMode(in3,OUTPUT);
   pinMode(in4,OUTPUT);
  
   pinMode(enA,OUTPUT);
   pinMode(enB,OUTPUT);
 
   pinMode(A0, INPUT); // initialize Left sensor as an input
   pinMode(A1, INPUT); // initialize Right sensor as an input 
}

//loop() implements the main routine  
void loop() {
 
 int LeftSensor = digitalRead(A0);
 int RightSsensor = digitalRead(A1);
  
if(LeftSensor==0 && RightSsensor==0) {
  moveForward(); //call moveForward
}
 
 else if(LeftSensor==1 && RightSsensor==0) {
  moveRight(); //call moveRight
 }
 
 else if(LeftSensor==0 && RightSsensor==1) {
  moveLeft(); //call moveLeft
}
 
 else if(LeftSensor==1 && RightSsensor==1) {
  Stop(); //call Stop
 }
}
 
 
//moveBack() implements car backing motion
void moveBack()
{
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
       
  analogWrite(enA, MotorSpeed);
  analogWrite(enB, MotorSpeed);
}

//moveForward() implements car forward motion  
void moveForward()
{
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
       
  analogWrite(enA, MotorSpeed);
  analogWrite(enB, MotorSpeed);
}

//moveRight() implemenets car moving right motion  
void moveRight()
{
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
       
  analogWrite(enA, RotationSpeed);
  analogWrite(enB, MotorSpeed); //analogWrite(enB, RotationSpeed);
}

//moveLeft() implements car moving left motion  
void moveLeft()
{
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
       
  analogWrite(enA, MotorSpeed); //analogWrite(enA, RotationSpeed);
  analogWrite(enB, RotationSpeed);
}

//Stop() implements car stop  
void Stop()
{
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
}

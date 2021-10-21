#include <Servo.h> //Library to use the Servo

Servo myServo;  //Servo object
const int trigPin = 12; //Trigpin connected to port 12
const int echoPin = 8;  //Echopin connected to port 8
float distance;  //variable to measure distance
float duration;  //variable for duration of sound wave travel


void setup(){
  myServo.attach(2);  //Connect servo to port 2
  pinMode(trigPin, OUTPUT); //Trigpin as output
  pinMode(echoPin, INPUT);  //Echopin as input
}

void loop(){
  ultraSound();
 
  myServo.write(0); //Start servo at position 0
 
  if(distance <= 10){ //Distance smaller or equal move servo to position 90
    myServo.write(90);
  }
  if(distance <= 4){ //Distance smaller or equal move servo to position 180
    myServo.write(180);
  }
}

void ultraSound(){
  digitalWrite(trigPin, LOW); //Clear trigPin condition
  delayMicroseconds(2);  //delay
  digitalWrite(trigPin, HIGH); //Set trigpin active for 10 microseconds
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH); //Reads the echoPin, return the sound wave travel time
  distance = duration / 58; //calculate the distance of sound through the speed of sound
  
}

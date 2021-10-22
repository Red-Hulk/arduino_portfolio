#include <Servo.h> //Biblioteek importeren servo

Servo myServo;  //Servo object
const int trigPin = 12; //Trigpin verbinden met poort 12
const int echoPin = 8;  //Echopin verbinden met poort 8
float distance;  //variable om afstand in op te slaan
float duration;  //variable voor duur van geluidsgolf


void setup(){
  myServo.attach(2);  //Verbind servo met pin 2
  pinMode(trigPin, OUTPUT); //Trigpin als output
  pinMode(echoPin, INPUT);  //Echopin als input
}

void loop(){
  ultraSound();
 
  myServo.write(0); //Start servo met positie 0
 
  if(distance <= 10){ //Afstand kleiner of gelijk aan 10
    myServo.write(90);// beweeg servo
  }
  if(distance <= 4){ //Afstand kleiner of gelijk aan 4
    myServo.write(180);// beweeg servo
  }
}

void ultraSound(){
  digitalWrite(trigPin, LOW); //Leegmaken trigPin conditie
  delayMicroseconds(2);  //vertraging
  digitalWrite(trigPin, HIGH); //Zet trigpin actief voor 10 microseconden
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH); //Lees de echoPin, terugsturen geluidsgolf
  distance = duration / 58; //berekenen van afstand
  
}

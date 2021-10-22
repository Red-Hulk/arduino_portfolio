#include <Servo.h> //Bibliotheek toevoegen van servo

Servo myServo; //Servo object
int position;  //Variable voor positie servo

const int buttonOne = 12; //Pin van knop 1
const int buttonTwo = 3;  //Pin van knop 2
int posButtonOne; //Staat van knop 1
int posButtonTwo; //Staat van knop 2
int posBothButtons; //Staat van beide knoppen bij elkaar

void setup(){
  myServo.attach(6); //Verbindt servo met pin 6
  pinMode(buttonOne, INPUT_PULLUP); //Klaarzetten knop 1
  pinMode(buttonTwo, INPUT_PULLUP); //Klaarzetten knop 2
  myServo.write(0); //Lezen van begin positie servo
}

void loop(){
  position = myServo.read(); //Lees de huidige stand servo
  
  servoFunction(); //Functie om de servo te laten bewegen 
  
}

void servoFunction(){
  
  //Nakijken of knop 1 is ingedrukt en of de positie servo kleiner is dan 120 graden
  if(digitalRead(buttonOne) == LOW && position <= 120){
    //Verhoog met 1
    posButtonOne = position + 1;
    //De servo laten bewegen aan de hand van de posButtonOne
    myServo.write(posButtonOne);
    //Kleine vertraging
    delay(8);
    
    //Als de positie 120 is stop met verhogen
    //De servo gaat automatisch naar positie 0
    if(position == 120){
      for(position = 120; position >= 0; position--){
            //Beweeg Servo
          myServo.write(position);
            //Vertraag met 1 sec
          delay(8);
      }
    }
  }
  
  //Nakijken of knop 2 is ingedrukt en of de positie servo kleiner is dan 120 graden
  if(digitalRead(buttonTwo) == LOW && position <= 120){
    
    //Verhoog met 1
    posButtonTwo = position + 1;
    //De servo laten bewegen aan de hand van de posButtonTwo
    myServo.write(posButtonTwo);
    //Vertraging halve seconde
    delay(4);
    
    //Als de positie 120 is stop met verhogen
    //De servo gaat automatisch naar positie 0
    if(position == 120){
      for(position = 120; position >= 0; position--){
        //Beweeg servo
        myServo.write(position);
        //Vertraag 0.5 seconde
        delay(4);
      }
    }
    
  }
 

  //Als de beide knoppen zijn ingedrukt en positie lager of gelijk is aan 120 graden
  if(digitalRead(buttonOne) == LOW && digitalRead(buttonTwo) == LOW
    && position <= 120){
    
    //Verhogen met 1
    posBothButtons = position + 1;
    
    //The servo moves according the value posButtonOne
    myServo.write(posBothButtons);
    //Vertaging
    delay(8);
    
    //Als de positie 120 is stop met verhogen
    //De servo gaat automatisch naar positie 0
    if(position == 120){
      //Eerste vertraging 2 seconde servo staat vast
      delay(2000);
      for(position = 120; position >= 0; position--){
        //Beweeg servo
        myServo.write(position);
        //Vertraging
        delay(8);
      }
    
    }
    
  }
}

#include <Servo.h> //Include library for servo

Servo myServo; //Servo object
int position;  //Variable for position servo

const int buttonOne = 12; //Pin of button one
const int buttonTwo = 3;  //Pin of button two
int posButtonOne; //State of button one
int posButtonTwo; //State of button two
int posBothButtons;

void setup(){
  myServo.attach(6); //Connect servo with pin 6
  pinMode(buttonOne, INPUT_PULLUP); //Setup for button one
  pinMode(buttonTwo, INPUT_PULLUP); //Setup for button two
  myServo.write(0); //Read the initial position for servo
}

void loop(){
  position = myServo.read(); //Read the current position of the servo
  
  servoFunction(); //Function to move the servo's position
  
}

void servoFunction(){
  
  //Check if the buttonOne is pressed and hold & if the position is lower of equal to 120 degrees
  if(digitalRead(buttonOne) == LOW && position <= 120){
    //Increment position by one
    posButtonOne = position + 1;
    //The servo moves according the value posButtonOne
    myServo.write(posButtonOne);
    //Delay in total of 1 sec (1000:120)
    delay(8);
    
    //If the position value is 120 stop incrementing
    //and move servo automatically back to position 0
    if(position == 120){
      for(position = 120; position >= 0; position--){
            //Move servo
          myServo.write(position);
            //Delay with 1 sec
          delay(8);
      }
    }
  }
  
  //Check if the buttonTwo is pressed and hold & if the position is lower of equal to 120 degrees
  if(digitalRead(buttonTwo) == LOW && position <= 120){
    
    //Increment position by one
    posButtonTwo = position + 1;
    //The servo moves according the value posButtonTwo
    myServo.write(posButtonTwo);
    //Delay in total of 0.5 sec (500:120)
    delay(4);
    
    //If the position value is 120 stop incrementing
    //and move servo automatically back to position 0
    if(position == 120){
      for(position = 120; position >= 0; position--){
        //Move servo
        myServo.write(position);
        //Delay in total of 0.5 sec
        delay(4);
      }
    }
    
  }
 
  //If both buttons are pressed and hold & if the position is lower of equal to 120 degrees
  if(digitalRead(buttonOne) == LOW && digitalRead(buttonTwo) == LOW
    && position <= 120){
    
    //Increment position by one
    posBothButtons = position + 1;
    
    //The servo moves according the value posButtonOne
    myServo.write(posBothButtons);
    //Delay in total of 1 sec (1000:120)
    delay(8);
    
    //If the position value is 120 stop incrementing
    //and move servo automatically back to position 0
    if(position == 120){
      //First delay 2sec, servo fixed position
      delay(2000);
      for(position = 120; position >= 0; position--){
        //Move servo
        myServo.write(position);
        //Delay in total of 1 sec
        delay(8);
      }
    
    }
    
  }
}

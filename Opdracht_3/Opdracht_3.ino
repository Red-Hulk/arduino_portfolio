//Ports led and potentiometer initial value
const int potPin = A5;
const int ledPin1 = 7;
const int ledPin2 = 8;
const int ledPin3 = 9;
const int ledPin4 = 10;
const int ledPin5 = 11;
const int ledPin6 = 12;
const int ledPin7 = 13;
int potmeterWaarde = 0;



void setup() {
  //Setup the leds
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(ledPin3, OUTPUT);
  pinMode(ledPin4, OUTPUT);
  pinMode(ledPin5, OUTPUT);
  pinMode(ledPin6, OUTPUT);
  pinMode(ledPin7, OUTPUT);
  
}

void loop() {

  //Reading the potentiometer
  potmeterWaarde = analogRead(potPin);
  
  //Checks values of potentiometer 
  //to decide led on or off
  if(potmeterWaarde > 146){
    digitalWrite(ledPin1, HIGH);
  }
  if(potmeterWaarde > 292){
    digitalWrite(ledPin2, HIGH);
    
  }
  if(potmeterWaarde > 438){
    digitalWrite(ledPin3, HIGH);
    
  }
  if(potmeterWaarde > 582){
    digitalWrite(ledPin4, HIGH);
    
  }
  if(potmeterWaarde > 728){
    digitalWrite(ledPin5, HIGH);
    
  }
  if(potmeterWaarde > 874){
    digitalWrite(ledPin6, HIGH);
    
  }
  if(potmeterWaarde > 1020){
    digitalWrite(ledPin7, HIGH);
  }
  
  if(potmeterWaarde < 146){
    digitalWrite(ledPin1, LOW);
  }
  if(potmeterWaarde < 292){
    digitalWrite(ledPin2, LOW);
    
  }
  if(potmeterWaarde < 438){
    digitalWrite(ledPin3, LOW);
    
  }
  if(potmeterWaarde < 582){
    digitalWrite(ledPin4, LOW);
    
  }
  if(potmeterWaarde < 728){
    digitalWrite(ledPin5, LOW);
    
  }
  if(potmeterWaarde < 874){
    digitalWrite(ledPin6, LOW);
    
  }
  if(potmeterWaarde < 1020){
    digitalWrite(ledPin7, LOW);
  }
  
  
  
}

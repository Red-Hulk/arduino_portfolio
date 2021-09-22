// These are the ports where the pins are connected to
const int ledPinOne = 1;
const int ledPinTwo = 2;
const int ledPinThree = 3;
const int ledPinFour = 4;
const int ledPinFive = 5;
const int ledPinSix = 6;
const int ledPinSeven = 7;
const int ledPinEight = 8;

void setup() {
  
  //Setup code for the pins
  pinMode(ledPinOne, OUTPUT);
  pinMode(ledPinTwo, OUTPUT);
  pinMode(ledPinThree, OUTPUT);
  pinMode(ledPinFour, OUTPUT);
  pinMode(ledPinFive, OUTPUT);
  pinMode(ledPinSix, OUTPUT);
  pinMode(ledPinSeven, OUTPUT);
  pinMode(ledPinEight, OUTPUT);
}

void blink(int pin){
  //Led goes on
  digitalWrite(pin, HIGH);
  //Short delay between on and off
  delay(100);
  //Led goes out
  digitalWrite(pin, LOW);
  //Short delay between on and off
  delay(100);
}

void loop() {
  
  //Method to let the led blink
  blink(ledPinOne);
  blink(ledPinTwo);
  blink(ledPinThree);
  blink(ledPinFour);
  blink(ledPinFive);
  blink(ledPinSix);
  blink(ledPinSeven);
  blink(ledPinEight);
 
  blink(ledPinSeven);
  blink(ledPinSix);
  blink(ledPinFive);
  blink(ledPinFour);
  blink(ledPinThree);
  blink(ledPinTwo);
}

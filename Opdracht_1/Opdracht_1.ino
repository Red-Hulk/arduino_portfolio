// Dit zijn de poorten waar de leds inzitten
const int ledPinOne = 1;
const int ledPinTwo = 2;
const int ledPinThree = 3;
const int ledPinFour = 4;
const int ledPinFive = 5;
const int ledPinSix = 6;
const int ledPinSeven = 7;
const int ledPinEight = 8;

void setup() {
  
  //Setup code voor de pins
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
  //Lichtje gaat aan
  digitalWrite(pin, HIGH);
  //Kort vertraging
  delay(100);
  //Lichtje gaat uit
  digitalWrite(pin, LOW);
  //Korte vertraging
  delay(100);
}

void loop() {
  
  //Methode om de lichtjes te laten blinken
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

//Poorten van de leds
const int ledRed = 11;
const int ledGreen = 6;
const int ledYellow = 3;

void setup()
{
  //Setup code voor de leds
  pinMode(ledRed, OUTPUT);
  pinMode(ledGreen, OUTPUT);
  pinMode(ledYellow, OUTPUT);
}

void loop()
{
  //Loop door 1 t/m 255 om de waarden te veranderen van de RGB
  for(int x=0; x<255; x++){
    analogWrite(ledRed, x);
    delay(1000);
    analogWrite(ledGreen, x);
    delay(1000);
    analogWrite(ledYellow, x);
    delay(1000);
  }
  //Loop terug door 1 t/m 255 om de waarden te veranderen van de RGB
  for(int x=255; x>0; x--){
    analogWrite(ledRed, x);
    delay(1000);
    analogWrite(ledGreen, x);
    delay(1000);
    analogWrite(ledYellow, x);
    delay(1000);
  }
  
}

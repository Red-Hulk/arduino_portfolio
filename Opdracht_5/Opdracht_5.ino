//Ports of the led
const int ledRed = 11;
const int ledGreen = 6;
const int ledYellow = 3;

void setup()
{
  //Setup code for the led
  pinMode(ledRed, OUTPUT);
  pinMode(ledGreen, OUTPUT);
  pinMode(ledYellow, OUTPUT);
}

void loop()
{
  //Loop up from 0 to 255 for changing the RGB values
  for(int x=0; x<255; x++){
    analogWrite(ledRed, x);
    delay(1000);
    analogWrite(ledGreen, x);
    delay(1000);
    analogWrite(ledYellow, x);
    delay(1000);
  }
  //Loop down from 255 to 0 for changing the RGB values
  for(int x=255; x>0; x--){
    analogWrite(ledRed, x);
    delay(1000);
    analogWrite(ledGreen, x);
    delay(1000);
    analogWrite(ledYellow, x);
    delay(1000);
  }
  
}

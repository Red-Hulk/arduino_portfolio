//Poort temperatuursensor
const int tempPin = A0;


void setup()
{
  //Monitor opzetten
  Serial.begin(9600);
}

void loop()
{ 
  //Lees de analoge pin
  int temp = analogRead(tempPin);   
  //Omzetten naar celsuis
  temp = temp * 0.48828125;
  //Printen naar de console
  Serial.print("Temperatuur in graden Celsius: ");
  //Print temperatuur
  Serial.println(temp);
  //Korte vertraging
  delay(1000);  
}

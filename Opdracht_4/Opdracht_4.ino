//Port temp
const int tempPin = A0;


void setup()
{
  //Tells monitor to be ready
  Serial.begin(9600);
}

void loop()
{ 
  //Read the analog pin
  int temp = analogRead(tempPin);   
  //Convert output to celsius
  temp = temp * 0.48828125;
  //Print to the console
  Serial.print("Temperatuur in graden Celsius: ");
  //Print to the console with line break
  Serial.println(temp);
  //Delay for printing
  delay(1000);  
}

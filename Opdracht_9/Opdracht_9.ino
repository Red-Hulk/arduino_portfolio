const int ledPins[] = {2,3,4}; // Poorten lichtjes
String msg,cmd;

void setup() {
  
  //Setup code voor lichtjes
  for(int led : ledPins){
    pinMode(led, OUTPUT);
   }

  //Eerst uitzetten de lichtjes
  for(int led : ledPins){
    digitalWrite(led, LOW);
  }
  
  Serial.begin(9600); // Communicatie met bluetooth module
  msg = "";
}

void loop() {
  
  
  // Lezen van bericht van app
  if (Serial.available() > 0){ // Checken of er data binnenkomt
    msg = Serial.readString(); // Lezen van bericht
    Serial.println("Android Command: " + msg);
  }

  // Als bericht is turn on dan stoplicht uitvoeren
  if (msg == "<turn on>"){
    digitalWrite(ledPins[0], HIGH);
    delay(12000);
    digitalWrite(ledPins[0], LOW);
    
    
    digitalWrite(ledPins[1], HIGH);
    delay(6000);
    digitalWrite(ledPins[1], LOW);
    
    
    digitalWrite(ledPins[2], HIGH);
    delay(12000);
    digitalWrite(ledPins[2], LOW);
  
    msg = ""; // reset bericht
  } else {
    //als het bericht turn off is laat de oranje lamp knipperen
    if (msg == "<turn off>"){
        while(msg == "<turn off>"){
          digitalWrite(ledPins[1], HIGH);
          delay(1000);
          digitalWrite(ledPins[1], LOW);
          delay(1000);
          msg = Serial.readString();
          }
         
      msg = ""; // reset command
    }
  }
}

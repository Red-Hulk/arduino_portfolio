const int ledPins[] = {2,3,4}; // Built in LED in Arduino board
String msg,cmd;

void setup() {
  
  //pins led 
  for(int led : ledPins){
    pinMode(led, OUTPUT);
   }

  for(int led : ledPins){
    digitalWrite(led, LOW);
  }
  
  Serial.begin(9600); // Communication rate of the Bluetooth Module
  msg = "";
}

void loop() {
  
  
  // To read message received from other Bluetooth Device
  if (Serial.available() > 0){ // Check if there is data coming
    msg = Serial.readString(); // Read the message as String
    Serial.println("Android Command: " + msg);
  }

  // Control LED in Arduino board
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
   
    Serial.println("LED is turned on\n"); // Then send status message to Android
    msg = ""; // reset command
  } else {
    if (msg == "<turn off>"){
        while(msg == "<turn off>"){
          digitalWrite(ledPins[1], HIGH);
          delay(1000);
          digitalWrite(ledPins[1], LOW);
          delay(1000);
          msg = Serial.readString();
          }
          
          
       
      
      Serial.println("LED is turned off\n"); // Then send status message to Android
      msg = ""; // reset command
    }
  }
}

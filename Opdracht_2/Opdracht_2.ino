//Ports of button, led and initial value(s)
const int Button = 1;
const int LED = 11;
int ButtonState = 0;
int Count = 0;

void setup() {
  //Set up code for button and led
  pinMode(Button, INPUT);
  pinMode(LED, OUTPUT);
}

void loop() {
  //Reading the button
  ButtonState = digitalRead(Button);
  
  //If pushed on button increase count with one
  if(ButtonState == HIGH){
    Count++;
    delay(300);
  }
  //Decide if button should be on or off
  if(Count % 2 == 0){
    digitalWrite(LED, LOW);
  }else{
    digitalWrite(LED, HIGH);
  }
}

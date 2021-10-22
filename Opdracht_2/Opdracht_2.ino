//Poorten van de knop, lichtje, de begin waarde van de button & variable count om te kunnen bepalen of het lichtje aan of uit moet
const int Button = 1;
const int LED = 11;
int ButtonState = 0;
int Count = 0;

void setup() {
  //Set up code voor de knop en lichtje
  pinMode(Button, INPUT);
  pinMode(LED, OUTPUT);
}

void loop() {
  //Staat knopje 
  ButtonState = digitalRead(Button);
  
  //Als knopje wordt ingedrukt dan variable met eentje verhogen
  if(ButtonState == HIGH){
    Count++;
    delay(300);
  }
  //Bepaal of knop aan of uit moet
  if(Count % 2 == 0){
    digitalWrite(LED, LOW);
  }else{
    digitalWrite(LED, HIGH);
  }
}

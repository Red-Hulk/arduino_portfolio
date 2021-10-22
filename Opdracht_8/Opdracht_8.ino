#include <IRremote.h> //importeren library remote
 
const int irPin = 7;  //Ontvangst pin

IRrecv irrecv(irPin); //Nieuwe instantie van remote 
decode_results results; // Variable results om ontvangst knop in op te slaan


const int ledPins[] = {2,3,10,11};
const int knipperTimes[] = {100,200,300,400};


unsigned long lastTimes[] = {0,0};

int ledStatus[] = {LOW, LOW};

//variable om bij te houden of er geklikt is
int bijhouden;
int knipperen;
bool led[] = {false, false, false, false};

void setup(){
  Serial.begin(9600); //Stelt de seriele monitor in
  irrecv.enableIRIn(); //Start de IR-ontvanger
  for(int i : ledPins){
    pinMode(i , OUTPUT);
  }
}

void loop(){
  
    
    buttonPressed();
    

    blinkLed();
  
}

//Buttondrukken 
void buttonPressed(){
   if(irrecv.decode(&results)){
    Serial.println(results.value, HEX);
    irrecv.resume();
      switch(results.value){
        //Button 1
        case 0xFD08F7:
          if(bijhouden == 0){
            bijhouden = 1;
            led[0] = true;
          }else if(bijhouden == 1){
            bijhouden += 1;
            knipperen = 1;
            }
        else{
          bijhouden = 0;
        }
          
          break;
          
        //Knop 2
        case 0xFD8877:
          if(bijhouden == 0){
            bijhouden = 1;
            led[1] = true;
          }else if(bijhouden == 1){
            bijhouden += 1;
            knipperen = 2;
            }
        else{
          bijhouden = 0;
        }
    
          break;
          
        //Knop 3
        case 0xFD48B7:
          if(bijhouden == 0){
            bijhouden = 1;
            led[2] = true;
          }else if(bijhouden == 1){
            bijhouden += 1;
            knipperen = 3;
            }
        else{
          bijhouden = 0;
        }
    
          break;
          
        //Knop 4
        case 0xFD28D7:
          if(bijhouden == 0){
            bijhouden = 1;
            led[3] = true;
          }else if(bijhouden == 1){
            knipperen = 4;
            bijhouden += 1;
            }
        else{
          bijhouden = 0;
        }
    
          break;
      }
    
    }
}


//Knippersnelheid 500
void blinkLed(){
  
 
  //knipperen led 1
  if(led[0] == true && knipperen == 1){
    blink(0, 0);
    
  }
  if(led[0] == true && knipperen == 2){
    blink(0, 1);
  }
  if(led[0] == true && knipperen == 3){
    blink(0, 2);
  }
  if(led[0] == true && knipperen == 4){
    blink(0, 3);
  }
  
  //knipperen led 2
  if(led[1] == true && knipperen == 1){
    blink(1, 0);
  }
  if(led[1] == true && knipperen == 2){
    blink(1, 1);
  }
  if(led[1] == true && knipperen == 3){
    blink(1, 2);
  }
  if(led[1] == true && knipperen == 4){
    blink(1, 3);
  }
  
  //knipperen led 3
  if(led[2] == true && knipperen == 1){
    blink(2, 0);
  }
  if(led[2] == true && knipperen == 2){
    blink(2, 1);
  }
  if(led[2] == true && knipperen == 3){
    blink(2, 2);
  }
  if(led[2] == true && knipperen == 4){
    blink(2, 3);
  }
  
  //knipperen led 4
  if(led[3] == true && knipperen == 1){
    blink(3, 0);
  }
  if(led[3] == true && knipperen == 2){
    blink(3, 1);
  }
  if(led[3] == true && knipperen == 3){
    blink(3, 2);
  }
  if(led[3] == true && knipperen == 4){
    blink(3, 3);
  }
  
  
  
}


//Checken of de waarde van statebuttons groter is dan 0 als er al een button is geselecteerd
void blink(int x, int y){
  unsigned long huidigeTijd = millis();
   if(huidigeTijd - lastTimes[0] >= knipperTimes[y]){
      lastTimes[0] = huidigeTijd;
      ledStatus[0] = (ledStatus[0] == LOW) ? HIGH : LOW;
      digitalWrite(ledPins[x], ledStatus[0]);
    }
}

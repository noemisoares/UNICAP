#include "pitches.h"
int potPin = A2;
int valorPot = 0;
byte ledPin[] = {4, 5, 6, 7, 8, 9, 10, 11, 12, 13}; 
int buzzerPin = 3;



void setup() {
    for (int x = 0; x < 10; x++) { 
        pinMode(ledPin[x], OUTPUT);
    }
    
    pinMode(buzzerPin, OUTPUT);
    pinMode(potPin, INPUT);
    tone(buzzerPin, 0);
}

void loop() {
    valorPot = analogRead(potPin);
    int tempo = map(valorPot, 0, 1023, 100, 1000);
    
    changeVolume(tempo);
    changeLED(tempo);
    logicMelody();
}
void changeLED(int tempo) {
   if(tempo >= 100){
    for(int i = 0; i < 10; i++){
     digitalWrite(ledPin[i], LOW);
    }
    digitalWrite(ledPin[0], HIGH);
  }if(tempo >= 200){
    
    
    digitalWrite(ledPin[1], HIGH);
  }if(tempo >= 300){
    
    digitalWrite(ledPin[2], HIGH);
    
  }
  
  if(tempo >= 400){
   
    digitalWrite(ledPin[3], HIGH);
    
  }
  
  if(tempo >= 500){
    
    digitalWrite(ledPin[4], HIGH);
    
  }if(tempo >= 600){
    
    digitalWrite(ledPin[5], HIGH);
  }
  if(tempo >= 700){
    
    digitalWrite(ledPin[6], HIGH);
  }
  if(tempo >= 800){
    
    digitalWrite(ledPin[7], HIGH);
  }
  if(tempo >= 900){
    
   
    digitalWrite(ledPin[8], HIGH);
  }
  if(tempo >= 1000){
    
   
    digitalWrite(ledPin[9], HIGH);
  }
}

void changeVolume(int tempo){
  
  tone(buzzerPin, tempo*3.10);
  
  
}

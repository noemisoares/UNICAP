int potPin = A2;
int valorPot = 0;
byte ledPin[] = {4, 5, 6, 7, 8, 9, 10, 11, 12, 13}; 

int currentLEDdir = 0, currentLEDesq = 9;
unsigned long changeTime;

void setup() {
    for (int x = 0; x < 10; x++) { 
        pinMode(ledPin[x], OUTPUT);
    }
    changeTime = millis();
}

void loop() {
    valorPot = analogRead(potPin);
    int tempo = map(valorPot, 0, 1023, 0, 100);
    changeLED(tempo);
}

void changeLED(int tempo) {
  if(tempo < 5){
    for(int i = 0; i < 10; i++){
    	digitalWrite(ledPin[i], LOW);
    }
  }else if(tempo >= 5 && tempo < 20){
  	for(int i = 0; i < 10; i++){
    	digitalWrite(ledPin[i], LOW);
    }
    digitalWrite(ledPin[0], HIGH);
    digitalWrite(ledPin[9], HIGH);
  }else if(tempo >= 20 && tempo < 40){
  	for(int i = 0; i < 10; i++){
    	digitalWrite(ledPin[i], LOW);
    }
    digitalWrite(ledPin[1], HIGH);
    digitalWrite(ledPin[8], HIGH);
  }else if(tempo >= 40 && tempo < 60){
  	for(int i = 0; i < 10; i++){
    	digitalWrite(ledPin[i], LOW);
    }
    digitalWrite(ledPin[2], HIGH);
    digitalWrite(ledPin[7], HIGH);
  }else if(tempo >= 60 && tempo < 80){
  	for(int i = 0; i < 10; i++){
    	digitalWrite(ledPin[i], LOW);
    }
    digitalWrite(ledPin[3], HIGH);
    digitalWrite(ledPin[6], HIGH);
  }else if(tempo >= 80 && tempo < 100){
  	for(int i = 0; i < 10; i++){
    	digitalWrite(ledPin[i], LOW);
    }
    digitalWrite(ledPin[4], HIGH);
    digitalWrite(ledPin[5], HIGH);
  }
}

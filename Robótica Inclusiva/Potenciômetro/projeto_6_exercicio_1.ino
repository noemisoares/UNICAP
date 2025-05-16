int potPin = A2;
int valorPot = 0;
byte ledPin[] = {4, 5, 6, 7, 8, 9, 10, 11, 12, 13}; 

int direction = 1;
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
    int tempo = map(valorPot, 0, 1023, 50, 1000);

    if ((millis() - changeTime) > tempo) { 
        changeLED();
        changeTime = millis();
    }
}

void changeLED() {
    for (int x = 0; x < 10; x++) { 
        digitalWrite(ledPin[x], LOW);
    }
  
    digitalWrite(ledPin[currentLEDdir], HIGH); 
    digitalWrite(ledPin[currentLEDesq], HIGH);

    currentLEDdir += direction;
    currentLEDesq -= direction;

    if (currentLEDdir == 5) { direction = -1; }
    if (currentLEDdir == 0) { direction = 1; }
}

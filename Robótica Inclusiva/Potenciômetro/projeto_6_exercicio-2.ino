const byte ledPin[] = {4, 5, 6, 7, 8, 9, 10, 11, 12, 13}; 
const int numLeds = sizeof(ledPin) / sizeof(ledPin[0]);

void setup() {
    for (int i = 0; i < numLeds; i++) {
        pinMode(ledPin[i], OUTPUT);
    }
}

void loop() {
    int alturaMax = numLeds - 1;
    while (alturaMax > 0) {
        quicar(alturaMax);
        alturaMax--;
    }
}

void quicar(int alturaMax) {
    int delayTempo = 100;

    for (int i = 0; i <= alturaMax; i++) {
        acenderLED(i);
        delay(delayTempo);
    }

    for (int i = alturaMax - 1; i >= 0; i--) {
        acenderLED(i);
        delay(delayTempo);
    }
}

void acenderLED(int indice) {
    for (int i = 0; i < numLeds; i++) {
        digitalWrite(ledPin[i], LOW);
    }
    digitalWrite(ledPin[indice], HIGH);
}

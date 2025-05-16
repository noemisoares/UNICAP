//PROJETO 4.

void setup() {
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(2, INPUT);
}

int buttonState = 0;
const int buttonPin = 2;

void loop() {
  buttonState = digitalRead(buttonPin);
 
  if(buttonState == HIGH){
    digitalWrite(8, LOW);
    delay(2000);
    digitalWrite(12, HIGH);
    delay(2000);
    digitalWrite(12, LOW);
    delay(2000);
    digitalWrite(4, LOW);
    digitalWrite(13, HIGH);
    digitalWrite(7, HIGH);
    delay(6000);
    digitalWrite(7, LOW);
    digitalWrite(4, HIGH);
    digitalWrite(13, LOW);
  }else{
    digitalWrite(8,HIGH);
    digitalWrite(4, HIGH);
  }
}

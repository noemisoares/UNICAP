//PROJETO 1 - EXERCICIO 1.

void setup() {
  pinMode(13, OUTPUT);
}

void loop() {
  digitalWrite(13, HIGH);
  delay(3000); 
  digitalWrite(13, LOW);
  delay(3000); 
  digitalWrite(13, HIGH);
  delay(200); 
  digitalWrite(13, LOW);
  delay(500); 
}

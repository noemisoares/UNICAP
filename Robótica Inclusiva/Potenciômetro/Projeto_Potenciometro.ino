// Projeto 05

int redPin = 13, potenciometro = A0;
int luz, potAnalog;

void setup()
{
  pinMode(redPin, OUTPUT);
  pinMode(potenciometro, INPUT);  
}

void loop()
{
  potAnalog = analogRead(potenciometro);
  luz = map(potAnalog,0,1023,0,255); 
  analogWrite(redPin,luz);   
}

int vermelho = 10;
int amarelo = 9;
int verde = 8;
int buzzer = 4;
int azul = 7;
void blueBlinck(int valor);
void setup() {
pinMode (vermelho, OUTPUT);
pinMode (verde, OUTPUT);
pinMode (amarelo, OUTPUT);
pinMode (azul, OUTPUT);
pinMode (buzzer, OUTPUT);

Serial.begin (9600);
}

void loop() {

int valor = analogRead(A0);
Serial.print("Luminosidade: ");
Serial.println(valor);

delay (100);

if (valor >= 0 && valor < 500)
{ digitalWrite(vermelho, HIGH);
 digitalWrite (amarelo, LOW);
 digitalWrite (verde, LOW);
 
 digitalWrite (buzzer, LOW);
 
 blueBlinck(valor);
 
}

else if (valor >= 500 && valor < 800)
{ digitalWrite(vermelho, LOW);
 digitalWrite(amarelo, HIGH);
 digitalWrite(verde, LOW);
 digitalWrite (buzzer, HIGH);
 
 blueBlinck(valor);
}

else
{ 
  digitalWrite(verde, HIGH);
  digitalWrite(amarelo, LOW);
  digitalWrite(vermelho, LOW);
  digitalWrite (buzzer, HIGH);
  
  blueBlinck(valor);
}
}


void blueBlinck(int valor){
  if (valor >= 0 && valor < 500)
{  
 tone(buzzer, 10);
 digitalWrite(azul, HIGH);
 delay(1000);
 noTone(buzzer);
 digitalWrite(azul, LOW);
 delay(1000);


 
}

else if (valor >= 500 && valor < 800)
{ 
  tone(buzzer, 1000);
  digitalWrite(azul, HIGH);
  delay(500);
  noTone(buzzer);
  digitalWrite(azul, LOW);
  delay(500);

}

else
{ 
  tone(buzzer, 2000);
  digitalWrite(azul, HIGH);
  delay(100);
  noTone(buzzer);
  digitalWrite(azul, LOW);
  delay(100);
 
}

}

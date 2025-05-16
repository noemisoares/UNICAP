byte led[]= {4,5,6,7,8,9,10,11,12,13};
int leddelay(100);
int direcao = 1;
int ledatual = 0;
unsigned long mudatempo;

void setup(){
  for(int x = 0; x < 10; x++){
    pinMode(led[x], OUTPUT);
    }
    mudatempo = millis();
}

void loop(){
  if((millis()-mudatempo)>leddelay){
    mudaLed();
    mudatempo = millis();
  }
}

void mudaLed(){
  for(int x = 0; x < 10; x++){
    digitalWrite(led[x], LOW);
  }
  digitalWrite(led[ledatual], HIGH);
  ledatual += direcao;
  if (ledatual == 9){
    direcao = -1;
  }
  if (ledatual == 0){
    direcao = 1;
  }
}

#include <Servo.h>

const int TRIG_PIN  = 9;
const int ECHO_PIN  = 8;
const int SERVO_PIN = 10;
const int verde = 7;
const int amarelo = 6;
const int vermelho = 5;
const int buzzer = 4;
const int DISTANCE_FAR = 100;
const int DISTANCE_MIDDLE = 50;
int destination = 0;
void warning(float distance, int far, int middle, int buzzer);
Servo servo;

void setup() {
  Serial.begin(9600);
  pinMode (vermelho, OUTPUT);
  pinMode (verde, OUTPUT);
  pinMode (amarelo, OUTPUT);
  pinMode (buzzer, OUTPUT);
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  servo.attach(SERVO_PIN);
  servo.write(0); 
}

void loop() {
  digitalWrite(TRIG_PIN, HIGH); 
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);
  digitalWrite(buzzer, LOW);
  noTone(buzzer);
  servo.write(0);
  float duration_us = pulseIn(ECHO_PIN, HIGH);
  float distance_cm = 0.017 * duration_us;
 

  warning(distance_cm, DISTANCE_FAR, DISTANCE_MIDDLE, buzzer, destination);

 
  delay(500);
}
void warning(float distance, int far, int middle, int buzzer, int destination){
  if (distance > far) {
    tone(buzzer, 20);
    
    digitalWrite(verde, HIGH);
    digitalWrite (amarelo, LOW);
    digitalWrite (vermelho, LOW);
    servo.write(0);

  } else if(distance >= middle && distance < far){
    tone(buzzer, 50);
    digitalWrite(verde, LOW);
    digitalWrite (amarelo, HIGH);
    digitalWrite (vermelho, LOW);
    servo.write(90);

  }else if(distance < middle){
    digitalWrite(verde, LOW);
    digitalWrite (amarelo, LOW);
    digitalWrite (vermelho, HIGH);
    digitalWrite(buzzer, HIGH);
    
    digitalWrite(buzzer,HIGH);
    tone(buzzer, 1000);
    delay(500);
    digitalWrite(buzzer,LOW);
    servo.write(0);
    delay(500);
    moveCem(destination);
       
  }
 }
 void moveCem(int destination){
  if(destination == 0){
    for(int i = destination; i <180; i++){
        servo.write(i); 
        destination = 180;
      }
  }else{
      for(int i = 180; i >= 0; i--){
        servo.write(i); 
      }
    }
 }

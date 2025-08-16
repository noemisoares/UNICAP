#include <Servo.h>  
#define FALSE 0
#define TRIG_PIN 2
#define ECHO_PIN 3
#define TRIG_PIN_RE 8
#define ECHO_PIN_RE 9
#define FORWARD 'F'
#define BACKWARD 'B'
#define LEFT 'L'
#define RIGHT 'R'
#define CIRCLE 'C'
#define CROSS 'X'
#define TRIANGLE 'T'
#define SQUARE 'S'
#define START 'A'
#define PAUSE 'P'
 
unsigned long lastStopTime = 0;
const unsigned long stopDuration = 1000;

int valorLDR = 0;
int pinLDR = A0;
int LED1 = 13;
int LED2 = 12;
int SERVO_PIN = 11;
int angle = 0;
int in1 = 7;  
int in2 = 6;  
int in3 = 5;  
int in4 = 4;  
int vetN[4] = {in1, in2, in3, in4};
char cha; 

Servo servo;
void setup() {
  Serial.begin(9600);
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  pinMode(TRIG_PIN_RE, OUTPUT);
  pinMode(ECHO_PIN_RE, INPUT);
  pinMode(pinLDR, INPUT);
  pinMode(LED1,OUTPUT);
  pinMode(LED2,OUTPUT);
  servo.attach(SERVO_PIN);
  servo.write(0);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
  digitalWrite(LED1, LOW);
  digitalWrite(LED2, LOW);
}

void loop() {
 
  valorLDR = analogRead(pinLDR);
  bool dectL = dectLight(valorLDR);
  turnOnTheLight(dectL, LED1, LED2);

  if (Serial.available() > 0) {
    cha = Serial.read();
    delay(2);  // Aguarda a leitura do comando

    // Executa o comando recebido
    executeCommand(cha);
  }
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);
  int distance = medirDistancia();

  digitalWrite(TRIG_PIN_RE, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN_RE, LOW);
  int distanceRE = medirDistanciaRe();

  angle = moverServo(distance, angle);

  if(detectorRE(distanceRE, vetN)== false && detector(distance, vetN, angle) == true){
    mix(true, false, vetN);
  }
  if(detectorRE(distanceRE, vetN)== true && detector(distance, vetN, angle) == false){
    mix(false, true, vetN);
  }
  if(detectorRE(distanceRE, vetN)== false && detector(distance, vetN, angle) == false){
    mix(false, false, vetN);
  }
  if(detectorRE(distanceRE, vetN)== true && detector(distance, vetN, angle) == true){
    mix(true, true, vetN);
  }
  
  Serial.print("LDR: "); Serial.print(valorLDR);
  Serial.print(" | Front distance: "); Serial.println(distance);
  Serial.print(" | Rear distance : "); Serial.println(distanceRE);
  delay(20);
  
}

int medirDistancia() {
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);
  
  long duration = pulseIn(ECHO_PIN, HIGH);
  int distance = duration * 0.017;
  
  return distance;
}

int medirDistanciaRe() {
  digitalWrite(TRIG_PIN_RE, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN_RE, LOW);
  
  long duration = pulseIn(ECHO_PIN_RE, HIGH);
  int distanceRe = duration * 0.017;
  
  return distanceRe;
}

bool detector(int distance, int vet[], int angle) {
  if (distance <= 30) {
    servo.write(angle);
    return true;
  }
  return false;
}

bool detectorRE(int distance, int vet[]) {
  if (distance <= 50) {
    return true;
  }
  return false;
}

void mix(bool value, bool valueR, int vet[]) {
  if (value == true && valueR == false) {
    for (int i = 0; i < 4; i++) {
      digitalWrite(vet[i], LOW);
    }
    delay(20);
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);
  } else if (value == false && valueR == true) {
    for (int i = 0; i < 4; i++) {
      digitalWrite(vet[i], LOW);
    }
    delay(20);
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
    digitalWrite(in3, LOW);
    digitalWrite(in4, HIGH);
    
  } else if (value == true && valueR == true) {
    for (int i = 0; i < 4; i++) {
      digitalWrite(vet[i], LOW);
    }
    delay(20);
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    digitalWrite(in3, LOW);
    digitalWrite(in4, LOW);
  }
  else if (value == false && valueR == false){
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
    digitalWrite(in3, LOW);
    digitalWrite(in4, HIGH);
  }
}

bool dectLight(int LDR){
  if(LDR > 500){
  	return true;
  }else{
  	return false;
  }
}

void turnOnTheLight(bool dect, int LED,int LED2){
  if(dect == true){
  	digitalWrite(LED1,HIGH);
    digitalWrite(LED2,HIGH);
  }else{
  	digitalWrite(LED1,LOW);
    digitalWrite(LED2,LOW);    
  }
}
int moverServo(int distance, int angle) {
  for (int i = angle; i <= 180; i += 5) {
    servo.write(i);
    delay(20);
    if(medirDistancia() <= 30) return i;
  }
  
  // Movimento para trás
  for (int i = 180; i >= 0; i -= 5) {
    servo.write(i);
    delay(20);
    if(medirDistancia() <= 30) return i;
  }
  return angle;
}
void executeCommand(char command) {
  switch (command) {
    case FORWARD:
      moveForward();  // Mover para frente
      break;
    case BACKWARD:
      moveBackward();  // Mover para trás
      break;
    case LEFT:
      turnLeft();  // Virar para a esquerda
      break;
    case RIGHT:
      turnRight();  // Virar para a direita
      break;
    case CIRCLE:
      // Adicione a lógica para ação de CIRCLE aqui, se necessário
      break;
    case CROSS:
      stopMotors();  // Parar imediatamente
      break;
    case TRIANGLE:
      toggleLEDs();  // Alternar LEDs
      break;
    case SQUARE:
      sendStatus();  // Retornar o status ou qualquer outra operação de informação
      break;
    case START:
      startProcess();  // Iniciar um processo ou operação
      break;
    case PAUSE:
      pauseProcess();  // Pausar um processo ou operação
      break;
    default:
      // Caso o comando seja inválido
      break;
  }
}

// Funções de controle de movimento
void moveForward() {
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
}

void moveBackward() {
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
}

void turnLeft() {
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
}

void turnRight() {
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
}

void stopMotors() {
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
}

// Função para alternar os LEDs
void toggleLEDs() {
  static bool ledsOn = false;  // Variável para armazenar o estado dos LEDs
  if (ledsOn) {
    digitalWrite(LED1, LOW);
    digitalWrite(LED2, LOW);
  } else {
    digitalWrite(LED1, HIGH);
    digitalWrite(LED2, HIGH);
  }
  ledsOn = !ledsOn;  // Alterna o estado dos LEDs
}

// Funções para operações adicionais
void sendStatus() {
  Serial.println("Status: Motores e LEDs funcionando corretamente.");
}

void startProcess() {
  Serial.println("Processo iniciado.");
}

void pauseProcess() {
  Serial.println("Processo pausado.");
}

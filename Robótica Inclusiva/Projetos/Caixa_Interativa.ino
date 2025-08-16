#include <LiquidCrystal_I2C.h>

#include <Wire.h>
#include <Servo.h>


// LCD I2C
LiquidCrystal_I2C lcd(0x27, 16, 2); // Endereço 0x27, 16 colunas, 2 linhas

// Sensor ultrassônico 1
#define trig 10
#define echo 9

// Sensor ultrassônico 2
#define trig2 13
#define echo2 12

// Buzzer
#define buzzer 8

// LEDs
#define led1 6
#define led2 7

// Servo
#define servoPin 11
Servo meuServo;

// PIR
#define pirPin A0
bool pessoaDetectada = false;
unsigned long ultimoAviso = 0;
unsigned long tempoAviso = 8000;

float distance1, distance2;
bool doacaoDetectada = false;

void setup() {
  Serial.begin(9600);

  // Sensor 1
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);

  // Sensor 2
  pinMode(trig2, OUTPUT);
  pinMode(echo2, INPUT);

  pinMode(buzzer, OUTPUT);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(pirPin, INPUT);

  // LCD I2C
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Deixe sua");
  lcd.setCursor(0, 1);
  lcd.print("doacao aqui");

  meuServo.attach(servoPin);
  meuServo.write(0);
}

void loop() {
  // Verificar presença com PIR
  if (digitalRead(pirPin) == HIGH && millis() - ultimoAviso > tempoAviso) {
    pessoaDetectada = true;
    ultimoAviso = millis();

    // Mensagem no LCD
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Aproxime o");
    lcd.setCursor(0, 1);
    lcd.print("QR Code :)");

    // Som diferente
    tone(buzzer, 440);
    delay(200);
    tone(buzzer, 494);
    delay(200);
    noTone(buzzer);

    delay(3000);
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Deixe sua");
    lcd.setCursor(0, 1);
    lcd.print("doacao aqui");
  }

  // Medir distância do sensor 1
  distance1 = medirDistancia(trig, echo);
  // Medir distância do sensor 2
  distance2 = medirDistancia(trig2, echo2);

  Serial.print("Distancia1: ");
  Serial.println(distance1);
  Serial.print("Distancia2: ");
  Serial.println(distance2);

  if (((distance1 > 0 && distance1 <= 40) || (distance2 > 0 && distance2 <= 40)) && !doacaoDetectada) {
    doacaoDetectada = true;

    // Mensagem de agradecimento
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Agradecemos sua");
    lcd.setCursor(0, 1);
    lcd.print("doacao!");

    // Música
    tocarMusica();

    // LEDs
    piscarLEDs(5, 200);

    // Servo vai e volta
    meuServo.write(90);
    delay(500);
    meuServo.write(0);
    delay(500);
    meuServo.write(90);
    delay(500);
    meuServo.write(0);
    delay(500);

    delay(3000);
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Deixe sua");
    lcd.setCursor(0, 1);
    lcd.print("doacao aqui");
  }

  if (distance1 > 40 || distance2 > 40) {
    doacaoDetectada = false;
  }

  delay(300);
}

float medirDistancia(int trigPin, int echoPin) {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  return pulseIn(echoPin, HIGH) / 58.0;
}

void tocarMusica() {
  tone(buzzer, 523); delay(200);
  tone(buzzer, 587); delay(200);
  tone(buzzer, 659); delay(200);
  noTone(buzzer);
}

void piscarLEDs(int vezes, int intervalo) {
  for (int i = 0; i < vezes; i++) {
    digitalWrite(led1, HIGH);
    digitalWrite(led2, LOW);
    delay(intervalo);
    digitalWrite(led1, LOW);
    digitalWrite(led2, HIGH);
    delay(intervalo);
  }
  digitalWrite(led1, LOW);
  digitalWrite(led2, LOW);
}

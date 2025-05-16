#define TRIG_PIN 10
#define ECHO_PIN 11
#define SERVO_PIN 12

#include <Servo.h>

Servo servo;

void setup() {
    Serial.begin(9600);
    servo.attach(SERVO_PIN);
    pinMode(TRIG_PIN, OUTPUT);
    pinMode(ECHO_PIN, INPUT);
}

void loop() {
    for (int angle = 0; angle <= 180; angle++) {
        servo.write(angle);
        delay(30);
        
        int distance = medirDistancia();
        Serial.print(angle);
        Serial.print(",");
        Serial.print(distance);
        Serial.println(".");
    }

    for (int angle = 180; angle >= 0; angle--) {
        servo.write(angle); 
        delay(30);

        int distance = medirDistancia();
        Serial.print(angle);
        Serial.print(",");
        Serial.print(distance);
        Serial.println(".");
    }
}

int medirDistancia() {
    digitalWrite(TRIG_PIN, LOW);
    delayMicroseconds(2);
    digitalWrite(TRIG_PIN, HIGH);
    delayMicroseconds(10);
    digitalWrite(TRIG_PIN, LOW);

    long duration = pulseIn(ECHO_PIN, HIGH);
    int distance = duration * 0.034 / 2;

    return distance > 200 ? 200 : distance;
}

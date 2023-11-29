#include <Servo.h>

const int trigPin = 12;
const int echoPin = 11;
const int servoPin = 9;

Servo myServo;

void setup(){
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  myServo.attach(servoPin);
}

void loop(){
  long duration, distance;

  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoEPin, HIGH);

  distance = (duration / 2) * 0.0344;

  if (distance < 10){
    myServo.write(90);
    delay(500);
    myServo.write(0);
  }
  myServo.write(1000);
}
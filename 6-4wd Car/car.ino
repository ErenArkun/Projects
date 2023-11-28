const int motorA1 = 5;
const int motorA2 = 6;
const int motorB1 = 10;
const int motorB2 = 9;

void setup() {
    pinMode(motorA1, OUTPUT);
    pinMode(motorA2, OUTPUT);
    pinMode(motorB1, OUTPUT);
    pinMode(motorB2, OUTPUT);
    Serial.begin(9600);
}

void loop() {
    if (Serial.available() > 0) {
        state = Serial.read();
    }

    if (state == 'F') {
        digitalWrite(motorA1, HIGH);
        digitalWrite(motorA2, LOW);
        digitalWrite(motorB1, HIGH);
        digitalWrite(motorB2, LOW);
    }

    else if (state == 'B') {
        digitalWrite(motorA1, LOW);
        digitalWrite(motorA2, HIGH);
        digitalWrite(motorB1, LOW);
        digitalWrite(motorB2, HIGH);
    }

    else if (state == 'L') {
        digitalWrite(motorA1, HIGH);
        digitalWrite(motorA2, LOW);
        digitalWrite(motorB1, LOW);
        digitalWrite(motorB2, HIGH);
    }

    else if (state == 'R') {
        digitalWrite(motorA1, LOW);
        digitalWrite(motorA2, HIGH);
        digitalWrite(motorB1, HIGH);
        digitalWrite(motorB2, LOW);
    }

    else if (state == 'S') {
        digitalWrite(motorA1, LOW);
        digitalWrite(motorA2, LOW);
        digitalWrite(motorB1, LOW);
        digitalWrite(motorB2, LOW);
    }
}

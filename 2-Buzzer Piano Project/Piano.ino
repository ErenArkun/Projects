const int buttonPin1 = 2;
const int buttonPin2 = 3;
const int buttonPin3 = 4;
const int buttonPin4 = 5;
const int buttonPin5 = 6;
const int buttonPin6 = 7;
const int buttonPin7 = 8;
const int buttonPin8 = 9;

const int speakerPin = 9;

void setup(){
    pinMode(buttonPin1, INPUT_PULLUP);
    pinMode(buttonPin2, INPUT_PULLUP);
    pinMode(buttonPin3, INPUT_PULLUP);
    pinMode(buttonPin4, INPUT_PULLUP);
    pinMode(buttonPin5, INPUT_PULLUP);
    pinMode(buttonPin6, INPUT_PULLUP);
    pinMode(buttonPin7, INPUT_PULLUP);
    pinMode(buttonPin8, INPUT_PULLUP);

    pinMode(speakerPin, OUTPUT);
}

void loop(){
    if (digitalRead(buttonPin1) == LOw){
        playNote(0);
        delay(100);
    }

    if (digitalRead(buttonPin2) == LOw){
        playNote(1);
        delay(100);
    }

    if (digitalRead(buttonPin3) == LOw){
        playNote(2);
        delay(100);
    }

    if (digitalRead(buttonPin4) == LOw){
        playNote(3);
        delay(100);
    }

    if (digitalRead(buttonPin5) == LOw){
        playNote(4);
        delay(100);
    }

    if (digitalRead(buttonPin6) == LOw){
        playNote(5);
        delay(100);
    }

    if (digitalRead(buttonPin7) == LOw){
        playNote(6);
        delay(100);
    }

    if (digitalRead(buttonPin8) == LOw){
        playNote(7);
        delay(100);
    }
  
}

void playNote(int buttonIndex){
    int frequencies[] = {261, 294, 329, 349, 392, 440, 493};
    int frequency = frequencies[buttonIndex];

    tone(speakerPin, frequency, 200);
    delay(10);
    noTone(speakerPin);
}
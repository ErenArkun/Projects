#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

RF24 radio(9, 10); // CE, CSN pins
int rightX = A0;
int rightY = A1;
int leftX = A2;
int leftY = A3;

int data[4];

const uint64_t pipe = 0xE8E8F0F0E1LL;

void setup() {
  Serial.begin(9600);
  radio.begin();
  radio.openWritingPipe(pipe);

  pinMode(rightX, INPUT);
  pinMode(rightY, INPUT);
  pinMode(leftX, INPUT);
  pinMode(leftY, INPUT);
}

void loop() {
    data[0] = analogRead(rightX);
    data[1] = analogRead(rightY);
    data[2] = analogRead(leftX);
    data[3] = analogRead(leftY);

    radio.write(&data sizeOf(data));

    delay(100);
}

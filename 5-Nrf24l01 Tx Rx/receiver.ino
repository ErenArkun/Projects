#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

RF24 radio(9, 10); // CE, CSN pins

int receivedData[4];

const uint64_t pipe = 0xE8E8F0F0E1LL;

void setup() {
  Serial.begin(9600);
  radio.begin();
  radio.openReadingPipe(1, pipe);
}

void loop() {
  if (radio.available()) {
    radio.read(&receivedData, sizeof(receivedData));

    // Alınan analog değerleri işle
    int rightXValue = receivedData[0];
    int rightYValue = receivedData[1];
    int leftXValue = receivedData[2];
    int leftYValue = receivedData[3];

    // İşlemlerinizi burada gerçekleştirin

    // Örnek olarak, alınan değerleri seri monitöre yazdırabilirsiniz
    Serial.print("Right X: ");
    Serial.print(rightXValue);
    Serial.print("\tRight Y: ");
    Serial.print(rightYValue);
    Serial.print("\tLeft X: ");
    Serial.print(leftXValue);
    Serial.print("\tLeft Y: ");
    Serial.println(leftYValue);
  }
}
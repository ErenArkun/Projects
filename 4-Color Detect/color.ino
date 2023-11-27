// TCS3200 Pin Bağlantıları
const int S2 = 2;
const int S3 = 3;
const int OUT = 4;

void setup() {
  Serial.begin(9600);

  // TCS3200 pinlerini giriş/çıkış olarak ayarla
  pinMode(S2, OUTPUT);
  pinMode(S3, OUTPUT);
  pinMode(OUT, INPUT);

  // Frekans ölçme için varsayılan değerleri ayarla
  digitalWrite(S2, LOW);
  digitalWrite(S3, LOW);
}

void loop() {
  // Renk ölçümü
  int redValue, greenValue, blueValue;

  // Kırmızı renk ölçümü
  digitalWrite(S2, LOW);
  digitalWrite(S3, LOW);
  redValue = pulseIn(OUT, digitalRead(OUT) == HIGH ? LOW : HIGH);

  // Yeşil renk ölçümü
  digitalWrite(S2, HIGH);
  digitalWrite(S3, HIGH);
  greenValue = pulseIn(OUT, digitalRead(OUT) == HIGH ? LOW : HIGH);

  // Mavi renk ölçümü
  digitalWrite(S2, LOW);
  digitalWrite(S3, HIGH);
  blueValue = pulseIn(OUT, digitalRead(OUT) == HIGH ? LOW : HIGH);

  // Renkleri tanıma
  if (redValue < 100 && greenValue < 100 && blueValue < 100) {
    Serial.println("Black");
  } else if (redValue > 200 && greenValue > 200 && blueValue > 200) {
    Serial.println("White");
  } else if (redValue > 200 && greenValue < 100 && blueValue < 100) {
    Serial.println("Red");
  } else if (redValue > 200 && greenValue > 200 && blueValue < 100) {
    Serial.println("Yellow");
  } else if (redValue < 100 && greenValue < 100 && blueValue > 200) {
    Serial.println("Blue");
  } else if (redValue > 200 && greenValue < 100 && blueValue > 200) {
    Serial.println("Purple");
  } else if (redValue > 200 && greenValue > 100 && blueValue < 100) {
    Serial.println("Orange");
  }

  // Biraz bekleyin
  delay(500);
}

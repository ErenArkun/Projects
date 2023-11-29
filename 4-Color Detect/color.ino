const int S2 = 2;
const int S3 = 3;
const int OUT = A0;

void setup() {
  Serial.begin(9600);
  pinMode(S2, OUTPUT);
  pinMode(S3, OUTPUT);
  pinMode(OUT, INPUT);
  digitalWrite(S2, LOW);
  digitalWrite(S3, LOW);
}

void loop() {
  int redValue, greenValue, blueValue;

  digitalWrite(S2, LOW);
  digitalWrite(S3, LOW);
  redValue = pulseIn(OUT, HIGH, 1000000);

  digitalWrite(S2, HIGH);
  digitalWrite(S3, HIGH);
  greenValue = pulseIn(OUT, HIGH, 1000000);

  digitalWrite(S2, LOW);
  digitalWrite(S3, HIGH);
  blueValue = pulseIn(OUT, HIGH, 1000000);

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
  } else {
    Serial.println("Diğer Renk");
  }

  delay(500);
}
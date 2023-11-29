#define SensorSol 10
#define SensorOrta 11
#define SensorSag 12

void setup() {
  pinMode(SensorSol, INPUT);
  pinMode(SensorOrta, INPUT);
  pinMode(SensorSag, INPUT);
  Serial.begin(9600);
  Serial.println("Cizgi Sensoru Testi");
  delay(2000);
}

void loop() {
  Serial.print(digitalRead(SensorSol));
  Serial.print(",");
  Serial.print(digitalRead(SensorOrta));
  Serial.print(",");
  Serial.println(digitalRead(SensorOrta));
  delay(100);
}

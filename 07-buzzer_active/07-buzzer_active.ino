const int buzzPin = 3;

void setup() {
  pinMode(buzzPin, OUTPUT);
}

void loop() {
  digitalWrite(buzzPin, HIGH);
  delay(500);
  digitalWrite(buzzPin, LOW);
  delay(3000);
}

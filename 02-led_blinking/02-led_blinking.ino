const int ledPin = 10;
//#define ledPin 10

void setup() {
  pinMode(ledPin, OUTPUT);
  //pinMode(ledPin, INPUT); // less bright light
}

void loop() {
  digitalWrite(ledPin, HIGH);
  delay(1000);
  digitalWrite(ledPin, LOW);
  delay(1000);
}
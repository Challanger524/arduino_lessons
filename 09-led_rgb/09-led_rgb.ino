const int redPin = 11;
const int bluePin = 10;
const int greenPin = 9;

void setup() {
  pinMode(redPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
  pinMode(greenPin, OUTPUT);
}

void loop() {
  for (int i = 0; i < 255; i++) {
    analogWrite(redPin, i);
    analogWrite(bluePin, 128 - i);
    analogWrite(greenPin, 255 - i);
    delay(2);
  }

  for (int i = 255; i > 0; i--) {
    analogWrite(redPin, i);
    analogWrite(bluePin, 128 - i);
    analogWrite(greenPin, 255 - i);
    delay(2);
  }
}

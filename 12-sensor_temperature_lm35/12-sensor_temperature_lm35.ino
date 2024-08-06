const int temprPin = A0; // temperature sensor pin

void setup() {
  Serial.begin(9600);
  //pinMode(A0, INPUT);
  pinMode(temprPin, INPUT);
}

void loop() {
  const int sensor = analogRead(temprPin);

  Serial.print(sensor * 5.0 / 1023.0); // voltage
  Serial.print("V (");
  Serial.print(sensor);
  Serial.print(")");

  const int tempr = (sensor * 125) >> 8;
  Serial.print(" = ");
  Serial.print(tempr);
  Serial.print("C");

  Serial.print("\n");
  delay(500);
}

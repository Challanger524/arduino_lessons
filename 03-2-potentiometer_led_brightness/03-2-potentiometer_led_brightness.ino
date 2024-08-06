const int ledPin = 11;

void setup() {
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  const int sensor = analogRead(A0);            // read the input on analog pin 0:
  const float voltage = sensor * 5.0 / 1023.0;  // convert the analog reading (which goes from 0 - 1023) to a voltage (0 - 5V):
  static int sensorPrev = sensor;               // previous val (to discard small natural deviations)

  Serial.print(voltage);  // print out the value you read:
  Serial.print("V (");
  Serial.print(sensor);
  Serial.print(")");

  if (abs(sensor - sensorPrev) > 2) {
    sensorPrev = sensor;

    // Since my potentiometer is working between [0:400) and if reversed - [1023:603) // (400 units)
    // boundaries are measured dynamically
    static int max = 0;
    static int min = 1023;

    if (sensor > max) max = sensor;
    if (sensor < min) min = sensor;

    Serial.print(" [");
    Serial.print(min);
    Serial.print(":");
    Serial.print(max);
    Serial.print("]");

#if 0 // using `map()` - less precision
    const int bright = map(sensor, min, max, 0, 255);
#else
    const float percent = static_cast<float>(sensor - min) / (max - min);
    Serial.print(" ");
    Serial.print(int(percent * 100));
    Serial.print("\%");

    const int bright = 255.0 * percent;
#endif

    Serial.print(" = ");
    Serial.print(bright);

    analogWrite(ledPin, bright);
  }

  Serial.print("\n");
  delay(300);
}

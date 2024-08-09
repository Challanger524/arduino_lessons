#include <Servo.h>  // https://www.arduino.cc/reference/en/libraries/servo

constexpr uint8_t servoPin = 9;
Servo servo;

void setup() {
  servo.attach(servoPin);  //, 544, 2400);
  servo.write(0);
  delay(1000);
}

void loop() {
  constexpr uint64_t milsec = 25; // delay
  constexpr int srvoMin = 0;
  constexpr int srvoMax = 175;

  for (int i = srvoMin; i <= srvoMax; i++) {
    servo.write(i);
    delay(milsec);
  }
  delay(200);

  for (int i = srvoMax; i >= srvoMin; i--) {
    servo.write(i);
    delay(milsec);
  }
  delay(200);
}

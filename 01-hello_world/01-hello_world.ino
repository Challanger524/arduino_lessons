#include <LiquidCrystal.h>

void setup() { // put your setup code here, to run once:
  Serial.begin(9600); // Set the serial port baud rate to `9600`
}

int val;

void loop() { // put your main code here, to run repeatedly:
  val = Serial.read(); // read the instruction or character from PC to Arduino, and assign them to Val.
  if (val == 'R') { // determine if the instruction or character received is “R”.
    Serial.println("Hello World by Keyestudio!");  // Serial port printing
  }
  else Serial.print(val);

  Serial.println("Hello World!"); // Serial port printing
  delay(1000); // Delay of 1 second
}

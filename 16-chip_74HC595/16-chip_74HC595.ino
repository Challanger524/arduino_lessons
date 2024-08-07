const int dataPin = 2;   // #14 DS Serial data input
const int clockPin = 5;  // #11 SH_CP Shift Register Clock Uoutput
const int latchPin = 4;  // #12 ST_CP Storage Register Clock Input

void setup() {
  pinMode(dataPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(latchPin, OUTPUT);
}

void loop() {
  for (int i = 0; i < 16; i++) {  // 3-LED bit counter
    updateLEDs(i << 1);           // bitshift 1 coz chip `Q0` output #15 is skipped
    delay(1000);
  }
}

void updateLEDs(const int byte) {
  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, MSBFIRST, byte);  // serial data “output”, high level first
  digitalWrite(latchPin, HIGH);
}

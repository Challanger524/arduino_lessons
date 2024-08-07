#define DECODE_NEC
#include <IRremote.hpp>

#define IR_RECEIVE_PIN 11

#if !defined(STR_HELPER)
#define STR_HELPER(x) #x
#define STR(x) STR_HELPER(x)
#endif
//const int remotePin = 11;

void setup() {
  Serial.begin(9600);
  while (!Serial)
    ;  // Wait for Serial to become available. Is optimized away for some cores.
  // Just to know which program is running on my Arduino
  Serial.println();
  Serial.println(F("START " __FILE__ " from " __DATE__ "\r\nUsing library version: " VERSION_IRREMOTE));
  // Start the receiver and if not 3. parameter specified, take LED_BUILTIN pin from the internal boards definition as default feed
  IrReceiver.begin(IR_RECEIVE_PIN, ENABLE_LED_FEEDBACK);
  Serial.print(F("Ready to receive IR signals of protocols: "));
  printActiveIRProtocols(&Serial);
  Serial.println(F("at pin: " STR(IR_RECEIVE_PIN)));
  Serial.println();
}

void loop() {
  /*
   * Check if received data is available and if yes, try to decode it.
   * Decoded result is in the IrReceiver.decodedIRData structure.
   *
   * E.g. command is in IrReceiver.decodedIRData.command
   * address is in command is in IrReceiver.decodedIRData.address
   * and up to 32 bit raw data in IrReceiver.decodedIRData.decodedRawData
   */
  if (IrReceiver.decode()) {
    // Print a summary of received data
    if (IrReceiver.decodedIRData.protocol == UNKNOWN) {
      Serial.println(F("Received noise or an unknown (or not yet enabled) protocol"));
      // We have an unknown protocol here, print extended info
      IrReceiver.printIRResultRawFormatted(&Serial, true);
      IrReceiver.resume();  // Do it here, to preserve raw data for printing with printIRResultRawFormatted()
    } else {
      IrReceiver.resume();  // Early enable receiving of the next IR frame
      IrReceiver.printIRResultShort(&Serial);
      //IrReceiver.printIRSendUsage(&Serial);
    }
    Serial.println();

    // Finally, check the received data and perform actions according to the received command
    switch (IrReceiver.decodedIRData.command) {
      case 0x40: Serial.print("'OK'"); break;

      case 0x46: Serial.print("'Up'"); break;
      case 0x15: Serial.print("'Down'"); break;

      case 0x52: Serial.print("'0'"); break;
      case 0x16: Serial.print("'1'"); break;
      case 0x19: Serial.print("'2'"); break;

      case 0x42: Serial.print("'*'"); break;
      default:   Serial.print("'?'");
    }
    Serial.print("\n\n");
  }
}

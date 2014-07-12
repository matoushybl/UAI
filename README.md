UAI
===

Universal Arduino interface for communication with top level cpu - like RPi or Android device

Usage
=====
```C++
#include <UAI.h>
#include <inttypes.h>

#define COMMAND_ID 5

UAI uai;

void setup() {
 Serial.begin(115200);
 uai.setStream(Serial); // sets communication device - can be Serial, Wire, etc. everything that inherits from Stream class
 uai.registerCallback(COMMAND_ID, callback);
}

void loop() {
  uai.loop();
}

void callback(uint8_t data[]) {
 Serial.println("callback invoked, 5 received");
}
```

On the top level side, you send bytes (therefore not working in Arduino Serial Monitor) using this protocol:

```C
uint8_t data = {NUMBER_OF_BYTES, COMMAND_ID, DATA, DATA, DATA, ...};
```
NUMBER_OF_BYTES is the length of your array -1, NUMBER_OF_BYTES is not included.
In the callback you get that array with NUMBER_OF_BYTES excluded.

NOTE: there is no timeout implemented so if you do not send the amount of data you "promised" to send, your program will wait till the amount is received.

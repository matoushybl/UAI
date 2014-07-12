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
uint8_t data[] = {NUMBER_OF_BYTES, COMMAND_ID, DATA, DATA, DATA, ...};
```
NUMBER_OF_BYTES is the length of your array -1, NUMBER_OF_BYTES is not included.
In the callback you get that array with NUMBER_OF_BYTES excluded.

NOTE: there is no timeout implemented so if you do not send the amount of data you "promised" to send, your program will wait till the amount is received.

License
=======
 The MIT License (MIT)

 Copyright (c) 2014 Matouš Hýbl

 Permission is hereby granted, free of charge, to any person obtaining a copy
 of this software and associated documentation files (the "Software"), to deal
 in the Software without restriction, including without limitation the rights
 to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 copies of the Software, and to permit persons to whom the Software is
 furnished to do so, subject to the following conditions:

 The above copyright notice and this permission notice shall be included in all
 copies or substantial portions of the Software.

 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 SOFTWARE.

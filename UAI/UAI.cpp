/*
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
 */

#include "Arduino.h"
#include "Stream.h"
#include <inttypes.h>
#include "UAI.h"

UAI::UAI() {
	lastCallbackIndex = 0;
}

void UAI::setStream(Stream &_stream) {
	stream = &_stream;
}

void UAI::loop() {
	if (stream->available()) {
		uint8_t numOfBytes = stream->read();
		uint8_t data[numOfBytes];
		while (stream->available() < numOfBytes);
		stream->readBytes((char *)data, numOfBytes); // cast because of lower versions of Arduino than 1.5
		for(uint8_t i = 0; i < numOfBytes; i++) {
			if(data[0] == commands[i]){
				callbacks[i](data);
			}
		}
	}
}

void UAI::registerCallback(uint8_t code, void (*callback)(uint8_t[])) {
	callbacks[lastCallbackIndex] = callback;
	commands[lastCallbackIndex] = code;
	lastCallbackIndex++;
}

void UAI::write(uint8_t *data, uint8_t size) {
	stream->write(data, size);
}

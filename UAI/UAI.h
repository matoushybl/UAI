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

#ifndef UAI_h
#define UAI_h

#include "Arduino.h"
#include "HardwareSerial.h"

#define MAX_CALLBACKS 50

class UAI {

private:
	HardwareSerial* _serial;
	void(*callbacks[MAX_CALLBACKS])(int[]);
	int commands[MAX_CALLBACKS];
	int lastCallbackIndex;

public:
	UAI();
	void loop();
	void registerCallback(int code, void (*)(int[]));
	void setSerial(HardwareSerial &serial);
};

#endif

#pragma once
#include <Arduino.h>
#include "Button.h"

#define ENCODER_DELAY 30

struct Encoder {
    uint8_t pinRight;
    uint8_t pinLeft;

    Button button;  

    uint8_t lastEncoded;
    bool left;
    bool right;
    unsigned long rotateTimer;
};

void encoderTick(Encoder &e);
/*
Encoder enc = {pinRight, pinLeft, {Button(pin)}};

pinMode(enc.pinRight, INPUT_PULLUP);
pinMode(enc.pinLeft, INPUT_PULLUP);
pinMode(enc.button.pin, INPUT_PULLUP);

encoderTick(enc);

if (enc.right) {
	Keyboard.clickMultimediaKey(KEY_VOL_UP);
	enc.right = false;
}

if (enc.left) {
	Keyboard.clickMultimediaKey(KEY_VOL_DOWN);
	enc.left = false;
}

if (enc.button.click) {
	
	enc.button.click = 0;
}

if (enc.button.press) {
	
	enc.button.press = 0;
}

if (enc.button.hold) {
	
}

if (enc.button.released) {
	
	enc.button.released = 0;
}
*/
#pragma once
#include <Arduino.h>

#define DEBOUNCE_TIME 100
#define HOLD_TIME     270
#define DOUBLE_TIME   250

struct Button {
    uint8_t pin;

    bool state;
    bool lastState;

    bool click;
    bool dbl;
    bool press;
    bool hold;
    bool released;

    bool waitingDouble;
    bool holdMode;

    unsigned long changeTimer;
    unsigned long doubleTimer;
};

void buttonTick(Button &b);

/*
Button btn = {pin};

buttonTick(btn);

if (btn.click) {

	btn.click = 0;
}

if (btn.dbl) {

    btn.dbl = 0;
}

if (btn.press) {

    btn.press = 0;
}

if (btn.hold) {

}

if (btn.released) {

	btn.released = 0;
}
*/
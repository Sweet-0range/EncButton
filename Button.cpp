#include "Button.h"

void buttonTick(Button &b) {

  bool reading = !digitalRead(b.pin);

  if (reading != b.state &&
      millis() - b.changeTimer > DEBOUNCE_TIME) {
    b.state = reading;
    b.changeTimer = millis();
  }

  if (b.state) {
    if (!b.holdMode &&
        millis() - b.changeTimer > HOLD_TIME) {

      b.holdMode = true;
      b.press = true;
      b.waitingDouble = false;
    }

    if (b.holdMode) {
      b.hold = true;
    }
  }

  if (!b.state && b.lastState) {

    if (b.holdMode) {
      b.released = true;
      b.holdMode = false;
      b.hold = false;
    }
    else {
      if (b.waitingDouble) {
        b.dbl = true;
        b.waitingDouble = false;
      } else {
        b.waitingDouble = true;
        b.doubleTimer = millis();
      }
    }
  }

  if (b.waitingDouble &&
      millis() - b.doubleTimer > DOUBLE_TIME) {
    b.click = true;
    b.waitingDouble = false;
  }

  b.lastState = b.state;
}
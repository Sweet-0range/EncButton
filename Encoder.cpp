#include "Encoder.h"

void encoderTick(Encoder &e) {
    buttonTick(e.button);

    int MSB = !digitalRead(e.pinRight);
    int LSB = !digitalRead(e.pinLeft);

    int encoded = (MSB << 1) | LSB;
    int sum = (e.lastEncoded << 2) | encoded;

    switch(sum) {
        // clockwise
        case 0b1101:
        case 0b0100:
        case 0b0010:
        case 0b1011:
            e.stepAccum++;
            break;

        // counter-clockwise
        case 0b1110:
        case 0b0111:
        case 0b0001:
        case 0b1000:
            e.stepAccum--;
            break;
    }

    // 1 щелчок = 4 перехода
    if (e.stepAccum >= 4) {
        e.right = true;
        e.stepAccum = 0;
    }
    else if (e.stepAccum <= -4) {
        e.left = true;
        e.stepAccum = 0;
    }

    e.lastEncoded = encoded;
}

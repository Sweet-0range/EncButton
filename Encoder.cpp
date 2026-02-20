#include "Encoder.h"

void encoderTick(Encoder &e) {
    buttonTick(e.button);

    // Инвертируем сигналы (active-low)
    int MSB = !digitalRead(e.pinRight);
    int LSB = !digitalRead(e.pinLeft);

    int encoded = (MSB << 1) | LSB;
    int sum = (e.lastEncoded << 2) | encoded;

    unsigned long now = millis();

    // Проверка переходов с задержкой
    if (now - e.rotateTimer >= ENCODER_DELAY) {
        switch(sum) {
            case 0b1101: case 0b0100: case 0b0010: case 0b1011:
                e.right = true;
                e.rotateTimer = now;  // обновляем таймер
                break;
            case 0b1110: case 0b0111: case 0b0001: case 0b1000:
                e.left = true;
                e.rotateTimer = now;  // обновляем таймер
                break;
        }
    }

    e.lastEncoded = encoded;
}
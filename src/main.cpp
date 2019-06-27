//
// Created by imanuel on 26.06.19.
//

#include <Arduino.h>
#include "TimeLeds.h"

auto leds = new TimeLeds();

void setup() {
    pinMode(1, OUTPUT);
    for (int i = 4; i < 14; ++i) {
        pinMode(i, OUTPUT);
    }

    leds->setup();
    Serial.begin(9600);
}

void loop() {
    leds->displayCurrentTime();
}
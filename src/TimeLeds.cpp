//
// Created by imanuel on 26.06.19.
//

#include "TimeLeds.h"

void TimeLeds::displayCurrentTime() {
    if (millis() - lastMillis > 500) {
        lastMillis = millis();
        auto now = RTC_DS3231::now();
        auto hour = now.hour();
        auto minute = now.minute();

        if (hour == 0) {
            for (int i = 9; i < 13; ++i) {
                digitalWrite(i, LOW);
            }
        } else {
            displayHour(hour);
        }

        if (minute == 0) {
            digitalWrite(1, LOW);
            for (int i = 4; i < 9; ++i) {
                digitalWrite(i, LOW);
            }
        } else {
            displayMinutes(minute);
        }
    }
}

void TimeLeds::displayHour(uint8_t hour) const {
    if (hour / 16 != 0) {
        digitalWrite(13, HIGH);
    } else {
        digitalWrite(13, LOW);
    }

    if ((hour % 16) / 8 != 0) {
        digitalWrite(12, HIGH);
    } else {
        digitalWrite(12, LOW);
    }

    if (((hour % 16) % 8) / 4 != 0) {
        digitalWrite(11, HIGH);
    } else {
        digitalWrite(11, LOW);
    }

    if ((((hour % 16) % 8) % 4) / 2 != 0) {
        digitalWrite(10, HIGH);
    } else {
        digitalWrite(10, LOW);
    }

    if (((((hour % 16) % 8) % 4) % 2) / 1 != 0) {
        digitalWrite(9, HIGH);
    } else {
        digitalWrite(9, LOW);
    }
}

void TimeLeds::displayMinutes(uint8_t minute) const {
    if (minute / 32 != 0) {
        digitalWrite(8, HIGH);
    } else {
        digitalWrite(8, LOW);
    }

    if ((minute % 32) / 16 != 0) {
        digitalWrite(7, HIGH);
    } else {
        digitalWrite(7, LOW);
    }

    if (((minute % 32) % 16) / 8 != 0) {
        digitalWrite(6, HIGH);
    } else {
        digitalWrite(6, LOW);
    }

    if ((((minute % 32) % 16) % 8) / 4 != 0) {
        digitalWrite(5, HIGH);
    } else {
        digitalWrite(5, LOW);
    }

    if (((((minute % 32) % 16) % 8) % 4) / 2 != 0) {
        digitalWrite(4, HIGH);
    } else {
        digitalWrite(4, LOW);
    }

    if ((((((minute % 32) % 16) % 8) % 4) % 2) / 1 != 0) {
        digitalWrite(1, HIGH);
    } else {
        digitalWrite(1, LOW);
    }
}

void TimeLeds::setup() {
    if (!rtc.begin()) {
        while (1);
    }
    lastMillis = millis();
}

TimeLeds::TimeLeds() : rtc() {}

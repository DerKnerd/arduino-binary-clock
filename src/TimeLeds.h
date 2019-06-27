//
// Created by imanuel on 26.06.19.
//

#ifndef BINARY_CLOCK_TIMELEDS_H
#define BINARY_CLOCK_TIMELEDS_H

#include <Arduino.h>
#include <RTClib.h>
#include <Wire.h>

class TimeLeds {
public:
    TimeLeds();

    void displayCurrentTime();

    void setup();

private:
    RTC_DS3231 rtc;
    long lastMillis;

    void displayHour(uint8_t hour) const;

    void displayMinutes(uint8_t minute) const;
};


#endif //BINARY_CLOCK_TIMELEDS_H

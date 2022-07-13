#ifndef DIGITAL_WATCH_HPP
#define DIGITAL_WATCH_HPP

#include "raylib.h"

class DigitalWatch
{
private:
    const Texture2D background = LoadTexture("assets/digital_watch_background.png");
    const Texture2D digitsTexture = LoadTexture("assets/digital_watch_digits.png");
    constexpr static float digitWidth = 32;
    constexpr static float digitHeight = 72;
    constexpr static int numDigits = 10;

    int hours;
    int minutes;

    void drawDigit(int digit, float x, float y);

public:
    void draw();
};

#endif
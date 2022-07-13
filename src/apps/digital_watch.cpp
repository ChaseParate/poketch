#include "digital_watch.hpp"

#include <ctime>
#include <string>
#include "raylib.h"

#include "../constants.hpp"

void DigitalWatch::drawDigit(int digit, float x, float y)
{
    DrawTexturePro(digitsTexture,
                   {digit * (digitWidth + 8), 0, digitWidth, digitHeight},
                   {x, y, digitWidth, digitHeight},
                   {0, 0}, 0, WHITE);
}

void DigitalWatch::draw()
{
    std::time_t t = std::time(0);
    std::tm *now = std::localtime(&t);

    hours = now->tm_hour;
    minutes = now->tm_min;
    separatorBlink = now->tm_sec % 2 == 1;

    DrawTextureV(background, {0, 0}, WHITE);
    drawDigit(hours / numDigits, 8, 40);
    drawDigit(hours % numDigits, 48, 40);
    drawDigit(minutes / numDigits, 104, 40);
    drawDigit(minutes % numDigits, 144, 40);
    if (separatorBlink)
    {
        DrawRectangle(88, 57, 8, 8, foregroundColor);
        DrawRectangle(88, 88, 8, 8, foregroundColor);
    }
}
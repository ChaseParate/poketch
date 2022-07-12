#ifndef CONSTANTS_HPP
#define CONSTANTS_HPP

#include "raylib.h"

const int gameWidth = 256;
const int gameHeight = 192;

const int windowScale = 3;
const int windowWidth = gameWidth * windowScale;
const int windowHeight = gameHeight * windowScale;

const int poketchWidth = 192;
const int poketchHeight = 160;
const Vector2 poketchOffset = {16, 16};

const Color backgroundColor = {112, 176, 112, 255};
const Color foregroundColor = {56, 80, 48, 255};

const float digitalWatchDigitWidth = 32;
const float digitalWatchDigitHeight = 72;
const int digitalWatchNumDigits = 10;

#endif
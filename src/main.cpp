#include <ctime>
#include <string>

#include "raylib.h"

int main()
{
    const int gameWidth = 256;
    const int gameHeight = 192;

    const int poketchWidth = 192;
    const int poketchHeight = 160;
    const Vector2 poketchOffset = {16, 16};

    const int windowScale = 3;
    const int windowWidth = gameWidth * windowScale;
    const int windowHeight = gameHeight * windowScale;

    InitWindow(windowWidth, windowHeight, "Pokétch");
    SetTargetFPS(60);

    RenderTexture2D gameScreen = LoadRenderTexture(gameWidth, gameHeight);
    RenderTexture2D poketchScreen = LoadRenderTexture(poketchWidth, poketchHeight);

    const Color backgroundColor = {112, 176, 112, 255};
    const Color foregroundColor = {56, 80, 48, 255};
    const Texture2D borderTexture = LoadTexture("assets/border_plat.png");

    const Texture2D digitalWatchBackground = LoadTexture("assets/digital_watch_background.png");
    const float digitalWatchDigitWidth = 32;
    const float digitalWatchDigitHeight = 72;
    const int digitalWatchNumDigits = 10;
    const Texture2D digitalWatchDigitsTexture = LoadTexture("assets/digital_watch_digits.png");
    Rectangle digitalWatchDigitBoundingBoxes[digitalWatchNumDigits];
    for (int i = 0; i < digitalWatchNumDigits; i++)
    {
        digitalWatchDigitBoundingBoxes[i] = {i * (digitalWatchDigitWidth + 8), 0, digitalWatchDigitWidth, digitalWatchDigitHeight};
    }

    int hours;
    int minutes;
    bool colonBlink;

    while (!WindowShouldClose())
    {
        std::time_t t = std::time(0);
        std::tm *now = std::localtime(&t);

        hours = now->tm_hour;
        minutes = now->tm_min;
        colonBlink = now->tm_sec % 2 == 1;

        BeginDrawing();

        BeginTextureMode(poketchScreen);
        ClearBackground(backgroundColor);
        DrawTextureV(digitalWatchBackground, {0, 0}, WHITE);
        DrawTexturePro(digitalWatchDigitsTexture, digitalWatchDigitBoundingBoxes[hours / digitalWatchNumDigits], {8, 40, digitalWatchDigitWidth, digitalWatchDigitHeight}, {0, 0}, 0, WHITE);
        DrawTexturePro(digitalWatchDigitsTexture, digitalWatchDigitBoundingBoxes[hours % digitalWatchNumDigits], {48, 40, digitalWatchDigitWidth, digitalWatchDigitHeight}, {0, 0}, 0, WHITE);
        DrawTexturePro(digitalWatchDigitsTexture, digitalWatchDigitBoundingBoxes[minutes / digitalWatchNumDigits], {104, 40, digitalWatchDigitWidth, digitalWatchDigitHeight}, {0, 0}, 0, WHITE);
        DrawTexturePro(digitalWatchDigitsTexture, digitalWatchDigitBoundingBoxes[minutes % digitalWatchNumDigits], {144, 40, digitalWatchDigitWidth, digitalWatchDigitHeight}, {0, 0}, 0, WHITE);
        if (colonBlink)
        {
            DrawRectangle(88, 57, 8, 8, foregroundColor);
            DrawRectangle(88, 88, 8, 8, foregroundColor);
        }
        EndTextureMode();

        BeginTextureMode(gameScreen);
        ClearBackground(BLACK);
        DrawTexture(borderTexture, 0, 0, WHITE);
        DrawTexturePro(poketchScreen.texture, {0, 0, poketchWidth, -poketchHeight}, {poketchOffset.x, poketchOffset.y, poketchWidth, poketchHeight}, {0, 0}, 0, WHITE);
        EndTextureMode();

        DrawTexturePro(gameScreen.texture, {0, 0, gameWidth, -gameHeight}, {0, 0, windowWidth, windowHeight}, {0, 0}, 0, WHITE);

        EndDrawing();
    }

    UnloadRenderTexture(gameScreen);
    UnloadRenderTexture(poketchScreen);
    CloseWindow();

    return 0;
}
#include <ctime>
#include <string>

#include "raylib.h"

#include "constants.hpp"

int main()
{
    InitWindow(windowWidth, windowHeight, "Pokétch");
    SetTargetFPS(60);

    RenderTexture2D gameScreen = LoadRenderTexture(gameWidth, gameHeight);
    RenderTexture2D poketchScreen = LoadRenderTexture(poketchWidth, poketchHeight);

    const Texture2D borderTexture = LoadTexture("assets/border_plat.png");

    const Texture2D digitalWatchBackground = LoadTexture("assets/digital_watch_background.png");
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
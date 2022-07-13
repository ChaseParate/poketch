#include "raylib.h"

#include "constants.hpp"
#include "apps/digital_watch.hpp"

int main()
{
    InitWindow(windowWidth, windowHeight, "Pokétch");
    SetTargetFPS(60);

    RenderTexture2D gameScreen = LoadRenderTexture(gameWidth, gameHeight);
    RenderTexture2D poketchScreen = LoadRenderTexture(poketchWidth, poketchHeight);

    const Texture2D borderTexture = LoadTexture("assets/border_plat.png");

    DigitalWatch digitalWatch;

    while (!WindowShouldClose())
    {
        BeginDrawing();

        BeginTextureMode(poketchScreen);
        ClearBackground(backgroundColor);
        digitalWatch.draw();
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
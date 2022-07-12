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

    while (!WindowShouldClose())
    {
        BeginDrawing();

        BeginTextureMode(poketchScreen);
        ClearBackground(backgroundColor);
        DrawText("Hello, Pokétch!", 20, 70, 20, foregroundColor);
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
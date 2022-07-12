#include "raylib.h"

int main()
{
    const int screenWidth = 256;
    const int screenHeight = 192;

    const int windowScale = 3;
    const int windowWidth = screenWidth * windowScale;
    const int windowHeight = screenHeight * windowScale;

    InitWindow(windowWidth, windowHeight, "Pokétch");
    SetTargetFPS(60);

    RenderTexture2D screen = LoadRenderTexture(screenWidth, screenHeight);

    while (!WindowShouldClose())
    {
        BeginDrawing();

        BeginTextureMode(screen);
        ClearBackground(RAYWHITE);
        DrawText("Hello World!", 0, 0, 20, LIGHTGRAY);
        EndTextureMode();

        DrawTexturePro(screen.texture, {0, 0, screenWidth, -screenHeight}, {0, 0, windowWidth, windowHeight}, {0, 0}, 0, WHITE);

        EndDrawing();
    }

    UnloadRenderTexture(screen);
    CloseWindow();

    return 0;
}
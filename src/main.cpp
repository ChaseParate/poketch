#include "raylib.h"

int main()
{
    const int displayWidth = 256;
    const int displayHeight = 192;

    const int windowScale = 3;
    const int windowWidth = displayWidth * windowScale;
    const int windowHeight = displayHeight * windowScale;

    InitWindow(windowWidth, windowHeight, "Pokétch");
    SetTargetFPS(60);

    RenderTexture2D window = LoadRenderTexture(displayWidth, displayHeight);

    while (!WindowShouldClose())
    {
        BeginDrawing();

        BeginTextureMode(window);
        ClearBackground(RAYWHITE);
        DrawText("Hello World!", 0, 0, 20, LIGHTGRAY);
        EndTextureMode();

        DrawTexturePro(window.texture, {0, 0, displayWidth, -displayHeight}, {0, 0, windowWidth, windowHeight}, {0, 0}, 0, WHITE);

        EndDrawing();
    }

    UnloadRenderTexture(window);
    CloseWindow();

    return 0;
}
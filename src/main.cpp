#include "raylib.h"

int main()
{
    const int displayWidth = 256;
    const int displayHeight = 192;

    const int windowScale = 3;
    const int windowWidth = displayWidth * windowScale;
    const int windowHeight = displayHeight * windowScale;

    const Vector2 screenOffset = {16, 16};

    InitWindow(windowWidth, windowHeight, "Pokétch");
    SetTargetFPS(60);

    RenderTexture2D window = LoadRenderTexture(displayWidth, displayHeight);

    Texture2D border = LoadTexture("assets/border_plat.png");
    Texture2D screen = LoadTexture("assets/screen.png");

    while (!WindowShouldClose())
    {
        BeginDrawing();

        BeginTextureMode(window);
        ClearBackground(BLACK);
        DrawTexture(border, 0, 0, WHITE);
        DrawTextureV(screen, screenOffset, WHITE);
        EndTextureMode();

        DrawTexturePro(window.texture, {0, 0, displayWidth, -displayHeight}, {0, 0, windowWidth, windowHeight}, {0, 0}, 0, WHITE);

        EndDrawing();
    }

    UnloadRenderTexture(window);
    CloseWindow();

    return 0;
}
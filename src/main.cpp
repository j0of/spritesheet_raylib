#include "raylib.h"

#include "Globals.h"
#include "Icon.h"
#include "Chickn.h"

#include <iostream>

using namespace spritesheet;

int main(void) {

    InitWindow(Globals::WINDOW_WIDTH, Globals::WINDOW_HEIGHT, Globals::WINDOW_TITLE.c_str());

    InitAudioDevice();

    Texture2D iconTexture = LoadTexture("../assets/raylib_128x128.png");
    Texture2D chicknTexture = LoadTexture("../assets/chickn.png");

    Sound bruh = LoadSound("../assets/bruh.wav");

    Icon icon {iconTexture};
    Chickn chickn {chicknTexture, bruh};

    SetTargetFPS(144);

    float timer = 0;
    Color color = LIGHTGRAY;

    while (!WindowShouldClose()) {
        // TODO : Add update logic here
        
        icon.Update();
        chickn.Update();

        if (timer >= 3) {
            color.a -= 50 * GetFrameTime();
        } else {
            timer += GetFrameTime();
        }

        BeginDrawing();

            ClearBackground(RAYWHITE);

            // TODO : Draw textures here

            icon.Draw();
            chickn.Draw();

            DrawFPS(10, 10);

            DrawText("WASD/Arrow keys to move; SPACE to talk", 10, 30, 24, color);

        EndDrawing();
    }

    // TODO : De-initialize objects here

    UnloadTexture(iconTexture);
    UnloadTexture(chicknTexture);
    UnloadSound(bruh);

    CloseWindow();

    return 0;
}
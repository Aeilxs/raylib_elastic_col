#include "Balls.h"
#include "config.h"
#include "defines.h"

i32 main(void) {
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, WINDOW_TITLE);
    SetConfigFlags(FLAG_FULLSCREEN_MODE);
    SetTargetFPS(120);
start_simulation:

    Balls balls;

    while (!WindowShouldClose()) {
        BeginDrawing();

        ClearBackground(BLACK);
        DrawText("PRESS SPACE", SCREEN_WIDTH / 2 - MeasureText("PRESS SPACE", 40) / 2, SCREEN_HEIGHT / 2, 40, WHITE);
        EndDrawing();

        if (IsKeyPressed(KEY_SPACE)) break;
    }

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(BLACK);

        balls.update();
        balls.draw();

        DrawFPS(20, 20);
        EndDrawing();

        if (IsKeyPressed(KEY_SPACE)) {
            goto start_simulation;
        }
    }

    CloseWindow();
    return 0;
}

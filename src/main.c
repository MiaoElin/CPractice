#include <stdio.h> // 官方库
#include <stdlib.h>
#include "import.h"
#include "MainContext.h"
int main()
{
    printf("Hello World\r\n");

    SampleEntry();
    InitWindow(600, 600, "hello C World");

    while (!WindowShouldClose())
    {
        // input
        MainContext *ctx = New_MainContext();
        float dt = GetFrameTime();

        BeginDrawing();
        ClearBackground(WHITE);
        // Tick
        // 生成飞机
        E_Plane *player = calloc(1, sizeof(E_Plane));
        Vector2 playerPos = {300, -500};

        DrawCircle(50, 50, 50, PINK);
        EndDrawing();
    }
    CloseWindow();

    return 0;
}

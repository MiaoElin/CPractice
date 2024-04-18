#include <stdio.h> // 官方库
#include "test.h"  // 自定义库
#include "..\include\raylib.h"

int main()
{
    printf("Hello World\r\n");
    InitWindow(600, 600, "hello C World");

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(WHITE);
        DrawCircle3D((Vector3){50, 50, 5}, 5, (Vector3){0, 0, 0}, 50, PINK);
        EndDrawing();
    }
    CloseWindow();
    return 0;
}
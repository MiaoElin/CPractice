#include <stdio.h> // 官方库
#include <stdlib.h>
#include "import.h"
#include "export.h"

int main()
{
    printf("Hello World\r\n");

    SampleEntry();
    // InitWindow(600, 600, "hello C World");

    // while (!WindowShouldClose())
    // {
    //     BeginDrawing();
    //     ClearBackground(WHITE);
    //     DrawCircle(50, 50, 50, PINK);
    //     EndDrawing();
    // }
    // CloseWindow();
    
    return 0;
}

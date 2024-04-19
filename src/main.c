#include <stdio.h> // 官方库
#include "import.h"
#include "export.h"

#define ARRAYLEN(arr) (sizeof(arr) / sizeof(arr[0]))


int main()
{
    printf("Hello World\r\n");

    int a = 10;
    printf("a的值是%d\n", *&a);

    // // 自定义类
    // MyVector3 v3 = NewVector3(0, 2, 3);
    // MyVector3 v4 = NewVector3(0, 2, 3);

    // MyVector3Add(v3, v4);

    // 数组排序
    int arr[] = {3, 8, 2, 5, 9, 0, 4, 2};
    int len = ARRAYLEN(arr);
    ArraySortFun1(arr, len);
    PrintfArr(arr);
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

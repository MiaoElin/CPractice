#include <stdio.h> // 官方库
// #include "import.h"
#include "export.h"

#define ARRAYLEN(arr) (sizeof(arr) / sizeof(arr[0]))

void ArraySortFun1(int *arr, int len)
{
    for (int i = 0; i < 8 - 1; i++)
    {
        for (int j = i + 1; j < 8; j++)
        {
            int temp;
            if (arr[j] < arr[i])
            {
                temp = arr[j];
                arr[j] = arr[i];
                arr[i] = temp;
            }
        }
    }
}

void PrintfArr(int *arr)
{
    for (int i = 0; i < 8; i++)
    {
        printf("%d\r\n", arr[i]);
    }
}

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

#ifndef INARRAYSORT_H__
#define INARRAYSORT_H__
#endif

#include <stdio.h>

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

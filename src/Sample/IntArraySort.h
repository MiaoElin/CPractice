#ifndef INARRAYSORT_H__
#define INARRAYSORT_H__

#include <stdio.h>

void ArraySortFun1(int *arr, int len) {
    for (int i = 0; i < len - 1; i++) {
        for (int j = i + 1; j < len; j++) {
            int temp;
            if (arr[j] < arr[i]) {
                temp = arr[j];
                arr[j] = arr[i];
                arr[i] = temp;
            }
        }
    }
}

void ArraySortFun2(int *arr, int len) {
    int minInt;
    int index;
    for (int i = 0; i < len - 1; i++) {
        minInt = arr[i];
        index = i;
        for (int j = i + 1; j < len; j++) {
            if (arr[j] < minInt) {
                minInt = arr[j];
                index = j;
            }
        }
        arr[index] = arr[i];
        arr[i] = minInt;
    }
}

void PrintfArr(int *arr) {
    for (int i = 0; i < 8; i++) {
        printf("%d\r\n", arr[i]);
    }
}
#endif


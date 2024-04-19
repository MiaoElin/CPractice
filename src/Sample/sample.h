#ifndef SAMPLE_H__
#define SAMPLE_H__
#endif

#include "IntArraySort.h"
#include "MyVector3.h"
#include "MyList.h"

#define ARRAYLEN(arr) (sizeof(arr) / sizeof(arr[0]))

void SampleEntry()
{
    // 自定义类
    MyVector3 v3 = NewVector3(0, 2, 3);
    MyVector3 v4 = NewVector3(0, 2, 3);

    MyVector3Add(v3, v4);

    // 数组排序
    int arr[] = {3, 8, 2, 5, 9, 0, 4, 2};
    int len = ARRAYLEN(arr);
    ArraySortFun2(arr, len);
    PrintfArr(arr);

    // 自定义List
    MyList *list = calloc(1, sizeof(MyList));
    NewMyList(list);
    MyListAdd(list, 1);
    MyListAdd(list, 1);
    MyListAdd(list, 1);
    MyListAdd(list, 1);
    MyListAdd(list, 1);
    MyListRemove(list,1);
    printf("list's Count is: %d\n", list->count);
}

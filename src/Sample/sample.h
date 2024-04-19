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
    MyList_Add(list, 1);
    MyList_Add(list, 2);
    MyList_Add(list, 3);
    MyList_Add(list, 4);
    MyList_Add(list, 5);
    MyList_Remove(list, 6);
    printf("list's Count is: %d\n", list->count);
    int a = MyList_TryGetvalue(list, 3);
    printf("a is : %d\n", a);
    MyList_Foreach(list);
}

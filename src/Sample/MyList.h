#ifndef MYLIST_H__
#define MYLIST_H__
#endif

#include <stdlib.h>

typedef struct MysList
{
    int *arr;
    int arrlen;
    int count;

} MyList;

void NewMyList(MyList *MyList)
{
    MyList->arr = (int *)calloc(4, sizeof(int));
    MyList->arrlen = 4;
}

void MyListAdd(MyList *list, int a)
{
    for (int i = 0; i < list->arrlen; i++)
    {
        // int *aa = &(list->arr[i]);
        // if (aa == NULL)
        // {
        //     aa = &a;
        // }
        if ((list->arr[i]) == 0)
        {
            list->arr[i] = a;
            list->count++;
            return;
        }
    }
    if (list->arr[list->arrlen - 1] != 0)
    {
        // 扩充数组
        int *newlist = (int *)calloc(list->arrlen * 2, sizeof(int));
        for (int i = 0; i < list->arrlen - 1; i++)
        {
            newlist[i] = list->arr[i];
        }
        list->arr = newlist;
        list->arrlen *= 2;

        // 赋值
        list->arr[list->count] = a;
        list->count++;
    }
}

void MyListRemove(MyList *list, int value)
{
    for (int i = 0; list->count - 1; i++)
    {
        if (list->arr[i] == value)
        {
            list->arr[i] = list->arr[list->count - 1];
            list->count -= 1;
            break;
        }
    }
}

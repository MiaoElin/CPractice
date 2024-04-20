#ifndef LIST_H__
#define LIST_H__
#endif

#include <stdlib.h>

typedef struct List
{
    void **items;
    size_t size;
    int arrlen;
    int count;

} List;

List *NewList(size_t size)
{
    List *list = (List *)calloc(1, sizeof(List));
    list->items = (void **)calloc(4, sizeof(void *));
    list->size = size;
    list->arrlen = 4;
    list->count = 0;
}

void List_Add(List *list, void *value)
{
    if (list->count == list->arrlen)
    {
        // 扩充数组
        list->arrlen *= 2;
        list->items = (void **)realloc(list->items, list->arrlen);
    }
    list->items[list->count] = calloc(1, list->size);
    list->items[list->count] = value;
    list->count += 1;
}

void List_Remove(List *list, void *value)
{
    int has = 0;
    for (int i = 0; i < list->count - 1; i++)
    {
        if (list->items[i] == value)
        {
            list->items[i] = list->items[list->count - 1];
            list->count -= 1;
            has = 1;
            return;
        }
    }
    if (has == 0)
    {
        printf("There is no %d\n", value);
    }
}

void *List_TryGetvalue(List *list, int index)
{
    return list->items[index];
}

void List_Foreach(List *list, void (*action)(void *plane))
{
    for (int i = 0; i < list->count; i++)
    {
        void *a = list->items[i];
        action(a);
    }
}
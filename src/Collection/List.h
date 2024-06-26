#ifndef LIST_H__
#define LIST_H__

#include <stdio.h>
#include <stdlib.h>

typedef struct List {
    void **items;
    size_t size;
    int arrlen;
    int count;
} List;

List *List_New(size_t size) {
    List *list = (List *)calloc(1, sizeof(List));
    list->items = (void **)calloc(4, sizeof(void *));
    // list->size = size;
    list->arrlen = 4;
    list->count = 0;
    return list;
}

void List_Free(List *list) {
    free(list->items);
    free(list);
}

void List_Add(List *list, void *value) {
    assert(value != NULL);
    // list->items[list->count] = calloc(1, list->size);
    list->items[list->count] = value;
    list->count += 1;
    if (list->count == list->arrlen) {
        // 扩充数组
        list->arrlen *= 2;
        // realloc：在原内存大小的基础上，扩大至第二个参数的大小（每个元素的size*元素数量：sizeof（指针）*arrlen）
        list->items = realloc(list->items, sizeof(void *) * list->arrlen);
        // void **newItems = malloc(list->arrlen * list->size);
        // for (int i = 0; i < list->count; i += 1) {
        //     newItems[i] = list->items[i];
        // }
        // free(list->items);
        // list->items = newItems;
    }
}

void List_Remove(List *list, void *value) {
    int has = 0;
    for (int i = 0; i < list->count - 1; i++) {
        if (list->items[i] == value) {
            list->items[i] = list->items[list->count - 1];
            list->count -= 1;
            has = 1;
            return;
        }
    }
    if (has == 0) {
        printf("There is no %d\n", value);
    }
}

void *List_TryGetvalue(List *list, int index) {
    return list->items[index];
}

void List_Foreach(List *list, void (*action)(void *plane)) {
    for (int i = 0; i < list->count; i++) {
        void *a = list->items[i];
        action(a);
    }
}
#endif

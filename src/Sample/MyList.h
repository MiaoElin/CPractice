#ifndef MYLIST_H__
#define MYLIST_H__

#include <stdlib.h>

typedef struct MyList {
    int *arr;
    int arrlen;
    int count;

} MyList;

void NewMyList(MyList *MyList) {
    MyList->arr = (int *)calloc(4, sizeof(int));
    MyList->arrlen = 4;
    MyList->count = 0;
}

void MyList_Add(MyList *list, int a) {
    if (list->count == list->arrlen) {
        // 扩充数组
        int *newarr = (int *)calloc(list->arrlen * 2, sizeof(int));
        for (int i = 0; i < list->count; i++) {
            newarr[i] = list->arr[i];
        }
        list->arr = newarr;
        list->arrlen *= 2;
    }
    list->arr[list->count] = a;
    list->count += 1;
}

void MyList_Remove(MyList *list, int value) {
    int has = 0;
    for (int i = 0; i < list->count - 1; i++) {
        if (list->arr[i] == value) {
            list->arr[i] = list->arr[list->count - 1];
            list->count -= 1;
            has = 1;
            return;
        }
    }
    if (has == 0) {
        printf("There is no %d\n", value);
    }
}

int MyList_TryGetvalue(MyList *list, int index) {
    return list->arr[index];
}

void MyList_Foreach(MyList *list, void (*action)(int index, int value)) {
    for (int i = 0; i < list->count; i++) {
        int a = list->arr[i];
        action(i, a);
    }
}
#endif

#ifndef DICTIONARY_H__
#define DICTIONARY_H__
#endif

#include <stdio.h>
#include <stdlib.h>

typedef struct DictionaryEntry {

    long key;
    void *value;
    bool isExists;
    DictionaryEntry *next; // 某个数据的地址

} DictionaryEntry;

typedef struct Dictionary {

    DictionaryEntry *all; // 数组的地址
    int capacity;
    int count;

} Dictionary;

Dictionary *Dictionary_New(int capacity) {
    Dictionary *dic = (Dictionary *)calloc(1, sizeof(Dictionary));
    dic->all = (DictionaryEntry *)calloc(capacity, sizeof(DictionaryEntry *));
    dic->capacity = capacity;
    dic->count = 0;
    return dic;
}

void Dictionary_Free(Dictionary *dic) {
    free(dic->all);
    free(dic);
}

bool Dictionary_TryAdd(Dictionary *dic, long key, void *value) {
    if (dic->count >= dic->capacity) {
        printf("the Dictionary is full");
        return false;
    }
    int index = key % dic->capacity;
    DictionaryEntry *entry = &dic->all[index];
    // 这个entry没有存数据(不用开内存,每个index下都开了一个内存区域)
    if (!entry->isExists) {
        entry->key = key;
        entry->value = value;
        entry->isExists = true;
        entry->next = NULL;
        dic->count++;
        return true;
    }
    // 这个entry有数据，且它的下个也有数据
    while (entry->next->isExists) {
        // 这个entry的key重复了。直接退出，存储失败
        if (entry->key == key) {
            printf("the key is exists");
            return false;
        }
        // 获取下一个entry
        entry = entry->next;
    }
    // 直到entry的下一个没数据
    // 创建一个新的entry,开一个内存区域
    DictionaryEntry *newEntry = (DictionaryEntry *)malloc(sizeof(DictionaryEntry));
    newEntry->key = key;
    newEntry->value = value;
    newEntry->isExists = true;
    newEntry->next = NULL;
    entry->next = newEntry;
    dic->count++;
    return true;
}

bool Dictionary_Tryget(Dictionary *dic, long key, void **value) {
    int index = key % dic->capacity;
    DictionaryEntry *entry = &dic->all[index];
    if (!entry->isExists) {
        printf("there is no this Key");
        return false;
    }
    while (entry!=NULL) {
        if (entry->key == key) {
            *value = entry->value;
            return true;
        }
        entry=entry->next;
    }
    return false;
}

bool Dictionary_TryRemove(Dictionary *dic, long key) {
    int index = key % dic->capacity;
    DictionaryEntry *entry = &dic->all[index];
    // 没有数据，退出.(不能用entry==NULL来判断,因为第一个一定不为空)
    if (!entry->isExists) {
        printf("this Key is not Exists");
        return false;
    }
    // 有数据
    do {
        // 找到要移除的入口
        if (entry->key == key) {
            // 要移除的入口的一下不为空
            if (entry->next != NULL) {
                // 存下下一个入口
                DictionaryEntry *next = entry->next;
                // 清空这个入口的内存
                free(entry);
                entry = next;
                dic->count--;
                return true;
            }
            free(entry);
            dic->count--;
            return true;
        }
        // key没找到,就找下一个entry
        entry = entry->next;
    } while (entry != NULL);
    return false;
}

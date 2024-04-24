#ifndef DICTIONARY_H__
#define DICTIONARY_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef bool
#define bool char
#define true 1
#define false 0
#endif

typedef struct DictionaryEntry DictionaryEntry;
typedef struct Dictionary Dictionary;

struct DictionaryEntry {
    long key;
    void *value;
    bool isExists;
    DictionaryEntry *next; // 某个数据的地址
};

struct Dictionary {
    DictionaryEntry *all; // 数组的地址
    int capacity;
    int count;
};

Dictionary *Dictionary_New(int capacity) {
    Dictionary *dic = (Dictionary *)calloc(1, sizeof(Dictionary));
    dic->all = (DictionaryEntry *)calloc(capacity, sizeof(DictionaryEntry));
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
    // 这个entry有数据，且它的下个也有数据 NUL
    while (entry->next != NULL) {
        // 这个entry的key重复了。直接退出，存储失败
        if (entry->key == key) {
            printf("the key is exists");
            return false;
        }
        // 获取下一个entry
        entry = entry->next;
    }
    assert(entry != NULL);
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

bool Dictionary_TryGetValue(Dictionary *dic, long key, void **value) {
    // void *value;
    int index = key % dic->capacity;
    DictionaryEntry *entry = &dic->all[index];
    if (!entry->isExists) {
        printf("there is no this Key");
        return false;
    }
    while (entry != NULL) {
        if (entry->key == key) {
            *value = entry->value;
            return true;
        }
        entry = entry->next;
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
    // 第一个入口
    if (entry->key == key) {
        printf("remove id is %d\r\n", key);
        entry->isExists = false;
        dic->count -= 1;
        // 要移除的入口的一下不为空
        if (entry->next != NULL) {
            // 存下下一个入口
            DictionaryEntry *next = entry->next;
            // 清空这个入口的内存
            memcpy(entry, next, sizeof(DictionaryEntry));
            free(next);
            return true;
        }
        return true;
    }
    // key没找到,就找下一个entry
    entry = entry->next;
    // 有数据
    while (entry != NULL) {
        // 找到要移除的入口
        if (entry->key == key) {
            printf("remove id is %d\r\n", key);
            dic->count -= 1;
            // 要移除的入口的一下不为空
            if (entry->next != NULL) {
                // 存下下一个入口
                DictionaryEntry *next = entry->next;
                // 清空这个入口的内存
                memcpy(entry, next, sizeof(DictionaryEntry));
                free(next);
                return true;
            }
            DictionaryEntry *next = NULL;
            memcpy(entry, next, sizeof(DictionaryEntry));
            return true;
        }
        // key没找到,就找下一个entry
        entry = entry->next;
    }
    return false;
}

int Dictionary_GetAllValue(Dictionary *dic, void **arr) {
    int arrCount = 0;
    for (int i = 0; i < dic->capacity; i++) {
        // 找到第一个entry
        DictionaryEntry *entry = &dic->all[i];
        assert(entry != NULL);
        // 如果不存在，说明当前入口没有数据
        if (!entry->isExists) {
            continue;
        }
        // 存在数据 NULL.xxx
        while (entry != NULL && entry->isExists) {
            // 存储数据
            assert(arrCount < dic->count);
            assert(entry->value != NULL);
            arr[arrCount] = entry->value;
            arrCount++;
            // 找下一个
            entry = entry->next;
        }
    }
    return arrCount;
}
#endif

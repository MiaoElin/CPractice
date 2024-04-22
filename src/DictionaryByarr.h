#ifndef DICTIONARYBYARR_H__
#define DICTIONARYBYARR_H__
#endif

typedef struct DictionaryByarr {

    void **key;
    void **value;
    int arrLen;
    int count;

} DictionaryByarr;

DictionaryByarr *DictionaryByarr_New() {
    DictionaryByarr *dic = (DictionaryByarr *)malloc(sizeof(DictionaryByarr));
    dic->key = (void **)calloc(4, sizeof(void **));
    dic->value = (void **)calloc(4, sizeof(void **));
    dic->arrLen = 4;
    dic->count = 0;
    return dic;
}

void DictionaryByarr_Add(DictionaryByarr *dic, void *key, void *value) {
    for (int i = 0; i < dic->count; i++) {
        void *k = dic->key[i];
        if (k == key) {
            printf("DictionaryByarr key is repeat");
            return;
        }
    }
    dic->key[dic->count] = key;
    dic->value[dic->count] = value;
    dic->count++;
    if (dic->count == dic->arrLen) {
        // 扩容
        dic->arrLen *= 2;
        dic->key = (void **)realloc(dic->key, sizeof(void *) * dic->arrLen);
        dic->value = (void **)realloc(dic->value, sizeof(void *) * dic->arrLen);
    }
}

void *DictionaryByarr_TryGetValue(DictionaryByarr *dic, void *key) {
    for (int i = 0; i < dic->count; i++) {
        void *k = dic->key[i];
        if (k == key) {
            return dic->value[i];
        }
    }
}

void DictionaryByarr_Remove(DictionaryByarr *dic, void *key) {
    for (int i = 0; i < dic->count; i++) {
        void *k = dic->key[i];
        if (k == key) {
            dic->key[i] = dic->key[dic->count - 1];
            dic->value[i] = dic->value[dic->count - 1];
            dic->count -= 1;
            break;
        }
    }
}

void DictionaryByarr_Foreach(DictionaryByarr *dic, void (*action)(void *Value)) {
    for (int i = 0; i < dic->count; i++) {
        void *val = dic->value[i];
        action(val);
    }
}

void DictionaryByarr_Free(DictionaryByarr *dic) {
    free(dic->key);
    free(dic->value);
    free(dic);
}
#ifndef DICTIONARY_H__
#define DICTIONARY_H__
#endif

#include <stdlib.h>

typedef struct Dictionary {

    void **key;
    void **value;
    int arrLen;
    int count;

} Dictionary;

// Dictionary* Dictionary_New(size)
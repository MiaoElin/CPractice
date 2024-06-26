#ifndef BULLETREPO_H__
#define BULLETREPO_H__

#include "import.h"

typedef struct BulletRepo {
    Dictionary *all;
    int bulletRecord;
} BulletRepo;

BulletRepo *BulletRepo_New() {
    BulletRepo *repo = (BulletRepo *)malloc(sizeof(BulletRepo));
    repo->all = Dictionary_New(2000);
    repo->bulletRecord = 0;
    return repo;
}

void BulletRepo_Free(BulletRepo *repo) {
    Dictionary_Free(repo->all);
    free(repo);
}

bool BulletRepo_Add(BulletRepo *repo, long key, void *value) {
    return Dictionary_TryAdd(repo->all, key, value);
}

int BulletRepo_TakeAll(BulletRepo *repo, E_Bullet **arr) {
    return Dictionary_GetAllValue(repo->all, (void **)arr);
}
#endif

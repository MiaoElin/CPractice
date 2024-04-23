#ifndef BULLETREPO_H__
#define BULLETREPO_H__
#endif

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
#ifndef PLANEREPO_H__
#define PLANEREPO_H__

#include "import.h"

typedef struct PlaneRepo {
    Dictionary *all;
    int idRecord;

} PlaneRepo;

PlaneRepo *PlaneRepo_New() {
    PlaneRepo *planeRepo = calloc(1, sizeof(PlaneRepo));
    Dictionary *all = Dictionary_New(1000);
    planeRepo->all = all;
    planeRepo->idRecord = 0;
    return planeRepo;
}

void PlaneRepo_Add(PlaneRepo *repo, E_Plane *plane) {
    Dictionary_TryAdd(repo->all, (long)(plane->id), plane);
}

bool PlaneRepo_Find(PlaneRepo *repo, int id, E_Plane **value) {
    return Dictionary_TryGetValue(repo->all, (long)id, (void **)value);
}

void PlaneRepo_Free(PlaneRepo *repo) {
    Dictionary_Free(repo->all);
    free(repo);
}

// E_Plane*[]
int PlaneRepo_TakeAll(PlaneRepo *repo, E_Plane **all) {
    return Dictionary_GetAllValue(repo->all, (void **)all);
}

int PlaneRepo_GetCount(PlaneRepo *repo) {
    return repo->all->count;
}
#endif

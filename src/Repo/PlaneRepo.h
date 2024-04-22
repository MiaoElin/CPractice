#ifndef PLANEREPO_H__
#define PLANEREPO_H__
#endif

#include "../DictionaryByarr.h"

typedef struct PlaneRepo {
    DictionaryByarr *all;
    int idRecord;

} PlaneRepo;

PlaneRepo *PlaneRepo_New() {
    PlaneRepo *planeRepo = calloc(1, sizeof(PlaneRepo));
    DictionaryByarr *all = DictionaryByarr_New(sizeof(E_Plane));
    planeRepo->all = all;
    planeRepo->idRecord = 0;
    return planeRepo;
}

void PlaneRepo_Add(PlaneRepo *repo, E_Plane *plane) {
    DictionaryByarr_Add(repo->all, &(plane->id), plane);
}

E_Plane *PlaneRepo_Find(PlaneRepo *repo, int id) {
    return DictionaryByarr_TryGetValue(repo->all, &id);
}

void PlaneRepo_Free(PlaneRepo *pRepo) {
    DictionaryByarr_Free(pRepo->all);
    free(pRepo);
}
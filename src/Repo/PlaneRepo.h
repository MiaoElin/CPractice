#ifndef PLANEREPO_H__
#define PLANEREPO_H__
#endif

#include "../List.h"

typedef struct PlaneRepo {
    List *all;
    int idRecord;

} PlaneRepo;

PlaneRepo *PlaneRepo_New() {
    PlaneRepo *planeRepo = calloc(1, sizeof(PlaneRepo));
    List *all = List_New(sizeof(E_Plane));
    planeRepo->all = all;
    planeRepo->idRecord = 0;
    return planeRepo;
}

void PlaneRepo_Add(PlaneRepo *repo, E_Plane *plane) {
    List_Add(repo->all, plane);
}

E_Plane *PlaneRepo_Find(PlaneRepo *repo, int id) {
    for (int i = 0; i < repo->all->count; i += 1) {
        //
    }
    return NULL;
}

void PlaneRepo_Free(PlaneRepo *pRepo) {
    List_Free(pRepo->all);
    free(pRepo);
}
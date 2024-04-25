#ifndef PLANEREPO_H__
#define PLANEREPO_H__

#include "import.h"
#include "float.h"

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

bool PlaneRepo_FindNearlyPlane(PlaneRepo *repo, Vector2 targetPos, AllyEnum ally, E_Plane **plane) {
    // E_Plane *nearlyP;
    float nearlyDistance = FLT_MAX;
    float currentDistance;
    E_Plane *all[1024];
    int planeCount = PlaneRepo_TakeAll(repo, all);
    for (int i = 0; i < planeCount; i++) {
        E_Plane *currentP = all[i];
        if (currentP->ally == ally) {
            continue;
        }
        currentDistance = Vector2DistanceSqr(currentP->pos, targetPos);
        if (currentDistance <= nearlyDistance) {
            nearlyDistance = currentDistance;
            *plane = currentP;
        }
    }
    // plane = nearlyP;
    if (plane == NULL) {
        return false;
    } else {
        printf("has nearlyenemy,id is :%d\r\n", (*plane)->id);
        return true;
    }
}

#endif

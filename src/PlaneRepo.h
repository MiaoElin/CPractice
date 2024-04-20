#ifndef PLANEREPO_H__
#define PLANEREPO_H__
#endif

#include "Sample/List.h"

typedef struct PlaneRepo
{
    List *all;
    int idRecord;

} PlaneRepo;

PlaneRepo *New_PlaneRepo()
{
    PlaneRepo *planeRepo = calloc(1, sizeof(planeRepo));
    List *all = NewList(sizeof(E_Plane));
    planeRepo->all = all;
    planeRepo->idRecord = 0;
}

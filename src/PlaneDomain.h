#ifndef PLANEDOMAIN_H__
#define PLANEDOMAIN_H__
#endif

#include "MainContext.h"

// 生成飞机
E_Plane *PlaneDomain_Spawn(GameContext *ctx, Vector2 pos, float speed, Color color, Movetype movetype) {
    // printf("before repo arrlen is : %d\n", ctx->planeRepo->all->count);
    E_Plane *plane = New_Plane(pos, speed, color, movetype);
    assert(plane != NULL);
    plane->id = ctx->planeRepo->idRecord++;
    PlaneRepo_Add(ctx->planeRepo, (void*)plane);
    // printf("repo arrcount is : %d\r\n", ctx->planeRepo->all->count);
    return plane;
}

// 移动飞机
void PlaneDoMain_Move(GameContext *ctx, E_Plane *plane, float dt) {
    if (plane->movetype == ByInput) {
        Plane_Move(plane, ctx->input->moveAxis, dt);
    } else if (plane->movetype == ByAI) {
        // todo
    }
}

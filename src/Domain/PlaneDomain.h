#ifndef PLANEDOMAIN_H__
#define PLANEDOMAIN_H__

#include "../Context/MainContext.h"

// 生成飞机
E_Plane *PlaneDomain_Spawn(GameContext *ctx, Vector2 pos, float speed, Texture2D texture, Movetype movetype, AllyEnum ally, Vector2 faceDir, float interval) {
    // printf("before repo arrlen is : %d\n", ctx->planeRepo->all->count);
    E_Plane *plane = Plane_New(pos, speed, texture, movetype, ally, faceDir, interval);
    assert(plane != NULL);
    plane->id = ctx->planeRepo->idRecord++;
    PlaneRepo_Add(ctx->planeRepo, (void *)plane);
    // printf("repo arrcount is : %d\r\n", ctx->planeRepo->all->count);
    return plane;
}

// 移动飞机
void PlaneDoMain_Move(GameContext *ctx, E_Plane *plane, float dt) {
    if (plane->movetype == Movetype_ByInput) {
        Plane_Move(plane, ctx->input->moveAxis, dt);
    } else if (plane->movetype == Movetype_ByTrack) {
        E_Plane *player = GameContext_GetPlayer(ctx);
        Vector2 dir = Vector2Subtract(player->pos, plane->pos);
        Plane_Move(plane, dir, dt);
    }
}

#endif

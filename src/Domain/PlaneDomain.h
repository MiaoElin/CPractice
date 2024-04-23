#ifndef PLANEDOMAIN_H__
#define PLANEDOMAIN_H__
#endif

#include "../Context/MainContext.h"

// 生成飞机
E_Plane *PlaneDomain_Spawn(GameContext *ctx, Vector2 pos, float speed, Texture2D texture, Movetype movetype, Ally ally, Vector2 faceDir, float interval) {
    // printf("before repo arrlen is : %d\n", ctx->planeRepo->all->count);
    E_Plane *plane = New_Plane(pos, speed, texture, movetype, ally, faceDir, interval);
    assert(plane != NULL);
    plane->id = ctx->planeRepo->idRecord++;
    PlaneRepo_Add(ctx->planeRepo, (void *)plane);
    // printf("repo arrcount is : %d\r\n", ctx->planeRepo->all->count);
    return plane;
}

// 移动飞机
void PlaneDoMain_Move(GameContext *ctx, E_Plane *plane, float dt) {
    if (plane->movetype == ByInput) {
        Plane_Move(plane, ctx->input->moveAxis, dt);
    } else if (plane->movetype == ByTrack) {
        E_Plane *player = GameContext_GetPlayer(ctx);
        Vector2 dir = Vector2Subtract(player->pos, plane->pos);
        Plane_Move(plane, dir, dt);
    }
}

void PlaneDomain_ShootBul(GameContext *ctx, E_Plane *plane, float dt) {
    float timer = plane->timer;
    float interval = plane->interval;
    timer += dt;
    if (timer >= interval) {
        timer = 0;
        if (plane->ally == Player) {
            if (ctx->input->isShootBul) {
                BulletDomain_Spawn(ctx, plane->pos, Player, plane->faceDir);
            }
        } else if (plane->ally == Enemy) {
            BulletDomain_Spawn(ctx, plane->pos, Player, plane->faceDir);
        }
    }
}
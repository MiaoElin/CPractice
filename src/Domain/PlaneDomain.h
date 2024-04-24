#ifndef PLANEDOMAIN_H__
#define PLANEDOMAIN_H__

#include "import.h"
#include "BulletDomain.h"

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

void PlaneDomain_ShootBul(GameContext *ctx, E_Plane *plane, float dt) {
    float *interval = &plane->interval;
    plane->timer += dt;
    // printf("%f\n", plane->timer);
    if (plane->timer >= *interval) {
        plane->timer = 0;
        if (plane->ally == Ally_Player) {
            if (ctx->input->isShootBul) {
                BulletDomain_Spawn(ctx, plane->pos, Ally_Player, plane->faceDir);
            }
        } else if (plane->ally == Ally_Enemy) {
            BulletDomain_Spawn(ctx, plane->pos, Ally_Enemy, plane->faceDir);
        }
    }
}

void PlaneDomain_Draw(GameContext *ctx) {
    // 画飞机
    void *allPlane[1024];
    int planeCount = PlaneRepo_TakeAll(ctx->planeRepo, allPlane);
    for (size_t i = 0; i < planeCount; i++) {
        E_Plane *plane = (E_Plane *)allPlane[i];
        Plane_Draw(plane);
    }
}

#endif

#ifndef GAMEBUSINESS_H__
#define GAMEBUSINESS_H__

#include <assert.h>

#include "../Domain/BulletDomain.h"
#include "../Domain/PlaneDomain.h"

void GameBusiness_Enter(GameContext *ctx) {
    // 生成Player
    Vector2 playerPos = {300, 500};
    Vector2 faceDir = {0, -1};
    Vector2 size = {20, 20};
    E_Plane *player = PlaneDomain_Spawn(ctx, playerPos, 10000, size, 100, ctx->assetCtx->player1, Movetype_ByInput, Ally_Player, faceDir, 0.2f);

    ctx->playerID = player->id;

    // 进入InGame
    ctx->status = GameStatus_Ingame;
}

void GameBusiness_IngameTick(GameContext *ctx, float dt) {
    // 生成敌人
    // float *timer = &ctx->waveTimer;
    float *interval = &ctx->interval;

    ctx->waveTimer += dt;
    // printf("%f\n", ctx->waveTimer);
    if (ctx->waveTimer >= *interval) {
        ctx->waveTimer = 0;
        Vector2 newPos = PF_GetRDVector2(600, 100);
        Vector2 faceDir = {0, 1};
        Vector2 size = {16, 16};
        E_Plane *p = PlaneDomain_Spawn(ctx, newPos, 20, size, 50, ctx->assetCtx->enemy1, Movetype_ByTrack, Ally_Enemy, faceDir, 1);
        assert(p != NULL);
    }

    // 飞机移动
    E_Plane *allPlane[1024];
    int planeCount = PlaneRepo_TakeAll(ctx->planeRepo, allPlane);
    // int planeCount = PlaneRepo_GetCount(ctx->planeRepo);
    // printf("%d\r\n", planeCount);
    for (int i = 0; i < planeCount; i++) {
        E_Plane *plane = allPlane[i];
        // const char *txt = TextFormat("i%d\r\n", i);
        // printf(txt);
        // assert(plane != NULL);
        PlaneDoMain_Move(ctx, plane, dt);
        PlaneDomain_ShootBul(ctx, plane, dt);
    }
    // 子弹
    E_Bullet *allBullet[2048];
    int bulletCount = BulletRepo_TakeAll(ctx->bulletRepo, allBullet);
    for (int i = 0; i < bulletCount; i++) {
        E_Bullet *bul = allBullet[i];
        // 子弹移动
        BullletDomain_Move(ctx, bul, dt);
        // 找最近的敌人
        if (bul->ally == Ally_Enemy) {
            E_Plane *nearlyPlane = GameContext_GetPlayer(ctx);
            BulletDomain_Remove(ctx, bul, nearlyPlane);
        }
        if (bul->ally == Ally_Player) {
            E_Plane *nearlyPlane;
            bool has = BulletDomain_FindNearlyEnemy(ctx, bul->pos, bul->ally, &nearlyPlane);
            if (has) {
                BulletDomain_Remove(ctx, bul, nearlyPlane);
            }
        }
    }

    // 飞机移除
    for (int i = 0; i < planeCount; i++) {
        E_Plane *plane = allPlane[i];
        if (plane->isDead) {
            printf("dead1");
            Dictionary_TryRemove(ctx->planeRepo->all, plane->id);
        }
    }
    // 子弹移除
    for (int i = 0; i < bulletCount; i++) {
        E_Bullet *bul = allBullet[i];
        if (bul->isDead) {
            // printf("bulCount is : %d\n", ctx->bulletRepo->all->count);
            Dictionary_TryRemove(ctx->bulletRepo->all, bul->id);
            // printf("bulCount is : %d\n", ctx->bulletRepo->all->count);
        }
    }
}

void GameBusiness_Draw(GameContext *ctx) {
    BulletDomain_Draw(ctx);
    PlaneDomain_Draw(ctx);
}

void GameBusiness_Tick(GameContext *ctx, float dt) {
    GameStatus status = ctx->status;
    if (status == GameStatus_Enter) {
        GameBusiness_Enter(ctx);
    } else if (status == GameStatus_Ingame) {
        GameBusiness_IngameTick(ctx, dt);
    }
}

#endif

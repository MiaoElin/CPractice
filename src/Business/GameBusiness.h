#ifndef GAMEBUSINESS_H__
#define GAMEBUSINESS_H__

#include <assert.h>

#include "../Domain/PlaneDomain.h"
#include "../Domain/BulletDomain.h"

typedef struct GameBusiness {

} GameBusiness;

void Game_Enter(GameContext *ctx) {
    // 生成Player
    Vector2 playerPos = {300, 500};
    Vector2 faceDir = {0, -1};
    E_Plane *player = PlaneDomain_Spawn(ctx, playerPos, 100, ctx->assetCtx->player1, Movetype_ByInput, Ally_Player, faceDir, 0.2f);

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
        E_Plane *p = PlaneDomain_Spawn(ctx, newPos, 50, ctx->assetCtx->enemy1, Movetype_ByTrack, Ally_Enemy, faceDir, 1);
        assert(p != NULL);
    }

    // player
    E_Plane *player = GameContext_GetPlayer(ctx);
    // PlaneDoMain_Move(ctx, player, dt);

    // 飞机移动
    E_Plane *allPlane[1024];
    int count = PlaneRepo_TakeAll(ctx->planeRepo, allPlane);
    // int planeCount = PlaneRepo_GetCount(ctx->planeRepo);
    // printf("%d\r\n", planeCount);
    for (int i = 0; i < count; i++) {
        E_Plane *plane = (E_Plane *)allPlane[i];
        // const char *txt = TextFormat("i%d\r\n", i);
        // printf(txt);
        // assert(plane != NULL);
        PlaneDoMain_Move(ctx, plane, dt);
        PlaneDomain_ShootBul(ctx, plane, dt);
    }

    // 子弹移动
    void *allBullet[2048];
    int bulletCount = BulletRepo_TakeAll(ctx->bulletRepo, allBullet);
    for (int i = 0; i < bulletCount; i++) {
        E_Bullet *bul = (E_Bullet *)allBullet[i];
        BullletDomain_Move(ctx, bul, dt);
    }
}

void GameBusiness_Draw(GameContext *ctx) {
    BulletDomain_Draw(ctx);
    PlaneDomain_Draw(ctx);
}

void GameBusiness_Tick(GameContext *ctx, float dt) {
    GameStatus status = ctx->status;
    if (status == GameStatus_Ingame) {
        GameBusiness_IngameTick(ctx, dt);
    }
}
#endif

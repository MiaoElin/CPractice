#ifndef GAMEBUSINESS_H__
#define GAMEBUSINESS_H__
#endif

#include <assert.h>

#include "../Domain/PlaneDomain.h"

typedef struct GameBusiness {

} GameBusiness;

void Game_Enter(GameContext *ctx) {
    // 生成Player
    Vector2 playerPos = {300, 500};

    E_Plane *player = PlaneDomain_Spawn(ctx, playerPos, 100, ctx->assetCtx->player1, ByInput);

    ctx->playerID = player->id;

    // 进入InGame
    ctx->status = Ingame;
}

void GameBusiness_Tick(GameContext *ctx, float dt) {
    // 生成敌人
    float *timer = &ctx->waveTimer;
    float *interval = &ctx->interval;

    *timer += dt;
    if (*timer >= *interval) {
        *timer = 0;
        Vector2 newPos = PF_GetRDVector2(600, 100);
        E_Plane *p = PlaneDomain_Spawn(ctx, newPos, 50, ctx->assetCtx->enemy1, ByAI);
        assert(p != NULL);
    }

    // player
    E_Plane *player = GameContext_GetPlayer(ctx);
    // PlaneDoMain_Move(ctx, player, dt);

    // 移动
    void *all[1024];
    int count = PlaneRepo_TakeAll(ctx->planeRepo, all);
    // int planeCount = PlaneRepo_GetCount(ctx->planeRepo);
    // printf("%d\r\n", planeCount);
    if (ctx->status == Ingame) {
        for (int i = 0; i < count; i++) {
            E_Plane *plane = (E_Plane *)all[i];
            // const char *txt = TextFormat("i%d\r\n", i);
            // printf(txt);
            // assert(plane != NULL);
            PlaneDoMain_Move(ctx, plane, dt);
        }
    }
}

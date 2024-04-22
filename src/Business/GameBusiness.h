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
    E_Plane *player = PlaneDomain_Spawn(ctx, playerPos, 100, BLUE, ByInput);

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
        E_Plane *p = PlaneDomain_Spawn(ctx, newPos, 100, BLACK, ByAI);
        assert(p != NULL);
    }

    // 移动
    if (ctx->status == Ingame) {
        for (int i = 0; i < ctx->planeRepo->all->count; i++) {
            E_Plane *plane = (E_Plane *)ctx->planeRepo->all->value[i];
            // const char *txt = TextFormat("i%d\r\n", i);
            // printf(txt);
            assert(plane != NULL);
            PlaneDoMain_Move(ctx, plane, dt);
        }
    }
}

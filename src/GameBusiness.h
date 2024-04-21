#ifndef GAMEBUSINESS_H__
#define GAMEBUSINESS_H__
#endif

#include "PlaneDomain.h"

typedef struct GameBusiness
{

} GameBusiness;

void Game_Enter(GameContext *ctx)
{
    // 生成Player
    Vector2 playerPos = {300, 500};
    E_Plane *player = PlaneDomain_Spawn(ctx, playerPos, 100, BLUE, ByInput);
    ctx->playerID = player->id;

    // 进入InGame
    ctx->status = Ingame;
}

void GameBusiness_Tick(GameContext *ctx, float dt)
{
    // 生成敌人
    

    if (ctx->status == Ingame)
    {
        for (int i = 0; i < ctx->PlaneRepo->all->count; i++)
        {
            E_Plane *plane = ctx->PlaneRepo->all->items[i];
            PlaneDoMain_Move(ctx, plane, dt);
        }
    }
}

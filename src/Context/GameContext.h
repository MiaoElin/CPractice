#ifndef GAMECONTEXT_H__
#define GAMECONTEXT_H__
#endif

#include "../export.h"

typedef struct GameContext {
    PlaneRepo *planeRepo;
    E_Input *input;
    int playerID;
    GameStatus status;
    float waveTimer;
    float interval;
} GameContext;

GameContext *GameContext_New() {
    GameContext *ctx = calloc(1, sizeof(GameContext));
    ctx->planeRepo = PlaneRepo_New();
    ctx->waveTimer = 0;
    ctx->interval = 1;
    return ctx;
}

// E_Plane *Get_Player(GameContext *ctx)
// {
//     return List_TryGetvalue(ctx->planeRepo->all, ctx->playerID);
// }

void GameContext_Free(GameContext *ctx) {
    PlaneRepo_Free(ctx->planeRepo);
    free(ctx);
}
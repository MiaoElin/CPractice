#ifndef GAMECONTEXT_H__
#define GAMECONTEXT_H__
#endif

#include "../export.h"
#include "AssetContext.h"

typedef struct GameContext {
    PlaneRepo *planeRepo;
    E_Input *input;
    AssetContext *assetCtx;
    
    int playerID;
    GameStatus status;
    float waveTimer;
    float interval;
} GameContext;

GameContext *GameContext_New() {
    GameContext *ctx = calloc(1, sizeof(GameContext));
    ctx->planeRepo = PlaneRepo_New();
    ctx->waveTimer = 0;
    ctx->interval = 2;
    return ctx;
}

E_Plane *GameContext_GetPlayer(GameContext *ctx) {
    void *value;
    bool has = PlaneRepo_Find(ctx->planeRepo, ctx->playerID, &value);
    if (!has) {
        return NULL;
    }
    E_Plane *player = (E_Plane *)value;
    return player;
}

void GameContext_Free(GameContext *ctx) {
    PlaneRepo_Free(ctx->planeRepo);
    free(ctx);
}
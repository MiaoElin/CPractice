#ifndef GAMECONTEXT_H__
#define GAMECONTEXT_H__

#include "../Entity/E_Export.h"
#include "../Repo/export.h"
#include "AssetContext.h"

typedef struct GameContext {
    E_Input *input;
    AssetContext *assetCtx;
    GameStatus status;

    // Plane
    PlaneRepo *planeRepo;
    int playerID;
    float waveTimer;
    float interval;

    // Bullet
    BulletRepo *bulletRepo;
} GameContext;

GameContext *GameContext_New() {
    GameContext *ctx = calloc(1, sizeof(GameContext));
    ctx->planeRepo = PlaneRepo_New();
    ctx->waveTimer = 0;
    ctx->interval = 2;
    ctx->bulletRepo = BulletRepo_New();
    return ctx;
}

E_Plane *GameContext_GetPlayer(GameContext *ctx) {
    E_Plane *value;
    bool has = PlaneRepo_Find(ctx->planeRepo, ctx->playerID, &value);
    if (!has) {
        return NULL;
    }
    E_Plane *player = value;
    return player;
}

void GameContext_Free(GameContext *ctx) {
    PlaneRepo_Free(ctx->planeRepo);
    BulletRepo_Free(ctx->bulletRepo);
    free(ctx);
}
#endif

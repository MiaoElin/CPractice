#ifndef GAMECONTEXT_H__
#define GAMECONTEXT_H__
#endif

#include "export.h"

typedef struct GameContext
{
    PlaneRepo *PlaneRepo;
    E_Input *input;
    int playerID;
    GameStatus status;
} GameContext;

GameContext *New_GameContext()
{
    GameContext *ctx = calloc(1, sizeof(GameContext));
    ctx->PlaneRepo = New_PlaneRepo();
    return ctx;
}

E_Plane *Get_Player(GameContext *ctx)
{
    return List_TryGetvalue(ctx->PlaneRepo->all, ctx->playerID);
}

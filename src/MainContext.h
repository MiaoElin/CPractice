#ifndef MAINCONTEXT_H__
#define MAINCONTEXT_H__
#endif

#include "GameContext.h"

typedef struct MainContext
{
    E_Input *input;
    GameContext *gameCtx;

} MainContext;

MainContext *New_MainContext()
{
    MainContext *ctx = calloc(1, sizeof(MainContext));
    ctx->input = New_Input();
    ctx->gameCtx = New_GameContext();
    ctx->gameCtx->input = ctx->input;
    return ctx;
}

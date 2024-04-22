#ifndef MAINCONTEXT_H__
#define MAINCONTEXT_H__
#endif

#include "GameContext.h"

typedef struct MainContext {
    E_Input *input;
    GameContext *gameCtx;
} MainContext;

MainContext *New_MainContext() {
    MainContext *ctx = calloc(1, sizeof(MainContext));
    ctx->input = E_Input_New();
    ctx->gameCtx = GameContext_New();
    ctx->gameCtx->input = ctx->input;
    return ctx;
}

void MainCtx_Free(MainContext *ctx) {
    E_Input_Free(ctx->input);
    GameContext_Free(ctx->gameCtx);
    free(ctx);
}

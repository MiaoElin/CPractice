#ifndef LOGINPANELBUSINESS_H__
#define LOGINPANELBUSINESS_H__

#include "../Domain/UIDomain.h"

void LoginBusiness_Enter(MainContext *ctx) {
    UIDomain_LoginPanel_Open(ctx->uiCtx);
}

void LoginBusiness_Tick(MainContext *ctx) {
    // TO do 按键检测
    LoginPanel *panel = ctx->uiCtx->loginPanel;

    if (panel->isOpen) {
        // 简易
        if (IsKeyPressed(KEY_F1)) {
            ctx->gameCtx->status = GameStatus_Enter;
            UIDomain_LoginPanel_Close(ctx->uiCtx);
        }
    }
}

void LoginBusiness_Draw(MainContext *ctx) {
    UIDomain_LoginPanel_Draw(ctx->uiCtx);
}

#endif
#ifndef UIDOMAIN_H__
#define UIDOMAIN_H__

#include "import.h"

void UIDomain_LoginPanel_Open(UIContext *ctx) {
    LoginPanel_Ctor(ctx->loginPanel);
}

void UIDomain_LoginPanel_Close(UIContext *ctx) {
    ctx->loginPanel->isOpen = false;
}

void UIDomain_LoginPanel_Draw(UIContext *ctx) {
    if (ctx->loginPanel->isOpen) {
        LoginPanel_Draw(ctx->loginPanel);
    }
}

#endif
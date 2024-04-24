#ifndef UIDOMAIN_H__
#define UIDOMAIN_H__

#include "UIContext.h"

void UIDomain_LoginPanel_Open(UIContext *ctx) {
    if (ctx->loginPanel == NULL) {
        LoginPanel_Ctor(ctx->loginPanel);
    }
}

void UIDomain_LoginPanel_Close(UIContext*ctx){
    
}

#endif
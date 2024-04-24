#ifndef UICONTEXT_H__
#define UICONTEXT_H__

#include "../Panel/Panel_export.h"

typedef struct UIContext {
    LoginPanel *loginPanel;
} UIContext;

UIContext *UIContext_New() {
    UIContext *ctx = (UIContext *)malloc(sizeof(UIContext));
    ctx->loginPanel = LoginPanel_New();
}

void UIContext_Free(UIContext *ctx) {
    LoginPanel_Free(ctx->loginPanel);
    free(ctx);
}

#endif

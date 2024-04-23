#ifndef ASSETCONTEXT_H__
#define ASSETCONTEXT_H__
#endif

#include "../import.h"

typedef struct AssetContext {
    Texture2D player1;
    Texture2D enemy1;

} AssetContext;

AssetContext *AssetContext_New() {
    AssetContext *assets = calloc(1, sizeof(AssetContext));
    assets->player1 = LoadTexture("E:/Project/Clan/Assets/player1.png");
    assets->enemy1 = LoadTexture("E:/Project/Clan/Assets/enemy1.png");
    return assets;
}

void AssetContext_Free(AssetContext *assetCtx) {
    UnloadTexture(assetCtx->enemy1);
    UnloadTexture(assetCtx->player1);
    free(assetCtx);
}
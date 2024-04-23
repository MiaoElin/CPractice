#ifndef BULLETDOMAIN_H__
#define BULLETDOMAIN_H__
#endif

#include "../Context/MainContext.h"

E_Bullet* BulletDomain_Spawn(GameContext* ctx, Vector2 pos, Ally ally, Vector2 faceDir) {
    Texture2D bullet;
    float moveSpeed;
    Movetype moveType;

    // player
    if (ally == Player) {
        bullet = ctx->assetCtx->bullet1;
        moveSpeed = 400;
        moveType = ByStatick;
    }
    // 敌人
    if (ally == Enemy) {
        bullet = ctx->assetCtx->bullet2;
        moveSpeed = 200;
        moveType = ByTrack;
    }
    E_Bullet* bul = E_Bullet_New(pos, bullet, moveSpeed, moveType, ally, faceDir);
}

void BullletDomain_Move(GameContext* ctx, E_Bullet* bul, Vector2 dir, float dt) {
    if (bul->movetype == ByStatick) {
        Vector2 dir = {0, -1};
        E_Bullet_Move(bul, dir, dt);
    } else if (bul->movetype == ByTrack) {
        // 找最近的敌人，向敌人移动
        E_Plane* player = GameContext_GetPlayer(ctx);
        Vector2 dir = Vector2Subtract(player->pos, bul->pos);
    }
}
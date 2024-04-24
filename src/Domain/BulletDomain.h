#ifndef BULLETDOMAIN_H__
#define BULLETDOMAIN_H__

#include "import.h"

E_Bullet* BulletDomain_Spawn(GameContext* ctx, Vector2 pos, AllyEnum ally, Vector2 faceDir) {
    Texture2D bullet;
    float moveSpeed;
    Movetype moveType;

    // player
    if (ally == Ally_Player) {
        bullet = ctx->assetCtx->bullet1;
        moveSpeed = 400;
        moveType = Movetype_ByStatick;
    }
    // 敌人
    if (ally == Ally_Enemy) {
        bullet = ctx->assetCtx->bullet2;
        moveSpeed = 200;
        moveType = Movetype_ByTrack;
    }
    E_Bullet* bul = E_Bullet_New(pos, bullet, moveSpeed, moveType, ally, faceDir);
}

void BulletDomain_ShootBul(GameContext* ctx, E_Plane* plane, float dt) {
    float timer = plane->timer;
    float interval = plane->interval;
    timer += dt;
    if (timer >= interval) {
        timer = 0;
        if (plane->ally == Ally_Player) {
            if (ctx->input->isShootBul) {
                BulletDomain_Spawn(ctx, plane->pos, Ally_Player, plane->faceDir);
            }
        } else if (plane->ally == Ally_Enemy) {
            BulletDomain_Spawn(ctx, plane->pos, Ally_Player, plane->faceDir);
        }
    }
}

void BullletDomain_Move(GameContext* ctx, E_Bullet* bul, Vector2 dir, float dt) {
    if (bul->movetype == Movetype_ByStatick) {
        Vector2 dir = {0, -1};
        E_Bullet_Move(bul, dir, dt);
    } else if (bul->movetype == Movetype_ByTrack) {
        // 找最近的敌人，向敌人移动
        E_Plane* player = GameContext_GetPlayer(ctx);
        Vector2 dir = Vector2Subtract(player->pos, bul->pos);
    }
}
#endif

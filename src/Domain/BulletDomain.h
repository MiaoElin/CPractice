#ifndef BULLETDOMAIN_H__
#define BULLETDOMAIN_H__

#include "import.h"

E_Bullet* BulletDomain_Spawn(GameContext* ctx, Vector2 pos, AllyEnum ally, Vector2 faceDir) {
    Texture2D bullet;
    float moveSpeed;
    Movetype moveType;
    int damage;
    Vector2 size = {16, 16};
    // player
    if (ally == Ally_Player) {
        bullet = ctx->assetCtx->bullet1;
        moveSpeed = 400;
        moveType = Movetype_ByStatick;
        damage = 10;
    }
    // 敌人
    if (ally == Ally_Enemy) {
        bullet = ctx->assetCtx->bullet2;
        moveSpeed = 200;
        moveType = Movetype_ByTrack;
        damage = 5;
    }
    E_Bullet* bul = E_Bullet_New(pos, damage, size, bullet, moveSpeed, moveType, ally, faceDir);
    bul->id = ctx->bulletRepo->bulletRecord++;
    BulletRepo_Add(ctx->bulletRepo, (long)bul->id, bul);
}

void BullletDomain_Move(GameContext* ctx, E_Bullet* bul, float dt) {
    if (bul->movetype == Movetype_ByStatick) {
        Vector2 dir = {0, -1};
        E_Bullet_Move(bul, dir, dt);
    } else if (bul->movetype == Movetype_ByTrack) {
        // 找最近的敌人，向敌人移动
        E_Plane* player = GameContext_GetPlayer(ctx);
        Vector2 dir = Vector2Subtract(player->pos, bul->pos);
        E_Bullet_Move(bul, dir, dt);
    }
}

bool BulletDomain_FindNearlyEnemy(GameContext* ctx, Vector2 bulPos, AllyEnum bullAlly, E_Plane** plane) {

    bool has = PlaneRepo_FindNearlyPlane(ctx->planeRepo, bulPos, bullAlly, plane);
    // printf("has nearlyenemy,id is :%d\r\n", plane->id);
    return has;
}

void BulletDomain_Remove(GameContext* ctx, E_Bullet* bul, E_Plane* plane) {
    bool isInteract = PF_IsCircle_Rect_Interact(plane->pos, plane->size, bul->pos, bul->size);
    if (isInteract) {
        // 子弹死亡
        bul->isDead = true;
        // 飞机扣血
        plane->hp -= bul->damage;
        printf("%f\r\n", plane->hp);
        if (plane->hp <= 0) {
            // 飞机死亡
            printf("has palne dead\r\n");
            plane->isDead = true;
        }
    }
}

void BulletDomain_Draw(GameContext* ctx) {
    E_Bullet* allBullet[2048];
    int bulletCount = BulletRepo_TakeAll(ctx->bulletRepo, allBullet);
    for (int i = 0; i < bulletCount; i++) {
        E_Bullet* bul = allBullet[i];
        E_Bullet_Draw(bul);
    }
}
#endif

// #include "BulletDomain.h"

// void BullletDomain_Move(GameContext* ctx, E_Bullet* bul, float dt) {
//     if (bul->movetype == Movetype_ByStatick) {
//         Vector2 dir = {0, -1};
//         E_Bullet_Move(bul, dir, dt);
//     } else if (bul->movetype == Movetype_ByTrack) {
//         // 找最近的敌人，向敌人移动
//         E_Plane* player = GameContext_GetPlayer(ctx);
//         Vector2 dir = Vector2Subtract(player->pos, bul->pos);
//         E_Bullet_Move(bul, dir, dt);
//     }
// }
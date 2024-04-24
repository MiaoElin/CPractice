#ifndef BULLET_H_
#define BULLET_H_

#include "E_import.h"

typedef struct E_Bullet {
    int id;
    Vector2 pos;
    float moveSpeed;
    Texture2D texture;
    Movetype movetype;
    AllyEnum ally;
    Vector2 faceDir;
} E_Bullet;

E_Bullet* E_Bullet_New(Vector2 pos, Texture2D texture, float moveSpeed, Movetype moveType, AllyEnum ally, Vector2 faceDir) {
    E_Bullet* bul = (E_Bullet*)malloc(sizeof(E_Bullet));
    bul->pos = pos;
    bul->moveSpeed = moveSpeed;
    bul->texture = texture;
    bul->movetype = moveType;
    bul->ally = ally;
    bul->faceDir = faceDir;
    return bul;
}

void E_Bullet_Move(E_Bullet* bul, Vector2 dir, float dt) {
    dir = Vector2Normalize(dir);
    dir = Vector2Scale(dir, bul->moveSpeed * dt);
    bul->pos = Vector2Add(bul->pos, dir);
}

void E_Bullet_Free(E_Bullet* bul) {
    free(bul);
}

void E_Bullet_Draw(E_Bullet* bul) {
}
#endif

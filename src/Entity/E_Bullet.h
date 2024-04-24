#ifndef BULLET_H_
#define BULLET_H_

#include "E_import.h"

typedef struct E_Bullet {
    int id;
    Vector2 pos;
    Vector2 size; // 方形 长宽
    float moveSpeed;
    Texture2D texture;
    Movetype movetype;
    AllyEnum ally;
    Vector2 faceDir;
    int damage;

    bool isDead;
} E_Bullet;

E_Bullet* E_Bullet_New(Vector2 pos, int damage, Vector2 size, Texture2D texture, float moveSpeed, Movetype moveType, AllyEnum ally, Vector2 faceDir) {
    E_Bullet* bul = (E_Bullet*)malloc(sizeof(E_Bullet));
    bul->pos = pos;
    bul->size = size;
    bul->moveSpeed = moveSpeed;
    bul->texture = texture;
    bul->movetype = moveType;
    bul->ally = ally;
    bul->faceDir = faceDir;
    bul->isDead = false;
    bul->damage = damage;
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
    Rectangle sour = {0, 0, bul->texture.width, bul->texture.height};
    Rectangle dest = {bul->pos.x, bul->pos.y, bul->texture.width, bul->texture.height};
    Vector2 center = {bul->texture.width / 2, bul->texture.height / 2};
    Vector2 star = {0, -1};
    float rotation = Vector2Angle(star, bul->faceDir);
    rotation = rotation * 180 / M_PI;
    // printf("%f\n", rotation);
    // printf("%f %f\r\n",plane->faceDir.x,plane->faceDir.y);
    DrawTexturePro(bul->texture, sour, dest, center, rotation, WHITE);
}

#endif

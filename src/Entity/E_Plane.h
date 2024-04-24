#ifndef E_PLANE_H__
#define E_PLANE_H__

#include <math.h>
#include "E_import.h"

#define M_PI		3.14159265358979323846

typedef struct E_Plane {
    Vector2 pos;
    int id;
    float speed;
    Movetype movetype;
    Texture2D texture;
    AllyEnum ally;
    Vector2 faceDir;
    // bullet
    float timer;
    float interval;

} E_Plane;

E_Plane *Plane_New(Vector2 pos, float speed, Texture2D texture, Movetype movetype, AllyEnum ally, Vector2 faceDir, float interval) {
    E_Plane *plane = calloc(1, sizeof(E_Plane));
    plane->pos = pos;
    plane->texture = texture;
    plane->speed = speed;
    plane->movetype = movetype;
    plane->ally = ally;
    plane->faceDir = faceDir;
    plane->timer = 0;
    plane->interval = interval;
    return plane;
}

void Plane_Move(E_Plane *plane, Vector2 moveAxis, float dt) {
    // 归一化
    moveAxis = Vector2Normalize(moveAxis);
    // 向量乘以float
    Vector2 dir = Vector2Scale(moveAxis, plane->speed * dt);
    // 向量相加,得到新方向
    plane->pos = Vector2Add(plane->pos, dir);
}

void Plane_Draw(E_Plane *plane) {
    Rectangle sour = {0, 0, plane->texture.width, plane->texture.height};
    Rectangle dest = {plane->pos.x, plane->pos.y, plane->texture.width, plane->texture.height};
    Vector2 center = {plane->texture.width / 2, plane->texture.height / 2};
    Vector2 star = {0, -1};
    float rotation = Vector2LineAngle(star, plane->faceDir);
    rotation = rotation * 180 / M_PI;
    // printf("%f\n", rotation);
    printf("%f %f\r\n",plane->faceDir.x,plane->faceDir.y);
    DrawTexturePro(plane->texture, sour, dest, center, rotation, WHITE);
}

void Plane_Free(void *plane) {
    free(plane);
}
#endif

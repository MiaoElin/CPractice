#ifndef E_PLANE_H__
#define E_PLANE_H__
#endif

// #include "E_Import.h"

typedef struct E_Plane
{
    Vector2 pos;
    int id;
    Color color;
    float speed;
} E_Plane;

E_Plane *NewPlane(Vector2 pos, float speed, Color color, int id)
{
    E_Plane *plane = calloc(1, sizeof(E_Plane));
    plane->pos = pos;
    plane->color = color;
    plane->speed = speed;
    plane->id = id;
    return plane;
}

void PlaneMove(E_Plane *plane, Vector2 moveAxis, float dt)
{
    // 归一化
    moveAxis = Vector2Normalize(moveAxis);
    // 向量乘以float
    Vector2 dir = Vector2Scale(moveAxis, plane->speed * dt);
    // 向量相加,得到新方向
    plane->pos = Vector2Add(plane->pos, dir);
}

#ifndef PUREFUNCTION_H__
#define PUREFUNCTION_H__
#endif

#include "import.h"

Vector2 PF_GetRDVector2(int width, int height)
{
    float x = (float)(rand() % width);
    float y = (float)(rand() % height);
    Vector2 v = {x, y};
    return v;
}

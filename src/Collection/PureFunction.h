#ifndef PUREFUNCTION_H__
#define PUREFUNCTION_H__

#include "import.h"
#include <stdlib.h>

Vector2 PF_GetRDVector2(int width, int height) {
    float x = (float)(rand() % width);
    float y = (float)(rand() % height);
    Vector2 v = {x, y};
    return v;
}

bool PF_IsCircle_Rect_Interact(Vector2 circlePos, Vector2 circleSize, Vector2 rectPos, Vector2 rectSize) {
    Vector2 rectSizeHalf = {rectSize.x / 2, rectSize.y / 2};
    Vector2 leftTop = {rectPos.x - rectSize.x / 2 - circleSize.x, rectPos.y - rectSize.y / 2 - circleSize.y};
    Vector2 rightBottom = Vector2Add(Vector2Add(rectPos, rectSizeHalf), circleSize);
    if (circlePos.x <= rightBottom.x && circlePos.x >= leftTop.x && circlePos.y >= leftTop.y && circlePos.y <= rightBottom.y) {
        return true;
    } else {
        return false;
    }
}

bool PF_IsPointInRect(Vector2 pointPos, Vector2 rectPos, Vector2 rectSize) {
    Vector2 rightBottom = Vector2Add(rectPos, rectSize);
    if (pointPos.x >= rectPos.x && pointPos.x <= rightBottom.x && pointPos.y >= rectPos.y && pointPos.y <= rightBottom.y) {
        return true;
    }
    return false;
}

#endif

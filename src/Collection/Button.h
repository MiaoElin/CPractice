#ifndef BUTTON_H__
#define BUTTON_H__

#include "../import.h"

typedef struct Button {
    Vector2 pos;
    Vector2 size;
    Color bgColor;
    char* nameTxt;
    Color txtColor;
} Button;

Button* Button_New(Vector2 pos, Vector2 size, Color bgColor, char* string, Color txtColor) {
    Button* btn = (Button*)malloc(sizeof(Button));
    btn->pos = pos;
    btn->size = size;
    btn->bgColor = bgColor;
    btn->nameTxt = string;
    btn->txtColor = txtColor;
    return btn;
}

void Button_Free(Button* btn) {
    free(btn->nameTxt);
    free(btn);
}

void Button_Draw(Button* btn) {
    DrawRectangleV(btn->pos, btn->size, btn->bgColor);
    DrawText(btn->nameTxt, btn->pos.x, btn->pos.y, 12, btn->txtColor);
}
#endif
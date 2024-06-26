#ifndef LOGINPANEL_H__
#define LOGINPANEL_H__

#include "../Collection/export.h"

typedef struct LoginPanel {
    Button* starBtn;
    bool isOpen;
} LoginPanel;

LoginPanel* LoginPanel_New() {
    LoginPanel* panel = (LoginPanel*)calloc(1, sizeof(LoginPanel));
    panel->isOpen = false;
    return panel;
}

void LoginPanel_Ctor(LoginPanel* panel) {
    panel->isOpen = true;
    Vector2 pos = {250, 250};
    Vector2 size = {100, 30};
    char* name = "Start Game";
    panel->starBtn = Button_New(pos, size, BLACK, name, WHITE);
}

void LoginPanel_Free(LoginPanel* panel) {
    Button_Free(panel->starBtn);
    free(panel);
}

void* LoginPanel_Draw(LoginPanel* panel) {
    Button_Draw(panel->starBtn);
}
#endif
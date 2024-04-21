#ifndef E_INPUT_H__
#define E_INPUT_H__
#endif

#include "E_import.h"

typedef struct E_Input
{
    Vector2 moveAxis;

} E_Input;

E_Input *New_Input()
{
    E_Input *input = calloc(1, sizeof(E_Input));
    return input;
}

void E_Input_Process(E_Input *input)
{
    input->moveAxis.x = 0;
    input->moveAxis.y = 0;
    if (IsKeyDown(KEY_W))
    {
        input->moveAxis.y = -1;
    }
    else if (IsKeyDown(KEY_S))
    {
        input->moveAxis.y = 1;
    }
    else if (IsKeyDown(KEY_A))
    {
        input->moveAxis.x = -1;
    }
    else if (IsKeyDown(KEY_D))
    {
        input->moveAxis.x = 1;
    }
}

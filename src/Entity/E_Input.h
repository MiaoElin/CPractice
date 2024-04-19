#ifndef E_INPUT_H__
#define E_INPUT_H__
#endif

#include "E_Import.h"

typedef struct E_Input
{
    Vector2 moveAxis;

} E_Input;

void E_Input_Process(E_Input *input)
{
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

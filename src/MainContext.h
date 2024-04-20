#ifndef MAINCONTEXT_H__
#define MAINCONTEXT_H__
#endif

#include "export.h"

typedef struct MainContext
{
    E_Input *input;
    PlaneRepo *PlaneRepo;
    int playerID;

} MainContext;

MainContext *New_MainContext()
{
    MainContext *ctx = calloc(1, sizeof(MainContext));
    ctx->input = New_Input();
    ctx->PlaneRepo = New_PlaneRepo();
    return ctx;
}

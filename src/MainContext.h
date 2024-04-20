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
    E_Input *input = calloc(1, sizeof(E_Input));
    PlaneRepo *planeRepo = calloc(1, sizeof(planeRepo));
    MainContext *ctx = calloc(1, sizeof(MainContext));
    ctx->input = input;
    ctx->PlaneRepo = planeRepo;
    return ctx;
}

#include <stdio.h> // 官方库
#include <stdlib.h>
#include "GameBusiness.h"

void DrawAllPlane(void *value);

int main()
{
    printf("Hello World\r\n");

    SampleEntry();
    InitWindow(600, 600, "hello C World");

    MainContext *ctx = New_MainContext();

    Game_Enter(ctx->gameCtx);

    while (!WindowShouldClose())
    {
        // input
        E_Input_Process(ctx->input);

        float dt = GetFrameTime();

        BeginDrawing();
        ClearBackground(WHITE);

        // Tick
        GameBusiness_Tick(ctx->gameCtx, dt);
        
        // 画飞机
        List_Foreach(ctx->gameCtx->PlaneRepo->all, DrawAllPlane);
        // DrawCircleV(player->pos, 50, player->color);

        EndDrawing();
    }
    CloseWindow();

    return 0;
}

void DrawAllPlane(void *value)
{
    E_Plane *plane = value;
    DrawCircleV(plane->pos, 20, plane->color);
}
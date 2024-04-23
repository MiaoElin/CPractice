#include <stdio.h> // 官方库
#include <stdlib.h>
#include <assert.h>
#include "Business/GameBusiness.h"

void DrawAllPlane(void *value);

int main() {

    SetTargetFPS(60);

    // SampleEntry();
    InitWindow(600, 600, "hello C World");

    // printf("1.%d\\r\n",sizeof(void*))

    MainContext *ctx = New_MainContext();
    assert(ctx != NULL);

    Game_Enter(ctx->gameCtx);

    while (!WindowShouldClose()) {
        // input
        float dt = GetFrameTime();

        // Tick
        E_Input_Process(ctx->input);

        BeginDrawing();
        ClearBackground(WHITE);

        GameBusiness_Tick(ctx->gameCtx, dt);

        // 画飞机

        // E_Plane *all = (E_Plane *)PlaneRepo_TakeAll(ctx->gameCtx->planeRepo);
        // int planeCount = PlaneRepo_GetCoutn(ctx->gameCtx->planeRepo);
        // for (size_t i = 0; i < planeCount; i++) {
        //     E_Plane *plane = &all[i];
        //     DrawCircleV(plane->pos, 50, plane->color);
        // }
        EndDrawing();
    }
    CloseWindow();

    // GC
    // 销毁飞机？todo
    // DictionaryByarr_Foreach(ctx->gameCtx->planeRepo->all, Plane_Free);
    MainCtx_Free(ctx);

    return 0;
}

void DrawAllPlane(void *value) {
    E_Plane *plane = (E_Plane *)value;
    DrawCircleV(plane->pos, 20, plane->color);
}
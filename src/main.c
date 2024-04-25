#include <stdio.h> // 官方库
#include <stdlib.h>
#include <assert.h>
#include "import.h"

void DrawAllPlane(void *value);

int main() {

    SetTargetFPS(60);

    // SampleEntry();
    InitWindow(600, 600, "hello C World");

    MainContext *ctx = New_MainContext();
    assert(ctx != NULL);
    LoginBusiness_Enter(ctx);

    while (!WindowShouldClose()) {

        float dt = GetFrameTime();

        // ==== Input ====
        E_Input_Process(ctx->input);

        BeginDrawing();
        ClearBackground(GRAY);

        // ==== Tick ====
        LoginBusiness_Tick(ctx);
        GameBusiness_Tick(ctx->gameCtx, dt);

        // ==== Draw World ====
        GameBusiness_Draw(ctx->gameCtx);

        // ==== Draw UI ====
        LoginBusiness_Draw(ctx);

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
}
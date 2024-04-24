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
        void *allPlane[1024];
        int planeCount = PlaneRepo_TakeAll(ctx->gameCtx->planeRepo, allPlane);
        for (size_t i = 0; i < planeCount; i++) {
            E_Plane *plane = (E_Plane *)allPlane[i];
            Plane_Draw(plane);
        }

        void *allBullet[2048];
        int bulletCount = BulletRepo_TakeAll(ctx->gameCtx->bulletRepo, allBullet);
        printf("BulletCount is: %d\n", bulletCount);
        for (int i = 0; i < bulletCount; i++) {
            E_Bullet *bul = (E_Bullet *)allBullet[i];
            E_Bullet_Draw(bul);
        }
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
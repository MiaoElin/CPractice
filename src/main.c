#include <stdio.h> // 官方库
#include <stdlib.h>
#include "import.h"
#include "MainContext.h"

// void DrawPlane(E_Plane *value);

int main()
{
    printf("Hello World\r\n");

    SampleEntry();
    InitWindow(600, 600, "hello C World");

    MainContext *ctx = New_MainContext();
    // 生成飞机
    Vector2 playerPos = {300, 500};
    E_Plane *player = NewPlane(playerPos, 100, BLUE, ctx->PlaneRepo->idRecord);
    ctx->PlaneRepo->idRecord++;
    ctx->playerID = player->id;
    List_Add(ctx->PlaneRepo->all, player);

    while (!WindowShouldClose())
    {
        // input
        E_Input_Process(ctx->input);

        float dt = GetFrameTime();

        BeginDrawing();
        ClearBackground(WHITE);
        // Tick

        // 移动飞机
        PlaneMove(player, ctx->input->moveAxis, dt);
        float x = ctx->input->moveAxis.x;

        // 画飞机
        // List_Foreach(ctx->PlaneRepo->all, DrawPlane);
        DrawCircleV(player->pos, 50, player->color);

        EndDrawing();
    }
    CloseWindow();

    return 0;
}
// void DrawPlane(E_Plane *value)
// {
//     DrawCircleV(value->pos, 50, value->color);
// }
#define BACKGROUND BLACK
#define TRIANGLE_COLOR BLUE
#include "raylib.h"
void DrawSierpinski(Vector2 p1, Vector2 p2, Vector2 p3, int depth) {
    
    if (depth == 0) {
        DrawTriangle(p1, p2, p3, TRIANGLE_COLOR);
    } else {
        Vector2 m1 = { (p1.x + p2.x) / 2.0f, (p1.y + p2.y) / 2.0f };
        Vector2 m2 = { (p2.x + p3.x) / 2.0f, (p2.y + p3.y) / 2.0f };
        Vector2 m3 = { (p3.x + p1.x) / 2.0f, (p3.y + p1.y) / 2.0f };
        DrawSierpinski(p1, m1, m3, depth - 1);
        DrawSierpinski(m1, p2, m2, depth - 1);
        DrawSierpinski(m3, m2, p3, depth - 1);
    }

}

int main(void) {
    const int screenWidth = 800;
    const int screenHeight = 600;

    SetConfigFlags(0x00000004);
    InitWindow(screenWidth, screenHeight, "Sierpinski Triangle");
    Vector2 p1 = { 400.0f, 50.0f };
    Vector2 p2 = { 100.0f, 550.0f };
    Vector2 p3 = { 700.0f, 550.0f }; 
    int recursionDepth = 7;
    SetTargetFPS(60);
    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(BACKGROUND);
        DrawSierpinski(p1, p2, p3, recursionDepth);
        EndDrawing();
    }
    CloseWindow();
    return 0;
}


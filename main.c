#include <raylib.h>
#include <string.h>

    typedef struct {
        int xPos, yPos; 
        float radius; 
        Color color;
        } Ball;


    void ball_move(Ball *ball, int movexPos, int moveyPos) {
        ball->xPos += movexPos;
	    ball->yPos += moveyPos;
    };

    int main() {
        const int windowWidth = 1200;
        const int windowHeight = 800;

        InitWindow(windowWidth, windowHeight, "First Game");
        SetTargetFPS(60);

        Ball ball1;
        ball1.xPos =+ windowWidth/2;
        ball1.yPos =+ windowHeight/2;
        ball1.radius = 30;
        ball1.color.r = 255;
        ball1.color.b = 255;
        ball1.color.g = 255;
        ball1.color.a = 0;
    

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(BLACK);
        DrawText("raylib is working successfully!", 190, 200, 20, WHITE);
		DrawCircle(ball1.xPos, ball1.yPos, ball1.radius, RED);
        ball_move(&ball1, 2, 2);
        EndDrawing();
    }

    CloseWindow();
    return 0;
}

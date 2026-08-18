#include <raylib.h>
#include <iostream>
#include <string>

class Ball {
    public:
        int xPos, yPos; float radius; std::string color;

        Ball(int xPos, int yPos, float radius, std::string color) :
            xPos(xPos), yPos(yPos), radius(radius), color(color) {
            //std::cout << "constructor executed" << std::endl;
            }
        void ballMove(int movexPos, int moveyPos) {
            this->xPos += movexPos;
			this->yPos += moveyPos;
        }
};

int main() {
    const int windowWidth = 1200;
    const int windowHeight = 800;

    InitWindow(windowWidth, windowHeight, "First Game");
    SetTargetFPS(60);

    Ball ball1((windowWidth/2), (windowHeight/2), 30, "YELLOW");
    

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(BLACK);
        DrawText("raylib is working successfully!", 190, 200, 20, WHITE);
		DrawCircle(ball1.xPos, ball1.yPos, ball1.radius, WHITE);
        ball1.ballMove(2, 2);
        EndDrawing();
    }

    CloseWindow();
    return 0;
}

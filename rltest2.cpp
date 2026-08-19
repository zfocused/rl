#include <raylib.h>
#include <iostream>
#include <string>

class Ball {
public:
    int xPos, yPos; float radius; Color color;

    Ball(int xPos, int yPos, float radius, Color color) :
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
    const int windowHeight = 1000;

    InitWindow(windowWidth, windowHeight, "First Game");
    SetTargetFPS(60);

    Ball ball1((windowWidth/2), (windowHeight/2), 30, Color{0, 121, 241, 255});
    int ballSpeed = 10;
    int movex = ballSpeed, movey = ballSpeed;


    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(BLACK);
        DrawText("raylib is working successfully!", 190, 200, 20, WHITE);
        DrawCircle(ball1.xPos, ball1.yPos, ball1.radius, ball1.color);

        if (ball1.xPos + ball1.radius >= windowWidth) { movex = -ballSpeed; }
        if ((ball1.yPos + ball1.radius) >= windowHeight) { movey = -ballSpeed; }
        if ((ball1.xPos - ball1.radius) <= 0) { movex = ballSpeed; }
        if ((ball1.yPos - ball1.radius) <= 0) { movey = ballSpeed; }

        ball1.ballMove(movex, movey);
        EndDrawing();
    }

    CloseWindow();
    return 0;
}
#include <iostream>
#include <raylib.h>
#include <random>
#include <chrono>
#include <string>
int screenWidth = 1280;
int screenHeight = 720;
Vector2 TargetPos;
int targetRadius = 50; // EASY: 75; MEDIUM: 50; HARD: 20;
int pointerRadius = 5;
double responseTime;
int tries = 0;
std::chrono::duration<double> elapsed_seconds;
bool gameFinished = false;

char* stringToChar(std::string input)
{
    char *output = new char[input.size() +1];
    input.copy(output,input.size()+1);
    output[input.size()] = '\0';
    return output;
}
int main()
{
	srand(time(NULL));
    std::chrono::time_point<std::chrono::system_clock> start, end;
    InitWindow(screenWidth, screenHeight,"Aim_game");
    HideCursor();
    TargetPos.x = rand() % (screenWidth - screenWidth/3) + screenWidth/6;
    TargetPos.y = rand() % (screenHeight - screenHeight/3) + screenHeight/6;
    start = std::chrono::system_clock::now();
    while(!WindowShouldClose())
    {
        if(IsMouseButtonPressed(0)
           && CheckCollisionCircles(TargetPos,targetRadius,GetMousePosition(),pointerRadius))
        {
            TargetPos.x = rand() % (screenWidth - screenWidth/3) + screenWidth/6;
            TargetPos.y = rand() % (screenHeight - screenHeight/3) + screenHeight/6;
            end = std::chrono::system_clock::now();
            elapsed_seconds = end - start;
            responseTime = elapsed_seconds.count();
            start = std::chrono::system_clock::now();
        }
        gameFinished = tries == 10 ? true : false;
        BeginDrawing();
        ClearBackground(LIGHTGRAY);
            DrawCircle(TargetPos.x,TargetPos.y,targetRadius,RED);
            DrawCircle(GetMouseX(),GetMouseY(),pointerRadius,BLUE);
            DrawText(stringToChar(std::to_string(responseTime)),20,20,30,BLACK);//reaction time
        EndDrawing();
    }
    CloseWindow();

    return 0;
}

#include "raylib.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

#define MAX_INPUT_CHARS 4

int main(void)
{
    const int screenWidth = 600;
    const int screenHeight = 400;

    InitWindow(screenWidth, screenHeight, "Guess the Number - Raylib Edition");
    SetTargetFPS(60);

    char input[MAX_INPUT_CHARS + 1] = "\0";
    int letterCount = 0;
    int framesCounter = 0;

    bool gameOver = false;
    bool inputActive = true;
    char message[64] = "Enter a number (1 - 100):";

    srand((unsigned int)time(NULL));
    int targetNumber = rand() % 100 + 1;
    int guess = 0;
    int attempts = 0;

    while (!WindowShouldClose())
    {
        if (inputActive)
        {
            int key = GetCharPressed();

            while (key > 0)
            {
                if ((key >= 48) && (key <= 57) && (letterCount < MAX_INPUT_CHARS))
                {
                    input[letterCount] = (char)key;
                    letterCount++;
                    input[letterCount] = '\0';
                }
                key = GetCharPressed();
            }

            if (IsKeyPressed(KEY_BACKSPACE))
            {
                if (letterCount > 0)
                {
                    letterCount--;
                    input[letterCount] = '\0';
                }
            }

            if (IsKeyPressed(KEY_ENTER) && letterCount > 0)
            {
                guess = atoi(input);
                attempts++;

                if (guess < targetNumber)
                    strcpy(message, "Too low! Try again:");
                else if (guess > targetNumber)
                    strcpy(message, "Too high! Try again:");
                else
                {
                    sprintf(message, "Correct! Attempts: %d. Press R to restart.", attempts);
                    gameOver = true;
                    inputActive = false;
                }

                letterCount = 0;
                input[0] = '\0';
            }
        }

        if (gameOver && IsKeyPressed(KEY_R))
        {
            targetNumber = rand() % 100 + 1;
            strcpy(message, "Enter a number (1 - 100):");
            attempts = 0;
            gameOver = false;
            inputActive = true;
        }

        BeginDrawing();
        ClearBackground(RAYWHITE);

        DrawText("Guess the Number", 20, 20, 30, DARKBLUE);
        DrawText(message, 20, 80, 20, BLACK);

        DrawRectangle(20, 120, 200, 50, LIGHTGRAY);
        DrawText(input, 30, 135, 30, BLACK);
        DrawRectangleLines(20, 120, 200, 50, DARKGRAY);

        if (inputActive)
        {
            if (letterCount < MAX_INPUT_CHARS)
            {
                if (((framesCounter / 20) % 2) == 0) DrawText("_", 30 + MeasureText(input, 30), 135, 30, BLACK);
            }
            framesCounter++;
        }

        EndDrawing();
    }

    CloseWindow();
    return 0;
}

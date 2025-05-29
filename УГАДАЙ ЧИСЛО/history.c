#include "raylib.h"
#include <stdlib.h>
#include <time.h>
#include <stdio.h> 

#define MAX_ITEMS 5

const char *heroes[MAX_ITEMS] = {
    "Brave knight", "Clever thief", "Powerful wizard", "Fearless explorer", "Bold pirate"
};

const char *places[MAX_ITEMS] = {
    "in a distant kingdom", "on an abandoned factory", "in the deep forest", "in outer space", "at the mountain's foot"
};

const char *actions[MAX_ITEMS] = {
    "defeated a dragon", "found a treasure", "won a great battle", "held a grand ball", "uncovered an ancient secret"
};

const char *details[MAX_ITEMS] = {
    "with a magical sword", "on a flying carpet", "to magical music", "with incredible power", "alongside a mystical creature"
};

char story[512];

void GenerateStory() {
    int h = rand() % MAX_ITEMS;
    int p = rand() % MAX_ITEMS;
    int a = rand() % MAX_ITEMS;
    int d = rand() % MAX_ITEMS;

    sprintf(story, "%s %s, %s %s.", heroes[h], places[p], actions[a], details[d]);
}

int main() {
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "Story Generator");

    srand((unsigned int)time(NULL));
    GenerateStory();

    SetTargetFPS(60);
    while (!WindowShouldClose()) {
        if (IsKeyPressed(KEY_SPACE)) {
            GenerateStory();
        }

        BeginDrawing();
        ClearBackground(RAYWHITE);

        DrawText("Press [SPACE] to generate a new story", 120, 40, 20, DARKGRAY);
        DrawText(story, 60, 200, 20, MAROON);

        EndDrawing();
    }

    CloseWindow();
    return 0;
}
#pragma once
#include "SDL.h"
#include "Cell.h"

// debug mode
#define DEBUG_ENABLED

#define FRAME_RATE 1000 / 60

#define WINDOW_WIDTH 400
#define WINDOW_HEIGHT 400

#define SCALE 4

#define ROWS WINDOW_WIDTH / SCALE
#define COLS WINDOW_HEIGHT / SCALE

extern SDL_Window* window;

extern Cell* grid[ROWS][COLS];
extern Cell* next[ROWS][COLS];
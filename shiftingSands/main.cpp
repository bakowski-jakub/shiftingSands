#define SDL_MAIN_HANDLED
#include "SDL.h"
#include "ShiftingSands.h"
#include "Cell.h"

// SDL
SDL_Window* window = nullptr;
SDL_Event event;

// grid
Cell* grid[ROWS][COLS];
Cell* next[ROWS][COLS];

// objects
RenderHandler renderHand;

int main(int argc, char* argv[])
{
	ShiftingSands game = ShiftingSands();
	return 0;
}
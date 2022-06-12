#pragma once
#include "Cell.h"
#include "settings.h"

extern Cell* grid[ROWS][COLS];
extern Cell* next[ROWS][COLS];

class Utility
{	
	Cell bounds;

	// returns true when given X and Y are out of bounds of the grid
	bool isOutOfBounds(uint16_t x, uint16_t y);

	// returns a Cell residing at grid[x][y]
	Cell* GetGrid(uint16_t x, uint16_t y);
	// returns a Cell residing at next[x][y]
	Cell* GetNext(uint16_t x, uint16_t y);

	void switchCells(uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2);
	
};


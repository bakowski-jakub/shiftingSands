#include "Utility.h"
#include "Cell.h"


bool Utility::isOutOfBounds(uint16_t x, uint16_t y) {
	if (x >= ROWS || x <= 0 || y >= COLS || y <= 0) {
		return true;
	}
	else {
		return false;
	}
}

Cell* Utility::GetGrid(uint16_t x, uint16_t y) {
	if (isOutOfBounds(x, y)) {
		return &bounds;
	}
	else {
		return grid[x][y];
	}
}

Cell* Utility::GetNext(uint16_t x, uint16_t y) {
	if (isOutOfBounds(x, y)) {
		return &bounds;
	}
	else {
		return next[x][y];
	}
}
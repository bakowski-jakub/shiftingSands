#include "ShiftingSands.h"
#include <iostream>
#include <string>
#include "vec3.h"
#include "RenderHandler.h"

ShiftingSands::ShiftingSands() {
	init();
}

void ShiftingSands::init() {

	window = SDL_CreateWindow("Shifting Sands", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WINDOW_WIDTH, WINDOW_HEIGHT, 0);
	if (window == nullptr) {
		throw std::runtime_error("Failed to create SDL_Window!");
	}

	renderHand.init();
	running = true;
	loop();
}

void ShiftingSands::pollEvents() {

}

void ShiftingSands::clearNext() {
	memset(next, 0, sizeof(next));
}

void ShiftingSands::updateGrid() {
	_memccpy(grid, next, 0, sizeof(grid));
}

void ShiftingSands::updateParticles() {
	for (uint16_t x = 0; x < ROWS; x++) {
		for (uint16_t y = 0; y < COLS; y++) {
			Cell* value = grid[x][y];
			if (value != 0) {
				value->CellUpdate(x, y);
			}
		}
	}
}

void ShiftingSands::updateWindowTitle() {
	std::string title = "Shifting Sands		FPS: " + std::to_string(fps);
	SDL_SetWindowTitle(window, title.c_str());
}

void ShiftingSands::loop() {
	
	Uint32 before, second = SDL_GetTicks(), after;
	int frame_time, frames = 0;
	
	while (running) {
		before = SDL_GetTicks();

		pollEvents();
		clearNext();
		updateParticles();
		renderHand.draw();
		updateGrid();

		frames++;
		after = SDL_GetTicks();
		frame_time = after - before;

		if (after - second >= 1000) {
			fps = frames;
			frames = 0;
			second = after;
			updateWindowTitle();
		}

		if (FRAME_RATE > frame_time) {
			SDL_Delay(FRAME_RATE - frame_time);
		}

	}
}
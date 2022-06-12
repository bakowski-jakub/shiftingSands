#pragma once
#include "RenderHandler.h"
#include "SDL.h"
#include "Cell.h"
#include "settings.h"

extern RenderHandler renderHand;

class ShiftingSands
{
public:
	ShiftingSands();
	
private:
	int fps;
	bool running = false;

	void init();

	void loop();

	void clearNext();
	void updateGrid();

	void pollEvents();
	void updateParticles();

	void updateWindowTitle();

	void quit();
};


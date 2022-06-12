#pragma once
#include "SDL.h"

extern SDL_Renderer* renderer;

class RenderHandler
{
public:

	SDL_Renderer* renderer = nullptr;

	void init();
	void draw();
	void clear();


};


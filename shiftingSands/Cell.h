#pragma once
#include "vec3.h"
#include "vec2.h"
#include <cstdint>

class Cell
{

public:
	// constructor and destructor
	Cell();
	virtual ~Cell();

	// update function, to be overriden by specific materials
	virtual void CellUpdate(uint16_t x, uint16_t y);
	
	// material id
	uint8_t type;
	
	// get/set color
	vec3 getColor();
	void setColor(int r, int g, int b);

private:
	vec3 color;
};


#include "Cell.h"

vec3 Cell::getColor() {
	return color;
}

void Cell::setColor(int r, int g, int b) {
	color.setX(r);
	color.setY(g);
	color.setZ(b);
}
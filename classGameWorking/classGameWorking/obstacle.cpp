#include "obstacle.h"

using namespace game;

void obstacle::setColor(int r, int g, int b) {
	red = r;
	green = g;
	blue = b;
}

void obstacle::setPosition(ofVec2f position) {
	this->pos = position;
}

ofVec2f obstacle::getPosition() {
	return pos;
}


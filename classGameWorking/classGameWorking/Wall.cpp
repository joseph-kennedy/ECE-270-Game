#include "Wall.h"
#include "obstacle.h"
using namespace game;
void Wall::draw(int wallNumber) {
	ofSetColor(red, green, blue);
	ofFill();
	ofDrawRectangle((barriers.at(wallNumber)).x, (barriers.at(wallNumber)).y, (barriers.at(wallNumber)).w, (barriers.at(wallNumber)).h);
}

void Wall::initWall(int x, int y, int w, int h) {
	int size = 60;

	barrier newWall;
	newWall.x = x * size;
	newWall.y = y * size;
	newWall.w = w * size;
	newWall.h = h * size;
	barriers.push_back(newWall);

	numWalls++;

}
Wall::Wall() {}


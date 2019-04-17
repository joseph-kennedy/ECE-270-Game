#include "coin.h"

using namespace game;


ofVec2f coin::getPosition() {
	return pos;
}

void coin::setPosition(ofVec2f position) {
	pos = position;
}
int coin::getSize() {
	return size; 
}
void coin::init( int location) {
	red = 244;
	green = 232;
	blue = 104;
	size = 10;
	setColor(red, green, blue);
	if (location == 8) {
		location = 1;
		printf("tried to go to location 8");
	}
	printf("location of coin spawn: %d\n", location);
	switch (location) {

	case 1:
		pos.x = ofRandom(600 + 1 + size, 1140 - size - 1);
		pos.y = ofRandom(60 + 1 + size, 360 - size - 1);
		break;
	case 2:
		pos.x = ofRandom(1200 + 1 + size, 1920 - size - 1);
		pos.y = ofRandom(60 + 1 + size, 300 - size - 1);
		break;
	case 3:
		pos.x = ofRandom(60 + 1 + size, 840 - size - 1);
		pos.y = ofRandom(360 + 1 + size, 720 - size - 1);
		break;
	case 4:
		pos.x = ofRandom(960 + 1 + size, 1920 - size - 1);
		pos.y = ofRandom(540 + 1 + size, 720 - size - 1);
		break;
	case 5:
		pos.x = ofRandom(420 + 1 + size, 840 - size - 1);
		pos.y = ofRandom(780 + 1 + size, 1080 - size - 1);
		break;
	case 6:
		pos.x = ofRandom(960 + 1 + size, 1620 - size - 1);
		pos.y = ofRandom(780 + 1 + size, 1020 - size - 1);
		break;
	case 7: 
		pos.x = ofRandom(0 + 1 + size, 540 - size - 1);
		pos.y = ofRandom(60 + 1 + size, 240 - size - 1);
		break;
	}
}

void coin::update() {

}

bool coin::checkSpace() {
	return true;
}

void coin::draw() {
	ofSetColor(red, green, blue);
	ofFill();
	ofDrawCircle(pos.x, pos.y, size);
}

void coin::pickUp() {
	printf("gotcha");
}

coin::coin(int location) {
	init(location);
}

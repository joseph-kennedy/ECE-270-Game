#include "spike.h"
using namespace game;

spike::spike() {
	//init(x, y, num, direct);
}

void spike::init(int x, int y, int num, int direct) {
	
	setColor(255, 0, 0);
	size = 60;

	pos.x = size * x;
	pos.y = size * y;

	direction = direct;
	numb = num;

	if (direction == 1 || direction == 2) {
		if (direction == 1) {
			p1.x = pos.x;
		}
		else {
			p1.x = pos.x + size;
		}

		p1.y = pos.y;
		p2.x = p1.x + size;
		p2.y = p1.y + (size / 2);
		p3.x = p1.x;
		p3.y = p1.y + size;

		if (direction == 2)
			p2.x = p2.x - (2 * size);

		width = size;
		height = numb * size;


	}
	else {
		if (direction == 3) {
			p1.y = pos.y;
		}
		else {
			p1.y = pos.y + size;
		}

		p1.x = pos.x;
		p2.x = p1.x + (size / 2);
		p2.y = p1.y + size;
		p3.x = p1.x + size;
		p3.y = p1.y;

		if (direction == 4)
			p2.y = p2.y - (2 * size);

		width = numb * size;
		height = size;
	}
	triangle newTriangle;/////////////////add values calculated above into vector of triangles
	newTriangle.x = pos.x;
	newTriangle.y = pos.y;
	newTriangle.width = width;
	newTriangle.height = height;
	newTriangle.p1 = p1;
	newTriangle.p2 = p2;
	newTriangle.p3 = p3;
	newTriangle.numb = numb;
	newTriangle.direct = direction;
	triangles.push_back(newTriangle);

}

void spike::draw(int number) {
	ofSetColor(255, 255, 255);
	ofFill();
	ofDrawRectangle((triangles.at(number)).x, (triangles.at(number)).y, (triangles.at(number)).width, (triangles.at(number)).height);

	ofSetColor(red, green, blue);
	ofFill();

	if ((triangles.at(number)).direct == 1 || (triangles.at(number)).direct == 2) {
		for (int i = 0; i < (triangles.at(number)).numb; i++)
			ofDrawTriangle((triangles.at(number)).p1.x, (triangles.at(number)).p1.y + (60*i), (triangles.at(number)).p2.x, (triangles.at(number)).p2.y + (60*i), (triangles.at(number)).p3.x, (triangles.at(number)).p3.y + (60*i));
	}
	else {
		for (int i = 0; i < (triangles.at(number)).numb; i++)
			ofDrawTriangle((triangles.at(number)).p1.x + (60*i), (triangles.at(number)).p1.y, (triangles.at(number)).p2.x + (60*i), (triangles.at(number)).p2.y, (triangles.at(number)).p3.x + (60*i), (triangles.at(number)).p3.y);
	}
}




/*
#include "spike.h"
using namespace game;
spike::spike(int x, int y, int num, int direct) {
	init(x, y, num, direct);
}
void spike::init(int x, int y, int num, int direct) {
	setColor(255, 0, 155);
	size = 60;

	pos.x = size * x;
	pos.y = size * y;

	direction = direct;
	numb = num;

	if (direction == 1 || direction == 2) {
		//Initializes to facing right
		p2.x = pos.x + size;
		p2.y = pos.y + (size / 2);
		p3.x = pos.x;
		p3.y = pos.y + size;

		width = size;
		height = numb * size;

		//Flips the tip to the left
		if (direction == 2)
			p2.x = p2.x - (2 * size);

	}
	else if (direction == 3 || direction == 4) {
		//Initializes pointing down
		p2.x = pos.x + (size / 2);
		p2.y = pos.y + size;
		p3.x = pos.x + size;
		p3.y = pos.y;

		width = numb * size;
		height = size;

		//Flips tip up
		if (direction == 4)
			p2.y = p2.y - (2 * size);
	}
}

void spike::draw() {
	ofSetColor(255, 255, 255);
	ofFill();
	if (direction == 4) {
		ofDrawRectangle(pos.x, pos.y - size, width, height);
	}
	else if (direction == 2) {
		ofDrawRectangle(pos.x - size, pos.y, width, height);
	}
	else {
		ofDrawRectangle(pos.x, pos.y, width, height);
	}

	ofSetColor(red, green, blue);
	ofFill();

	if (direction == 1 || direction == 2) {
		for (int i = 0; i < numb; i++)
			ofDrawTriangle(pos.x, pos.y + (size*i), p2.x, p2.y + (size*i), p3.x, p3.y + (size*i));
	}
	else {
		for (int i = 0; i < numb; i++)
			ofDrawTriangle(pos.x + (size*i), pos.y, p2.x + (size*i), p2.y, p3.x + (size*i), p3.y);
	}
}
*/
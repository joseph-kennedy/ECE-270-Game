
#include "Enemy.h"

using namespace game; 

ofVec2f Enemy::getPosition() {
	return pos;
}
int Enemy::getSize() {
	return size;
}
void Enemy::init(int x, int y, int right) {
	setColor(255, 0, 0);
	//size is representative of a side length of a square
	size = 60;

	pos.x = x * size;
	pos.y = y * size;
	leftX = x * size;
	rightX = right * size;

	velX = 6;
}

void Enemy::update() {
	if (pos.x < leftX || pos.x > rightX)
		velX *= -1;

	pos.x = pos.x + velX;
}

void Enemy::draw() {
	ofSetColor(red, green, blue);
	ofFill();
	ofDrawRectangle(pos.x, pos.y, 0, size, size);
}

Enemy::Enemy(int x, int y, int right) {
	init(x, y, right);
}


/*
#include "Enemy.h"

using namespace game;
ofVec2f Enemy::getPosition() {
	return pos;
}

void Enemy::setPosition(ofVec2f position) {
	pos = position;
}
ofVec2f Enemy::getVelocity() {
	return velocity;
}
void Enemy::setVelocity(ofVec2f velocity) {
	vel = velocity;
}
int Enemy::getSize() {
	return size;
}

Enemy::Enemy(int location) {
	Enemy::init(location);
}
void Enemy::init(int location) {
	red = 255;
	green = 0;
	blue = 0;
	setColor(red, green, blue);
	size = 50;
	printf("location of Enemy spawn: %d", location);
	switch (location) {
		
	case 1:
		pos.x = ofRandom(600 + 1, 1140 - size - 1);
		pos.y = ofRandom(60 + 1, 360 - size - 1);
		break;
	case 2:
		pos.x = ofRandom(1200 + 1, 1920 - size - 1);
		pos.y = ofRandom(60 + 1, 300 - size -1);
		break;
	case 3:
		pos.x = ofRandom(60 + 1, 840 -size - 1);
		pos.y = ofRandom(360 + 1, 720 - size - 1);
		break;
	case 4:
		pos.x = ofRandom(960 + 1, 1920 - size - 1);
		pos.y = ofRandom(540 + 1, 720 - size - 1);
		break;
	case 5:
		pos.x = ofRandom(420 + 1, 840 - size -1);
		pos.y = ofRandom(780 + 1, 1080 - size- 1);
		break;
	case 6:
		pos.x = ofRandom(960 + 1, 1620 - size- 1);
		pos.y = ofRandom(780 + 1, 1020- size - 1);
		break;
	}
	

	int maxSpeed = 5;

	vel.x = ofRandom(maxSpeed * 2) - maxSpeed;
	vel.y = ofRandom(maxSpeed * 2) - maxSpeed;
	
}

void Enemy::update() {

	if (pos.x < 0 || pos.x > ofGetWidth() - size)
		vel.x *= -1;

	if (pos.y < 0 || pos.y > ofGetHeight() - size)
		vel.y *= -1;

	pos += vel;
}

void Enemy::draw() {
	ofSetColor(255, 0, 0);
	ofFill();
	ofDrawRectangle(pos.x, pos.y, size, size);
}


*/



/*
#pragma once
#include "Enemy.h"
#include"GameConfig.h"
using namespace game;

Enemy::Enemy() {
	initEnemy();
	pos.x = radius + ofRandom(ofGetWidth() - 2 * radius);
}


Enemy::Enemy(int rightBound) {
	initEnemy();
	pos.x = radius + ofRandom(ofGetWidth() - rightBound - 2 * radius);
}

void Enemy::initEnemy() {
	timeAlive = ofGetElapsedTimeMillis();/////////////gets the time elapsed since when the app started
	maxTimeAlive = 10000;
	pos.y = radius + ofRandom(ofGetHeight() - 2 * radius);
	vel.x = -GameConfig::ENEMY_MINIMUM_SPEED + ofRandom(2 * GameConfig::ENEMY_MINIMUM_SPEED);
	vel.y = -GameConfig::ENEMY_MINIMUM_SPEED + ofRandom(2 * GameConfig::ENEMY_MINIMUM_SPEED);
}

//void Enemy::initEnemy() {
	//pos.y = radius + ofRandom(ofGetHeight() - 2 * radius);
	//vel.x = -30 + ofRandom(60);
	//vel.y = -30 + ofRandom(60);
//}
void Enemy::draw() {
	if (ofGetElapsedTimeMillis() - timeAlive < maxTimeAlive) {
		ofSetColor(0 + (int)((double)(ofGetElapsedTimeMillis() - timeAlive) / (double)maxTimeAlive * 255), (int)(255 * (1 - ((double)(ofGetElapsedTimeMillis() - timeAlive) / (double)maxTimeAlive))), 0);
	}
	else {
		ofSetColor(255, 0, 0);
	}
	ofDrawCircle(pos.x, pos.y, 0, radius);
}

int Enemy::update(ofVec2f playerPos) {
	pos += vel; // operator overloading

	if (pos.x <= radius || pos.x >= ofGetWidth() - radius) {
		vel.x = -vel.x;
	}

	if (pos.y <= radius || pos.y >= ofGetHeight() - radius) {
		vel.y = -vel.y;
	}
	

	if (sqrt(pow(pos.x - playerPos.x, 2) + pow(pos.y - playerPos.y, 2)) <= GameConfig::ENEMY_RADIUS + GameConfig::PLAYER_RADIUS) {
		return 1;
	}
	else {
		return 0;
	}
}

int Distance(int aX, int aY, int bX, int bY) {
	return (int)sqrt(pow(aX - bX, 2) + pow(aY - bY, 2));
}
*/
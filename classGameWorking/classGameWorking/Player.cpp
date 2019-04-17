#include "Player.h"
#include "GameConfig.h"

using namespace game;

ofVec2f Player::getPosition() {
	return pos;
}

void Player::setPosition(ofVec2f position) {
	pos = position;
}
ofVec2f Player::getVelocity() {
	return velocity;
}
void Player::setVelocity(ofVec2f vel) {
	velocity = vel;
}
int Player::getSize() {
	return size;
}
void Player::init() {
	red = 0;
	green = 255;
	blue = 0;
	setColor(red, green, blue);
	size = 35;

	pos.x = (2 * 60) + size/2;
	pos.y = (15 * 60) + size/2;

	isDownKeyPressed = false;
	isUpKeyPressed = false;
	isLeftKeyPressed = false;
	isRightKeyPressed = false;

	velocity.x = 0;
	velocity.y = 0;
}

void Player::handleMovementKeyPressed(MovementDirection direction) {

	switch (direction) {
	case UP:
		// is not moving up
		if (!isUpKeyPressed) {
			startMovingUp();
			isUpKeyPressed = true;

		}
		break;
	case DOWN:
		// is not moving down
		if (!isDownKeyPressed) {
			startMovingDown();
			isDownKeyPressed = true;
		}
		break;
	case RIGHT:
		// is not moving right
		if (!isRightKeyPressed) {
			startMovingRight();
			isRightKeyPressed = true;
		}
		break;
	case LEFT:
		// is not moving left
		if (!isLeftKeyPressed) {
			startMovingLeft();
			isLeftKeyPressed = true;
		}
		break;
	}
}

void Player::handleMovementKeyReleased(MovementDirection direction) {
	switch (direction) {
	case UP:
		// is actually moving up?
		if (isUpKeyPressed) {
			isUpKeyPressed = false;
			if (isDownKeyPressed) {
				startMovingDown();
			}
			else {
				stopVerticalMovement();
			}
		}
		break;
	case DOWN:
		// is actually moving down?
		if (isDownKeyPressed) {
			isDownKeyPressed = false;
			if (isUpKeyPressed) {
				startMovingUp();
			}
			else {
				stopVerticalMovement();
			}
		}
		break;
	case RIGHT:
		// is actually moving right?
		if (isRightKeyPressed) {
			isRightKeyPressed = false;
			if (isLeftKeyPressed) {
				startMovingLeft();
			}
			else {
				stopHorizontalMovement();
			}
		}
		break;
	case LEFT:
		// is actually moving left?
		if (isLeftKeyPressed) {
			isLeftKeyPressed = false;
			if (isRightKeyPressed) {
				startMovingRight();
			}
			else {
				stopHorizontalMovement();
			}
		}
		break;
	}
}

void Player::startMovingUp() {
	velocity.y = -GameConfig::PLAYER_INITIAL_SPEED;
	acceleration.y = -GameConfig::PLAYER_INITIAL_ACCEL;
}

void Player::startMovingDown() {
	velocity.y = GameConfig::PLAYER_INITIAL_SPEED;
	acceleration.y = GameConfig::PLAYER_INITIAL_ACCEL;
}

void Player::startMovingLeft() {
	velocity.x = -GameConfig::PLAYER_INITIAL_SPEED;
	acceleration.x = -GameConfig::PLAYER_INITIAL_ACCEL;
}

void Player::startMovingRight() {
	velocity.x = GameConfig::PLAYER_INITIAL_SPEED;
	acceleration.x = GameConfig::PLAYER_INITIAL_ACCEL;
}

void Player::stopVerticalMovement() {
	velocity.y = 0;
	acceleration.y = 0;
}

void Player::stopHorizontalMovement() {
	velocity.x = 0;
	acceleration.x = 0;
}



bool Player::checkSpace(ofVec2f delta) {

	return true;
}


void Player::collectCoin() {
	Coins_Collected++;

}

void Player::die() {

}


ofVec2f Player::update() {
	return updatePosition();
	
}

void Player::updateVelocity() {
	velocity += acceleration;
	if (velocity.x > GameConfig::PLAYER_MAX_SPEED) {
		velocity.x = GameConfig::PLAYER_MAX_SPEED;
	}
	else if (velocity.x < -GameConfig::PLAYER_MAX_SPEED) {
		velocity.x = -GameConfig::PLAYER_MAX_SPEED;
	}
	if (velocity.y > GameConfig::PLAYER_MAX_SPEED) {
		velocity.y = GameConfig::PLAYER_MAX_SPEED;
	}
	else if (velocity.y < -GameConfig::PLAYER_MAX_SPEED) {
		velocity.y = -GameConfig::PLAYER_MAX_SPEED;
	}
}

ofVec2f Player::updatePosition() {
	updateVelocity(); 

	ofVec2f delta = velocity;

	if (pos.x + delta.x + size >= ofGetWindowWidth()) {
		delta.x = 0;
		pos.x = ofGetWindowWidth() - size;

	}
	if (pos.x + delta.x <= 0) {
		delta.x = 0;
		pos.x = 0;
	}

	if (pos.y + delta.y + size >= ofGetWindowHeight()) {
		delta.y = 0;
		pos.y = ofGetWindowHeight() - size;

	}
	if (pos.y + delta.y <= 0) {
		delta.y = 0;
		pos.y = 0;

	}
	return delta;
}

Player::Player() {
	init();
}

Player::Player(int leftBound) {
	init();
	pos.x = leftBound + ofRandom(ofGetWidth() - leftBound - 2 * size);
	pos.y = size + ofRandom(ofGetHeight() - 2 * size);
}

void Player::draw() {
	ofSetColor(red, green, blue);
	ofDrawRectangle(pos.x, pos.y, size, size);
}
/*
#pragma once

#include "Player.h"
#include "GameConfig.h"
#include "Wall.h"

using namespace game;//////////// Here we say using namespace so that we can use all the variables and
///////////////////////////////// functions we may have declared in namespace game. 

Player p2;

Player::Player() {
	initPlayer();
}

Player::Player(int leftBound) {
	initPlayer();
	position.x = leftBound + ofRandom(ofGetWidth() - leftBound - 2 * radius);
	position.y = radius + ofRandom(ofGetHeight() - 2 * radius);
}

void Player::initPlayer() {
	radius = GameConfig::PLAYER_RADIUS;

	isDownKeyPressed = false;
	isUpKeyPressed = false;
	isLeftKeyPressed = false;
	isRightKeyPressed = false;

	velocity.x = 0;
	velocity.y = 0;
}

void Player::setPosition(ofVec2f position) {
	this->position = position;/////////////////so there is another variable named position from some internal function that 
	////////////////////////////////////////// sets the position. So we do this-> to specify which variable is which
	////////////////////////////////////////// don't have to do this in most cases 
}

ofVec2f Player::getPosition() {
	return position;
}

void Player::setRadius(int radius) {
	this->radius = radius;
}

int Player::getRadius() {
	return radius;
}


ofVec2f Player::update() {
	return updatePosition(GameConfig::UPDATE_PERIOD); ///////////////////////////////////dt is update period
}

void game::Player::updateVelocity(float dt) {
	velocity += acceleration * dt;
}

ofVec2f Player::updatePosition(float dt) {////returns position so enemies can check to see if they have hit player 

	updateVelocity(dt);

	ofVec2f delta = velocity * dt;

	if (position.x + delta.x + radius >= ofGetWindowWidth()) {
		delta.x = 0;
		position.x = ofGetWindowWidth() - radius;

	}
	if (position.x + delta.x - radius <= 0) {
		delta.x = 0;
		position.x = 0 + radius;
	}

	if (position.y + delta.y + radius >= ofGetWindowHeight()) {
		delta.y = 0;
		position.y = ofGetWindowHeight() - radius;

	}
	if (position.y + delta.y - radius <= 0) {
		delta.y = 0;
		position.y = 0 + radius;

	}
	/////////////////////////////////////////////////////////////this for loop cycles through all the walls and checks to make sure
	//////////////////////////////////////////////////////////// the player is not passing through the walls
	for (int i = 0; i < GameConfig::NUMBER_OF_WALLS; i++) {
		if (velocity.x > 0) {
			if (position.x + radius <= GameConfig::WALL_X_POS.at(i) &&
				position.x + delta.x + radius > GameConfig::WALL_X_POS.at(i) &&
				position.y + radius >= GameConfig::WALL_Y_POS.at(i) &&
				position.y - radius <= GameConfig::WALL_Y_POS.at(i) + GameConfig::WALL_HEIGHT.at(i)) {
				delta.x = 0;
				position.x = GameConfig::WALL_X_POS.at(i) - radius;
			}
		}

		else if (velocity.x < 0) {
			if (position.x - radius >= GameConfig::WALL_X_POS.at(i) + GameConfig::WALL_WIDTH.at(i) &&
				position.x + delta.x - radius < GameConfig::WALL_X_POS.at(i) + GameConfig::WALL_WIDTH.at(i) &&
				position.y + radius >= GameConfig::WALL_Y_POS.at(i) &&
				position.y - radius <= GameConfig::WALL_Y_POS.at(i) + GameConfig::WALL_HEIGHT.at(i)) {
				delta.x = 0;
				position.x = GameConfig::WALL_X_POS.at(i) + +GameConfig::WALL_WIDTH.at(i) + radius;
			}
		}
		//// do same thing for y value
		if (velocity.y > 0) {
			if (position.y + radius <= GameConfig::WALL_Y_POS.at(i) &&
				position.y + delta.y + radius > GameConfig::WALL_Y_POS.at(i) &&
				position.x + radius >= GameConfig::WALL_X_POS.at(i) &&
				position.x - radius <= GameConfig::WALL_X_POS.at(i) + GameConfig::WALL_WIDTH.at(i)) {
				delta.y = 0;
				position.y = GameConfig::WALL_Y_POS.at(i) - radius;
			}
		}

		else if (velocity.y < 0) {
			if (position.y - radius >= GameConfig::WALL_Y_POS.at(i) + GameConfig::WALL_HEIGHT.at(i) &&
				position.y + delta.y - radius < GameConfig::WALL_Y_POS.at(i) + GameConfig::WALL_HEIGHT.at(i) &&
				position.x + radius >= GameConfig::WALL_X_POS.at(i) &&
				position.x - radius <= GameConfig::WALL_X_POS.at(i) + GameConfig::WALL_WIDTH.at(i)) {
				delta.y = 0;
				position.y = GameConfig::WALL_Y_POS.at(i) + GameConfig::WALL_HEIGHT.at(i) + radius;
			}
		}
	}

	position += delta;
	return position;

}


void Player::handleMovementKeyPressed(MovementDirection direction) {

	switch (direction) {
	case UP:
		// is not moving up
		if (!isUpKeyPressed) {
			startMovingUp();
			isUpKeyPressed = true;
		}
		break;
	case DOWN:
		// is not moving down
		if (!isDownKeyPressed) {
			startMovingDown();
			isDownKeyPressed = true;
		}
		break;
	case RIGHT:
		// is not moving right
		if (!isRightKeyPressed) {
			startMovingRight();
			isRightKeyPressed = true;
		}
		break;
	case LEFT:
		// is not moving left
		if (!isLeftKeyPressed) {
			startMovingLeft();
			isLeftKeyPressed = true;
		}
		break;
	}
}

void Player::handleMovementKeyReleased(MovementDirection direction) {
	switch (direction) {
	case UP:
		// is actually moving up?
		if (isUpKeyPressed) {
			isUpKeyPressed = false;
			if (isDownKeyPressed) {
				startMovingDown();
			}
			else {
				stopVerticalMovement();
			}
		}
		break;
	case DOWN:
		// is actually moving down?
		if (isDownKeyPressed) {
			isDownKeyPressed = false;
			if (isUpKeyPressed) {
				startMovingUp();
			}
			else {
				stopVerticalMovement();
			}
		}
		break;
	case RIGHT:
		// is actually moving right?
		if (isRightKeyPressed) {
			isRightKeyPressed = false;
			if (isLeftKeyPressed) {
				startMovingLeft();
			}
			else {
				stopHorizontalMovement();
			}
		}
		break;
	case LEFT:
		// is actually moving left?
		if (isLeftKeyPressed) {
			isLeftKeyPressed = false;
			if (isRightKeyPressed) {
				startMovingRight();
			}
			else {
				stopHorizontalMovement();
			}
		}
		break;
	}
}

void Player::startMovingUp() {
	velocity.y = -GameConfig::PLAYER_INITIAL_SPEED;
	acceleration.y = -GameConfig::PLAYER_INITIAL_ACCEL;
}

void Player::startMovingDown() {
	velocity.y = GameConfig::PLAYER_INITIAL_SPEED;
	acceleration.y = GameConfig::PLAYER_INITIAL_ACCEL;
}

void Player::startMovingLeft() {
	velocity.x = -GameConfig::PLAYER_INITIAL_SPEED;
	acceleration.x = -GameConfig::PLAYER_INITIAL_ACCEL;
}

void Player::startMovingRight() {
	velocity.x = GameConfig::PLAYER_INITIAL_SPEED;
	acceleration.x = GameConfig::PLAYER_INITIAL_ACCEL;
}

void Player::stopVerticalMovement() {
	velocity.y = 0;
	acceleration.y = 0;
}

void Player::stopHorizontalMovement() {
	velocity.x = 0;
	acceleration.x = 0;
}



void Player::draw() {
	ofSetColor(244, 229, 66);
	ofDrawCircle(position.x, position.y, 0, radius);
}

int calculateDistance(int aX, int aY, int bX, int bY) {
	return (int)sqrt(pow(aX - bX, 2) + pow(aY - bY, 2));
}

*/
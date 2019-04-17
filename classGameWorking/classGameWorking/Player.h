#pragma once
#include "base.h"
#include "Wall.h"
#include "coin.h"

namespace game {

	class Player : public base
	{
	public:
		enum MovementDirection {
			UP,
			DOWN,
			LEFT,
			RIGHT
		};

		//Sets initial values for player
		void init();

		bool checkSpace(ofVec2f delta);
		void collectCoin();
		void die();
		ofVec2f getPosition();
		void setPosition(ofVec2f position);
		ofVec2f getVelocity();
		void setVelocity(ofVec2f vel);
		int getSize();

		//updates physics
		ofVec2f update();
		// draw method
		void draw();

		//Constructors
		Player();
		Player(int leftBound);

		// Movements methods
		void handleMovementKeyPressed(MovementDirection direction);
		void handleMovementKeyReleased(MovementDirection direction);
		int Coins_Collected = 0;

	private:
		ofVec2f pos;
		ofVec2f velocity;
		ofVec2f acceleration;

		int size;
	

		bool isUpKeyPressed;
		bool isDownKeyPressed;
		bool isRightKeyPressed;
		bool isLeftKeyPressed;

		void startMovingUp();
		void startMovingDown();
		void startMovingLeft();
		void startMovingRight();

		void stopVerticalMovement();
		void stopHorizontalMovement();

		void updateVelocity();
		ofVec2f updatePosition();
	};
}




/*
#pragma once
#include "ofMain.h"

namespace game { ///////////// Here we just say namespace. All the variables or functions we declare will be stored 
	///////////////////////// under the namespace game. We do this for all the .h folders
	class Player {//: public Entity { //  : entity    this shows that Player is a child of parent class Entity

	public:
		enum MovementDirection {
			UP,
			DOWN,
			LEFT,
			RIGHT
		};

		// Constructors
		Player();
		Player(int leftBound);

		// Getter and setters
		void setPosition(ofVec2f position);
		ofVec2f getPosition();
		void setRadius(int radius);
		int getRadius();

		// Movements methods
		void handleMovementKeyPressed(MovementDirection direction);
		void handleMovementKeyReleased(MovementDirection direction);

		// Update physics method
		ofVec2f update();

		// Drawing method
		void draw();
	private:
		int radius;
		ofVec2f position;
		ofVec2f velocity;
		ofVec2f acceleration;

		void initPlayer();

		bool isUpKeyPressed;
		bool isDownKeyPressed;
		bool isRightKeyPressed;
		bool isLeftKeyPressed;

		void startMovingUp();
		void startMovingDown();
		void startMovingLeft();
		void startMovingRight();

		void stopVerticalMovement();
		void stopHorizontalMovement();

		void updateVelocity(float dt);
		ofVec2f updatePosition(float dt);
		int calculateDistance(int aX, int aY, int bX, int bY);

	};

}
*/
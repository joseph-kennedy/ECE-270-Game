#pragma once
#include "ofMain.h"
//#include "ofxXboxController.h"
#include "Player.h"
#include "Enemy.h"
#include "Wall.h"
#include "coin.h"
#include <vector>
#include "spike.h"

namespace game {

	enum GameState {
		STARTING,
		RUNNING,
		ENDED
	};

	class ofGame : public ofBaseApp {
		void setup(); //called once when the app runs
		void update(); //called before every frame is drawn
		void draw(); //draws the next frame

		// Handles key strokes
		void keyPressed(int key);
		void keyReleased(int key);

		void distanceTo();
		void checkWalls();

		void checkCollisions();
		int spawnLocation();

	private:
		float previousTime;
		Player* player;
		coin* Coin;
		int coinSpawnPoint;
		Wall wall;
		Enemy* enemy1;
		Enemy* enemy2;
		Enemy* enemy3;
		Enemy* enemy4;
		Enemy* enemy5;
		Enemy* enemy6;
		Enemy* enemy7;
		Enemy* enemy8;

		
		bool gameOver = false;

		int spawnPoint;
		ofVec2f playerPos;
		ofVec2f playerVel;
		ofVec2f delta;
		int playerSize; 
		ofVec2f enemy1Pos;
		ofVec2f enemy2Pos;
		ofVec2f enemy3Pos;
		ofVec2f enemy4Pos;
		ofVec2f enemy5Pos;
		ofVec2f enemy6Pos;
		ofVec2f enemy7Pos;
		ofVec2f enemy8Pos;

		ofVec2f enemy1Vel;
		int enemySize = 60; 
		int enemyCount;
		ofVec2f coinPos;
		int coinSize; 
		int coinCount;

		spike Spike;
		/*
		spike* spike1;
		spike* spike2;
		spike* spike3;
		spike* spike4;
		spike* spike5;
		spike* spike6;
		spike* spike7;
		spike* spike8;
		spike* spike9;
		spike* spike10;
		spike* spike11;
		spike* spike12;
		spike* spike13;
		spike* spike14;
		spike* spike15;
		spike* spike16;
		spike* spike17;
		spike* spike18;
		*/
	};
}


/*
	public:

		// Main functions of the app
		void setup();       // called once when your app runs
		void update();      // called before every frame is drawn
		void draw();        // draws the next frame
		void exit();        // called when the app is done

		// Handles key strokes
		void keyPressed(int key);
		void keyReleased(int key);

		//void checkCollisions();

	private:

		void initEnemies(int boundary);
		void addEnemy();
		void addEnemy(int boundary);


		GameState state;
		//vector <Enemy*> enemy;
		Enemy enemy;
		Player player;
		Wall wall;
		ofVec2f playerCurrentPos;
		// Handles xbox controller
		//ofxXboxController xbox;
		//Gamepad* gamepad;
		int collision;

	};
	
}*/

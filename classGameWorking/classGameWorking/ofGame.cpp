#pragma once
#include "ofGame.h"
#include "GameConfig.h"

using namespace game;   

/////////////Here is where we define the static variables

int GameConfig::WINDOW_WIDTH = 1920;
int GameConfig::WINDOW_HEIGHT = 900;
int GameConfig::FRAME_RATE = 60;
int GameConfig::PLAYER_RADIUS = 20;
float GameConfig::PLAYER_INITIAL_ACCEL = 2.0f;/////What do these fs mean? 
float GameConfig::PLAYER_INITIAL_SPEED = 0.5f;
float GameConfig::PLAYER_MAX_SPEED = 10.0f;
float GameConfig::UPDATE_PERIOD = 1.0f / GameConfig::FRAME_RATE;

int GameConfig::ENEMY_RADIUS = 50;
float GameConfig::ENEMY_MINIMUM_SPEED = 30.0;
int GameConfig::MAX_INGAME_ENEMIES = 5;


void ofGame::setup() {
	ofSetFrameRate(GameConfig::FRAME_RATE);

	int boundary = (2.0 / 4) * ofGetWidth();
	//initEnemies(boundary);
	
	player = new Player();
	
	
	enemy1 = new Enemy(0, 2, 8);
	enemy2 = new Enemy(10, 3, 18);
	enemy3 = new Enemy(20, 3, 31);
	enemy4 = new Enemy(1, 7, 13);
	enemy5 = new Enemy(1, 10, 13);
	enemy6 = new Enemy(16, 10, 31);
	enemy7 = new Enemy(16, 14, 26);
	enemy8 = new Enemy(7, 15, 13);


	coinSpawnPoint = ofRandom(2, 6);
	Coin = new coin(coinSpawnPoint); 
	wall = Wall();
	Spike = spike();
	wall.initWall(2, 4, 2, 1);
	wall.initWall(9, 0, 1, 6); //continue this for every wall we want to build
	wall.initWall(19, 0, 1, 4);
	wall.initWall(28, 6, 4, 1);
	wall.initWall(20, 8, 4, 1);
	wall.initWall(14, 10, 1, 5);
	wall.initWall(10, 12, 4, 1);
	wall.initWall(5, 14, 1, 4);
	wall.initWall(20, 12, 4, 1);
	wall.initWall(28, 14, 1, 1);

	Spike.init(0, 0, 6, 3);
	Spike.init(10, 0, 9, 3);
	Spike.init(23, 0, 9, 3);
	Spike.init(2, 5, 2, 3);
	Spike.init(28, 5, 4, 4);
	Spike.init(14, 6, 1, 2);
	Spike.init(15, 6, 1, 1);
	Spike.init(19, 8, 1, 2);
	Spike.init(0, 9, 4, 1);
	Spike.init(15, 10, 5, 1);
	Spike.init(24, 12, 1, 1);
	Spike.init(5, 13, 1, 4);
	Spike.init(28, 13, 1, 4);
	Spike.init(6, 14, 4, 1);
	Spike.init(27, 14, 1, 2);
	Spike.init(29, 14, 1, 1);
	Spike.init(28, 15, 1, 3);
	Spike.init(18, 17, 6, 4);

/*
	spike1 = new spike(0, 0, 6, 3);
	spike2 = new spike(10, 0, 9, 3);
	spike3 = new spike(23, 0, 9, 3);
	spike4 = new spike(2, 5, 2, 3);
	spike5 = new spike(28, 5, 4, 4);
	spike6 = new spike(14, 6, 1, 2);
	spike7 = new spike(15, 6, 1, 1);
	spike8 = new spike(19, 8, 1, 2);
	spike9 = new spike(0, 9, 4, 1);
	spike10 = new spike(15, 10, 5, 1);
	spike11 = new spike(24, 12, 1, 1);
	spike12 = new spike(5, 13, 1, 4);
	spike13 = new spike(28, 13, 1, 4);
	spike14 = new spike(6, 14, 4, 1);
	spike15 = new spike(27, 14, 1, 2);
	spike16 = new spike(29, 14, 1, 1);
	spike17 = new spike(28, 15, 1, 3);
	spike18 = new spike(18, 17, 6, 4);
	*/
}
/*
spike1.init( 0, 0, 6, 3 );
spike2.init( 10, 0, 9, 3);
spike3.init( 23, 0, 9, 3);
spike4.init( 2, 5, 2, 3);
spike5.init( 28, 5, 4, 4);
spike6.init( 14, 6, 1, 2);
spike7.init( 15, 6, 1, 1);
spike8.init( 19, 8, 1, 2);
spike9.init( 0, 9, 4, 1);
spike10.init( 15, 10, 5, 1);
spike11.init( 24, 12, 1, 1);
spike12.init( 5, 13, 1, 4);
spike13.init( 28, 13, 1, 4);
spike14.init( 6, 14, 4, 1);
spike15.init( 27, 14, 1, 2);
spike16.init( 29, 14, 1, 1);
spike17.init( 28, 15, 1, 3);
spike18.init( 18, 17, 6, 4);

void ofGame::initEnemies(int boundary) {
	for (int i = 0; i < GameConfig::MAX_INGAME_ENEMIES; i++) {
		addEnemy(boundary);
	}
}

void ofGame::addEnemy() {
	addEnemy(ofGetWidth());
}

void ofGame::addEnemy(int boundary) {
	enemy.push_back( new Enemy(boundary));
}
*/

void ofGame::update() {
	if (gameOver) {
	}
	else{
		enemy1->update();
		enemy2->update();
		enemy3->update();
		enemy4->update();
		enemy5->update();
		enemy6->update();
		enemy7->update();
		enemy8->update();

		delta = player->update();
		checkWalls();
		checkCollisions();
	}
}




void ofGame::draw() {
	if (gameOver) {
		ofSetBackgroundColor(96, 3, 3); //Set red background
		enemy1->draw();
		enemy2->draw();
		enemy3->draw();
		enemy4->draw();
		enemy5->draw();
		enemy6->draw();
		enemy7->draw();
		enemy8->draw();

		Coin->draw();
		player->draw();
		for (int i = 0; i < wall.numWalls; i++) {
			wall.draw(i);
		}
		for (int i = 0; i < Spike.numSpikes; i++) {
			Spike.draw(i);
		}
	
		int COINS_COLLECTED = player->Coins_Collected;
		ofSetColor(255, 255, 255);
		ofFill();
		ofDrawBitmapString("Score: " + ofToString(COINS_COLLECTED), 1260, 42.20);
		ofDrawBitmapString("Game Over", 840, 100);
	}
	else {
		ofSetBackgroundColor(0, 0, 0); //Set black background

		enemy1->draw();
		enemy2->draw();
		enemy3->draw();
		enemy4->draw();
		enemy5->draw();
		enemy6->draw();
		enemy7->draw();
		enemy8->draw();
		Coin->draw();
		player->draw();
		for (int i = 0; i < wall.numWalls; i++) {
			wall.draw(i);
		}
		for (int i = 0; i < Spike.numSpikes; i++) {
			Spike.draw(i);
		}
		/*
		spike1->draw();
		spike2->draw();
		spike3->draw();
		spike4->draw();
		spike5->draw();
		spike6->draw();
		spike7->draw();
		spike8->draw();
		spike9->draw();
		spike10->draw();
		spike11->draw();
		spike12->draw();
		spike13->draw();
		spike14->draw();
		spike15->draw();
		spike16->draw();
		spike17->draw();
		spike18->draw();
		*/
		int COINS_COLLECTED = player->Coins_Collected;
		ofSetColor(255, 255, 255);
		ofFill();
		ofDrawBitmapString("Score: " + ofToString(COINS_COLLECTED), 1260, 42.20);
	}
}


void ofGame::keyPressed(int key) {
	switch (key) {
	case OF_KEY_RIGHT:
		player->handleMovementKeyPressed(Player::RIGHT);
		break;
	case OF_KEY_LEFT:
		player->handleMovementKeyPressed(Player::LEFT);
		break;
	case OF_KEY_UP:
		player->handleMovementKeyPressed(Player::UP);
		break;
	case OF_KEY_DOWN:
		player->handleMovementKeyPressed(Player::DOWN);
		break;
	}
}

void ofGame::keyReleased(int key) {
	switch (key) {
	case OF_KEY_RIGHT:
		player->handleMovementKeyReleased(Player::RIGHT);
		break;
	case OF_KEY_LEFT:
		player->handleMovementKeyReleased(Player::LEFT);
		break;
	case OF_KEY_UP:
		player->handleMovementKeyReleased(Player::UP);
		break;
	case OF_KEY_DOWN:
		player->handleMovementKeyReleased(Player::DOWN);
		break;
	}
}
void ofGame::checkCollisions() {
	playerPos = player->getPosition();
	playerSize = player->getSize();
	coinPos = Coin->getPosition();
	coinSize = Coin->getSize();

		float distance = sqrt(pow(playerPos.x + (int)(playerSize/2) - coinPos.x, 2) + pow(playerPos.y + (int)(playerSize / 2) - coinPos.y, 2));
		distance -= (coinSize + playerSize/2);
		//printf("\nDistance: %lf", distance);
		if (distance <= 0) {
			player->collectCoin();
			coinSpawnPoint = spawnLocation();
			Coin->init(coinSpawnPoint);
		}
		
		enemy1Pos = enemy1->getPosition();
		if (playerPos.x + playerSize > enemy1Pos.x &&
			playerPos.x < enemy1Pos.x + enemySize &&
			playerPos.y + playerSize > enemy1Pos.y &&
			playerPos.y < enemy1Pos.y + enemySize) {
			gameOver = true;
		}

		enemy2Pos = enemy2->getPosition();
		if (playerPos.x + playerSize > enemy2Pos.x &&
			playerPos.x < enemy2Pos.x + enemySize &&
			playerPos.y + playerSize > enemy2Pos.y &&
			playerPos.y < enemy2Pos.y + enemySize) {
			gameOver = true;
		}

		enemy3Pos = enemy3->getPosition();
		if (playerPos.x + playerSize > enemy3Pos.x &&
			playerPos.x < enemy3Pos.x + enemySize &&
			playerPos.y + playerSize > enemy3Pos.y &&
			playerPos.y < enemy3Pos.y + enemySize) {
			gameOver = true;
		}

		enemy4Pos = enemy4->getPosition();
		if (playerPos.x + playerSize > enemy4Pos.x &&
			playerPos.x < enemy4Pos.x + enemySize &&
			playerPos.y + playerSize > enemy4Pos.y &&
			playerPos.y < enemy4Pos.y + enemySize) {
			gameOver = true;
		}

		enemy5Pos = enemy5->getPosition();
		if (playerPos.x + playerSize > enemy5Pos.x &&
			playerPos.x < enemy5Pos.x + enemySize &&
			playerPos.y + playerSize > enemy5Pos.y &&
			playerPos.y < enemy5Pos.y + enemySize) {
			gameOver = true;
		}

		enemy6Pos = enemy6->getPosition();
		if (playerPos.x + playerSize > enemy6Pos.x &&
			playerPos.x < enemy6Pos.x + enemySize &&
			playerPos.y + playerSize > enemy6Pos.y &&
			playerPos.y < enemy6Pos.y + enemySize) {
			gameOver = true;
		}

		enemy7Pos = enemy7->getPosition();
		if (playerPos.x + playerSize > enemy7Pos.x &&
			playerPos.x < enemy7Pos.x + enemySize &&
			playerPos.y + playerSize > enemy7Pos.y &&
			playerPos.y < enemy7Pos.y + enemySize) {
			gameOver = true;
		}

		enemy8Pos = enemy8->getPosition();
		if (playerPos.x + playerSize > enemy8Pos.x &&
			playerPos.x < enemy8Pos.x + enemySize &&
			playerPos.y + playerSize > enemy8Pos.y &&
			playerPos.y < enemy8Pos.y + enemySize) {
			gameOver = true;
		}
}

int ofGame::spawnLocation(){
	playerPos = player->getPosition();
	playerSize = player->getSize();
	if (playerPos.x + playerSize > 600 && playerPos.x < 1140 && playerPos.y + playerSize > 60 && playerPos.y < 360) { // player in region 1
		spawnPoint = ofRandom(2, 8);
	}
	else if (playerPos.x + playerSize > 1200 && playerPos.x < 1920 && playerPos.y + playerSize > 60 && playerPos.y < 300) { // player in region 2
		spawnPoint = ofRandom(2, 8);
		if (spawnPoint == 2) {
			spawnPoint = 1;
		}
	}
	else if (playerPos.x + playerSize > 60 && playerPos.x < 840 && playerPos.y + playerSize > 360 && playerPos.y < 720) { // player in region 3
		spawnPoint = ofRandom(2, 8);
		if (spawnPoint == 3) {
			spawnPoint = 1;
		}
	}
	else if (playerPos.x + playerSize > 960 && playerPos.x < 1920 && playerPos.y + playerSize > 540 && playerPos.y < 720) { // player in region 4
		spawnPoint = ofRandom(2, 8);
		if (spawnPoint == 4) {
			spawnPoint = 1;
		}
	}
	else if (playerPos.x + playerSize > 420 && playerPos.x < 840 && playerPos.y + playerSize > 780 && playerPos.y < 1080) { // player in region 5
		spawnPoint = ofRandom(2, 8);
		if (spawnPoint == 5) {
			spawnPoint = 1;
		}
	}
	else if (playerPos.x + playerSize > 960 && playerPos.x < 1620 && playerPos.y + playerSize > 780 && playerPos.y < 1020) { // player in region 6
		spawnPoint = ofRandom(2, 8);
		if (spawnPoint == 6) {
			spawnPoint = 1;
		}
	}
	else if (playerPos.x + playerSize > 0 && playerPos.x < 540 && playerPos.y + playerSize > 60 && playerPos.y < 240) { //player in region 7
		spawnPoint = ofRandom(2, 8);
		if (spawnPoint == 7) {
			spawnPoint = 1;
		}

	}
	else {
		spawnPoint = ofRandom(1, 8);
	}
	return spawnPoint;
}

void ofGame::checkWalls() {
	playerPos = player->getPosition();
	playerVel = player->getVelocity();
	playerSize = player->getSize();
	for (int i = 0; i < wall.numWalls; i++) {
		if (playerVel.x > 0) {

			if (playerPos.x + playerSize <= wall.barriers.at(i).x &&
				playerPos.x + playerSize + delta.x >= wall.barriers.at(i).x &&
				playerPos.y + playerSize >= wall.barriers.at(i).y &&
				playerPos.y <= wall.barriers.at(i).y + wall.barriers.at(i).h) {
				delta.x = 0;
				playerPos.x = (wall.barriers.at(i).x) - playerSize - 1;

			}
		}

		else if (playerVel.x < 0) {
			if (playerPos.x >= (wall.barriers.at(i)).x + wall.barriers.at(i).w &&
				playerPos.x + delta.x <= (wall.barriers.at(i)).x + wall.barriers.at(i).w &&
				playerPos.y + playerSize >= (wall.barriers.at(i)).y &&
				playerPos.y <= (wall.barriers.at(i)).y + (wall.barriers.at(i)).h) {
				delta.x = 0;
				playerPos.x = (wall.barriers.at(i)).x + wall.barriers.at(i).w + 1;

			}
		}
		//// do same thing for y value
		if (playerVel.y > 0) {

			if (playerPos.y + playerSize <= wall.barriers.at(i).y &&
				playerPos.y + playerSize + delta.y >= wall.barriers.at(i).y &&
				playerPos.x + playerSize >= wall.barriers.at(i).x &&
				playerPos.x <= wall.barriers.at(i).x + wall.barriers.at(i).w) {
				delta.y = 0;
				playerPos.y = (wall.barriers.at(i).y) - playerSize - 1;

			}
		}

		else if (playerVel.y < 0) {
			if (playerPos.y >= (wall.barriers.at(i)).y + wall.barriers.at(i).h &&
				playerPos.y + delta.y <= (wall.barriers.at(i)).y + wall.barriers.at(i).h &&
				playerPos.x + playerSize >= (wall.barriers.at(i)).x &&
				playerPos.x <= wall.barriers.at(i).x + (wall.barriers.at(i)).w) {
				delta.y = 0;
				playerPos.y = wall.barriers.at(i).y + wall.barriers.at(i).h + 1;

			}
		}
	}

	player->setPosition(playerPos + delta);
	
	for (int i = 0; i < Spike.numSpikes; i++) {
		if (playerPos.x + playerSize > (Spike.triangles.at(i)).x &&
			playerPos.x < (Spike.triangles.at(i)).x + (Spike.triangles.at(i)).width &&
			playerPos.y + playerSize >(Spike.triangles.at(i)).y &&
			playerPos.y < (Spike.triangles.at(i)).y + (Spike.triangles.at(i)).height) {
			gameOver = true;
		}
	}

	
	
}


//void ofGame::exit() {
	//xbox.exit();
//}

/*
std::vector<int> GameConfig::WALL_X_POS = { GameConfig::WINDOW_WIDTH / 10, 2 * GameConfig::WINDOW_WIDTH / 10, 3 * GameConfig::WINDOW_WIDTH / 10,
			4 * GameConfig::WINDOW_WIDTH / 10, 5 * GameConfig::WINDOW_WIDTH / 10, 6 * GameConfig::WINDOW_WIDTH / 10, 7 * GameConfig::WINDOW_WIDTH / 10,
			8 * GameConfig::WINDOW_WIDTH / 10, 9 * GameConfig::WINDOW_WIDTH / 10, GameConfig::WINDOW_WIDTH / 10, 2 * GameConfig::WINDOW_WIDTH / 10, 3 * GameConfig::WINDOW_WIDTH / 10,
			4 * GameConfig::WINDOW_WIDTH / 10, 5 * GameConfig::WINDOW_WIDTH / 10, 6 * GameConfig::WINDOW_WIDTH / 10, 7 * GameConfig::WINDOW_WIDTH / 10,
			8 * GameConfig::WINDOW_WIDTH / 10, 9 * GameConfig::WINDOW_WIDTH / 10, };
std::vector<int> GameConfig::WALL_Y_POS = { GameConfig::WINDOW_HEIGHT / 3, GameConfig::WINDOW_HEIGHT / 3, GameConfig::WINDOW_HEIGHT / 3, GameConfig::WINDOW_HEIGHT / 3,
			GameConfig::WINDOW_HEIGHT / 3, GameConfig::WINDOW_HEIGHT / 3, GameConfig::WINDOW_HEIGHT / 3, GameConfig::WINDOW_HEIGHT / 3, GameConfig::WINDOW_HEIGHT / 3,
			2 * GameConfig::WINDOW_HEIGHT / 3, 2 * GameConfig::WINDOW_HEIGHT / 3, 2 * GameConfig::WINDOW_HEIGHT / 3, 2 * GameConfig::WINDOW_HEIGHT / 3, 2 * GameConfig::WINDOW_HEIGHT / 3,
		2 * GameConfig::WINDOW_HEIGHT / 3,  2 * GameConfig::WINDOW_HEIGHT / 3,  2 * GameConfig::WINDOW_HEIGHT / 3,  2 * GameConfig::WINDOW_HEIGHT / 3, };
std::vector<int> GameConfig::WALL_WIDTH = { 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20 };
std::vector<int> GameConfig::WALL_HEIGHT = { 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100 };
int GameConfig::NUMBER_OF_WALLS = 18;
*/
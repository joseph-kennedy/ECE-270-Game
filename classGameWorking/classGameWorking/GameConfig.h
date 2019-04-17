#pragma once

namespace game {

class GameConfig {
public:

	// static int don't change. They are in the same memory spot and are avaliable for everyone
	// you cannot define these values right here. look at ofGame.cpp

	//Frame dith and height
	static int WINDOW_WIDTH;
	static int WINDOW_HEIGHT;
	// How many frames per second to render
	static int FRAME_RATE;
	// How many seconds between updates of the entities in the game
	static float UPDATE_PERIOD;
	// Radius of player in pixels
	static int PLAYER_RADIUS;
	// Initial acceleration of the player when starts moving
	static float PLAYER_INITIAL_ACCEL;
	// Initial speed of the player when starts moving
	static float PLAYER_INITIAL_SPEED;
	// fastest speed 
	static float GameConfig::PLAYER_MAX_SPEED;
	// radius of enemy in pixels
	static int ENEMY_RADIUS;
	// minimum speed enemy will move 
	static float ENEMY_MINIMUM_SPEED;
	// wall position
	//static std::vector<int> WALL_X_POS;
	//static std::vector<int> WALL_Y_POS;
	//static std::vector<int> WALL_WIDTH;
	//static std::vector<int> WALL_HEIGHT;
	//static int NUMBER_OF_WALLS;

	// number of enemies
	static int MAX_INGAME_ENEMIES;

};
}

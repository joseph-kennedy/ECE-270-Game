#pragma once
#include "base.h"
namespace game {

	class Enemy : public base {
	private:
		int velX;
		int leftX;
		int rightX;

	public:
		void init(int x, int y, int right);
		void update();
		void draw();

		Enemy(int x, int y, int right);
		ofVec2f getPosition();
		int getSize();
	};
}




/*
#pragma once
#include "base.h"

namespace game {
	class Enemy : public base
	{
	public:
		void init(int location);
		void update();
		bool checkSpace;
		void draw();

		ofVec2f getPosition();
		void setPosition(ofVec2f position);
		ofVec2f getVelocity();
		void setVelocity(ofVec2f velocity);
		int getSize();

		Enemy(int location);


	private:
		ofVec2f vel; 
		int size;


	};

}
*/

/*
#pragma once
#include "ofMain.h"
#include "GameConfig.h"

namespace game {

	class Enemy  {

	public:

		ofVec2f pos;
		ofVec2f vel;
		int radius = GameConfig::ENEMY_RADIUS;

		//virtual int update(ofVec2f playerPos);
		//virtual void draw();
		int update(ofVec2f playerPos);
		void draw();

		void initEnemy();

		Enemy();
		Enemy(int rightBound);



	private:
	
		int maxTimeAlive;
		int timeAlive;
		int Distance(int aX, int aY, int bX, int bY);


	};

}
*/
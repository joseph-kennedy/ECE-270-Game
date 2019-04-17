#pragma once
#include "obstacle.h"
#include "base.h"

namespace game {

	class coin : public base
	{
	public:

		void init(int location);
		void update();
		bool checkSpace();
		void draw();
		void pickUp();

		ofVec2f getPosition();
		void setPosition(ofVec2f position);
		int getSize();

		//constructor
		coin(int location);
	private: 
		int size;
	};

}
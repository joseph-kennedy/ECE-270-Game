#pragma once
#include "ofVec2f.h"
#include "ofMain.h"


namespace game {

	class base
	{

	public:
		void setColor(int r, int g, int b);

		// Update physics method
		virtual void update(float timeNow, float timeBefore) {};

		// Drawing method
		virtual void draw(float timeNow, float timeBefore) {};

	

	protected:
		ofVec2f pos;
		ofVec2f velocity;
		ofVec2f acceleration;

		
		int green;
		int red;
		int blue;
		int size;

	};

}
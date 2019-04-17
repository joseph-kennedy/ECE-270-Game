#pragma once
#include "ofVec2f.h"
#include "ofMain.h"

//removed base.h in order to seperate entities from obstacles 

namespace game {

	class obstacle
	{
	protected:
		int width;
		int height;

		ofVec2f pos;

		int green;
		int red;
		int blue;
		int size;


	public:

		// Update physics method
		virtual void update(float timeNow, float timeBefore) {};

		// Drawing method
		virtual void draw(float timeNow, float timeBefore) {};

		void setColor(int r, int g, int b);


		// Getter and setter
		void setPosition(ofVec2f position);
		ofVec2f getPosition();
	};

}
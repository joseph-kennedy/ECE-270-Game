#pragma once
#include "obstacle.h"
#include <vector>
namespace game {
	class spike : public obstacle {
	public:
		// 1 is right, 2 is left, 3 is down, 4 is up
		int direction;
		int numb;
		ofVec2f p1;
		ofVec2f p2;
		ofVec2f p3;

		void init(int x, int y, int num, int direct);
		void draw(int number);

		struct triangle {
			int x;
			int y; 
			int width;
			int height;
			ofVec2f p1;
			ofVec2f p2;
			ofVec2f p3;
			int numb;
			int direct;
		};
		typedef struct triangle triangle;

		int numSpikes = 18; 
		vector<triangle> triangles;

		spike::spike();

	};
}



/*
#pragma once
#include "obstacle.h"
namespace game {
	class spike : public obstacle {
	public:
		// 1 is right, 2 is left, 3 is down, 4 is up
		int direction;
		int numb;
		ofVec2f p2;
		ofVec2f p3;

		void init(int x, int y, int num, int direct);
		void draw();

		spike::spike(int x, int y, int num, int direct);

	};
}
*/
#pragma once
#include "ofMain.h"
//#include "ofIntroExample.h"
//#include "ofPendulumExample.h"
/* #include <vector>
vector int <myVals> = {54,87,90,56};
					= (5,-1)
.pop()
.size()
*/
#include "../ofGame.h"


//using namespace examples;
using namespace game;

int main() {
	ofSetupOpenGL(1920, 1080, OF_FULLSCREEN);			// <-------- setup the GL context

	// this kicks off the running of my app
	// can be OF_WINDOW or OF_FULLSCREEN
	// pass in width and height too:

	//ofRunApp(new ofIntroExample());
	//ofRunApp(new ofPendulumExample());
	ofRunApp(new ofGame());//////////////////////////////////how does this work? 
}

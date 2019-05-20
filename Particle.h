#pragma once
#include "ofMain.h"


class Particle{

	public:

		void setup();
		void update(float windAmt, float forceAmt,  float velAmt, float noiseAmt);
		void draw(int red, int green, int blue, int alpha, int res, float size, float rotate);
		
		ofPoint pos;
		ofPoint vel;
		ofPoint force;
		
		float drag; 
		float uniqueVal;
		float scale;
		
};

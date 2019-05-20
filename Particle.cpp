#include "Particle.h"

void Particle::setup(){
	
	uniqueVal = ofRandom(-10000, 10000);
	
	pos.x = ofRandomWidth();
	pos.y = ofRandomHeight();
	
	vel.x = ofRandom(-3.9, 3.9);
	vel.y = ofRandom(-3.9, 3.9);
	
	force   = ofPoint(0,0,0);
	
	scale = ofRandom(0.5, 1.0);
	
    drag  = ofRandom(0.97, 0.99);
    vel.y = fabs(vel.y);
	
}

//------------------------------------------------------------------
void Particle::update(float windAmt, float forceAmt, float velAmt, float noiseAmt){
		
    float fakeWindX = ofSignedNoise(pos.x * 0.003, pos.y * 0.006, ofGetElapsedTimef() * 0.6) * windAmt;
    
    force.x = fakeWindX * 0.25 + (ofSignedNoise(uniqueVal, pos.y * 0.04) * noiseAmt) * 0.6 * forceAmt;
    force.y = (ofSignedNoise(uniqueVal, pos.x * 0.006, ofGetElapsedTimef()*0.2) * noiseAmt) * 0.09 + 0.18 * forceAmt;
    
    vel *= drag;
    vel += force * 0.4 * forceAmt;
    
    if(pos.y + vel.y > ofGetHeight()+(100)){
        pos.y -= ofGetHeight() + 200;
    }
    if(pos.y + vel.y < -100){
        pos.y += ofGetHeight() + 200;
    }
    
    pos += vel * velAmt;
}

//------------------------------------------------------------------
void Particle::draw(int red, int green, int blue, int alpha, int res, float size, float rotate){

    ofSetCircleResolution(res);
    
    ofSetColor(red, green, blue, alpha);
	ofDrawEllipse(pos.x, pos.y, scale * 2 * size, scale * 2 * size);
   
}


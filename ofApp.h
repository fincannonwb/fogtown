#pragma once

#include "ofMain.h"
#include "Particle.h"
#include "ofxGui.h"
#include "ofxOsc.h"
#include "ofxBlur.h"

#define PORT 8000

class ofApp : public ofBaseApp{
    
public:
    void setup();
    void reset();
    void update();
    void draw();
    void keyPressed(int key);
    
    vector <Particle> particles;
    
    ofxPanel gui;
    ofxBlur blur;
    ofxOscReceiver receive;
    
    ofParameterGroup paraGroup;
    ofParameter<int> red;
    ofParameter<int> green;
    ofParameter<int> blue;
    ofParameter<int> alpha;
    ofParameter<int> num;
    ofParameter<int> res;
    ofParameter<float> size;
    ofParameter<float> windAmt;
    ofParameter<float> forceAmt;
    ofParameter<float> rotate;
    ofParameter<float> velAmt;
    ofParameter<float> noiseAmt;
    ofParameter<float> alfa;
    
    float redSlider;
    float greenSlider;
    float blueSlider;
    float alphaSlider;
    
    float forceSlider;
    float velocitySlider;
    float windSlider;
    float noiseSlider;
    
    float resetButton;
    float sizeSlider;
    float numberSlider;
    float trailSlider;
    float resolutionSlider;
    
    float blurButton;
    
};

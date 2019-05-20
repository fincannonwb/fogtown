#include "ofApp.h"

void ofApp::setup(){
    
    receive.setup(PORT);
    
    ofSetFrameRate(60);
	ofSetVerticalSync(true);
    ofSetBackgroundColor(0);
    ofSetBackgroundAuto(false);
	
//    paraGroup.setName("paraGroup");
//    paraGroup.add(red.set("red", 255, 0, 255));
//    paraGroup.add(green.set("green", 255, 0, 255));
//    paraGroup.add(blue.set("blue", 255, 0, 255));
//    paraGroup.add(alpha.set("alpha", 255, 0, 255));
//
//    paraGroup.add(forceAmt.set("forceAmt", 1, 0, 1));
//    paraGroup.add(velAmt.set("velAmt", 0, -10, 10));
//    paraGroup.add(windAmt.set("windAmt", 1, 0, 1));
//    paraGroup.add(noiseAmt.set("noiseAmt", 2, 0, 2));
//
//    paraGroup.add(num.set("number", 100, 0, 20000));
//    paraGroup.add(res.set("resolution", 64, 3, 64));
//    paraGroup.add(size.set("size", 20, 1, 100));
//    paraGroup.add(alfa.set("trail", 255, 0, 255));
    
    //paraGroup.add(rotate.set("rotate", 0, 0, 90));
    
    redSlider = 255;
    greenSlider = 255;
    blueSlider = 255;
    alphaSlider = 255;
    forceSlider = 1;
    velocitySlider = 1;
    windSlider = 1;
    noiseSlider = 1;
    resetButton = 1;
    sizeSlider = 5;
    numberSlider = 1000;
    trailSlider = 255;
    resolutionSlider = 30;
    blurButton = 1;
    
    
    reset();
    
    gui.setup(paraGroup);
    
    blur.setup(ofGetWidth(), ofGetHeight(), 10, .2, 1);
    
}

void ofApp::reset(){
    particles.assign(numberSlider, Particle());
    for(unsigned int i = 0; i < particles.size(); i++){
        particles[i].setup();
    }
}

//--------------------------------------------------------------
void ofApp::update(){
    
    while(receive.hasWaitingMessages()){
        ofxOscMessage m;
        receive.getNextMessage(&m);
        
        if(m.getAddress()== "/rgba/red"){
            redSlider = m.getArgAsFloat(0);
            cout<<m.getArgAsFloat(0)<<m.getAddress()<<endl;
        }
        
        if(m.getAddress()== "/rgba/green"){
            greenSlider = m.getArgAsFloat(0);
            cout<<m.getArgAsFloat(0)<<m.getAddress()<<endl;
        }
        
        if(m.getAddress()== "/rgba/blue"){
            blueSlider = m.getArgAsFloat(0);
            cout<<m.getArgAsFloat(0)<<m.getAddress()<<endl;

        }
        
        if(m.getAddress()== "/rgba/alpha"){
            alphaSlider = m.getArgAsFloat(0);
            cout<<m.getArgAsFloat(0)<<m.getAddress()<<endl;

        }
        
        if(m.getAddress()== "/movement/force"){
            forceSlider = m.getArgAsFloat(0);
            cout<<m.getArgAsFloat(0)<<m.getAddress()<<endl;

        }
        
        if(m.getAddress()== "/movement/velocity"){
            velocitySlider = m.getArgAsFloat(0);
            cout<<m.getArgAsFloat(0)<<m.getAddress()<<endl;

        }
        
        if(m.getAddress()== "/movement/wind"){
            windSlider = m.getArgAsFloat(0);
            cout<<m.getArgAsFloat(0)<<m.getAddress()<<endl;

        }
        
        if(m.getAddress()== "/movement/noise"){
            noiseSlider = m.getArgAsFloat(0);
            cout<<m.getArgAsFloat(0)<<m.getAddress()<<endl;

        }
        
        if(m.getAddress()== "/circles/reset"){
            resetButton = m.getArgAsFloat(0);
            cout<<m.getArgAsFloat(0)<<m.getAddress()<<endl;

        }
        
        if(m.getAddress()== "/circles/size"){
            sizeSlider = m.getArgAsFloat(0);
            cout<<m.getArgAsFloat(0)<<m.getAddress()<<endl;
            
        }
        
        if(m.getAddress()== "/circles/number"){
            numberSlider = m.getArgAsFloat(0);
            cout<<m.getArgAsFloat(0)<<m.getAddress()<<endl;

        }
        
        if(m.getAddress()== "/circles/trail"){
            trailSlider = m.getArgAsFloat(0);
            cout<<m.getArgAsFloat(0)<<m.getAddress()<<endl;

        }
        
        if(m.getAddress()== "/circles/resolution"){
            resolutionSlider = m.getArgAsFloat(0);
            cout<<m.getArgAsFloat(0)<<m.getAddress()<<endl;

        }
        
        if(m.getAddress()== "/rgba/blur"){
            blurButton = m.getArgAsFloat(0);
            cout<<m.getArgAsFloat(0)<<m.getAddress()<<endl;
            
        }
        
       
        
        if(resetButton == 0) {
            reset();
            resetButton = 1;
        }
    }
    
	for(unsigned int i = 0; i < particles.size(); i++){
		particles[i].update(windSlider, forceSlider, velocitySlider, noiseSlider);
	}
    
//    blur.setScale(ofMap(slider1, 0, 1, 0, 10, true));
//    blur.setRotation(ofMap(slider2, 0, 1, -PI, PI,true));
}

//--------------------------------------------------------------
void ofApp::draw(){
    
     if (blurButton == 0) {
    
    blur.begin();
         
     }
    ofSetColor(0, trailSlider);
    ofDrawRectangle(-100, -100, ofGetWidth()+100, ofGetHeight()+100);
    


	for(unsigned int i = 0; i < particles.size(); i++){

		particles[i].draw(redSlider*i*0.001, greenSlider*i*0.001, blueSlider*i*0.001, alphaSlider, resolutionSlider, sizeSlider, rotate);
      
	}
     if (blurButton == 0) {
    blur.end();
     }
    
    if (blurButton == 0) {
    
    blur.draw();
    }
    //gui.draw();
}
//--------------------------------------------------------------

void ofApp::keyPressed(int key){
}

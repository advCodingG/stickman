#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    int w = ofGetWidth();
    int h = ofGetHeight();
    fbo.allocate(w, h, GL_RGB32F_ARB); //frame buffer object
    //32 bit float vs 16 bit float
    
    fbo.begin();
    ofClear(255, 255, 255);
    fbo.end();
   
    backgroundImage.loadImage("background.jpg");
    
    ofEnableSmoothing();
    ofEnableAntiAliasing();
    ofEnableAlphaBlending();
    
}

//--------------------------------------------------------------
void ofApp::update(){



    for (int i = 0; i < happyStickmen.size(); i ++) {
      //  erase the stickman from the vector when he is out of the window
        if(happyStickmen[i].leftFoot.x > ofGetWindowWidth()){
            happyStickmen.erase( happyStickmen.begin() + i);
        
        }
    
    }
    
    for (int j = 0; j < sadStickmen.size(); j ++) {

        if(sadStickmen[j].leftFoot.x > ofGetWindowWidth()){
            sadStickmen.erase( sadStickmen.begin() + j);
            
        }
        
    }

}

//--------------------------------------------------------------
void ofApp::draw(){
    
    fbo.begin();
    ofSetCircleResolution(500);
    backgroundImage.draw(0, 0);
    
    ofSetColor(0);
    ofDrawBitmapString("Press 'h' for happy stickmen", 100,100);
    ofDrawBitmapString("Press 's' for sad stickmen", 100,130);

    for(int i = 0; i<happyStickmen.size(); i++){

        happyStickmen[i].draw();
        
    }
    
    for(int j = 0; j<sadStickmen.size(); j++){
        sadStickmen[j].draw();
    }
    
    fbo.end();
    
    ofSetColor(255, 255, 255);
    fbo.draw(0, 0);
//    cout << happyStickmen.size();

    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if(key == 'h'){
        //add one happy stickman to the vector when key h is pressed
        happyStickman _happyStickman;
        _happyStickman.setup();
        happyStickmen.push_back(_happyStickman);
    }
    
    if(key == 's'){
        //add one sad stickman to the vector when key s is pressed
        sadStickman _sadStickman;
        _sadStickman.setup();
        sadStickmen.push_back(_sadStickman);

    
    }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
   
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}

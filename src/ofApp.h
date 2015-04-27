#pragma once

#include "ofMain.h"
#include "sadStickman.h"
#include "happyStickman.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
    
    ofFbo fbo;
    ofImage backgroundImage;
//    ofPoint hand, leftFoot, rightFoot, head, midPoint;
//    float leftArmDeg,leftArmRad, rightArmDeg, rightArmRad, leftLegDeg, leftLegRad,
//    rightLegDeg, rightLegRad;
//    
//    ofPolyline leftleg;
    ofPoint startingPos;
    vector<sadStickman> sadStickmen;
    vector<happyStickman> happyStickmen;
};

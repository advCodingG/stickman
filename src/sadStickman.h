//
//  sadStickman.h
//  stickFigure
//
//  Created by Glenna Xie on 4/26/15.
//
//

#ifndef __stickFigure__sadStickman__
#define __stickFigure__sadStickman__

#include "ofMain.h"

class sadStickman{
    
public:
    sadStickman();
    void setup();
    void update();
    void draw();
    
    ofPoint hand, leftFoot, rightFoot, head, midPoint, startingPos;
    float leftLegDeg, leftLegRad, rightLegDeg, rightLegRad, time;

};


#endif /* defined(__stickFigure__sadStickman__) */

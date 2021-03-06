//
//  happyStickman.h
//  stickFigure
//
//  Created by Glenna Xie on 4/26/15.
//
//

#ifndef __stickFigure__happyStickman__
#define __stickFigure__happyStickman__

#include "ofMain.h"

class happyStickman{
    
public:
    happyStickman();
    void setup();
    void update();
    void draw();
    

    ofPoint leftHand, rightHand, leftFoot, rightFoot, head, midPoint, startingPos, leftJoint, rightJoint, leftKnee, rightKnee;
    float leftArmDeg,leftArmRad, rightArmDeg, rightArmRad, leftLegDeg, leftLegRad,
    rightLegDeg, rightLegRad;

    float time;
    ofPolyline rightArm, leftArm, leftLeg, rightLeg;
};


#endif /* defined(__stickFigure__happyStickman__) */

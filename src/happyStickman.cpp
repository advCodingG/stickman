//
//  happyStickman.cpp
//  stickFigure
//
//  Created by Glenna Xie on 4/26/15.
//
//

#include "happyStickman.h"

happyStickman::happyStickman(){
  //   startingPos = ofVec2f(0 , 500);
}

void happyStickman::setup(){
    startingPos = ofPoint(0, 500);

}

void happyStickman::update(){
    
    
    
}

void happyStickman::draw(){
   // time = time0;
    time = ofGetElapsedTimef();
 
    float integral;
    float fractional  = modf(time, &integral);

    ofSetLineWidth(10);
    ofSetColor(0); //figure color
    
    //left arm
    if (remainder(integral, 2)== 0){
        leftArmDeg = fractional * 25 - 25;
        
    }else{
        leftArmDeg = -fractional* 25;
    }
    leftArmRad = ofDegToRad(leftArmDeg);
    
    ofPushMatrix();
    
    startingPos.x += 3;
    ofTranslate(startingPos.x+ fractional ,500);
    ofPoint neck = ofPoint(0,sin(leftArmRad)*20);

    leftHand = ofPoint(  50 * sin(leftArmRad),   50 * cos(leftArmRad));
    leftJoint = ofPoint(leftHand.x - 12, (neck.y + leftHand.y)/2);
    leftArm.clear();
    leftArm.lineTo(neck);
    leftArm.lineTo(leftJoint);
    ofCircle(leftJoint, 4);
    leftArm.lineTo(leftHand);
    leftArm.draw();
    // ofLine(neck, leftHand);
    ofCircle(leftHand, 4);
    
    //right arm
    
    rightArmDeg = - leftArmDeg;
    rightArmRad = ofDegToRad(rightArmDeg);
    rightHand = ofPoint( 50 * sin(rightArmRad),   50 * cos(rightArmRad));
    rightJoint = ofPoint(rightHand.x - 12, (neck.y + rightHand.y)/2 );
    rightArm.clear();
    //rightArm.lineTo(0,0);
    rightArm.lineTo(neck);
    rightArm.lineTo(rightJoint );
    rightArm.lineTo(rightHand);
    ofCircle(rightJoint, 4);
    rightArm.draw();

    
    ofCircle(rightHand, 4);
    
    
    //left leg
    ofTranslate(0, 50);
    ofPoint midPoint = ofPoint(0,sin(leftArmRad)*20);
    if (remainder(integral, 2)== 0){
        leftLegDeg = fractional * 20 - 20;
        
    }else{
        leftLegDeg = -fractional*20;
    }
    leftLegRad = ofDegToRad(leftLegDeg);
    
    leftFoot = ofPoint(  80 * sin(leftLegRad),   80 * cos(leftLegRad));
    ofCircle(leftFoot.x + 1.5,leftFoot.y, 5);
    ofLine(midPoint, leftFoot);
    
    
    //right leg
    rightLegDeg = - leftLegDeg;
    rightLegRad = ofDegToRad(rightLegDeg);
    rightFoot = ofPoint( 80 * sin(rightLegRad),   80 * cos(rightLegRad));
    ofLine(midPoint, rightFoot);
    ofCircle(rightFoot.x + 1.5,rightFoot.y, 5);
    
    
    //torso
   
   ofLine(0, 0, 0,-60);
    
    //head
    ofFill();
    head  = ofPoint(-2, -61 + (sin(leftArmRad)*20) );
    ofCircle(head, 15);
    ofPopMatrix();
}


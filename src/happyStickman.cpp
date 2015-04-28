//
//  happyStickman.cpp
//  stickFigure
//
//  Created by Glenna Xie on 4/26/15.
//
//

#include "happyStickman.h"

happyStickman::happyStickman(){
  
}

void happyStickman::setup(){
    //every stickman starts marching from the left of the screen
    startingPos = ofPoint(0, 500);

}

void happyStickman::update(){
    
    
    
}

void happyStickman::draw(){

    time = ofGetElapsedTimef();
 
    float integral;
    float fractional  = modf(time, &integral); //this method returns the fractional and the integral part of ofGetElapsedTimef(), later used to loop the swinging of the arms and the legs

    ofSetLineWidth(10);
    ofSetColor(0); //figure color
    
    //left arm
    if (remainder(integral, 2)== 0){
        leftArmDeg = fractional * 25 - 25; //when the intergral part is a multiply of 2, the arm swings down
        
    }else{
        leftArmDeg = -fractional* 25; // otherwise the arm swings up
    }
    leftArmRad = ofDegToRad(leftArmDeg);
    
    //all the drawings are within ofPushMatrix and ofPopMatrix so that all the ofTranslate clears every time a new stickman is generated
    ofPushMatrix();
    
    startingPos.x += 3;//this controls how fast the stickman walks
    ofTranslate(startingPos.x+ fractional ,500);
    
    //the neck point goes slightly up and down when the stickman walks
    ofPoint neck = ofPoint(0,sin(leftArmRad)*20);
    
    //the length of the arm is 50, the leftHand point is determined by the degree that the arm swings
    leftHand = ofPoint(  50 * sin(leftArmRad),   50 * cos(leftArmRad));
    
    //left elbow
    leftJoint = ofPoint(leftHand.x - 12, (neck.y + leftHand.y)/2);
    
    //leftArm is a polyline
    leftArm.clear();
    leftArm.lineTo(neck);
    leftArm.lineTo(leftJoint);
    ofCircle(leftJoint, 4);
    leftArm.lineTo(leftHand);
    leftArm.draw();
    
    ofCircle(leftHand, 4);
    
    //right arm is doing the same motion except for everything is the opposite of the left arm
    rightArmDeg = - leftArmDeg;
    rightArmRad = ofDegToRad(rightArmDeg);
    rightHand = ofPoint( 50 * sin(rightArmRad),   50 * cos(rightArmRad));
    rightJoint = ofPoint(rightHand.x - 12, (neck.y + rightHand.y)/2 );
    
    rightArm.clear();
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
    
    //head also goes slightly up and down
    ofFill();
    head  = ofPoint(-2, -61 + (sin(leftArmRad)*20) );
    ofCircle(head, 15);
    
    ofPopMatrix();
}


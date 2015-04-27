//
//  sadStickman.cpp
//  stickFigure
//
//  Created by Glenna Xie on 4/26/15.
//
//

#include "sadStickman.h"

sadStickman::sadStickman(){
    
}
void sadStickman::setup(){
    startingPos = ofPoint(0, 400);
}

void sadStickman::update(){



}

void sadStickman::draw(){
    

time = ofGetElapsedTimef();
float integral;
float fractional  = modf(time, &integral);

//   ofBackground(255, 255, 255);

ofSetLineWidth(5);
ofSetColor(50,50,50);

//arm
    ofPushMatrix();
    startingPos.x += 1;
ofTranslate( startingPos.x + fractional,400);
ofPoint neck = ofPoint(0, - 10+sin(leftLegRad)*10);
hand = ofPoint(neck.x+2, neck.y + 40);
ofLine(neck, hand);
ofCircle(hand.x+1,hand.y, 3);


//left leg
ofTranslate(-20, 30);
ofPoint midPoint = ofPoint(0,sin(leftLegRad)*10);
if (remainder(integral, 2)== 0){
    leftLegDeg = fractional * 20 - 20;
    
}else{
    leftLegDeg = -fractional*20;
}
leftLegRad = ofDegToRad(leftLegDeg);

leftFoot = ofPoint(  60 * sin(leftLegRad),   60 * cos(leftLegRad));
ofCircle(leftFoot.x + 1.5,leftFoot.y, 4);
ofLine(midPoint, leftFoot);


//right leg
rightLegDeg = - leftLegDeg;
rightLegRad = ofDegToRad(rightLegDeg);
rightFoot = ofPoint( 60 * sin(rightLegRad),   60 * cos(rightLegRad));
ofLine(midPoint, rightFoot);
ofCircle(rightFoot.x + 1.5,rightFoot.y, 4);


//torso

ofCurve(0, 20, midPoint.x, midPoint.y, 20, -40, 60, -30);

//head
ofFill();
head  = ofPoint(27, -45 + (sin(leftLegRad)*10) );
ofCircle(head, 10);

    ofPopMatrix();

}
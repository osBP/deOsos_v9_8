//
//  ofxTetra.cpp
//  deOsos_v9_8
//
//  Created by Oscar David Bravo Peña on 5/31/17.
//
//

#include "ofxTetra.h"

void tetra::initTetraWithRandom(){
    for (int i = 0; i < 4; i++) {
        point[i].x = ofRandom(-100,100);
        point[i].y = ofRandom(-100,100);
        point[i].z = ofRandom(-100,100);
    }
}

void tetra::drawTetra(){
    ofSetColor(255);
    ofDrawLine(point[0], point[1]);
    ofDrawLine(point[0], point[2]);
    ofDrawLine(point[0], point[3]);
    ofDrawLine(point[1], point[2]);
    ofDrawLine(point[1], point[3]);
    ofDrawLine(point[2], point[3]);
}

void tetra::setTetra(float ax, float ay, float az, float bx, float by, float bz, float cx, float cy, float cz, float dx, float dy, float dz){
    point[0].x = ax;
    point[0].y = ay;
    point[0].z = az;
    point[1].x = bx;
    point[1].y = by;
    point[1].z = bz;
    point[2].x = cx;
    point[2].y = cy;
    point[2].z = cz;
    point[3].x = dx;
    point[3].y = dy;
    point[3].z = dz;
}

ofPoint tetra::getTetraPoint(int index){
    if (0 <= index && index < 4) {
        return point[index];
    }else{
        return point[2];
    }
}

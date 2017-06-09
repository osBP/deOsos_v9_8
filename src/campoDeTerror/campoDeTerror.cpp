//
//  campoDeTerror.cpp
//  deOsos_v9_8
//
//  Created by Oscar David Bravo Peña on 6/6/17.
//
//


#include "ofApp.h"

void ofApp::campoDeTerrorSetup(){
    ofEnableSmoothing();
    ofVec3f origin(0,0,0);
    cam.setTarget(origin);
    shader.load("shadersGL3/shader");
}

void ofApp::campoDeTerrorUpdate(){
    color.w= 0;
    color.x= 0;
    color.y= 0;
    color.z= 0;
}

void ofApp::campoDeTerrorDraw(){
    ofBackground(0);
    float percentX = mouseX / (float)ofGetWidth();
    percentX = ofClamp(percentX, 0, 1);
    ofColor colorLeft = ofColor::magenta;
    ofColor colorRight = ofColor::cyan;
    ofColor colorMix = colorLeft.getLerped(colorRight, percentX);
    ofSetColor(colorMix);
    //cam.setDistance(150);
    cam.begin();
    shader.begin();
    shader.setUniform1f("time", ofGetElapsedTimef());
    ofNoFill();
    triangulation.draw();
    shader.end();
    cam.end();
}

void ofApp::campoDeTerrorKeyPressed(int key){
    if(key == 'r'){
        triangulation.reset();
    }
    triangulation.addPoint( ofPoint( ofRandom(-200,200) , ofRandom(-200,200) , ofRandom(-200,200) ) );
    triangulation.triangulate();
}



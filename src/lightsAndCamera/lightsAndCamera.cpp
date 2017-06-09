//
//  lightsAndCamera.cpp
//  deOsos_v9_8
//
//  Created by Oscar David Bravo Peña on 5/3/17.
//
//

#include "ofApp.h"

void ofApp::lightCameraSetup(){
    target.x=0;
    target.y=0;
    target.z=0;
    lightPoint.x=4000;
    lightPoint.y=4000;
    lightPoint.z=0;
    axis.x=1;
    axis.y=0;
    axis.z=0;
    cam.setTarget(target);
    light.setPointLight();
    ofEnableSmoothing();
    ofEnableDepthTest();
    zoomIn=false;
    zoomOut=false;
    distance = 4000;
    
    
}

void ofApp::lightCameraUpdate(){
    if (rotate)
        cam.rotateAround(0.5, axis , target);
    if (zoomIn) {
        distance-= 10.0;
        cam.setDistance(distance);
    }
    if (zoomOut) {
        distance+= 10.0;
        cam.setDistance(distance);
    }
    cam.setTarget(target);
}

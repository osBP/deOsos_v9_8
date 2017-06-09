//
//  ofxCartesianCylindricalSpherical.cpp
//  Todo_El_Ruido_01
//
//  Created by Oscar David Bravo Peña on 11/27/16.
//
//

#include "ofxCartesianCylindricalSpherical.h"

void ofxCartesianCylindricalSpherical::setSpherical(float rSph, float tSph, float pSph){
    radSpherical = rSph;
    thetaSpherical = tSph;
    phiSpherical = pSph;
    point.x = radSpherical*sinf(thetaSpherical)*cosf(phiSpherical);
    point.y = radSpherical*sinf(thetaSpherical)*sinf(phiSpherical);
    point.z = radSpherical*cosf(thetaSpherical);
}

void ofxCartesianCylindricalSpherical::setCylindrical(float rCyl, float pCyl, float zCyl){
    radCylindrical = rCyl;
    phiCylindrical = pCyl;
    zCylindrical = zCyl;
    point.x = radCylindrical*cosf(phiCylindrical);
    point.y = radCylindrical*sinf(phiCylindrical);
    point.z = zCylindrical;
}

void ofxCartesianCylindricalSpherical::updateSpherical(){
    point.x = radSpherical*sinf(thetaSpherical)*cosf(phiSpherical);
    point.y = radSpherical*sinf(thetaSpherical)*sinf(phiSpherical);
    point.z = radSpherical*cosf(thetaSpherical);
}

void ofxCartesianCylindricalSpherical::updateCylindrical(){
    point.x = radCylindrical*cosf(phiCylindrical);
    point.y = radCylindrical*sinf(phiCylindrical);
    point.z = zCylindrical;
}



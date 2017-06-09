//
//  ofxCartesianCylindricalSpherical.h
//  Todo_El_Ruido_01
//
//  Created by Oscar David Bravo Peña on 11/27/16.
//
//

#ifndef ofxCartesianCylindricalSpherical_h
#define ofxCartesianCylindricalSpherical_h

#include "ofMain.h"


class ofxCartesianCylindricalSpherical{
    
public:
    ofxCartesianCylindricalSpherical(){
        
    }
    ofxCartesianCylindricalSpherical(ofVec3f p){
        point = p;
        
    }
    void setSpherical(float rSph, float tSph, float pSph);
    void setCylindrical(float rCyl, float pCyl, float zCyl);
    void updateSpherical();
    void updateCylindrical();
    
    ofVec3f point;
    
    float radSpherical;
    float thetaSpherical;
    float phiSpherical;

    float radCylindrical;
    float phiCylindrical;
    float zCylindrical;
};

#endif /* ofxCartesianCylindricalSpherical_h*/

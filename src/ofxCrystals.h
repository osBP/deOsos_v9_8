//
//  ofxCrystals.h
//  deOsos_v9_8
//
//  Created by Oscar David Bravo Peña on 5/14/17.
//
//

#ifndef ofxCrystals_h
#define ofxCrystals_h

#include "ofMain.h"
#include "ofxTetra.h"
#include "triangleContainer.h"

class crystal{
public:
    bool drawPeaks;
    bool updatePeaks;
    tetra tetraedrum;
    triangleContainer tContainer[4];
    ofPoint peak;
    ofPoint p, temp1, temp2, temp3, temp4, temp5, temp6;
    
    void initCrystal();
    void updateCrystal();
    void drawCrystal();
};

#endif /* ofxCrystals_h */

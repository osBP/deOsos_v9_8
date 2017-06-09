//
//  ofxTetra.h
//  deOsos_v9_8
//
//  Created by Oscar David Bravo Peña on 5/31/17.
//
//

#ifndef ofxTetra_h
#define ofxTetra_h

#include "ofMain.h"

class tetra{
public:
    ofPoint point[4];
    void initTetraWithRandom();
    void drawTetra();
    void setTetra(ofPoint a, ofPoint b, ofPoint c, ofPoint d);
    void setTetra(float ax, float ay, float az, float bx, float by, float bz,float cx, float cy, float cz, float dx, float dy, float dz);
    ofPoint getTetraPoint(int index);
};

#endif /* ofxTetra_h */

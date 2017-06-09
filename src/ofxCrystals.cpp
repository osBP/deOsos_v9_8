//
//  ofxCrystals.cpp
//  deOsos_v9_8
//
//  Created by Oscar David Bravo Peña on 5/14/17.
//
//

#include "ofxCrystals.h"

void crystal::initCrystal(){
    //tetraedrum.initTetraWithRandom();
    
    tetraedrum.setTetra(100,   0,   0,
                          0, 100,   0,
                        -50,   0, 100,
                          0,   0,   0 );
    
    tContainer[0].setBounds(tetraedrum.getTetraPoint(0), tetraedrum.getTetraPoint(1), tetraedrum.getTetraPoint(2));
    
    temp1 = tetraedrum.getTetraPoint(0) + ( tetraedrum.getTetraPoint(1) - tetraedrum.getTetraPoint(0) )/2 ;
    temp2 = tetraedrum.getTetraPoint(0) + ( tetraedrum.getTetraPoint(2) - tetraedrum.getTetraPoint(0) )/2 ;
    temp3 = tetraedrum.getTetraPoint(1) + ( tetraedrum.getTetraPoint(2) - tetraedrum.getTetraPoint(1) )/2 ;
    
    //ofLineSegmentIntersection(temp1, tetraedrum.point[2], temp2, tetraedrum.point[1], peak);
    tContainer[0].setElements(1, -50, 100, 0, 100, 0, 100);
    
//    tContainer[1].setBounds(tetraedrum.getTetraPoint(0), tetraedrum.getTetraPoint(1), tetraedrum.getTetraPoint(3));
//    tContainer[2].setBounds(tetraedrum.getTetraPoint(0), tetraedrum.getTetraPoint(2), tetraedrum.getTetraPoint(3));
//    tContainer[3].setBounds(tetraedrum.getTetraPoint(1), tetraedrum.getTetraPoint(2), tetraedrum.getTetraPoint(3));
    
}

void crystal::updateCrystal(){
    if(updatePeaks){
        peak += ( peak - tetraedrum.getTetraPoint(3)) * ( .005 ) ;
    }
}

void crystal::drawCrystal(){
    tetraedrum.drawTetra();
    if (drawPeaks){
        ofSetLineWidth(0.5);
        ofDrawLine(peak, tetraedrum.getTetraPoint(2));
        ofDrawLine(peak, tetraedrum.getTetraPoint(1));
        ofDrawLine(peak, tetraedrum.getTetraPoint(0));
        ofDrawSphere(temp1, 4);
        ofDrawSphere(temp2, 4);
        ofDrawSphere(temp3, 4);
        //ofNoFill();
        //ofDrawTriangle(temp1, temp2, temp3);
        //ofDrawSphere(peak, 4);
        tContainer[0].drawElements();
    }
}

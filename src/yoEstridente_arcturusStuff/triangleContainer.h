//
//  triangleContainer.h
//  triangleContainer_01
//
//  Created by Oscar David Bravo Peña on 8/27/16.
//
//

#ifndef triangleContainer_h
#define triangleContainer_h

#include "ofMain.h"


class triangleContainer{
    
public:
    void setBounds(float,float,float,float,float,float);//2D
    void setBounds(float,float,float,float,float,float,float,float,float);//3D
    void setBounds(ofPoint,ofPoint,ofPoint);
    void setMirrorSegment(char,char);
    void getEquations();
    void drawBoundaries(int);
    void setElements(int n, float minX, float maxX, float minY, float maxY, float minZ, float maxZ);
    void drawElements();
    void moveElements3D();
    bool evaluatePoint(float,float,float);
    void getDistancesABC();
    void getDistancesPABC(float, float);
    void clear();
    
    //void getCoordinates(float *,float*);
    float X[3];
    float Y[3];
    float Z[3];
    float *Xe;
    float *Ye;
    float *Ze;
    float *Re;
    float *Xv;
    float *Yv;
    float *Zv;
    
private:
    float distAB,distBC,distCA;
    float distPA,distPB,distPC;
    int elementsInContainer;
    
    float Mab,Bab,Mbc,Bbc,Mca,Bca;
};

#endif /* triangleContainer_h */

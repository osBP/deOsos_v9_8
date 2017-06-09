//
//  algoSiempre.cpp
//  deOsos_v9_8
//
//  Created by Oscar David Bravo Peña on 5/11/17.
//
//

#include "ofApp.h"

void ofApp::algoSiempreSetup(){
    ofEnableSmoothing();
    ofVec3f origin(0,0,0);
    cam.setTarget(origin);
    //shader.load("shadersGL3/shader");
    crystals.initCrystal();
}

void ofApp::algoSiempreUpdate(){
    crystals.updateCrystal();
}

void ofApp::algoSiempreDraw(){
    ofBackground(0);
    cam.begin();
//    ofPoint origen(0,0,0);
//    ofPoint ejeX(10,0,0);
//    ofPoint ejeY(0,10,0);
//    ofPoint ejeZ(0,0,10);
//    ofSetColor(ofColor::red);
//    ofDrawLine(origen, ejeX);
//    ofSetColor(ofColor::green);
//    ofDrawLine(origen, ejeY);
//    ofSetColor(ofColor::blue);
//    ofDrawLine(origen, ejeZ);
    ofSetColor(255);
    crystals.drawCrystal();
    cam.end();
}

void ofApp::algoSiempreKeyPressed(int key){
    switch (key) {
        case 'r':
            triangulation.reset();
            break;
        case 'a':
            triangulation.addPoint( ofPoint( ofRandom(-200,200) , ofRandom(-200,200) , ofRandom(-200,200) ) );
            triangulation.triangulate();
            break;
        case 'g':
            cout <<"guardando poligono"<<endl
                 <<"num of points: " <<triangulation.getNumPoints()<<endl
                 <<"num of triangles: "<<triangulation.getNumTriangles()<<endl;
            for (int i = 0; i < triangulation.getNumTriangles(); i++) {
                vector<ofPoint> pointsIntriangle =   triangulation.getPointsForITriangle(triangulation.getTriangleAtIndex(i));
                for (int j = 0; j < 3; j++) {
                    cout<<"triangle["<< i <<"].x="<<pointsIntriangle[j].x <<endl
                        <<"triangle["<< i <<"].y="<<pointsIntriangle[j].y<<endl
                        <<"triangle["<< i <<"].z="<<pointsIntriangle[j].z<<endl;
                }
            }
            break;
        case 'd':
            crystals.drawPeaks = !crystals.drawPeaks;
            break;
        case 'u':
            crystals.updatePeaks = !crystals.updatePeaks;
            break;
        case '1':
            algoSiempre = false;
            todoElRuido = true;
            tissue = false;
            break;
        default:
            break;
    }
}

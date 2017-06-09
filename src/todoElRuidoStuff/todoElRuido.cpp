//
//  todoElRuidoUpdate.cpp
//  deOsos_v9_8
//
//  Created by Oscar David Bravo Peña on 5/3/17.
//
//

#include "ofApp.h"


void ofApp::todoElRuidoSetup(){
    
    initParticles();
    initParticleSystem();            //------Particles
    
    particlesScreen = true;
    drawBackground  = true;
    playSaturn = false;
    ofBackground(ofColor::black);
    cam.setDistance(distance);
    start = ofGetElapsedTimef();
    
    
    //---stripes---
    bgFlag=true;
    bgEnable=false;
    
    ofFill();
    n=256;
    descending=true;
    ascending=false;
}

void ofApp::todoElRuidoUpdate(){
    time = ofGetElapsedTimef();
    if (playSaturn) {
        if (glitch == false ) {
            updateParticlesWithDestiny();
        }
        if (glitch == true) {
            updateParticlesWithGlitch();
        }
        lightCameraUpdate();
        float timeDif = time - start;
        timeDif < 30.0? lineFactor = ofMap(timeDif, 0.0, 30.0, 0.0, 1.0): lineFactor = 1.0;
        timeDif < 360.0? positionFactor += ofMap(timeDif, 0.0, 360.0, 0.0, 0.0001) : distance *=1;
        audioUpdate();
    }
    if (playStripes){
        updateStripes();
    }
}

void ofApp::todoElRuidoDraw(){
    if (playSaturn) {
        drawSaturn();
    }
}

void ofApp::todoElRuidoKeyPressed(int key){
    switch (key) {
        case 'f':
            ofToggleFullscreen();
            break;
        case 'r':
            rotate = !rotate;
            break;
        case 'c':
            cout<<"cam distance "<<cam.getDistance()<<" time "<<time<<endl;
            break;
        case 'b':
            drawBackground = !drawBackground;
            break;
        case 's':
            particlesScreen= !particlesScreen;
            break;
        case OF_KEY_UP:
            lineFactor = 0.5;
            break;
        case OF_KEY_DOWN:
            resetParticlesWithRandom();
        case OF_KEY_LEFT:
            gain = 0.4;
            break;
        case OF_KEY_RIGHT:
            gain = 0.9;
            break;
        case '1':
            algoSiempre = false;
            todoElRuido = true;
            tissue = false;
            break;
            break;
        case 'R':
            
            break;
        default:
          
            break;
    }
}

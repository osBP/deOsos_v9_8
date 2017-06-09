//
//  particleStuff.cpp
//  Todo_El_Ruido_01
//
//  Created by Oscar David Bravo Peña on 12/1/16.
//
//

#include "ofApp.h"

void ofApp::initParticles(){
    glitch = false;
    gain = 1.0;
    saturnRatio=700;
    ringExternalRatio= 1000;
    ringInternalRatio = 900;
    for (int i = 0 ; i < NUM; i++) {
        particles[i].setSpherical(ofRandom(100,saturnRatio), ofDegToRad(ofRandom(360))  , ofDegToRad(ofRandom(360)));
        ratios[i]=ofRandom(15,25);
        amplitudes[i] = ofRandom(1,5);
        rotateDegrees[i] = ofRandom(0, 360);
    }
    for (int i = 0; i < NUMRING; i++) {
        rings[i].setCylindrical(ofRandom(ringInternalRatio,ringExternalRatio), ofDegToRad(i), 0);
    }
    
    for (int i = 0; i < NUM; i++) {
        destinys[i].setSpherical(saturnRatio, ofDegToRad((float) i) /* ofDegToRad(ofRandom(360)) */ ,(float) i );
    }
    for (int i = 0; i < NUM; i++)  {
        glitchDestiny[i].point *= 0;
    }
}

void ofApp::updateParticlesWithNoise(){
    for (int i = 0;  i < NUM; i++) {
        particles[i].radSpherical   +=  amplitudes[i] * ofSignedNoise( PHI * time * 0.000002 +i);
        particles[i].thetaSpherical +=  amplitudes[i] * ofSignedNoise( PHI * time * 0.000003 +i);
        particles[i].phiSpherical   +=  amplitudes[i] * ofSignedNoise( PHI * time * 0.000005 +i);
        particles[i].updateSpherical();
    }
}

void ofApp::updateParticlesWithDestiny(){
    for (int i = 0; i < NUM; i++) {
        ofVec3f temporal = destinys[i].point - particles[i].point;
        temporal *= positionFactor;
        particles[i].point += temporal;
    }
}

void ofApp::updateParticlesWithGlitch(){
    for (int i = 0; i < NUM; i++) {
        particles[i].point;
    }
}

void ofApp::resetParticlesWithRandom(){
    for (int i = 0 ; i < NUM; i++) {
        particles[i].setSpherical(ofRandom(100,saturnRatio), ofDegToRad(ofRandom(360))  , ofDegToRad(ofRandom(360)));
        ratios[i]=ofRandom(15,25);
        amplitudes[i] = ofRandom(1,5);
        rotateDegrees[i] = ofRandom(0, 360);
        particles[i].updateSpherical();
    }
}

void ofApp::drawPlanet(){
    ofFill();
    ofPushMatrix();
        if (!strobe)
            ofSetHexColor(0x017FB4);
        else
            ofSetHexColor(0xFE804B);
        for (int i = 0; i < NUM; i++) {
            ofSetLineWidth(1);
            ofVec3f temporal = particles[(i+1)%NUM].point - particles[i].point;
            temporal *= lineFactor;
            if (!strobe)
                ofSetHexColor(0x017FB4);
            else
                ofSetHexColor(0x008C95);
            ofDrawLine(particles[i].point, particles[i].point + temporal);
            if (!strobe)
                ofSetHexColor(0x006F8A);
            else
                ofSetHexColor(0x008C95);
            ofPushMatrix();
                ofDrawCircle(particles[i].point,ratios[i]);
                ofRotateX( ofDegToRad( rotateDegrees[i]));
            ofPopMatrix();
        }
    ofPopMatrix();
}

void ofApp::drawRings(){
    ofPushStyle();
        ofPushMatrix();
            if(!strobe)
                ofSetHexColor(0xD969F4);
            else
                ofSetHexColor(0x26960B);
            ofSetLineWidth(3);
            ofNoFill();
            ofBeginShape();
                for (int i = 0; i < 256; i++) 
                    ofVertex((1300+(right[i]*gain*161.8))*cosf(ofDegToRad((360*i/255))), (800+(right[i]*gain*161.8))*sinf(ofDegToRad((360*i/255))), 0);
            ofEndShape(false);
        ofPopMatrix();
    ofPopStyle();
    
    ofPushStyle();
        ofPushMatrix();
            if(!strobe)
                ofSetHexColor(0xD969F4);
            else
                ofSetHexColor(0x26960B);
            ofSetLineWidth(3);
            ofNoFill();
            ofBeginShape();
                for (int i = 0; i < 256; i++)
                    ofVertex((1350+(right[i]*gain*161.8))*cosf(ofDegToRad((360*i/255))), (850+(right[i]*gain*161.8))*sinf(ofDegToRad((360*i/255))), 0);
            ofEndShape(false);
        ofPopMatrix();
    ofPopStyle();
    
    ofPushStyle();
        ofPushMatrix();
            if(!strobe)
                ofSetHexColor(0xF469B6);
            else
                ofSetHexColor(0x0B9649);
            ofSetLineWidth(3);
            ofNoFill();
            ofBeginShape();
                for (int i = 0; i < 256; i++)
                    ofVertex((1400+(right[i]*gain*323.6))*cosf(ofDegToRad((360*i/255))), (900+(left[i]*gain*323.6))*sinf(ofDegToRad((360*i/255))), 0);
            ofEndShape(false);
        ofPopMatrix();
    ofPopStyle();
    
    ofPushStyle();
        ofPushMatrix();
            if(!strobe)
                ofSetHexColor(0xD969F4);
            else
                ofSetHexColor(0x26960B);
            ofSetLineWidth(3);
            ofNoFill();
            ofBeginShape();
                for (int i = 0; i < 256; i++)
                    ofVertex((1450+(left[i]*gain*161.8))*cosf(ofDegToRad((360*i/255))), (950+(left[i]*gain*161.8))*sinf(ofDegToRad((360*i/255))), 0);
            ofEndShape(false);
        ofPopMatrix();
    ofPopStyle();
    
    ofPushStyle();
        ofPushMatrix();
            if(!strobe)
                ofSetHexColor(0xD969F4);
            else
                ofSetHexColor(0x26960B);
            ofSetLineWidth(3);
            ofNoFill();
            ofBeginShape();
                for (int i = 0; i < 256; i++)
                    ofVertex((1500+(left[i]*gain*161.8))*cosf(ofDegToRad((360*i/255))), (1000+(left[i]*gain*161.8))*sinf(ofDegToRad((360*i/255))), 0);
            ofEndShape(false);
        ofPopMatrix();
    ofPopStyle();
}

void ofApp::drawSaturn(){
    if(drawBackground){
        if (!strobe)
            ofBackground(ofColor::black);
        else
            ofBackground(ofColor::white);
    }
    light.enable();
    if (particlesScreen) {
        cam.begin();
        if (glitch == true){
            ofPushMatrix();
            ofTranslate( ofRandom(-700, 700) , ofRandom(-5000, 5000) , 0);
        }
        drawPlanet();
        if (glitch == true)
            ofPopMatrix();
        drawRings();
        cam.end();
    }
    light.disable();
}

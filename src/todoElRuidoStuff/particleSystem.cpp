//
//  particleSystem.cpp
//  Todo_El_Ruido_01
//
//  Created by Oscar David Bravo Peña on 11/21/16.
//
//

#include "ofApp.h"

void ofApp::initParticleSystem(){
    saturnRatio = 500;
    ringInternalRatio =  800;
    ringExternalRatio = 1000;
    for (int i = 0; i < NUM; ) {
        ofVec3f temporal( ofRandom( -1000 , 1000 ) ,
                          ofRandom( -1000,  1000 ) ,
                          ofRandom( -1000 , 1000 ) );
        if (temporal.distance(target) < saturnRatio) {
            particles[i]=temporal;
            ratios[i] = ofRandom(15, 20);
            amplitudes[i] = ofRandom(5,15);
            i++;
        }
        
    }
    for (int i = 0; i < NUMRING; ) {
        ofVec3f temporal( ofRandom( -1000 , 1000 ) ,
                          ofRandom( -1000 , 1000 ) ,
                          0  );
        if (ringInternalRatio < temporal.distance(target) && temporal.distance(target) < ringExternalRatio) {
            rings[i]=temporal;
            ratiosForRings[i] = ofRandom(15, 20);
            amplitudesForRings[i] = ofRandom(5,15);
            i++;
        }
    }
}

void ofApp::updateParticlesWithNoise(){
    for (int i = 0;  i < NUM; i++) {
        particles[i].point.x +=  amplitudes[i] * ofSignedNoise( PHI * time * 0.2 +i);
        particles[i].point.y +=  amplitudes[i] * ofSignedNoise( PHI * time * 0.3 +i);
        particles[i].point.z +=  amplitudes[i] * ofSignedNoise( PHI * time * 0.5 +i);
    }
    for (int i = 0;  i < NUM; i++) {
        rings[i].point.x +=  amplitudesForRings[i] * ofSignedNoise( PHI * time * 0.2 +i);
        rings[i].point.y +=  amplitudesForRings[i] * ofSignedNoise( PHI * time * 0.3 +i);
    }
    
}

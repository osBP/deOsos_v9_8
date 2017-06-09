//
//  audioStuff.cpp
//  deOsos_v9_8
//
//  Created by Oscar David Bravo Peña on 5/3/17.
//
//

#include "ofApp.h"

void ofApp::audioIn(float *input, int bufferSize, int nChannels){
    float curVol = 0.0;
    // samples are "interleaved"
    int numCounted = 0;
    //lets go through each sample and calculate the root mean square which is a rough way to calculate volume
    for (int i = 0; i < bufferSize; i++){
        left[i]		= input[i*2]*0.5;
        right[i]	= input[i*2+1]*0.5;
        
        curVol += left[i] * left[i];
        curVol += right[i] * right[i];
        numCounted+=2;
    }
    //this is how we get the mean of rms :)
    curVol /= (float)numCounted;
    // this is how we get the root of rms :)
    curVol = sqrt( curVol );
    smoothedVol *= 0.93;
    smoothedVol += 0.07 * curVol;
    bufferCounter++;
}

void ofApp::audioSetup(){
    // 0 output channels,
    // 2 input channels
    // 44100 samples per second
    // 256 samples per buffer
    // 4 num buffers (latency)
    soundStream.printDeviceList();
    //if you want to set a different device id
    //soundStream.setDeviceID(0); //bear in mind the device id corresponds to all audio devices, including  input-only and output-only devices.
    int bufferSize = 256;
    left.assign(bufferSize, 0.0);
    right.assign(bufferSize, 0.0);
    volHistory.assign(400, 0.0);
    bufferCounter	= 0;
    drawCounter		= 0;
    smoothedVol     = 0.0;
    scaledVol		= 0.0;
    soundStream.setup(this, 0, 2, 44100, bufferSize, 4);
    soundStream.start();
}

void ofApp::audioUpdate(){
    scaledVol = ofMap(smoothedVol, 0.0, 0.17, 0.0, 1.0, true);
    //lets record the volume into an array
    volHistory.push_back( scaledVol );
    //if we are bigger the the size we want to record - lets drop the oldest value
    if( volHistory.size() >= 400 ){
        volHistory.erase(volHistory.begin(), volHistory.begin()+1);
    }
    
}

#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    width = ofGetWidth();
    height = ofGetHeight();
    ofSetFrameRate(24);
    ofSetFullscreen(true);
    ofSetBackgroundAuto(false);
    ofHideCursor();
    ofSetCircleResolution(360);
    midiSetup();
    audioSetup();
    
    lightCameraSetup();
    
    todoElRuido = false;
    algoSiempre = false;
    tissue = false;
    campoDeTerror = true;
    
    if(todoElRuido){
        todoElRuidoSetup();
    }
    if(algoSiempre){
        algoSiempreSetup();
    }
    if(tissue){
        voroSetup();
    }
    if(campoDeTerror){
        campoDeTerrorSetup();
    }
}

//--------------------------------------------------------------
void ofApp::update(){
    if(todoElRuido){
        todoElRuidoUpdate();
    }
    if (algoSiempre) {
        algoSiempreUpdate();
    }
    if (tissue) {
        voroUpdate();
    }
    if (campoDeTerror) {
        campoDeTerrorUpdate();
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    if (todoElRuido) {
        todoElRuidoDraw();
    }
    if (algoSiempre) {
        algoSiempreDraw();
    }
    if (tissue) {
        voroDraw();
    }
    if (campoDeTerror) {
        campoDeTerrorDraw();
    }
    
}

//--------------------------------------------------------------
void ofApp::exit(){
    ableton.closePort();
    ableton.removeListener(this);
    nanoKontrol2.closePort();
    nanoKontrol2.removeListener(this);
    soundStream.stop();
    container.clear();
    cout<<"bye BITCH"<<endl;
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if(todoElRuido){
        todoElRuidoKeyPressed(key);
    }
    if(algoSiempre){
        algoSiempreKeyPressed(key);
    }
    if(tissue){
        
    }
    if(campoDeTerror){
        campoDeTerrorKeyPressed(key);
        
    }
}

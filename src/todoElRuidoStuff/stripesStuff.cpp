//
//  stripesStuff.cpp
//  Todo_El_Ruido_01
//
//  Created by Oscar David Bravo Peña on 1/4/17.
//
//

#include "ofApp.h"

//-----------------------------------------
void ofApp::updateStripes(){
    if(ascending && n<256)
        n++;
    else if (n==256 && ascending){
        ascending= !ascending;
        descending=!descending;
    }
    if(n>2 && descending)
        n--;
    else if (n==2 && descending){
        ascending= !ascending;
        descending=!descending;
    }
}

//-----------------------------------------
void ofApp::drawStripes(){
        if(bgFlag){
            if (bgEnable) {
                ofBackground(255);
            }
        }
        else{
            if (bgEnable) {
                ofBackground(0);
            }
        }
        for (int i=0; i<n; i++) {
            if(i%2==0){
                ofSetColor(0);
            }
            else{
                ofSetColor(255);
            }
            ofPushMatrix();
            ofRotateX(-90);
            ofFill(); ofDrawRectangle(i*width/n, 0, width/n, width);
            ofPopMatrix();
        }
        for (int i=0; i<n; i++) {
            if(i%2==0){
                ofSetColor(0);
            }
            else{
                ofSetColor(255);
            }
            ofPushMatrix();
            ofRotateY(-90);
            ofFill(); ofDrawRectangle(i*width/n, 0, width/n, width);
            ofPopMatrix();
        }
        for (int i=0; i<n; i++) {
            if(i%2==0){
                ofSetColor(0);
            }
            else{
                ofSetColor(255);
            }
            ofPushMatrix();
            ofRotateZ(-90);
            ofFill(); ofDrawRectangle(i*width/n, 0, width/n, width);
            ofPopMatrix();
        }
        for (int i=0; i<n; i++) {
            if(i%2==0){
                ofSetColor(255);
            }
            else{
                ofSetColor(0);
            }
            ofPushMatrix();
            ofRotateX(90);
            ofFill(); ofDrawRectangle(i*width/n, 0, width/n, width);
            ofPopMatrix();
        }
        for (int i=0; i<n; i++) {
            if(i%2==0){
                ofSetColor(255);
            }
            else{
                ofSetColor(0);
            }
            ofPushMatrix();
            ofRotateY(90);
            ofFill(); ofDrawRectangle(i*width/n, 0, width/n, width);
            ofPopMatrix();
        }
        for (int i=0; i<n; i++) {
            if(i%2==0){
                ofSetColor(255);
            }
            else{
                ofSetColor(0);
            }
            ofPushMatrix();
            ofRotateZ(90);
            ofFill(); ofDrawRectangle(i*width/n, 0, width/n, width);
            ofPopMatrix();
        }
        
        
        
        for (int i=0; i<n; i++) {
            if(i%2==0){
                ofSetColor(0);
            }
            else{
                ofSetColor(255);
            }
            ofPushMatrix();
            ofRotateX(45);
            ofFill(); ofDrawRectangle(i*width/n, 0, width/n, width);
            ofPopMatrix();
        }
        for (int i=0; i<n; i++) {
            if(i%2==0){
                ofSetColor(0);
            }
            else{
                ofSetColor(255);
            }
            ofPushMatrix();
            ofRotateY(45);
            ofFill(); ofDrawRectangle(i*width/n, 0, width/n, width);
            ofPopMatrix();
        }
        for (int i=0; i<n; i++) {
            if(i%2==0){
                ofSetColor(0);
            }
            else{
                ofSetColor(255);
            }
            ofPushMatrix();
            ofRotateZ(45);
            ofFill(); ofDrawRectangle(i*width/n, 0, width/n, width);
            ofPopMatrix();
        }
        for (int i=0; i<n; i++) {
            if(i%2==0){
                ofSetColor(255);
            }
            else{
                ofSetColor(0);
            }
            ofPushMatrix();
            ofRotateX(-45);
            ofFill(); ofDrawRectangle(i*width/n, 0, width/n, width);
            ofPopMatrix();
        }
        for (int i=0; i<n; i++) {
            if(i%2==0){
                ofSetColor(255);
            }
            else{
                ofSetColor(0);
            }
            ofPushMatrix();
            ofRotateY(-45);
            ofFill(); ofDrawRectangle(i*width/n, 0, width/n, width);
            ofPopMatrix();
        }
        for (int i=0; i<n; i++) {
            if(i%2==0){
                ofSetColor(255);
            }
            else{
                ofSetColor(0);
            }
            ofPushMatrix();
            ofRotateZ(-45);
            ofFill(); ofDrawRectangle(i*width/n, 0, width/n, width);
            ofPopMatrix();
        }
        
        
        for (int i=0; i<n; i++) {
            if(i%2==0){
                ofSetColor(255);
            }
            else{
                ofSetColor(0);
            }
            ofPushMatrix();
            ofRotateX(-90);
            ofFill(); ofDrawRectangle(i*width/n, 0, width/n, width);
            ofPopMatrix();
        }
        for (int i=0; i<n; i++) {
            if(i%2==0){
                ofSetColor(255);
            }
            else{
                ofSetColor(0);
            }
            ofPushMatrix();
            ofRotateY(-90);
            ofFill(); ofDrawRectangle(i*width/n, 0, width/n, width);
            ofPopMatrix();
        }
        for (int i=0; i<n; i++) {
            if(i%2==0){
                ofSetColor(255);
            }
            else{
                ofSetColor(0);
            }
            ofPushMatrix();
            ofRotateZ(-90);
            ofFill(); ofDrawRectangle(i*width/n, 0, width/n, width);
            ofPopMatrix();
        }
        
        for (int i=0; i<n; i++) {
            if(i%2==0){
                ofSetColor(255);
            }
            else{
                ofSetColor(0);
            }
            ofPushMatrix();
            ofRotateX(225);
            ofFill(); ofDrawRectangle(i*width/n, 0, width/n, width);
            ofPopMatrix();
        }
        for (int i=0; i<n; i++) {
            if(i%2==0){
                ofSetColor(255);
            }
            else{
                ofSetColor(0);
            }
            ofPushMatrix();
            ofRotateY(225);
            ofFill(); ofDrawRectangle(i*width/n, 0, width/n, width);
            ofPopMatrix();
        }
        for (int i=0; i<n; i++) {
            if(i%2==0){
                ofSetColor(255);
            }
            else{
                ofSetColor(0);
            }
            ofPushMatrix();
            ofRotateZ(225);
            ofFill(); ofDrawRectangle(i*width/n, 0, width/n, width);
            ofPopMatrix();
        }
        
        for (int i=0; i<n; i++) {
            if(i%2==0){
                ofSetColor(255);
            }
            else{
                ofSetColor(0);
            }
            ofPushMatrix();
            ofRotateX(-225);
            ofFill(); ofDrawRectangle(i*width/n, 0, width/n, width);
            ofPopMatrix();
        }
        for (int i=0; i<n; i++) {
            if(i%2==0){
                ofSetColor(255);
            }
            else{
                ofSetColor(0);
            }
            ofPushMatrix();
            ofRotateY(-225);
            ofFill(); ofDrawRectangle(i*width/n, 0, width/n, width);
            ofPopMatrix();
        }
        for (int i=0; i<n; i++) {
            if(i%2==0){
                ofSetColor(255);
            }
            else{
                ofSetColor(0);
            }
            ofPushMatrix();
            ofRotateZ(-225);
            ofFill(); ofDrawRectangle(i*width/n, 0, width/n, width);
            ofPopMatrix();
        }
        
        for (int i=0; i<n; i++) {
            if(i%2==0){
                ofSetColor(255);
            }
            else{
                ofSetColor(0);
            }
            ofPushMatrix();
            ofRotateX(270);
            ofFill(); ofDrawRectangle(i*width/n, 0, width/n, width);
            ofPopMatrix();
        }
        for (int i=0; i<n; i++) {
            if(i%2==0){
                ofSetColor(255);
            }
            else{
                ofSetColor(0);
            }
            ofPushMatrix();
            ofRotateY(270);
            ofFill(); ofDrawRectangle(i*width/n, 0, width/n, width);
            ofPopMatrix();
        }
        for (int i=0; i<n; i++) {
            if(i%2==0){
                ofSetColor(255);
            }
            else{
                ofSetColor(0);
            }
            ofPushMatrix();
            ofRotateZ(270);
            ofFill(); ofDrawRectangle(i*width/n, 0, width/n, width);
            ofPopMatrix();
        }
        
        for (int i=0; i<n; i++) {
            if(i%2==0){
                ofSetColor(255);
            }
            else{
                ofSetColor(0);
            }
            ofPushMatrix();
            ofRotateX(-270);
            ofFill(); ofDrawRectangle(i*width/n, 0, width/n, width);
            ofPopMatrix();
        }
        for (int i=0; i<n; i++) {
            if(i%2==0){
                ofSetColor(255);
            }
            else{
                ofSetColor(0);
            }
            ofPushMatrix();
            ofRotateY(-270);
            ofFill(); ofDrawRectangle(i*width/n, 0, width/n, width);
            ofPopMatrix();
        }
        for (int i=0; i<n; i++) {
            if(i%2==0){
                ofSetColor(255);
            }
            else{
                ofSetColor(0);
            }
            ofPushMatrix();
            ofRotateZ(-270);
            ofFill(); ofDrawRectangle(i*width/n, 0, width/n, width);
            ofPopMatrix();
        }
        ofVec3f position( xPos[p],yPos[p],zPos[p] );
        cam.setPosition(position);
        ofVec3f centre;
        centre.x = 0;
        centre.y = 0;
        centre.z = 0;
        cam.lookAt(centre);
}

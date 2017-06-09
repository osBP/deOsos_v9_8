//
//  yoEstridente_arcturus.cpp
//  deOsos_v9_8
//
//  Created by Oscar David Bravo Peña on 6/4/17.
//
//

#include "ofApp.h"

#define NUMOFELEMENTS 500

void ofApp::yoEstridenteSetup(){
    //ofSetVerticalSync(true);
    ofBackground(0);
    ofSetFrameRate(16);
    //    container.setBounds(ofRandom(0,ofGetWidth()),ofRandom(0, ofGetHeight()),ofRandom(0,ofGetWidth()),ofRandom(0, ofGetHeight()),ofRandom(0,ofGetWidth()),ofRandom(0, ofGetHeight()));
    container.setBounds(-500,0,0, 500, 40,0, 450, 590,0);
    cout<<"bounds set ok"<<endl;
    container.setElements(NUMOFELEMENTS,0,200,0,200,0,0);
    cout<<"set elemets ok"<<endl;
    
    
    
    // load the texure
    ofDisableArbTex();
    ofLoadImage(texture, "dot.png");
    
    for (int i=0;  i<NUM; i++) {
        addPoint(container.Xe[i], container.Ye[i]);
    }
    
    // upload the data to the vbo
    int total = (int)points3D.size();
    vbo.setVertexData(&points3D[0], total, GL_STATIC_DRAW);
    vbo.setNormalData( &sizes[0], total, GL_STATIC_DRAW);
    // load the shader
#ifdef TARGET_OPENGLES
    shader.load("shaders_gles/shader");
    cout<<"gles"<<endl;
#else
    shader.load("shaders/shader");
    cout<<"gl"<<endl;
#endif
    cam.setDistance(1000);

    R=255;
    G=63;
    B=127;
    ALPHA=127;
}

void ofApp::yoEstridenteUpdate(){
    points3D.clear();
    container.moveElements3D();
    for (int i=0; i<NUM; i++) {
        addPoint(container.Xe[i], container.Ye[i]);
    }
    int total = (int)points3D.size();
    vbo.setVertexData(&points3D[0], total, GL_STATIC_DRAW);
    vbo.setNormalData( &sizes[0], total, GL_STATIC_DRAW);
}

void ofApp::yoEstridenteDraw(){
    cam.begin();
    container.drawBoundaries(127);
    //container.drawElements();
    glDepthMask(GL_FALSE);
    // this makes everything look glowy :)
    ofEnableBlendMode(OF_BLENDMODE_ADD);
    ofEnablePointSprites();
    
    // bind the shader and camera
    shader.begin();
    ofSetColor(R,G,B,ALPHA);
    
    // bind the texture so that when all the points
    // are drawn they are replace with our dot image
    texture.bind();
    vbo.draw(GL_POINTS, 1, (int)points3D.size());
    texture.unbind();
    
    shader.end();
    
    ofDisablePointSprites();
    ofDisableBlendMode();
    
    glDepthMask(GL_TRUE);
    cam.end();
}

void ofApp::addPoint(float x, float y){
    ofVec3f p(x, y,0);
    points3D.push_back(p);
    // we are passing the size in as a normal x position
    float size =ofRandom(20,25);
    sizes.push_back(size);
}

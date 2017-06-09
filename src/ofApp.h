#pragma once

#include "ofMain.h"
#include "ofxMidi.h"
#include "ofxCartesianCylindricalSpherical.h"
#include "ofxDelaunay.h"
#include "ofxVoro.h"
#include "ofxCrystals.h"

#define NUM 360
#define NUMRING 256
#define PHI 1.618033

class ofApp : public ofBaseApp, public ofxMidiListener {
    
public:
    void setup();
    void update();
    void draw();
    void exit();
    void keyPressed(int key);
    
    //-------------------MIDI---------------------------
    void newMidiMessage(ofxMidiMessage& eventArgs);
    ofxMidiMessage midiMessage;
    ofxMidiIn ableton;
    ofxMidiIn nanoKontrol2;
    void midiSetup();
    void midiSetup(string port, string port2);
    void midiTodoElRuido( MidiStatus status, int channel,int control, int value, int pitch, int velocity);
    void midiAlgoSiempre(MidiStatus status, int channel,int control, int value, int pitch, int velocity);
//    void midiTitan(ofxMidiMessage msg);
    void midiCampoDeTerror(ofxMidiMessage msg);
    void midiYoEstridente(MidiStatus status, int channel,int control, int value, int pitch, int velocity);
//  void midiArcturus(ofxMidiMessage msg);
    
    //--------------GENERAL BOOLEANS--------------------
    bool todoElRuido,algoSiempre,Titan,yoEstridente,arcturus,campoDeTerror;
    
    bool tissue;
    ////////////TODO EL RUIDO//////////////////
    void todoElRuidoSetup();
    void todoElRuidoUpdate();
    void todoElRuidoDraw();
    void todoElRuidoKeyPressed(int);
    //----General Variables-------------
    float time,start;
    bool playSaturn,playStripes;
    bool particlesScreen, marchingScene,drawBackground;
    int width,height;
    
    //---Particles----------------------
    ofxCartesianCylindricalSpherical particles[NUM];
    ofxCartesianCylindricalSpherical destinys[NUM];
    ofxCartesianCylindricalSpherical glitchDestiny[NUM];
    float ratios [NUM];
    float amplitudes [NUM];
    ofxCartesianCylindricalSpherical rings [NUMRING];
    float ratiosForRings [NUMRING];
    float amplitudesForRings [NUMRING];
    void initParticles();
    void initParticleSystem();
    void resetParticlesWithRandom();
    void updateParticlesWithNoise();
    void updateParticlesWithDestiny();
    void updateParticlesWithGlitch();
    void drawRings();
    void drawPlanet();
    void drawSaturn();
    float saturnRatio, ringExternalRatio, ringInternalRatio;
    float gain;
    float lineFactor;
    float positionFactor;
    float rotateDegrees[NUM];
    bool glitch;
    bool strobe;
    
    //--------------------Stripes---------------
    bool bgFlag,bgEnable,ascending,descending;
    int   n,p,dist,degr;
    float xPos[5]={-305.915 , 129.261 ,-464.601 ,-159.516 ,-389.453 };
    float yPos[5]={-113.794 ,-214.876 , 317.171 , 151.781 ,-231.365 };
    float zPos[5]={ 175.567 ,-574.597 , 276.749 ,-461.077 ,-236.371 };
    void drawStripes();
    void updateStripes();
    
    //---Light & Camera-------------------------
    void lightCameraSetup();
    void lightCameraUpdate();
    ofEasyCam cam;
    ofLight light;
    ofVec3f target,lightPoint,axis;
    float camFarDestiny,camNearDestiny;
    float distance;
    bool rotate;
    bool zoomOut;
    bool zoomIn;
    
    //------AUDIO---------
    void audioSetup();
    void audioUpdate();
    void audioIn(float * input, int bufferSize, int nChannels);
    vector <float> left;
    vector <float> right;
    vector <float> volHistory;
    int bufferCounter;
    int drawCounter;
    float smoothedVol;
    float scaledVol;
    ofSoundStream soundStream;
    
    ///////  algo Siempre  //////////////
    
    void algoSiempreSetup();
    void algoSiempreUpdate();
    void algoSiempreDraw();
    void algoSiempreKeyPressed(int);
    
    /////////////  VORO CELLS ////////////
    vector<ofPoint> cellCentroids;
    vector<float>   cellRadius;
    vector<ofVboMesh>  cellMeshes;
    vector<ofVboMesh>  cellMeshWireframes;
    void makeTissue(int _nCells, int _width, int _height, int _deep);
    
    void voroSetup();
    void voroUpdate();
    void voroDraw();
    void voroKeyPressed(int);
    
    ////////////// CRYSTALS /////////////
    crystal crystals;
    
    /////////YO _ESTRIDENTE ///////////
    triangleContainer container;
    void yoEstridenteSetup();
    void yoEstridenteUpdate();
    void yoEstridenteDraw();
    //void yoEstridenteKeyPressed();
    // vector to store all values
    vector <ofVec2f> points;
    vector <ofVec3f> points3D;
    vector <ofVec2f> vel;
    vector <ofVec3f> vel3D;
    vector <float> sizes;
    ofVbo          vbo;
    ofTexture  texture;
    void addPoint(float x, float y);
    float R,G,B,ALPHA;
    
    ///////////////CAMPO DE TERROR ABSOLUTO ////////////////
    ofxDelaunay triangulation;
    ofShader shader;
    ofVec4f color;
    void campoDeTerrorSetup();
    void campoDeTerrorUpdate();
    void campoDeTerrorDraw();
    void campoDeTerrorKeyPressed(int key);
    
    
};

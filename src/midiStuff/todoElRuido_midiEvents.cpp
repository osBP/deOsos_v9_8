//
//  todoElRuido.cpp
//  deOsos_v9_8
//
//  Created by Oscar David Bravo Peña on 5/3/17.
//
//

#include "ofApp.h"
#include "ofxMidi.h"

void ofApp::midiTodoElRuido(MidiStatus status, int channel ,int control, int value, int pitch, int velocity){
    switch (status) {
        case MIDI_CONTROL_CHANGE:
            switch (channel) {
                case 1:
                    switch (control) {
                        case 23:
                            distance = 10000 * ofMap(value, 0, 127, 0.1, 1.0);
                            cam.setDistance(distance);
                            break;
                        case 6:
                            lineFactor = ofMap(value, 0, 127, 0.0, 1.0);
                            break;
                        case 16:
                            gain = ofMap(value, 0, 127, 0.1, 1.0);
                            break;
                        default:
                            break;
                    }
                    break;
                default:
                    break;
            }
            break;
        case MIDI_NOTE_ON:
            switch (channel) {
                case 1:
                    switch (pitch) {
                        case 76:
                            zoomOut = true;
                            cout<<"Zooming Out on"<<endl;
                            break;
                        case 78:
                            zoomIn = true;
                            cout<<"Zooming In on"<<endl;
                            break;
                        default:
                            break;
                    }
                    break;
                case 3:
                    switch (pitch) {
                        case 36:
                            if(playSaturn)
                                cam.setPosition(ofRandom(-ofGetWidth(), ofGetWidth()) , ofRandom(-ofGetWidth(), ofGetWidth()), ofRandom(-ofGetWidth(), ofGetWidth()));
                            if(playStripes)
                                p=ofRandom(4);
                            break;
                        default:
                            break;
                    }
                    break;
                case 4:
                    switch (pitch) {
                        case 38:
                            resetParticlesWithRandom();
                            break;
                        case 2:
                            break;
                        default:
                            break;
                    }
                    break;
                case 13:
                    glitch = true;
                    break;
                case 10: //modified for new liveSet configuration
                    //cout<<pitch<<endl;
                    switch (pitch) {
                        case 60:
                            todoElRuido = true;
                            playSaturn = true;
                            playStripes=false;
                            algoSiempre = false;
                            tissue = false;
                            Titan = false;
                            arcturus = false;
                            yoEstridente = false;
                            break;
                        case 62:
                            algoSiempre = true;
                            algoSiempreSetup();
                            playSaturn = false;
                            todoElRuido = false;
                            tissue = false;
                            break;
                        case 64:
                            tissue  = true;
                            voroSetup();
                            algoSiempre = false;
                            todoElRuido = false;
                            playSaturn = false;
                            break;
                        case 69:
                            strobe = !strobe;
                            break;
                        default:
                            break;
                    }
                    break;
                default:
                    break;
            }
            break;
        case MIDI_NOTE_OFF:
            switch (channel) {
                case 1:
                    switch (pitch) {
                        case 76:
                            zoomOut = false;
                            cout<<"Zooming Out off"<<endl;
                            break;
                        case 78:
                            zoomIn = false;
                            cout<<"Zooming In off"<<endl;
                            break;
                        default:
                            break;
                    }
                    break;
                case 13:
                    glitch = false;
                    break;
                default:
                    break;
            }
            break;
        default:
            break;
    }
}



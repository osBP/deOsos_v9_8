//
//  yoEstridente_midiEvents.cpp
//  deOsos_v9_8
//
//  Created by Oscar David Bravo Peña on 5/4/17.
//
//


#include "ofApp.h"
#include "ofxMidi.h"

void ofApp::midiYoEstridente(MidiStatus status, int channel,int control, int value, int pitch, int velocity){
    switch (status) {
        case MIDI_CONTROL_CHANGE:
            switch (channel) {
                case 1:
                    switch (control) {
                        case 0:
                            R=ofMap(value,0,127,0,255);
                            break;
                        case 1:
                            ALPHA=ofMap(value,0,127,0,255);
                            break;
                        case 5:
                            G=ofMap(value,0,127,0,63);
                            break;
                        case 10:
                            B=ofMap(value,0,127,0,31);
                            break;
                        case 7:
                            
                            break;
                        case 41:
                            ofToggleFullscreen();
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
                        case 78:
                            break;
                        default:
                            break;
                    }
                    break;
                case 3:
                    switch (pitch) {
                        case 36:
                            break;
                        default:
                            break;
                    }
                    break;
                case 4:
                    switch (pitch) {
                        case 38:
                            
                            break;
                        case 2:
                            break;
                        default:
                            break;
                    }
                    break;
                case 13:
                    
                    break;
                case 10:
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
                            yoEstridente = false;
                            break;
                        case 64:
                            tissue  = true;
                            voroSetup();
                            algoSiempre = false;
                            todoElRuido = false;
                            playSaturn = false;
                            yoEstridente = false;
                            break;
                        case 65:
                            
                        case 69:
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
                            break;
                        case 78:
                            break;
                        default:
                            break;
                    }
                    break;
                case 13:
                    break;
                default:
                    break;
            }
            break;
        default:
            break;
    }
}


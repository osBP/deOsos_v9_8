//
//  algoSiempre_midiEvents.cpp
//  deOsos_v9_8
//
//  Created by Oscar David Bravo Peña on 5/4/17.
//
//

#include "ofApp.h"
#include "ofxMidi.h"

void ofApp::midiAlgoSiempre(MidiStatus status, int channel,int control, int value, int pitch, int velocity){
    switch (status) {
        case MIDI_CONTROL_CHANGE:
            switch (channel) {
                case 1:
                    switch (control) {
                        case 23:
                            break;
                        case 6:
                            break;
                        case 16:
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
                            yoEstridente = true;
                            
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

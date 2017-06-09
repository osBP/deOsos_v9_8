//
//  campoDeTerror_midiEvents.cpp
//  deOsos_v9_8
//
//  Created by Oscar David Bravo Peña on 6/7/17.
//
//

#include "ofApp.h"
#include "ofxMidi.h"

void ofApp::midiCampoDeTerror(ofxMidiMessage msg)  {
    switch (msg.status) {
        case MIDI_CONTROL_CHANGE:
            switch (msg.channel) {
                case 1:
                    switch (msg.control) {
                        case 0:
                            break;
                        case 1:
                            break;
                        case 5:
                            break;
                        case 10:
                            break;
                        case 7:
                            
                            break;
                        case 41:
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
            switch (msg.channel) {
                case 1:
                    switch (msg.pitch) {
                        case 76:
                        case 78:
                            break;
                        default:
                            break;
                    }
                    break;
                case 3:
                    switch (msg.pitch) {
                        case 36:
                            break;
                        default:
                            break;
                    }
                    break;
                case 4:
                    switch (msg.pitch) {
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
                    //cout<<msg.pitch<<endl;
                    switch (msg.pitch) {
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
            switch (msg.channel) {
                case 1:
                    switch (msg.pitch) {
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

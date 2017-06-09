//
//  midiStuff.cpp
//  deOsos_v9_8
//
//  Created by Oscar David Bravo Peña on 4/21/17.
//
//

#include "ofApp.h"
#include "ofxMidi.h"

//--------------------------------------------------------------
void ofApp::midiSetup(){
    ableton.listPorts();
    ableton.openPort("Driver IAC visualsBus");
    ableton.ignoreTypes(false, false, false);
    ableton.addListener(this);
    ableton.setVerbose(false);
    nanoKontrol2.openPort("nanoKONTROL2 SLIDER/KNOB");
    nanoKontrol2.ignoreTypes(false, false, false);
    nanoKontrol2.addListener(this);
    nanoKontrol2.setVerbose(false);
}

void ofApp::midiSetup(string port, string port2){
    ableton.listPorts();
    ableton.openPort(port);
    ableton.ignoreTypes(false, false, false);
    ableton.addListener(this);
    ableton.setVerbose(false);
    nanoKontrol2.openPort(port2);
    nanoKontrol2.ignoreTypes(false, false, false);
    nanoKontrol2.addListener(this);
    nanoKontrol2.setVerbose(false);
}

//--------------------------------------------------------------
void ofApp::newMidiMessage(ofxMidiMessage& eventArgs){
    midiMessage = eventArgs;
    if (todoElRuido) {
        midiTodoElRuido(midiMessage.status, midiMessage.channel, midiMessage.control, midiMessage.value, midiMessage.pitch, midiMessage.velocity);
    }
    if(algoSiempre){
        midiAlgoSiempre(midiMessage.status, midiMessage.channel, midiMessage.control, midiMessage.value, midiMessage.pitch, midiMessage.velocity);
    }
    if(tissue){
        
    }
}

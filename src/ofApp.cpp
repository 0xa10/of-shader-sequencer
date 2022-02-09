#include "ofApp.h"
#include <stdio.h>

void ofApp::setup()
{
    ofSetWindowTitle("/// shader viewer :::");
    ofToggleFullscreen();

    midiIn.listInPorts();
    midiIn.openPort("SQ-1 SEQ IN");
    midiIn.addListener(this);
    midiIn.setVerbose(true);
}

void ofApp::setupShader(std::string vertex_shader, std::string fragment_shader)
{
    shader.setupShaderFromSource(GL_VERTEX_SHADER, vertex_shader);
    shader.setupShaderFromSource(GL_FRAGMENT_SHADER, fragment_shader);
    shader.bindDefaults();
    shader.linkProgram();
}

void ofApp::newMidiMessage(ofxMidiMessage& message)
{
    if (message.status == MIDI_NOTE_ON || message.status == MIDI_NOTE_OFF) {
        _midiVelocity = message.velocity;
        _midiPitch = message.pitch;
    }
}

void ofApp::update()
{
}

void ofApp::draw()
{
    shader.begin();
    shader.setUniform1f("u_time", ofGetElapsedTimef());
    shader.setUniform2f("u_resolution", ofGetWidth(), ofGetHeight());
    shader.setUniform1f("u_velocity", _midiVelocity);
    shader.setUniform1f("u_pitch", _midiPitch);
    ofDrawRectangle(0, 0, ofGetWidth(), ofGetHeight());
    shader.end();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key)
{
    if (key == 'q') {
        ofExit(0);
    }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key)
{
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y)
{
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button)
{
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button)
{
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button)
{
}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y)
{
}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y)
{
}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h)
{
}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg)
{
}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo)
{
}

#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

    alarm.load("alarm.mp3");
}

//--------------------------------------------------------------
void ofApp::update(){
    if(ofGetHours() == 7 && ofGetMinutes() == 10 && ofGetSeconds() == 0)
    {
        alarm.play();
    }
    
    if(snooze)
    {
        if(ofGetHours() == 7 && ofGetMinutes() == 15 && ofGetSeconds() == 0)
        {
            alarm.play();
        }
    }
}

//--------------------------------------------------------------
void ofApp::draw(){

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    alarm.stop();
    
    if(snooze == false) snooze = true;
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}

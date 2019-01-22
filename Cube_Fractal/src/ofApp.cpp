#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
 
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            for(int k = 0; k < 3; k++)
            {
                b.push_back(Box(i, j, k, i*startSize, j*startSize, k*startSize, startSize));
            }
        }
    }
    
    b.erase(b.begin() + 10);
    b.erase(b.begin() + 13);
    b.erase(b.begin() + 22);
    b.erase(b.begin() + 14);
    b.erase(b.begin() + 4);
    b.erase(b.begin() + 12);
    b.erase(b.begin() + 16);
    
    for()
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){

    ofBackground(0);

    for(int i = 0; i < b.size(); i++)
    {
     b.at(i).display();
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

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

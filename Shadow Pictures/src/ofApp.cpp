#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup()
{
    cam.initGrabber(1280,720);
    pic = ofImage();
}

//--------------------------------------------------------------
void ofApp::update()
{
    cam.update();
}

//--------------------------------------------------------------
void ofApp::draw()
{
    ofBackground(0);
    
    cam.draw(0, 0);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key)
{
    if(!setUp)
    {
        base.grabScreen(0, 0, cam.getWidth(), cam.getHeight());
        
        base.save("base.png");
    }
    else
    {
       pic.grabScreen(0, 0, cam.getWidth(), cam.getHeight());
//       makeFigure(pic);
    }
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

void ofApp::makeFigure(ofImage img)
{
    for(int x = 0; x < img.getWidth(); x++)
    {
        for(int y = 0; y < img.getHeight(); y++)
        {
            if(img.getColor(x, y) == base.getColor(x, y))
            {
                img.setColor(x, y, ofColor(255, 0));
            }
            
            else
            {
                img.setColor(x, y, ofColor(0));
            }
        }
    }
}

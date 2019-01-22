#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    for(int i = 0; i < 4; i++)
    {
        scaleIncrease[i] = scaleDecrease[i] = false;
    }
    
    cam = CeasyCam(ofVec3f(0, 0, 0), 1, 1.5 * ofDist(dimensions.x, dimensions.y, dimensions.z, 0, 0, 0));
    
    changeScale();
    
    l.push_back(Line(GraphPoint(1, 1, 1), GraphPoint(2, 3, 4)));
}

//--------------------------------------------------------------
void ofApp::update(){
    if(m[0]) cam.moveForward();
    if(m[1]) cam.moveBack();
    if(m[2]) cam.moveLeft();
    if(m[3]) cam.moveRight();
    
    updateScale();
    
    cam.update();
}

//--------------------------------------------------------------
void ofApp::draw()
{
    ofBackground(0);
    
    cam.begin();
    
    ofNoFill();
    ofSetColor(255);
    ofDrawBox(dimensions.x, dimensions.y, dimensions.z);
    
    ofFill();
    ofSetColor(255, 0, 0);
    
    for (int i = 0; i < axes.size(); i++)
    {
        axes.at(i).display();
    }
    
    for (int i = 0; i < p.size(); i++)
    {
        p.at(i).display();
    }
    
    for (int i = 0; i < l.size(); i++)
    {
        l.at(i).display(ofColor(0, 255, 0));
    }
    
    for (int i = 0; i < gl.size(); i++)
    {
        gl.at(i).display(ofColor(255, 20));
    }
    
    cam.end();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key)
{
    if(key == 'w')
    {
        m[0] = true;
    }
    
    if(key == 's')
    {
        m[1] = true;
    }
    
    if(key == 'a')
    {
        m[2] = true;
    }
    
    if(key == 'd')
    {
        m[3] = true;
    }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key)
{
    if(key == 'w')
    {
        m[0] = false;
    }
    
    if(key == 's')
    {
        m[1] = false;
    }
    
    if(key == 'a')
    {
        m[2] = false;
    }
    
    if(key == 'd')
    {
        m[3] = false;
    }
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

void ofApp::changeScale()
{
    axes.clear();
    
    numPixels = dimensions/scale;
    
    for (int i = 0; i < scale.x+1; i++)
    {
        axes.push_back(GraphPoint(i-scale.x/2, 0, 0));
    }
    
    for (int i = 0; i < scale.y+1; i++)
    {
        axes.push_back(GraphPoint(0, i-scale.y/2, 0));
    }
    
    for (int i = 0; i < scale.z+1; i++)
    {
        axes.push_back(GraphPoint(0, 0, i-scale.z/2));
    }
    
    for(int i = 0; i <= scale.y; i+=2)
    {
      for(int j = 0; j <= scale.x; j+=2)
      {
        gl.push_back(Line(0, 0, 1, j-scale.x/2, i-scale.y/2, 0));
      }
    
      for(int k = 0; k <= scale.x; k+=2)
      {
        gl.push_back(Line(1, 0, 0, 0, i-scale.y/2, k-scale.z/2));
      }
    }
    
    for(int i = 0; i <= scale.x; i+=2)
    {
      for(int j = 0; j <= scale.z; j+=2)
      {
        gl.push_back(Line(0, 1, 0, i-scale.y/2, 0, j-scale.z/2));
      }
    }
    
//    for(GraphPoint point : p)
//    {
//        point.updatePos(); 
//    }
//    
//    for(Line line : l)
//    {
//        line.updatePos(); 
//    }
}

void ofApp::updateScale()
{
    if (scaleIncrease[0]) scale.x++;
    else if (scaleIncrease[1]) scale.y++;
    else if (scaleIncrease[2]) scale.z++;
    else if (scaleIncrease[3]) {scale.x++; scale.y++; scale.z++;}
    
    else if (scaleDecrease[0] && scale.x > 2) scale.x--;
    else if (scaleDecrease[1] && scale.y > 2) scale.y--;
    else if (scaleDecrease[2] && scale.z > 2) scale.z--;
    else if (scaleIncrease[3] && scale.x > 2 && scale.y > 2 && scale.z > 2) {scale.x--; scale.y--; scale.z--;}
    
    if(scaleIncrease[0] || scaleIncrease[1]  || scaleIncrease[2] || scaleIncrease[3] || scaleDecrease[0] || scaleDecrease[1]  || scaleDecrease[2] || scaleDecrease[3])
    {
        changeScale();
    }
}

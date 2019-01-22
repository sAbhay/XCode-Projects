//
//  robot.cpp
//  Megaton Hammer
//
//  Created by Abhay Singhal on 27/03/18.
//

#include "robot.hpp"

Robot::Robot()
{
    cam = CeasyCam();
    cam.setControllable(false);
    
    pos = ofVec3f(0,0,0);
    
    model.loadModel("/Users/abhaysinghal/Downloads/Megaton Hammer.stl", false);
    
    ofMesh mesh = model.getCurrentAnimatedMesh(0);
    
    model.setPosition(pos.x, pos.y, pos.z);
    model.setLoopStateForAllAnimations(OF_LOOP_NORMAL);
    model.playAllAnimations();

    speed = 10;
    
    center = ofxBBox(mesh).at(1);
    center.y *= -1;
//    center = mesh.getCentroid();
    size = ofxBBox(mesh).at(0);
    
    cout << size;
}

Robot::~Robot()
{

}

void Robot::update()
{
//    ofVec3f forward = ofVec3f(cam.getForward().x, 0, cam.getForward().z).normalize();
    cam.setPosition(pos + ofVec3f(-800, 0, 200)*1.5);
    cam.setPosition(ofVec3f(cam.getPosition().x, 300, cam.getPosition().z));
//    cam.setPosition(pos + ofVec3f(-1000, 300, 200));

//    cam.lookAt(model.getPosition() + center);

    cam.update();

//    pos = cam.getPosition() + 500*ofVec3f(forward.x, 0, forward.z);
//    pos += model.getScale()/2;
//
    model.setPosition(pos.x, 0, pos.z);
}

void Robot::display()
{
    ofPushMatrix();
    ofTranslate(model.getPosition() + center*100);
    ofRotate(-90, 1, 0, 0);
//    ofRotate(180, 0, 0, 1);
    model.drawFaces();
    ofPopMatrix();
    
    ofPushMatrix();
    ofTranslate(center);
//    ofFill();
//    ofSetColor(255,0,0);
//    ofDrawBox(10);
    ofPopMatrix();
}

vector<ofVec3f> Robot:: ofxBBox(ofMesh mesh) {
          vector<ofVec3f> res;
          if (mesh.getNumVertices() > 0) {
              float min_x, max_x, min_y, max_y, min_z, max_z;
              min_x = max_x = mesh.getVertex(0).x;
                          min_y = max_y = mesh.getVertex(0).y;
                          min_z = max_z = mesh.getVertex(0).z;
                  for (int i = 0; i < mesh.getNumVertices(); i++) {
                        if (mesh.getVertex(i).x < min_x) min_x = mesh.getVertex(i).x;
                        if (mesh.getVertex(i).x > max_x) max_x = mesh.getVertex(i).x;
                        if (mesh.getVertex(i).y < min_y) min_y = mesh.getVertex(i).y;
                        if (mesh.getVertex(i).y > max_y) max_y = mesh.getVertex(i).y;
                        if (mesh.getVertex(i).z < min_z) min_z = mesh.getVertex(i).z;
                        if (mesh.getVertex(i).z > max_z) max_z = mesh.getVertex(i).z;
              }
              
                  ofVec3f size = ofVec3f(max_x-min_x, max_y-min_y, max_z-min_z);
                  ofVec3f center = ofVec3f((min_x+max_x)/2, (min_y+max_y)/2, (min_z+max_z)/2);
              res.push_back(size);
                          res.push_back(center);
          }
          return res;
        }

//
//  robot.hpp
//  Megaton Hammer
//
//  Created by Abhay Singhal on 27/03/18.
//

#ifndef robot_hpp
#define robot_hpp

#include <stdio.h>
#include "ofMain.h"
#include "camera.hpp"
#include "ofxAssimpModelLoader.h"
#include "ofVboMesh.h"

class Robot
{
    private:
        CeasyCam cam;
        ofMesh mesh;
        ofxAssimpModelLoader model;
    
        ofVec3f center;
        ofVec3f size;
    
        ofVec3f pos;
        ofVec3f forward;
        float speed;
    
        vector<ofVec3f> ofxBBox(ofMesh mesh);
    
    public:
        Robot();
        ~Robot();
    
        void update();
        void display();
    
        void moveForward();
        void moveBack();
        void turnLeft();
        void turnRight();
    
        void beginCamera() {cam.begin();}
        void endCamera() {cam.end();}
};

#endif /* robot_hpp */

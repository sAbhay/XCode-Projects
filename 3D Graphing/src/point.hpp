//
//  point.hpp
//  3D Graphing
//
//  Created by Abhay Singhal on 10/26/17.
//
//

#ifndef point_hpp
#define point_hpp

#include <stdio.h>
#include "ofMain.h"
#include <global.h>

class GraphPoint
{
    private:
        ofVec3f index;
        ofVec3f pos;
    
        bool labelled;
        string label;
    
        float size;
    
    public:
        GraphPoint() {};
        GraphPoint(float x, float y, float z);
        GraphPoint(float x, float y, float z, string l);
    
        ~GraphPoint() {};
    
        void display();
        void updatePos();
    
        ofVec3f getPos() {return pos;}
        ofVec3f getIndex() {return index;}
        void setPos(ofVec3f& p) {pos = p;}
};

#endif /* point_hpp */

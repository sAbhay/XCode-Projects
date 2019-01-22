//
//  box.cpp
//  Cube_Fractal
//
//  Created by Abhay Singhal on 4/4/17.
//
//

#include "box.hpp"

Box::Box()
{
    pos = ofVec3f(0, 0, 0);
    size = 0;
}

Box::Box(int i, int j, int k, float x, float y, float z, float s)
{
    index = ofVec3f(i, j, k);
    pos = ofVec3f(x, y, z);
    size = s;
}

Box::~Box()
{
    
}

void Box::display()
{
    ofDrawBox(pos.x, pos.y, pos.z, size, size, size);
}

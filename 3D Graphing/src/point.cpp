//
//  point.cpp
//  3D Graphing
//
//  Created by Abhay Singhal on 10/26/17.
//
//

#include "point.hpp"

GraphPoint::GraphPoint(float x, float y, float z)
{
    index = ofVec3f(x, y, z);
    
    updatePos();
    
    //if(scale.x >= scale.y && scale.x >= scale.z) size = (75000/(scale.x * scale.y * scale.z)) * numPixels.x/70;
    //else if(scale.y >= scale.x && scale.y >= scale.z) size = (75000/(scale.x * scale.y * scale.z)) * numPixels.y/70;
    //else if(scale.z >= scale.x && scale.z >= scale.y) size = (75000/(scale.x * scale.y * scale.z)) * numPixels.z/70;
    
    size = 0.0011 * (dimensions.x + dimensions.y + dimensions.z)/3;
    
    labelled = false;
    label = "";
}

GraphPoint::GraphPoint(float x, float y, float z, string l)
{
    index = ofVec3f(x, y, z);
    
    updatePos();
    
    //if(scale.x >= scale.y && scale.x >= scale.z) size = (75000/(scale.x * scale.y * scale.z)) * numPixels.x/70;
    //else if(scale.y >= scale.x && scale.y >= scale.z) size = (75000/(scale.x * scale.y * scale.z)) * numPixels.y/70;
    //else if(scale.z >= scale.x && scale.z >= scale.y) size = (75000/(scale.x * scale.y * scale.z)) * numPixels.z/70;
    
    size = 0.0011 * (dimensions.x + dimensions.y + dimensions.z)/3;
    
    labelled = true;
    label = l;
}

void GraphPoint::display()
{

    ofFill();
    ofSetColor(255, 0, 0);
    
    ofDrawSphere(pos.x, pos.y, pos.z, size);
    
    if(labelled)
    {
        ofDrawBitmapString(label, pos.x, -20*size + pos.y, pos.z);
    }
}

void GraphPoint::updatePos()
{
    pos = index * numPixels;
}

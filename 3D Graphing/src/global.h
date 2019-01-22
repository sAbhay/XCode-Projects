//
//  global.h
//  3D Graphing
//
//  Created by Abhay Singhal on 22/01/18.
//

#ifndef global_h
#define global_h

#include "ofMain.h"

extern ofVec3f dimensions;
extern ofVec3f scale;
extern ofVec3f numPixels;

extern bool isBetween(float x, float lower, float upper)
{
    if(x >= lower && x <= upper)
    {
        return true;
    }
    
    return false;
}

#endif /* global_h */

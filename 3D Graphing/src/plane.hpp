//
//  plane.hpp
//  3D Graphing
//
//  Created by Abhay Singhal on 10/26/17.
//
//

#ifndef plane_hpp
#define plane_hpp

#include <stdio.h>
#include "ofMain.h"
#include "point.hpp"

class Plane
{
    private:
        GraphPoint input[3];
        GraphPoint points[4];
        ofVec3f normal;
        float sum;
    
//        ofShape s;
};

#endif /* plane_hpp */

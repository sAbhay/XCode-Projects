//
//  box.hpp
//  Cube_Fractal
//
//  Created by Abhay Singhal on 4/4/17.
//
//

#ifndef box_hpp
#define box_hpp

#include <stdio.h>
#include "ofMain.h"

class Box
{
    public:
        Box();
        Box(int i, int j, int k, float x, float y, float z, float s);
        ~Box();
        void display();
    
    private:
        ofVec3f index;
        ofVec3f pos;
        float size;
};

#endif /* box_hpp */

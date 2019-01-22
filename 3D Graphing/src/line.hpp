//
//  line.hpp
//  3D Graphing
//
//  Created by Abhay Singhal on 10/26/17.
//
//

#ifndef line_hpp
#define line_hpp

#include <stdio.h>
#include <global.h>
#include "point.hpp"

class Line
{
    private:
        GraphPoint points[2];
        GraphPoint input[2];
    
        ofVec3f multipliers;
    
        void calculateParameters(float xm, float xt, float ym, float yt, float zm, float zt);
    
    public:
        Line(float xm, float ym, float zm, float xt, float yt, float zt);
        Line(GraphPoint p1, GraphPoint p2);
        Line(GraphPoint p2);
    
        void display(ofColor c);
        void updatePos();
    
        ofVec3f getMultipliers() {return multipliers;}
        GraphPoint getInput(int i) {return input[i];}
        GraphPoint getPoint(float p) {return GraphPoint(multipliers.x * p + input[0].getIndex().x, multipliers.y * p + input[0].getIndex().y, multipliers.z * p + input[0].getIndex().z);}
};

#endif /* line_hpp */

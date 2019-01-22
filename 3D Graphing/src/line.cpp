//
//  line.cpp
//  3D Graphing
//
//  Created by Abhay Singhal on 10/26/17.
//
//

#include "line.hpp"

Line::Line(float xm, float ym, float zm, float xt, float yt, float zt)
{
    multipliers = ofVec3f(xm, ym, zm);
    
//    input[0] = GraphPoint(xt, yt, zt);
//    input[1] = NULL;
    
    calculateParameters(xm, xt, ym, yt, zm, zt);
}

Line::Line(GraphPoint p1, GraphPoint p2)
{
    ofVec3f m = p2.getIndex() - p1.getIndex();
    ofVec3f i = p1.getIndex();
    
    multipliers = m;
    
    input[0] = p1;
    input[1] = p2;
    
    calculateParameters(m.x, i.x, m.y, i.y, m.z, i.z);
}

Line::Line(GraphPoint p2)
{
    GraphPoint p1 = GraphPoint(0, 0, 0);
    
    ofVec3f m = p2.getIndex() - p1.getIndex();
    ofVec3f i = p1.getIndex();
    
    input[0] = p1;
    input[1] = p2;
    
    calculateParameters(m.x, i.x, m.y, i.y, m.z, i.z);
}

void Line::display(ofColor c)
{
    ofFill();
    ofSetColor(c);
    
    ofDrawLine(points[0].getPos(), points[1].getPos());
    
    for (int i = 0; i < 2; i++)
    {
        if (&input[i] != nullptr)
        {
            input[i].display();
        }
    }
}

void Line::calculateParameters(float xm, float xt, float ym, float yt, float zm, float zt)
{
    float t[2];
    
    t[0] = (-scale.x/2)/xm;
    t[1] = (scale.x/2)/xm;
    
    if (!isBetween(getPoint(t[0]).getIndex().y, -scale.y/2, scale.y/2) || !isBetween(getPoint(t[0]).getIndex().z, -scale.z/2, scale.z/2) || !isBetween(getPoint(t[1]).getIndex().y, -scale.y/2, scale.y/2) || !isBetween(getPoint(t[1]).getIndex().z, -scale.z/2, scale.z/2))
    {
        t[0] = (-scale.y/2)/ym;
        t[1] = (scale.y/2)/ym;
    }
    
    if (!isBetween(getPoint(t[0]).getIndex().z, -scale.z/2, scale.z/2) || !isBetween(getPoint(t[1]).getIndex().z, -scale.z/2, scale.z/2))
    {
        t[0] = (-scale.z/2)/zm;
        t[1] = (scale.z/2)/zm;
    }
    
    float pos[6];
    
    pos[0] = xm * t[0] + xt;
    pos[1] = ym * t[0] + yt;
    pos[2] = zm * t[0] + zt;
    
    pos[3] = xm * t[1] + xt;
    pos[4] = ym * t[1] + yt;
    pos[5] = zm * t[1] + zt;
    
    points[0] = GraphPoint(pos[0], pos[1], pos[2]);
    points[1] = GraphPoint(pos[3], pos[4], pos[5]);
}

void Line::updatePos()
{
    for (int i = 0; i < 2; i++)
    {
        points[i].updatePos();
    }
    
    for (int i = 0; i < 2; i++)
    {
        if (&input[i] != nullptr)
        {
            input[i].updatePos();
        }
    }
}

//
//  figure.cpp
//  Shadow Pictures
//
//  Created by Abhay Singhal on 8/14/17.
//
//

#include "figure.hpp"

Figure::Figure()
{
    
}

Figure::Figure(ofImage& image, int x, int y)
{
    img = image;
    
    pos = ofVec2f(x, y);
}

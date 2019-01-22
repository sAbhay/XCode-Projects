//
//  figure.hpp
//  Shadow Pictures
//
//  Created by Abhay Singhal on 8/14/17.
//
//

#ifndef figure_hpp
#define figure_hpp

#include <stdio.h>
#include "ofMain.h"

class Figure
{
    public:
        Figure();
        Figure(ofImage& image, int x, int y);
        ~Figure();
    
        void move();
        void display();
    
    private:
        ofImage img;
        ofVec2f pos;
};

#endif /* figure_hpp */

//
//  tile.hpp
//  Maze Generator
//
//  Created by Abhay Singhal on 14/01/18.
//

#ifndef tile_hpp
#define tile_hpp

#include <stdio.h>
#include "ofMain.h"

class Tile
{
    public:
        Tile(int x, int y, float w, float h, int s);
        void display();
    
        int getState() {return state;}
        void setState(int s) {state = s;}
        float[] getSize() {return size;}
    
    private:
        float pos[2];
        int index[2];
        float size[2];
        int state;

};

#endif /* tile_hpp */

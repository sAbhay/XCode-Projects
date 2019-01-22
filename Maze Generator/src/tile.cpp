//
//  tile.cpp
//  Maze Generator
//
//  Created by Abhay Singhal on 14/01/18.
//

#include "tile.hpp"

Tile::Tile(int x, int y, float w, float h, int s)
{
    index[0] = x; index[1] = y;
    size[0] = w; size[1] = h;
    pos[0] = x*w; pos[1] = y*h;
    state = s;
}

void Tile::display()
{
    ofFill();

    switch(state)
    {
    case 0:
      ofSetColor(0);
      break;

    case 1:
      ofSetColor(255);
      break;

    case 2:
      ofSetColor(255, 0, 0);
      break;

    case 3:
      ofSetColor(0, 255, 0);
      break;
    }

    ofDrawRectangle(pos[0], pos[1], size[0], size[1]);
}

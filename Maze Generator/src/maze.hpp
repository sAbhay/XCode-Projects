//
//  maze.hpp
//  Maze Generator
//
//  Created by Abhay Singhal on 14/01/18.
//

#ifndef maze_hpp
#define maze_hpp

#include <stdio.h>
#include "ofMain.h"
#include "tile.hpp"

class Maze
{
    public:
        
    
        Tile[][] getTiles() {return tiles;}
        void setGenerated(bool b) {generated = b;}
        void setPlayable(bool b) {playable = b;}

    
    private:
        static int size[2];
        Tile tiles[size[0]][size[1]];

        int start[2];
        int end[2];
        int ct[2];
        bool generated;
        bool playable;
};

#endif /* maze_hpp */

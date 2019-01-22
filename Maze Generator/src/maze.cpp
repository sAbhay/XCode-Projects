//
//  maze.cpp
//  Maze Generator
//
//  Created by Abhay Singhal on 14/01/18.
//

#include "maze.hpp"

Maze::Maze(int s[2])
{
    size = s;

    tiles = new Tile[(int) size[0]][(int) size[1]];

    start[0] = 0;
    start[1] = (int) random(size[1]);
    end[0] = size[0]-1;
    end[1] = (int) random(size[1]);
    ct = start;
    generated = false;
    playable = false;
    
    init();
}

void Maze::init()
  {
    for (int i = 0; i < size[0]; i++)
    {
      for (int j = 0; j < size[1]; j++)
      {
        tiles[i][j] = new Tile(i, j, width/size[0], height/size[1], 0);
      }
    }

    for (int i = 0; i < start.length; i++)
    {
      start[i] -= start[i]%2;
    }

    tiles[start[0]][start[1]].setState(2);
  }

  void Maze::update()
  {
    if (!playable)
    {
      if (!mazeGenerated(tiles)) genMaze();
      else
      {
        while (tiles[end[0]][end[1]].getState() != 1)
        {
          end[1] = (int) random(size[1]);
        }

        tiles[end[0]][end[1]].setState(3);
        playable = true;
      }
    }
  }
  
  void Maze::display()
  {
    for (int i = 0; i < tiles.length; i++)
    {
      for (int j = 0; j < tiles[i].length; j++)
      {
        tiles[i][j].display();
      }
    }
  }

  void Maze::genMaze()
  {
    int gen = (int) random(4);

    boolean valid[] = {true, true, false, true}; // left, right, up, down

    if (ct[0] > 1)
    {
      if (tiles[ct[0]-2][ct[1]].getState() == 0)
      {
        valid[0] = true;
      } else valid[0] = false;
    } else valid[0] = false;

    if (ct[0] < (size[0]-2))
    {
      if (tiles[ct[0]+2][ct[1]].getState() == 0)
      {
        valid[1] = true;
      } else valid[1] = false;
    } else valid[1] = false;

    if (ct[1] > 1)
    {
      if (tiles[ct[0]][ct[1]-2].getState() == 0)
      {
        valid[2] = true;
      } else valid[2] = false;
    } else valid[2] = false;

    if (ct[1] < (size[1]-2))
    {
      if (tiles[ct[0]][ct[1]+2].getState() == 0)
      {
        valid[3] = true;
      } else valid[3] = false;
    } else valid[3] = false;

    switch(gen)
    {
    case 0:
      if (valid[0])
      {
        tiles[ct[0]-1][ct[1]].setState(1);
        tiles[ct[0]-2][ct[1]].setState(1);
        ct[0]-=2;
      }
      break;

    case 1:
      if (valid[1])
      {
        tiles[ct[0]+1][ct[1]].setState(1);
        tiles[ct[0]+2][ct[1]].setState(1);
        ct[0]+=2;
      }
      break;

    case 2:
      if (valid[2])
      {
        tiles[ct[0]][ct[1]-1].setState(1);
        tiles[ct[0]][ct[1]-2].setState(1);
        ct[1]-=2;
      }
      break;

    case 3:
      if (valid[3])
      {
        tiles[ct[0]][ct[1]+1].setState(1);
        tiles[ct[0]][ct[1]+2].setState(1);
        ct[1]+=2;
      }
      break;
    }

    if (allFalse(valid))
    {
      for (int i = 0; i < ct.length; i++)
      {
        ct[i] = ((int) random(size[i]));
        ct[i] = ct[i] - (ct[i]%2);
      }

      while (tiles[ct[0]][ct[1]].state != 1)
      {
        for (int i = 0; i < ct.length; i++)
        {
          ct[i] = ((int) random(size[i]));
          ct[i] = ct[i] - (ct[i]%2);
        }
      }
    }
  }

  bool Maze::mazeGenerated(Tile tiles[][])
  {
    for (int i = 0; i < tiles.length-1; i++)
    {
      for (int j = 0; j < tiles[i].length-1; j++)
      {
        if (tiles[i][j].getState() == 0 && tiles[i+1][j].getState() == 0 && tiles[i][j+1].getState() == 0 && tiles[i+1][j+1].getState() == 0)
        {
          return false;
        }
      }
    }

    return true;
  }
}
}

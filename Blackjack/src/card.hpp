//
//  card.hpp
//  Blackjack
//
//  Created by Abhay Singhal on 5/4/17.
//
//

#ifndef card_hpp
#define card_hpp

#include <stdio.h>
#include "ofMain.h"

class Card
{
    private:
        int value;
        string name;
        string v;
        int index;
        ofImage face;
    
    public:
        Card();
        Card(int i, ofImage *f);
        ~Card();
    
        int getValue() {return value;}
        string getName() {return name;};
        void setValue(int v) {value = v;}
        bool isAce();
    
        void display(float x, float y);
    
        int getHeight() {return face.getHeight();}
        void setDimensions(int x, int y);
};

#endif /* card_hpp */

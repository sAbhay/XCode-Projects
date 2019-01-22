//
//  card.cpp
//  Blackjack
//
//  Created by Abhay Singhal on 5/4/17.
//
//

#include "card.hpp"

Card::Card()
{
    value = 0;
    name = "";
}

Card::Card(int i, ofImage *f)
{
    index = i;
    face = *f;

    if(index % 13 > 10 || index % 13 == 0)
    {
        value = 10;
        
        if(index % 13 == 11) v = "Jack";
        else if(index % 13 == 12) v = "Queen";
        else if(index % 13 == 0) v = "King";
    }
    else
    {
        value = index % 13;
        
        ostringstream k;
        k << value;
        string number(k.str());
        
        v = number;
        
        if(value == 1)
        {
            v = "Ace";
            value = 11;
        }
    }
    
    string suit = "";
    
    if(index > 0 && index <= 13) suit = "Clubs";
    else if(index > 13 && index <= 26) suit = "Spades";
    else if(index > 26 && index <= 39) suit = "Hearts";
    else if(index > 39 && index <= 52) suit = "Diamonds";
    
    name = v + " of " + suit;
}

Card::~Card()
{
    
}

bool Card::isAce()
{
    if(v == "Ace")
    {
        return true;
    }
    
    return false;
}

void Card::display(float x, float y)
{
    face.draw(x, y);
}

void Card::setDimensions(int x, int y)
{
    face.resize(x, y);
}

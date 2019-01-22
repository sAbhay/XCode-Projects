//
//  player.hpp
//  Blackjack
//
//  Created by Abhay Singhal on 5/4/17.
//
//

#ifndef player_hpp
#define player_hpp

#include <stdio.h>
#include "card.hpp"

class Player
{
   private:
        vector<Card> hand;
        int value;
    
    public:
        Player();
        ~Player();
    
        int getValue() {return value;}
        void addCard(int i, ofImage f) {hand.push_back(Card((i+1), &f));}
        bool isBust();
    
        void displayCards(float n, string name);
        void update();
        void emptyHand();
    
        void resize();
};

#endif /* player_hpp */

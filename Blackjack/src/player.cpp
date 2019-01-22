//
//  player.cpp
//  Blackjack
//
//  Created by Abhay Singhal on 5/4/17.
//
//

#include "player.hpp"

Player::Player()
{
    value = 0;
}

Player::~Player()
{
    
}

void Player::displayCards(float n, string name)
{
    int h;

    for(int i = 0; i < hand.size(); i++)
    {
        h = hand.at(i).getHeight();
    
        hand.at(i).display((int) (ofGetWidth()/5 + (i * ofGetWidth()/5)), (int) ((n/3) * ofGetHeight()  - hand.at(i).getHeight()/0.85));
        ofDrawBitmapString(hand.at(i).getName(), (int) (ofGetWidth()/5 + (i * ofGetWidth()/5)), (int) ((n/3) * ofGetHeight()));
    }
    
    ofDrawBitmapString(value, ofGetWidth()/11, (n/3) * ofGetHeight() - (0.4*h/0.85));
    ofDrawBitmapString(name, ofGetWidth()/11, (n/3) * ofGetHeight() - (0.6*h/0.85));
}

bool Player::isBust()
{
    if(value > 21)
    {
        return true;
    }
    
    return false;
}

void Player::update()
{
    value = 0;
    
    for(int i = 0; i < hand.size(); i++)
    {
        value += hand.at(i).getValue();
    }
    
    if(value > 21)
    {
        for(int i = 0; i < hand.size(); i++)
        {
            if(hand.at(i).isAce())
            {
                hand.at(i).setValue(1);
            }
        }
    }
}

void Player::emptyHand()
{
    hand.clear();
}

void Player::resize()
{
    for(int i = 0; i < hand.size(); i++)
    {
        hand.at(i).setDimensions((int) (ofGetWidth()/12), (int) (ofGetWidth()/12 * 98/73));
    }
}

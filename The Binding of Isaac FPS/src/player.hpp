//
//  player.hpp
//  The Binding of Isaac FPS
//
//  Created by Abhay Singhal on 7/4/17.
//
//

#ifndef player_hpp
#define player_hpp

#include <stdio.h>
#include "ofMain.h"
#include "bullet.hpp"

class Player
{
    private:
        ofVec3f pos;
    
        ofVec3f size;
        float damage;
        float speed;
        float shotSpeed;
        float tears;
        float range;
        float tearSize;
    
        ofVec3f target;
    
        vector<Bullet> b;
    
        float health;
    
        float maxHealth;
    
        bool hit;
        int frame = 0;
    
        void checkBoundaries();
        void checkHealth();
    
    public:
        Player();
        ~Player();
        Player(ofVec3f _size, float _damage, float _speed, float _shotSpeed, float _tears, float _range, float _tearSize, float _health);
    
        void shoot();
        void update();
//        void hit(Enemy enemy);
        
};

#endif /* player_hpp */

//
//  enemy.hpp
//  Final Project
//
//  Created by Matthew on 2017-07-19.
//  Copyright © 2017 Matthew. All rights reserved.
//

#ifndef enemy_hpp
#define enemy_hpp

#include "character.h"
#include "../floor.h"
#include <cstdlib>
#include <ctime>

class Enemy: public Character{
    virtual void Dead(Character &other)=0;
    Floor *place;
public:
    Enemy(int Hp,int MaxHp,int Atk,int Def,string Race,char Symbol, Floor *place);
};
#endif /* enemy_hpp */

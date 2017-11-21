//
//  vampire.cpp
//  Final Project
//
//  Created by Matthew on 2017-07-19.
//  Copyright © 2017 Matthew. All rights reserved.
//

#include "vampire.h"
#include <math.h>

Vampire:: Vampire():Character{50,0,25,25,"Vampire",'@'}{}  // Vampire has no max HP

bool Vampire::attack(Character &other) {
    other.defend(*this);
    if (other.getRace()=="Dwarf") addHp(-5);
    else addHp(5);
    return true;
}


void Vampire::ability(TurnStage t){}

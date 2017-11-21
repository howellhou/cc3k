//
//  dwarf.cpp
//  Final Project
//
//  Created by Matthew on 2017-07-19.
//  Copyright © 2017 Matthew. All rights reserved.
//

#include "dwarf.h"
#include <math.h>

Dwarf:: Dwarf(Floor *place) : Enemy{100,100,20,30,"Dwarf",'W',place}{}

bool Dwarf::attack(Character &other){
    srand(time(NULL));
    int n=rand()%2;
    if (n==0) other.defend(*this);
    return true;
}

void Dwarf::defend(Character &other) {
    addHp(-ceil(100*other.getAtk()/(100+getDef())));
    if (getHp()<0) {
        addHp(-getHp());
    }
    if (getHp()==0) Dead(other);
}

void Dwarf::ability(TurnStage t){}

void Dwarf:: Dead(Character &other){
    srand(time(NULL));
    int n=rand()%2;
    if (n==0) other.addGold(1);
    else other.addGold(2);
}

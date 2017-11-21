//
//  orcs.cpp
//  Final Project
//
//  Created by Matthew on 2017-07-19.
//  Copyright © 2017 Matthew. All rights reserved.
//

#include "orcs.h"
#include <math.h>

Orcs:: Orcs(Floor *place) : Enemy{180,180,30,25,"Orcs",'O',place}{}

bool Orcs::attack(Character &other){
    srand(time(NULL));
    int n=rand()%2;
    if (n==0) other.defend(*this);
    return true;
}

void Orcs::defend(Character &other) {
    addHp(-ceil(100*other.getAtk()/(100+getDef())));
    if (getHp()<0) {
        addHp(-getHp());
    }
    if (getHp()==0) Dead(other);
}

void Orcs::ability(TurnStage t){}

void Orcs:: Dead(Character &other){
    srand(time(NULL));
    int n=rand()%2;
    if (n==0) other.addGold(1);
    else other.addGold(2);
}

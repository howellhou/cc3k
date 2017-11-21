//
//  halfling.cpp
//  Final Project
//
//  Created by Matthew on 2017-07-19.
//  Copyright © 2017 Matthew. All rights reserved.
//

#include "halfling.h"
#include <math.h>
#include <stdlib.h>
using namespace std;

Halfling:: Halfling(Floor *place) : Enemy{100,100,15,20,"Halfling",'L',place}{}

bool Halfling::attack(Character &other){
    srand(time(NULL));
    int n=rand()%2;
    if (n==0) other.defend(*this);
    return true;
}

void Halfling::defend(Character &other) {
    srand(time(NULL));
    int n=rand()%2;
    if (n==0) return;
    addHp(-ceil(100*other.getAtk()/(100+getDef())));
    if (getHp()<0) {
        addHp(-getHp());
    }
    if (getHp()==0) Dead(other);
}

void Halfling::ability(TurnStage t){}

void Halfling:: Dead(Character &other){
    srand(time(NULL));
    int n=rand()%2;
    if (n==0) other.addGold(1);
    else other.addGold(2);
}

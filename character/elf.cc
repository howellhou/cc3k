//
//  elf,orcs.cpp
//  Final Project
//
//  Created by Matthew on 2017-07-19.
//  Copyright © 2017 Matthew. All rights reserved.
//

#include "elf.h"
#include <math.h>

Elf:: Elf(Floor *place) : Enemy{140,140,30,10,"Elf",'E',place}{}

bool Elf::attack(Character &other) {
    srand(time(NULL));
    int n=rand()%2;
    if (n==0) other.defend(*this);
    if (other.getRace()!="Drow") {
        srand(time(NULL));
        n=rand()%2;
        if (n==0) other.defend(*this);
    }
    return true;
}

void Elf::defend(Character &other) {
    addHp(-ceil(100*other.getAtk()/(100+getDef())));
    if (getHp()<0) {
        addHp(-getHp());
    }
    if (getHp()==0) Dead(other);
}

void Elf::ability(TurnStage t){}

void Elf:: Dead(Character &other){
    srand(time(NULL));
    int n=rand()%2;
    if (n==0) other.addGold(1);
    else other.addGold(2);
}

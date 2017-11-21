//
//  merchant.cpp
//  Final Project
//
//  Created by Matthew on 2017-07-19.
//  Copyright © 2017 Matthew. All rights reserved.
//

#include "merchant.h"
#include <math.h>

bool Merchant:: isAttack=false;

Merchant:: Merchant(Floor *place) : Enemy{30,30,70,5,"Merchant",'M',place}{}

bool Merchant::attack(Character &other) {
    if(isAttack) {
        srand(time(NULL));
        int n=rand()%2;
        if (n==0) {
            other.defend(*this);
        }
        return true;
    }
    return false;
}

void Merchant::defend(Character &other) {
    isAttack=true;
    addHp(-ceil(100*other.getAtk()/(100+getDef())));
    if (getHp()<0) {
        addHp(-getHp());
    }
    if (getHp()==0) Dead(other);
}

void Merchant::ability(TurnStage t){}

void Merchant:: Dead(Character &other){}

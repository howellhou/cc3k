//
//  human.cpp
//  Final Project
//
//  Created by Matthew on 2017-07-19.
//  Copyright © 2017 Matthew. All rights reserved.
//

#include "human.h"
#include <math.h>

Human:: Human(Floor *place) : Enemy{140,140,20,20,"Human",'H', place}{}

bool Human::attack(Character &other){
    srand(time(NULL));
    int n=rand()%2;
    if (n==0) other.defend(*this);
    return true;
}

void Human::defend(Character &other) {
    addHp(-ceil(100*other.getAtk()/(100+getDef())));
    if (getHp()<0) {
        addHp(-getHp());
    }
    if (getHp()==0) Dead(other);
}

void Human::ability(TurnStage t){}

void Human:: Dead(Character &other){
   // other.addGold(4);
}

//
//  goblin.cpp
//  Final Project
//
//  Created by Matthew on 2017-07-19.
//  Copyright © 2017 Matthew. All rights reserved.
//

#include "goblin.h"
#include <math.h>

Goblin:: Goblin():Character{110,110,15,20,"Goblin",'@'}{}


void Goblin::defend(Character &other) {
    if (other.getRace()=="Orcs") addHp(1.5*(-ceil(100*other.getAtk()/(100+getDef()))));
    else addHp(-ceil(100*other.getAtk()/(100+getDef())));
    if (getHp()<0) {
        addHp(-getHp());
    }
    if (other.getHp()==0) ability(TurnStage::KillEnemy);
}

void Goblin::ability(TurnStage t){
    if (t==TurnStage:: KillEnemy) addGold(5);
}

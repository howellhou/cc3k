//
//  troll.cpp
//  Final Project
//
//  Created by Matthew on 2017-07-19.
//  Copyright © 2017 Matthew. All rights reserved.
//

#include "troll.h"
#include <math.h>

Troll:: Troll():Character{120,120,25,15,"Troll",'@'}{}

void Troll::ability(TurnStage t){
    if (t==TurnStage:: AfterTurn) addHp(5);
}

//
//  merchant.hpp
//  Final Project
//
//  Created by Matthew on 2017-07-19.
//  Copyright © 2017 Matthew. All rights reserved.
//

#ifndef merchant_hpp
#define merchant_hpp

#include "character.h"
#include "enemy.h"

class Merchant: public Enemy{
    static bool isAttack;
    void Dead(Character &other) override;
public:
    Merchant(Floor *place);
    bool attack(Character &other) override;
    void defend(Character &other) override;
    void ability(TurnStage t) override;
    
};

#endif /* merchant_hpp */

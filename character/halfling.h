//
//  halfling.hpp
//  Final Project
//
//  Created by Matthew on 2017-07-19.
//  Copyright © 2017 Matthew. All rights reserved.
//

#ifndef halfling_hpp
#define halfling_hpp

#include "character.h"
#include "enemy.h"

class Halfling: public Enemy{
    void Dead(Character &other) override;
public:
    Halfling(Floor *place);
    bool attack(Character &other) override;
    void defend(Character &other) override;
    void ability(TurnStage t) override;
    
};

#endif /* halfling_hpp */

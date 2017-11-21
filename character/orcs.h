//
//  orcs.hpp
//  Final Project
//
//  Created by Matthew on 2017-07-19.
//  Copyright © 2017 Matthew. All rights reserved.
//

#ifndef orcs_hpp
#define orcs_hpp

#include "character.h"
#include "enemy.h"

class Orcs: public Enemy{
    void Dead(Character &other) override;
public:
    Orcs(Floor *place);
    bool attack(Character &other) override;
    void defend(Character &other) override;
    void ability(TurnStage t) override;
    
};

#endif /* orcs_hpp */

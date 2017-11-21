//
//  human.hpp
//  Final Project
//
//  Created by Matthew on 2017-07-19.
//  Copyright © 2017 Matthew. All rights reserved.
//

#ifndef human_hpp
#define human_hpp


#include "enemy.h"

class Human: public Enemy{
    void Dead(Character &other) override;
public:
    Human(Floor *place);
    bool attack(Character &other) override;
    void defend(Character &other) override;
    void ability(TurnStage t) override;
    
};

#endif /* human_hpp */

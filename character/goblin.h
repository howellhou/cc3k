//
//  goblin.hpp
//  Final Project
//
//  Created by Matthew on 2017-07-19.
//  Copyright © 2017 Matthew. All rights reserved.
//

#ifndef goblin_hpp
#define goblin_hpp

#include "character.h"

class Goblin: public Character{
public:
    Goblin();
    void defend(Character &other) override;
    void ability(TurnStage t) override;
};

#endif /* goblin_hpp */

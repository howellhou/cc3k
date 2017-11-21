//
//  troll.hpp
//  Final Project
//
//  Created by Matthew on 2017-07-19.
//  Copyright © 2017 Matthew. All rights reserved.
//

#ifndef troll_hpp
#define troll_hpp

#include "character.h"

class Troll: public Character{
public:
    Troll();
    void ability(TurnStage t) override;
};

#endif /* troll_hpp */

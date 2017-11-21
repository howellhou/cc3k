//
//  vampire.hpp
//  Final Project
//
//  Created by Matthew on 2017-07-19.
//  Copyright © 2017 Matthew. All rights reserved.
//

#ifndef vampire_hpp
#define vampire_hpp

#include "character.h"

class Vampire : public Character{
public:
    Vampire();
    bool attack(Character &other) override;
    void ability(TurnStage t) override;
};

#endif /* vampire_hpp */

//
//  dwarf.hpp
//  Final Project
//
//  Created by Matthew on 2017-07-19.
//  Copyright © 2017 Matthew. All rights reserved.
//

#ifndef dwarf_hpp
#define dwarf_hpp

#include "character.h"
#include "enemy.h"

class Dwarf: public Enemy{
    void Dead(Character &other) override;
public:
    Dwarf(Floor *place);
    bool attack(Character &other) override;
    void defend(Character &other) override;
    void ability(TurnStage t) override;
    
};

#endif /* dwarf_hpp */

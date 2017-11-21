//
//  elf,orcs.hpp
//  Final Project
//
//  Created by Matthew on 2017-07-19.
//  Copyright © 2017 Matthew. All rights reserved.
//

#ifndef elf_orcs_hpp
#define elf_orcs_hpp

#include "character.h"
#include "enemy.h"

class Elf: public Enemy{
    void Dead(Character &other) override;
public:
    Elf(Floor *place);
    bool attack(Character &other) override;
    void defend(Character &other) override;
    void ability(TurnStage t) override;
    
};

#endif /* elf_orcs_hpp */

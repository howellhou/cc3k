//
//  drow.hpp
//  Final Project
//
//  Created by Matthew on 2017-07-19.
//  Copyright © 2017 Matthew. All rights reserved.
//

#ifndef drow_hpp
#define drow_hpp

#include "character.h"

class Drow : public Character{
public:
    Drow();
    void ability(TurnStage t) override;
    
};

#endif /* drow_hpp */

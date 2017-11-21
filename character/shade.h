#ifndef SHADE_H_INCLUDED
#define SHADE_H_INCLUDED

#include"character.h"

class Shade: public Character {
public:
    Shade();
    void ability(TurnStage t) override;
};


#endif // SHADE_H_INCLUDED

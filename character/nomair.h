#ifndef NOMAIR_H_INCLUDED
#define NOMAIR_H_INCLUDED

#include"character.h"

class Nomair: public Character {
public:
    Nomair();
    bool attack(Character &other) override;
    void defend(Character &other) override;
    void ability(TurnStage t) override;
};


#endif // NOMAIR_H_INCLUDED

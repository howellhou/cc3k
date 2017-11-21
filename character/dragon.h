#ifndef DRAGON_H_INCLUDED
#define DRAGON_H_INCLUDED
#include "enemy.h"
#include "../item/gold.h"


class Dragon : public Enemy {
    void Dead(Character &other) override;
public:
    Dragon(Floor *place,Cell *guard);
    void ability(TurnStage t) override;
    bool attack(Character &other) override;
};

#endif // DRAGON_H_INCLUDED

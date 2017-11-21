#ifndef GOLD_H_INCLUDED
#define GOLD_H_INCLUDED

#include "item.h"

class Character;

class Gold:public Item {
    int amount;
public:
    Gold(int amount);
    void use() override;
} ;

#endif // GOLD_H_INCLUDED

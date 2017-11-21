#include "dragon.h"
#include "../item/gold.h"

void Dragon::Dead(Character &other){}

Dragon::Dragon(Floor *place,Cell *guard):Enemy{150,150,20,20,"Dragon",'D',place} {this->guard=guard;}

void Dragon::ability(TurnStage t){}

bool Dragon::attack(Character &other) {
    srand(time(NULL));
    int n=rand()%2;
    if (n==0) other.defend(*this);
    return true;
}

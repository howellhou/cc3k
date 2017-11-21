#include "nomair.h"
#include <math.h>

Nomair::Nomair():Character{9999,9999,9999,9999,"Nomair",'@'}{}

bool Nomair::attack(Character &other) {
    other.defend(*this);
    return true;
}

void Nomair::defend(Character &other) {
    //Nomair will never lose HP!
}

void Nomair::ability(TurnStage t){}

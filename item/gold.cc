#include "gold.h"
#include "../character/character.h"

Gold::Gold(int amount):Item{"",'G'},amount{amount}{
    symbol = 'G';
    if (amount==1) {
        name = "small";
    } else if (amount == 2) {
        name = "normal";
    } else if (amount == 4) {
        name = "merchant hoard";
    } else {
        name = "dragon hoard";
    }
}

void Gold::use() {
    PC->addGold(amount);
}



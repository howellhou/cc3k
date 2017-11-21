#include "character.h"
#include "../cell.h"
#include <math.h>
using namespace std;

Character::Character(int Hp,int MaxHp,int Atk,int Def,string Race,char Symbol):Hp{Hp},MaxHp{MaxHp},Atk{Atk},Def{Def},Race{Race},Symbol{Symbol} {
    DefaultAtk=Atk;
    DefaultDef=Def;
}

void Character::addHp(int num) {
    Hp+=num;
    if (MaxHp!=0 && Hp>MaxHp) Hp=MaxHp;
}

void Character::addAtk(int num) {
    Atk+=num;
    if (Atk<0) Atk=0;
}

void Character::addDef(int num) {
    Def+=num;
    if (Def<0) Def=0;
}

int Character::getHp() const {return Hp;}

int Character::getAtk() const {return Atk;}

int Character::getDef() const {return Def;}

int Character::getX() const {return pos_x;}

int Character::getY() const {return pos_y;}

void Character::setX(int num) {pos_x=num;}

void Character::setY(int num) {pos_y=num;}

string Character::getRace() const{return Race;}

char Character::getSymbol() const {return Symbol;}

int Character::getGold() const {return gold;}

void Character::addGold(int num) {
    gold+=num;
    if (gold<0) gold=0;
}

void Character::addPotion(Item* p){
    UsedPotion.push_back(p);
}

void Character::clearAll() {
    Atk=DefaultAtk;
    Def=DefaultDef;
    UsedPotion.clear();
}

bool Character::attack(Character &other){
    other.defend(*this);
    return true;
}

void Character::defend(Character &other) {
    addHp(-ceil(100*other.getAtk()/(100+getDef())));
    if (getHp()<0) {
        addHp(-getHp());
    }
}

Cell* Character::getGuard() const {
    return guard;
}

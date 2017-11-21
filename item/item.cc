#include"item.h"
#include<iostream>

using namespace std;

Character* Item::PC=nullptr;

Item::Item(string name,char symbol):name{name},symbol{symbol}{}


void Item::unuse(){}

char Item::getSymbol() const {return symbol;}

string Item::getName() const {return name;}

Character* Item::getGuard() const{
    return guard;
}

void Item::setGuard(Character* guard) {
    this->guard=guard;
}

#include "potion.h"
#include "../character/character.h"

using namespace std;

Potion::Potion(string name):Item{name,'P'} {}

RH::RH() :Potion{"RH"}{}

BA::BA() :Potion{"BA"}{}

BD::BD() :Potion{"BD"}{}

PH::PH() :Potion{"PH"}{}

WA::WA() :Potion{"WA"}{}

WD::WD() :Potion{"WD"}{}

void RH::use() {
    PC->addHp(10);
    if (PC->getRace()=="Drow") PC->addHp(10*0.5);
}

void BA::use() {
    PC->addAtk(5);
    if (PC->getRace()=="Drow") PC->addAtk(5*0.5);
}

void BA::unuse() {
    PC->addAtk(-5);
    if (PC->getRace()=="Drow") PC->addAtk(-5*0.5);
}

void BD::use() {
    PC->addDef(5);
    if (PC->getRace()=="Drow") PC->addDef(5*0.5);
}

void BD::unuse() {
    PC->addDef(-5);
    if (PC->getRace()=="Drow") PC->addDef(-5*0.5);
}

void PH::use() {
    PC->addHp(-10);
    if (PC->getRace()=="Drow") PC->addHp(-10*0.5);
}


void WA::use() {
    PC->addAtk(-5);
    if (PC->getRace()=="Drow") PC->addAtk(-5*0.5);
}

void WA::unuse() {
    PC->addAtk(5);
    if (PC->getRace()=="Drow") PC->addAtk(5*0.5);
}

void WD::use() {
    PC->addAtk(-5);
    if (PC->getRace()=="Drow") PC->addAtk(-5*0.5);
}

void WD::unuse() {
    PC->addAtk(5);
    if (PC->getRace()=="Drow") PC->addAtk(5*0.5);
}

#ifndef POTION_H_INCLUDED
#define POTION_H_INCLUDED
#include <string>
#include "item.h"
using namespace std;

class Potion:public Item{
public:
    Potion(string name);
};

class RH:public Potion{
public:
    RH();
    void use() override;
};

class BA:public Potion{
public:
    BA();
    void use() override;
    void unuse() override;
};

class BD:public Potion{
public:
    BD();
    void use() override;
    void unuse() override;
};

class PH:public Potion{
public:
    PH();
    void use() override;
};

class WA:public Potion{
public:
    WA();
    void use() override;
    void unuse() override;
};

class WD:public Potion{
public:
    WD();
    void use() override;
    void unuse() override;
};
#endif // POTION_H_INCLUDED

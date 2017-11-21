#ifndef FLOOR_H_INCLUDED
#define FLOOR_H_INCLUDED

#include <vector>
#include "cell.h"
#include "item/gold.h"
#include "item/potion.h"
#include <string>
#include <memory>
using namespace std;

class Enemy;

class Floor{
    const int width=79;
    const int height=25;
    const int FloorNum;
    string action;
    Character *PC;
    vector <vector <Cell>> TheFloor;
    void setChamber(int x,int y,int num);
    bool PCMove (string direction);
    bool PcUsePotion(string direction);
    bool PCAttack(string direction);
    vector <Cell *> EmptyCell[5];
    Cell *getEmpty(int NotFrom=-1);
    vector <shared_ptr<Gold>> GoldList;
    vector <shared_ptr<Potion>> PotionList;
    vector <shared_ptr<Enemy>> EnemyList;
    static bool freeze;
public:
    static void SetFreeze(bool flag);
    Floor(Character *PC,int FloorNum,std::istream &in,bool GivenMap);
    void PCExecute(string command);
    void EnemyExecute();
    friend std::ostream &operator<<(std::ostream &out, const Floor &f);
};

class Dead {};

class NextFloor {};

#endif // FLOOR_H_INCLUDED

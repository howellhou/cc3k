#ifndef CHARACTER_H_INCLUDED
#define CHARACTER_H_INCLUDED

#include <string>
#include <vector>
#include "../item/potion.h"

using  namespace std;

enum class TurnStage {AfterAttack,AfterTurn,KillEnemy};

class Item;
class Cell;

class Character{
    int Hp;
    int MaxHp;
    int Atk;
    int DefaultAtk;
    int Def;
    int DefaultDef;
    int pos_x;
    int pos_y;
    int gold=0;
    string Race;
    char Symbol;
    vector <Item*> UsedPotion;
protected:
    Cell* guard=nullptr;
public:
    Character(int Hp,int MaxHp,int Atk,int Def,string race,char symbol);
    virtual void ability(TurnStage t)=0;
    virtual bool attack(Character &other);
    virtual void defend(Character &other);
    char getSymbol() const;
    void addHp(int num);
    void addAtk(int num);
    void addDef(int num);
    int getHp() const;
    int getAtk() const;
    int getDef() const;
    int getX() const;
    int getY() const;
    int getGold() const;
    void addGold(int num);
    void setX(int num);
    void setY(int num);
    void addPotion(Item* p);
    void clearAll();
    string getRace() const;
    Cell* getGuard() const;
};


#endif // CHARACTER_H_INCLUDED

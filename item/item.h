#ifndef ITEM_H_INCLUDED
#define ITEM_H_INCLUDED
#include <string>

using namespace std;

class Character;

class Item {
protected:
    string name;
    char symbol;
    Character* guard=nullptr;
public:
    Item(string name,char symbol);
    static Character* PC;
    virtual void use()=0;
    virtual void unuse();
    char getSymbol() const;
    string getName() const;
    Character* getGuard() const;
    void setGuard(Character* guard);

};


#endif // ITEM_H_INCLUDED

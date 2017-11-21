#ifndef CELL_H_INCLUDED
#define CELL_H_INCLUDED
#include <iostream>
#include "item/potion.h"
enum class CellType {wall,tile,doorway,stairway,passage,nothing};
enum class CellContent {character,item,nothing};

class Character;
class Item;

class Cell {
    int pos_x;
    int pos_y;
    int ChamberNum;
    CellType type;
    char symbol;
    CellContent content;
    Character* CharacterPtr=nullptr;
    Item* ItemPtr=nullptr;
public:
    Cell(int x,int y,char symbol);
    CellType getType() const;
    CellContent getContent() const;
    int getChamberNum() const;
    void setChamber(int num);
    void set(Character* CharacterPtr);
    void unset();
    void set(Item* ItemPtr);
    void useitem();
    void setStairway();
    int getX() const;
    int getY() const;
    Item* getItem() const;
    Character* getCharacter() const;
    char getSymbol() const;
    friend std::ostream &operator<<(std::ostream &out, const Cell &c);

};


#endif // CELL_H_INCLUDED

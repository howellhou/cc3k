#include "cell.h"
#include "character/character.h"
#include "item/item.h"

Cell::Cell(int x,int y,char symbol):pos_x{x},pos_y{y},ChamberNum{-1},symbol{symbol},content{CellContent::nothing}{
    if (symbol=='-' || symbol=='|') {
        type = CellType::wall;
    } else if (symbol=='+') {
        type = CellType::doorway;
    } else if (symbol=='#') {
        type = CellType::passage;
    } else if (symbol==' ') {
        type = CellType::nothing;
    } else if (symbol=='.'){
        type = CellType::tile;
    }
}

std::ostream &operator<<(std::ostream &out, const Cell &c) {
    out<<c.symbol;
    return out;
}

CellType Cell::getType() const{
    return type;
}

int Cell::getChamberNum() const{
    return ChamberNum;
}

void Cell::setChamber(int num) {
    ChamberNum=num;
}

void Cell::setStairway() {
    type=CellType::stairway;
    symbol='\\';
}

void Cell::unset() {
    CharacterPtr = nullptr;
    ItemPtr = nullptr;
    content = CellContent::nothing;
    if (type==CellType::doorway) symbol='+';
    if (type==CellType::passage) symbol='#';
    if (type==CellType::tile) symbol='.';
}

void Cell::set(Character* CharacterPtr) {
    this->CharacterPtr = CharacterPtr;
    content = CellContent::character;
    symbol=CharacterPtr->getSymbol();
}

void Cell::set(Item* ItemPtr) {
    this->ItemPtr = ItemPtr;
    content = CellContent::item;
    symbol = ItemPtr->getSymbol();
}

CellContent Cell::getContent() const {
    return content;
}

int Cell::getX() const {
    return pos_x;
}

int Cell::getY() const {
    return pos_y;
}

char Cell::getSymbol() const {
    return symbol;
}

void Cell::useitem() {
    if (ItemPtr!=nullptr) ItemPtr->use();
}

Item* Cell::getItem() const {
    return ItemPtr;
}

Character* Cell::getCharacter() const{
    return CharacterPtr;
}

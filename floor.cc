#include "floor.h"
#include <fstream>
#include <sstream>
#include "character/allrace.h"
#include <cstdlib>
#include <ctime>
#include <math.h>
#include "item/gold.h"
#include "item/potion.h"
#include <algorithm>

using namespace std;

bool EnemyCmp(shared_ptr<Enemy> e1,shared_ptr<Enemy> e2) {
    Enemy* ePtr1 = e1.get();
    Enemy* ePtr2 = e2.get();
    if (ePtr1->getX()<ePtr2->getX()) return true;
    return (ePtr1->getY()<ePtr2->getY());
}

bool Floor::freeze=false;

bool JudgeDirection(string direction,int &x,int &y)
{
    x=0;
    y=0;
    if (direction=="no")
    {
        x=-1;
    }
    else if (direction=="so")
    {
        x=1;
    }
    else if (direction=="ea")
    {
        y=1;
    }
    else if (direction=="we")
    {
        y=-1;
    }
    else if (direction=="ne")
    {
        x=-1;
        y=1;
    }
    else if (direction=="nw")
    {
        x=-1;
        y=-1;
    }
    else if (direction=="se")
    {
        x=1;
        y=1;
    }
    else if (direction=="sw")
    {
        x=1;
        y=-1;
    }
    else
    {
        return false;
    }
    return true;
}

Floor::Floor(Character *PC,int FloorNum,istream &in,bool GivenMap):FloorNum {FloorNum},PC {PC}
{
    if (GivenMap)
    {
        char Map[25][79];
        char symbol;
        string line;
        for (int i=0; i<25; i++)
        {
            getline(in,line);
            istringstream ss {line};
            vector<Cell> RowTemp {};
            for (int j=0; j<79; j++)
            {
                symbol=ss.get();
                Map[i][j]=symbol;
                if (symbol!='.'&&symbol!='-'&&symbol!='|'&&
                        symbol!='+'&&symbol!='#'&&symbol!=' ') symbol='.';
                Cell temp {i,j,symbol};
                RowTemp.push_back(temp);
            }
            TheFloor.push_back(RowTemp);
        }
        int num=0;
        for (int i=0; i<25; i++)
        {
            for (int j=0; j<79; j++)
            {
                if (TheFloor[i][j].getType()==CellType::tile &&
                        TheFloor[i][j].getChamberNum()==-1)
                {
                    setChamber(i,j,num);
                    num++;
                }
            }
        }
        for (int i=0; i<25; i++)
        {
            for (int j=0; j<79; j++)
            {
                if(Map[i][j]=='@')
                {
                    TheFloor[i][j].set(PC);
                    PC->setX(i);
                    PC->setY(j);
                }
                else if (Map[i][j]=='\\')
                {
                    TheFloor[i][j].setStairway();
                }
                else if (Map[i][j]=='0')
                {
                    shared_ptr<Potion> PotionTemp {new RH{}};
                    PotionList.push_back(PotionTemp);
                    TheFloor[i][j].set(PotionList.back().get());
                }
                else if (Map[i][j]=='1')
                {
                    shared_ptr<Potion> PotionTemp {new BA{}};
                    PotionList.push_back(PotionTemp);
                    TheFloor[i][j].set(PotionList.back().get());
                }
                else if (Map[i][j]=='2')
                {
                    shared_ptr<Potion> PotionTemp {new BD{}};
                    PotionList.push_back(PotionTemp);
                    TheFloor[i][j].set(PotionList.back().get());
                }
                else if (Map[i][j]=='3')
                {
                    shared_ptr<Potion> PotionTemp {new PH{}};
                    PotionList.push_back(PotionTemp);
                    TheFloor[i][j].set(PotionList.back().get());
                }
                else if (Map[i][j]=='4')
                {
                    shared_ptr<Potion> PotionTemp {new WA{}};
                    PotionList.push_back(PotionTemp);
                    TheFloor[i][j].set(PotionList.back().get());
                }
                else if (Map[i][j]=='5')
                {
                    shared_ptr<Potion> PotionTemp {new WD{}};
                    PotionList.push_back(PotionTemp);
                    TheFloor[i][j].set(PotionList.back().get());
                }
                else if (Map[i][j]=='6')
                {
                    shared_ptr<Gold> GoldTemp {new Gold{2}};
                    GoldList.push_back(GoldTemp);
                    TheFloor[i][j].set(GoldTemp.get());
                }
                else if (Map[i][j]=='7')
                {
                    shared_ptr<Gold> GoldTemp {new Gold{1}};
                    GoldList.push_back(GoldTemp);
                    TheFloor[i][j].set(GoldTemp.get());
                }
                else if (Map[i][j]=='8')
                {
                    shared_ptr<Gold> GoldTemp {new Gold{4}};
                    GoldList.push_back(GoldTemp);
                    TheFloor[i][j].set(GoldTemp.get());
                }
                else if (Map[i][j]=='H')
                {
                    shared_ptr<Enemy> EnemyTemp {new Human{this}};
                    EnemyList.push_back(EnemyTemp);
                    TheFloor[i][j].set(EnemyTemp.get());
                    EnemyList.back()->setX(i);
                    EnemyList.back()->setY(j);
                }
                else if (Map[i][j]=='W')
                {
                    shared_ptr<Enemy> EnemyTemp {new Dwarf{this}};
                    EnemyList.push_back(EnemyTemp);
                    TheFloor[i][j].set(EnemyTemp.get());
                    EnemyList.back()->setX(i);
                    EnemyList.back()->setY(j);
                }
                else if (Map[i][j]=='E')
                {
                    shared_ptr<Enemy> EnemyTemp {new Elf{this}};
                    EnemyList.push_back(EnemyTemp);
                    TheFloor[i][j].set(EnemyTemp.get());
                    EnemyList.back()->setX(i);
                    EnemyList.back()->setY(j);
                }
                else if (Map[i][j]=='O')
                {
                    shared_ptr<Enemy> EnemyTemp {new Orcs{this}};
                    EnemyList.push_back(EnemyTemp);
                    TheFloor[i][j].set(EnemyTemp.get());
                    EnemyList.back()->setX(i);
                    EnemyList.back()->setY(j);
                }
                else if (Map[i][j]=='M')
                {
                    shared_ptr<Enemy> EnemyTemp {new Merchant{this}};
                    EnemyList.push_back(EnemyTemp);
                    TheFloor[i][j].set(EnemyTemp.get());
                    EnemyList.back()->setX(i);
                    EnemyList.back()->setY(j);
                }
                else if (Map[i][j]=='L')
                {
                    shared_ptr<Enemy> EnemyTemp {new Halfling{this}};
                    EnemyList.push_back(EnemyTemp);
                    TheFloor[i][j].set(EnemyTemp.get());
                    EnemyList.back()->setX(i);
                    EnemyList.back()->setY(j);
                }
                else if (Map[i][j]=='9')
                {
                    int DragonX;
                    int DragonY;
                    for(int tempi=i-1; tempi<=i+1; tempi++)
                    {
                        for (int tempj=j-1; tempj<=j+1; tempj++)
                        {
                            if (Map[tempi][tempj]=='D')
                            {
                                DragonX=tempi;
                                DragonY=tempj;
                            }
                        }
                    }
                    shared_ptr<Gold> GoldTemp {new Gold{6}};
                    GoldList.push_back(GoldTemp);
                    TheFloor[i][j].set(GoldTemp.get());
                    shared_ptr<Enemy> EnemyTemp {new Dragon{this,&TheFloor[i][j]}};
                    EnemyList.push_back(EnemyTemp);
                    TheFloor[DragonX][DragonY].set(EnemyTemp.get());
                    GoldTemp->setGuard(EnemyTemp.get());
                    EnemyTemp->setX(DragonX);
                    EnemyTemp->setY(DragonY);
                }
            }
        }
    }
    else {
        char symbol;
        string line;
        for (int i=0; i<25; i++)
        {
            getline(in,line);
            istringstream ss {line};
            vector<Cell> RowTemp {};
            for (int j=0; j<79; j++)
            {
                symbol=ss.get();
                Cell temp {i,j,symbol};
                RowTemp.push_back(temp);
            }
            TheFloor.push_back(RowTemp);
        }
        int num=0;
        for (int i=0; i<25; i++)
        {
            for (int j=0; j<79; j++)
            {
                if (TheFloor[i][j].getType()==CellType::tile &&
                        TheFloor[i][j].getChamberNum()==-1)
                {
                    setChamber(i,j,num);
                    num++;
                }
            }
        }
        Cell* RndPos = getEmpty();
        PC->setX(RndPos->getX());
        PC->setY(RndPos->getY());
        TheFloor[RndPos->getX()][RndPos->getY()].set(PC);
        Cell* RndStair = getEmpty(RndPos->getChamberNum());
        RndStair->setStairway();
        for (int i=0; i<10; i++) //Create Potions
        {
            RndPos = getEmpty();
            int PotionType = rand() % 6;
            if (PotionType == 0)
            {
                shared_ptr<Potion> PotionTemp {new RH{}};
                PotionList.push_back(PotionTemp);
            }
            else if (PotionType == 1)
            {
                shared_ptr<Potion> PotionTemp {new BA{}};
                PotionList.push_back(PotionTemp);
            }
            else if (PotionType == 2)
            {
                shared_ptr<Potion> PotionTemp {new BD{}};
                PotionList.push_back(PotionTemp);
            }
            else if (PotionType == 3)
            {
                shared_ptr<Potion> PotionTemp {new PH{}};
                PotionList.push_back(PotionTemp);
            }
            else if (PotionType == 4)
            {
                shared_ptr<Potion> PotionTemp {new WA{}};
                PotionList.push_back(PotionTemp);
            }
            else if (PotionType == 5)
            {
                shared_ptr<Potion> PotionTemp {new WD{}};
                PotionList.push_back(PotionTemp);
            }
            RndPos->set(PotionList.back().get());
        }
        for (int i=0; i<10; i++) //Create Golds
        {
            RndPos = getEmpty();
            int PotionType = rand() % 8;
            if (PotionType < 5)
            {
                shared_ptr<Gold> GoldTemp {new Gold{1}};
                GoldList.push_back(GoldTemp);
                RndPos->set(GoldTemp.get());
            }
            else if (PotionType < 7)
            {
                shared_ptr<Gold> GoldTemp {new Gold{2}};
                GoldList.push_back(GoldTemp);
                RndPos->set(GoldTemp.get());
            }
            else
            {
                shared_ptr<Gold> GoldTemp {new Gold{6}};
                GoldList.push_back(GoldTemp);
                RndPos->set(GoldTemp.get());
                vector<Cell*> PossiblePos;
                for (int j=-1; j<=1; j++)
                    for (int k=-1; k<=1; k++)
                        if (TheFloor[RndPos->getX()+j][RndPos->getY()+k].getSymbol()=='.')
                        {
                            PossiblePos.push_back(&TheFloor[RndPos->getX()+j][RndPos->getY()+k]);
                        }
                if (PossiblePos.size()!=0)
                {
                    Cell* RndDragon=PossiblePos[rand()%PossiblePos.size()];
                    for (int z=0; z<EmptyCell[RndDragon->getChamberNum()].size(); z++)
                    {
                        if (EmptyCell[RndDragon->getChamberNum()][z]==RndDragon)
                        {
                            EmptyCell[RndDragon->getChamberNum()].erase(EmptyCell[RndDragon->getChamberNum()].begin()+z);
                        }
                    }
                    shared_ptr<Enemy> EnemyTemp {new Dragon{this,RndPos}};
                    EnemyList.push_back(EnemyTemp);
                    RndDragon->set(EnemyTemp.get());
                    GoldTemp->setGuard(EnemyTemp.get());
                    EnemyTemp->setX(RndDragon->getX());
                    EnemyTemp->setY(RndDragon->getY());
                }
            }
        }
        for (int i=0; i<10; i++) //Create Enemies
        {
            RndPos = getEmpty();
            int EnemyType = rand() % 18;
            if (EnemyType < 4)
            {
                shared_ptr<Enemy> EnemyTemp {new Human{this}};
                EnemyList.push_back(EnemyTemp);
                RndPos->set(EnemyTemp.get());
            }
            else if (EnemyType < 7)
            {
                shared_ptr<Enemy> EnemyTemp {new Dwarf{this}};
                EnemyList.push_back(EnemyTemp);
                RndPos->set(EnemyTemp.get());
            }
            else if (EnemyType < 12)
            {
                shared_ptr<Enemy> EnemyTemp {new Halfling{this}};
                EnemyList.push_back(EnemyTemp);
                RndPos->set(EnemyTemp.get());
            }
            else if (EnemyType < 14)
            {
                shared_ptr<Enemy> EnemyTemp {new Elf{this}};
                EnemyList.push_back(EnemyTemp);
                RndPos->set(EnemyTemp.get());
            }
            else if (EnemyType < 16)
            {
                shared_ptr<Enemy> EnemyTemp {new Orcs{this}};
                EnemyList.push_back(EnemyTemp);
                RndPos->set(EnemyTemp.get());
            }
            else
            {
                shared_ptr<Enemy> EnemyTemp {new Merchant{this}};
                EnemyList.push_back(EnemyTemp);
                RndPos->set(EnemyTemp.get());
            }
            EnemyList.back()->setX(RndPos->getX());
            EnemyList.back()->setY(RndPos->getY());
        }
    }
}

bool Floor::PcUsePotion(string direction)
{
    int x,y;
    if(!JudgeDirection(direction,x,y))
    {
        action="Invalid direction!!";
        return false;
    }
    Cell* dest = &TheFloor[PC->getX()+x][PC->getY()+y];
    if (dest->getSymbol()=='P')
    {
        PC->addPotion(dest->getItem());
        dest->getItem()->use();
        action="PC uses "+dest->getItem()->getName()+"!!";
        dest->unset();
        if (PC->getHp()<0)
        {
            PC->addHp(-PC->getHp());
            cout<<*this;
            Dead d;
            throw d;
        }
        return true;
    }
    else
    {
        action="Hey, there's no potion at that direction!";
        return false;
    }
}

void Floor::setChamber(int x,int y,int num)
{
    TheFloor[x][y].setChamber(num);
    EmptyCell[num].push_back(&TheFloor[x][y]);
    if(x+1<25 &&
            TheFloor[x+1][y+0].getType()==CellType::tile &&
            TheFloor[x+1][y+0].getChamberNum()==-1)
        setChamber(x+1,y+0,num);
    if(x-1>=0 &&
            TheFloor[x-1][y+0].getType()==CellType::tile &&
            TheFloor[x-1][y+0].getChamberNum()==-1)
        setChamber(x-1,y+0,num);
    if(y+1<79 &&
            TheFloor[x+0][y+1].getType()==CellType::tile &&
            TheFloor[x+0][y+1].getChamberNum()==-1)
        setChamber(x+0,y+1,num);
    if(y-1>=0 &&
            TheFloor[x+0][y-1].getType()==CellType::tile &&
            TheFloor[x+0][y-1].getChamberNum()==-1)
        setChamber(x+0,y-1,num);
}

std::ostream &operator<<(std::ostream &out, const Floor &f)
{
    for (int i=0; i<25; i++)
    {
        for (int j=0; j<79; j++)
        {
            out<<f.TheFloor[i][j];
        }
        out<<endl;
    }
    out<<"Race: "<<f.PC->getRace()<<"     Gold:"<<f.PC->getGold()<<"                                             Floor:"<<f.FloorNum<<endl;
    out<<"HP: "<<f.PC->getHp()<<endl;
    out<<"Atk: "<<f.PC->getAtk()<<endl;
    out<<"Def: "<<f.PC->getDef()<<endl;
    out<<"Action: "<<f.action<<endl;
    return out;
}

void Floor::EnemyExecute()
{
    if (!freeze)
    {
        for (int i=0; i<EnemyList.size(); i++)
        {
            if ((abs(PC->getX()-EnemyList[i]->getX())<=1 &&
                    abs(PC->getY()-EnemyList[i]->getY())<=1) ||
                    (EnemyList[i]->getRace()=="Dragon" &&
                     abs(PC->getX()-EnemyList[i]->getGuard()->getX())<=1 &&
                     abs(PC->getY()-EnemyList[i]->getGuard()->getY())<=1))
            {
                int PastHP = PC->getHp();
                if (EnemyList[i]->attack(*PC))
                {
                    action+=EnemyList[i]->getRace()+" attacks PC";
                    int CurHp = PC->getHp();
                    if (CurHp==PastHP)
                    {
                        action+=" but missed~";
                    }
                    else
                    {
                        action+=" and deals "+ to_string(PastHP-CurHp) +" damage.";
                    }
                    if (PC->getHp()==0)
                    {
                        cout<<*this;
                        Dead d;
                        throw d;
                    }
                }
            }
            else
            {
                if (EnemyList[i]->getRace()=="Dragon") continue;
                vector<Cell*> PossiblePos;
                for (int j=-1; j<=1; j++)
                    for (int k=-1; k<=1; k++)
                        if (TheFloor[EnemyList[i]->getX()+j][EnemyList[i]->getY()+k].getSymbol()=='.')
                        {
                            PossiblePos.push_back(&TheFloor[EnemyList[i]->getX()+j][EnemyList[i]->getY()+k]);
                        }
                if (PossiblePos.size()!=0)
                {
                    Cell* RndMov=PossiblePos[rand()%PossiblePos.size()];
                    RndMov->set(EnemyList[i].get());
                    TheFloor[EnemyList[i]->getX()][EnemyList[i]->getY()].unset();
                    EnemyList[i]->setX(RndMov->getX());
                    EnemyList[i]->setY(RndMov->getY());

                }
            }
        }
    }
    std::sort(EnemyList.begin(),EnemyList.end(),EnemyCmp);
}

bool Floor::PCMove(string direction)
{
    int x,y;
    JudgeDirection(direction,x,y);
    Cell* dest = &TheFloor[PC->getX()+x][PC->getY()+y];
    if (dest->getType()==CellType::stairway)
    {
        NextFloor n;
        PC->clearAll();
        throw n;
    }
    if (dest->getSymbol()=='G'&&(dest->getItem()->getGuard()==nullptr))
    {
        dest->useitem();
        dest->unset();
        action="PC picked some Gold! ";
    }
    if (dest->getSymbol()!='.' && dest->getSymbol()!='G'&&
            dest->getSymbol()!='#' && dest->getSymbol()!='+')
    {
        action="Can't Walk through that direction!";
        return false;
    }
    TheFloor[PC->getX()+x][PC->getY()+y].set(PC);
    if (TheFloor[PC->getX()][PC->getY()].getItem()!=nullptr)
    {
        Item* goldin= TheFloor[PC->getX()][PC->getY()].getItem();
        TheFloor[PC->getX()][PC->getY()].unset();
        TheFloor[PC->getX()][PC->getY()].set(goldin);
    }
    else
    {
        TheFloor[PC->getX()][PC->getY()].unset();
    }
    PC->setX(PC->getX()+x);
    PC->setY(PC->getY()+y);
    action+="PC moves "+direction+". ";

    return true;
}

bool Floor::PCAttack(string direction)
{
    int x,y;
    if(!JudgeDirection(direction,x,y))
    {
        action="Invalid direction!!";
        return false;
    }
    Cell* dest = &TheFloor[PC->getX()+x][PC->getY()+y];
    if (dest->getContent()!=CellContent::character)
    {
        action="Hey, there's no enemy at that direction!";
        return false;
    }
    else
    {
        Character* target=dest->getCharacter();
        int PastHp=target->getHp();
        PC->attack(*target);
        if (PC->getHp()==0)
        {
            cout<<*this;
            Dead d;
            throw d;
        }
        int CurHp=target->getHp();
        action="PC attacks "+ target->getRace();
        if (PastHp-CurHp!=0) {
            action+=" and deals "+to_string(PastHp-CurHp)+" damage";
        } else {
            action+=" but missed";
        }
        action+=" ("+to_string(CurHp)+" HP).";
        if (target->getHp()==0)
        {
            string KilledRace=target->getRace();
            dest->unset();
            if (KilledRace=="Dragon") target->getGuard()->getItem()->setGuard(nullptr);
            if (KilledRace=="Human"||KilledRace=="Merchant")
            {
                shared_ptr<Gold> GoldTemp {new Gold{4}};
                GoldList.push_back(GoldTemp);
                dest->set(GoldTemp.get());
            }
            for (int i=0; i<EnemyList.size(); i++)
            {
                if (target==EnemyList[i].get()) EnemyList.erase(EnemyList.begin()+i);
            }

        }
        return true;
    }
}

void Floor::PCExecute(string command)
{
    action="";
    if (command=="no"||command=="so"||command=="ea"||command=="we"||
            command=="ne"||command=="nw"||command=="se"||command=="sw")
    {
        if(PCMove(command))
        {
            EnemyExecute();
            PC->ability(TurnStage::AfterTurn);
        }
    }
    else if (command == "f")
    {
        if (freeze)
        {
            freeze=false;
            action="Enemies can move now!";
        }
        else
        {
            freeze=true;
            action="Enemies can't move now!";
        }
    }
    else
    {
        istringstream ss {command};
        string lhs;
        string rhs;
        ss>>lhs;
        ss>>rhs;
        if (lhs=="u")
        {
            if (PcUsePotion(rhs))
            {
                EnemyExecute();
                PC->ability(TurnStage::AfterTurn);
            }
        }
        else if (lhs=="a")
        {
            if (PCAttack(rhs))
            {
                EnemyExecute();
                PC->ability(TurnStage::AfterTurn);
            }
        }
        else
        {
            action="Invalid Input!";
        }
    }
    cout<<*this;
}

Cell * Floor::getEmpty(int NotFrom)
{
    int RndChamber = rand() % 5;
    while (EmptyCell[RndChamber].size() == 0 || RndChamber==NotFrom) RndChamber = rand() % 5;
    int RndCellNum = rand() % EmptyCell[RndChamber].size();
    Cell *RndCell = EmptyCell[RndChamber][RndCellNum];
    EmptyCell[RndChamber].erase(EmptyCell[RndChamber].begin()+RndCellNum);
    return RndCell;
}

void Floor:: SetFreeze(bool flag)
{
    freeze=flag;
}

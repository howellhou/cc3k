#include <iostream>
#include "floor.h"
#include <cstdlib>
#include <fstream>
#include <memory>
#include "character/allrace.h"
#include <cstdlib>
#include <ctime>
#include "item/item.h"
#include <string.h>
#include "room-gen.h"
using namespace std;

class Quit {};
class Restart {};

int main(int argc, char *argv[])
{
    bool GivenMap=false;
    bool SpecialControl=false;
    bool RndMap=false;
    string MapName="DefaultMap.txt";
    for (int i=1;i<argc;i++) {
        if (argv[i][0]!='-'){
            GivenMap=true;
            MapName=argv[1];
        }
        if (strcmp(argv[i],"-WASD")==0) SpecialControl=true;
        if (strcmp(argv[i],"-RandomMap")==0) RndMap=true;
    }
    if (RndMap) {
        GenMap();
        MapName="rnfloor.txt";
        GivenMap=false;
    }
    Floor::SetFreeze(false);
    srand((unsigned)time(NULL));
    vector<shared_ptr<Character>> PC;
    while (true)
    {
        cout<<"Welcome to the World of CC3K,please choose your Race:"<<endl<<endl;
        cout<<"You have the following choices:"<<endl;
        cout<<"Shade:   125 HP, 25 Atk, 25 Def ,have a 50% increase to the score.                          Enter 's' to be a Shade"<<endl;
        cout<<"Drow:    150 HP, 25 Atk, 15 Def ,all potions have their effect magnified by 1.5.            Enter 'd' to be a Drow"<<endl;
        cout<<"Vampire:  50 HP, 25 Atk, 25 Def ,gains 5 HP every successful attack and has no maximum HP.  Enter 'v' to be a Vampire"<<endl;
        cout<<"Troll:   120 HP, 25 Atk, 15 Def ,regains 5 HP every turn; HP is capped at 120 HP.           Enter 't' to be a Troll"<<endl;
        cout<<"Goblin:  110 HP, 15 Atk, 20 Def ,steals 5 gold from every slain enemy.                      Enter 'g' to be a Goblin"<<endl;
        while (true)
        {
            char choice;
            cin>>choice;
            if (choice=='s')
            {
                shared_ptr<Character> TempPC {new Shade{}};
                PC.push_back(TempPC);
                break;
            }
            else if (choice=='d')
            {
                shared_ptr<Character> TempPC {new Drow{}};
                PC.push_back(TempPC);
                break;
            }
            else if (choice=='v')
            {
                shared_ptr<Character> TempPC {new Vampire{}};
                PC.push_back(TempPC);
                break;
            }
            else if (choice=='t')
            {
                shared_ptr<Character> TempPC {new Troll{}};
                PC.push_back(TempPC);
                break;
            }
            else if (choice=='g')
            {
                shared_ptr<Character> TempPC {new Goblin{}};
                PC.push_back(TempPC);
                break;
            }
            else if (choice=='N')
            {
                shared_ptr<Character> TempPC {new Nomair{}};
                PC.push_back(TempPC);
                break;
            }
            cout<<"Invalid choice! Please choose again";
        }
        Character* Player=PC[0].get();
        Item::PC = Player;
        ifstream fs {MapName};
        string firstline;
        getline(cin,firstline);
        try
        {
            for (int i=0; i<5; i++)
            {
                Floor f {Player,i+1,fs,GivenMap};
                cout<<f;
                while (true)
                {
                    string line;
                    getline(cin,line);
                    if (line=="q")
                    {
                        Quit qq;
                        throw qq;
                    }
                    if (line=="r")
                    {
                        Restart rr;
                        throw rr;
                    }
                    try
                    {
                        f.PCExecute(line);
                    }
                    catch (NextFloor& n)
                    {
                        if (i!=4) break;
                        cout<<"You Win!!!Your score is:" << Player->getGold()*(Player->getRace()=="Shade"?1.5:1)<<endl;
                        cout<<"Enter 'r' to play again, or enter 'q' to quit."<<endl;
                        while (true)
                        {
                            char choice;
                            cin>>choice;
                            if (choice=='r')
                            {
                                Restart rr;
                                throw rr;
                            }
                            if (choice=='q')
                            {
                                Quit qq;
                                throw qq;
                            }
                            cout<<"Invalid choice!"<<endl;
                        }
                    }
                    catch (Dead& d)
                    {
                        cout<<"Sorry,you died...Your score is:" << Player->getGold()*(Player->getRace()=="Shade"?1.5:1)<<endl;
                        cout<<"Enter 'r' to try again, or enter 'q' to quit."<<endl;
                        while (true)
                        {
                            char choice;
                            cin>>choice;
                            if (choice=='r')
                            {
                                Restart rr;
                                throw rr;
                            }
                            if (choice=='q')
                            {
                                Quit qq;
                                throw qq;
                            }
                            cout<<"Invalid choice!"<<endl;
                        }
                    }
                }
            }
        }
        catch (Quit& q)
        {
            break;
        }
        catch (Restart& r)
        {
            PC.clear();
            continue;
        }
    }
}

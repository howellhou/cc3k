//
//  enemy.cpp
//  Final Project
//
//  Created by Matthew on 2017-07-19.
//  Copyright © 2017 Matthew. All rights reserved.
//

#include "enemy.h"
using namespace std;

Enemy:: Enemy(int Hp,int MaxHp,int Atk,int Def,string Race,char Symbol, Floor *place): Character{Hp,MaxHp,Atk,Def,Race,Symbol}, place{place} {}



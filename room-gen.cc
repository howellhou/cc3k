#include <string>
#include <iostream>
#include <stdlib.h>
#include <vector>
#include <fstream>
#include <time.h>
#include "room-gen.h"

using namespace std;

class RoomFail {};

char map[25][79];

int room_max_width_big = 25;
int room_min_width_big = 20;
int room_max_height_big = 15;
int room_min_height_big = 12;

int room_max_width_small = 13;
int room_min_width_small = 9;
int room_max_height_small = 10;
int room_min_height_small = 7;


struct Room
{
    int pos_x;
    int pos_y;
    int w;
    int h;
    int start_x;
    int start_y;

    Room (int pos_x, int pos_y, int w, int h)
        :pos_x {pos_x}, pos_y {pos_y}, w {w}, h {h}, start_x {0}, start_y {0} {}


    void setStartPoint ()
    {
        start_x = rand() % (w-2) + 1 + pos_x;
        start_y = rand() % (h-2) + 1 + pos_y;
    }
};

void print_room (ofstream &out)
{
    for (int i = 0; i < 25; ++i)
    {
        for (int j = 0; j < 79; ++j)
        {
            out << map[i][j];
        }
        out << endl;
    }
}

//initilized wall
void wall_ini ()
{
    for (int i = 0; i < 25 ; ++ i)
    {
        for (int j = 0; j < 79 ; ++j )
        {
            if (j == 0 || j == 78)
            {
                map[i][j] = '|';
            }
            else if ((i == 0 || i == 24)&&(j>=1 && j<=77))
            {
                map[i][j] = '-';
            }
            else
            {
                map[i][j] = ' ';
            }
        }
    }
}

//print the room
void build_room (int pos_x , int pos_y , int w , int h)
{
    for (int i = 0; i < h; ++i )
    {
        for (int j = 0; j < w; ++ j)
        {
            if (j == 0 || j == w-1)
            {
                map[i + pos_y][j + pos_x] = '|';
            }
            else if ((i == 0 || i == h-1)&&(j>=1 && j<=w-2))
            {
                map[i + pos_y][j + pos_x] = '-';
            }
            else
            {
                map[i + pos_y][j + pos_x] = '.';
            }
        }
    }
}

//vaild room_post

bool vaild_room_pos (int pos_x, int pos_y, int w, int h)
{
    //check out of the edge
    if (pos_x + w > 79 || pos_y + h > 25) return false;
    for (int i = 0; i < h + 3; ++i )
    {
        for (int j = 0; j < w + 3; ++j)
        {
            if (map[pos_y - 1 + i][ pos_x - 1  + j] != ' ')
            {
                return false;
            }
        }
    }
    return true;

}
//generator room

void room_gen (int nor ,std::vector<Room> &vr)
{
    int big_rm = 2;
    int maketry = 1000;
    while (nor != 0 && maketry > 0)
    {
        int ran_size = rand() % 2;
        int rw, rh, rx, ry;
        if (ran_size == 0 && big_rm > 0)
        {
            maketry--;
            rw = rand() % (room_max_width_big - room_min_width_big) + room_min_width_big;
            rh = rand() % (room_max_height_big - room_min_height_big) + room_min_height_big;
            rx = rand() % 79;
            ry = rand() % 25;
            big_rm--;
            if (vaild_room_pos (rx, ry ,rw , rh))
            {
                build_room (rx, ry ,rw , rh);
                --nor;
                vr.emplace_back(Room {rx,ry,rw,rh});
            }
        }
        else if (ran_size == 1)
        {
            maketry--;
            rw = rand() % (room_max_width_small - room_min_width_small) + room_min_width_small;
            rh = rand() % (room_max_height_small - room_min_height_small) + room_min_height_small;
            rx = rand() % 79;
            ry = rand() % 25;

            if (vaild_room_pos (rx, ry ,rw , rh))
            {
                build_room (rx, ry ,rw , rh);
                --nor;
                vr.emplace_back(Room {rx,ry,rw,rh});
            }
        }

    }
    if (maketry == 0)
    {
        RoomFail ff;
        throw ff;
    }
}

// connect the room and create the pass
void connectRoom (Room r1, Room r2)
{
    int digdirect;
    while (r1.start_x != r2.start_x || r1.start_y != r2.start_y)
    {
        digdirect = rand() % 2;
        if (digdirect == 0 && (r1.start_x != r2.start_x))
        {
            if (r1.start_x > r2.start_x)
            {
                --r1.start_x;
            }
            else if (r1.start_x < r2.start_x)
            {
                ++r1.start_x;
            }
        }
        else if (digdirect == 1 && (r1.start_y != r2.start_y))
        {
            if (r1.start_y > r2.start_y)
            {
                --r1.start_y;
            }
            else if (r1.start_y < r2.start_y)
            {
                ++r1.start_y;
            }
        }
        if(map[r1.start_y][r1.start_x] == ' ')
        {
            map[r1.start_y][r1.start_x]='#';
        }
        else if (map[r1.start_y][r1.start_x] == '|' || map[r1.start_y][r1.start_x] == '-')
        {
            map[r1.start_y][r1.start_x]='+';
        }
    }
}

void createTunnel (std::vector<Room> &vr)
{
    for (int i = 0; i < 5 ; ++ i)
    {
        vr[i].setStartPoint();
    }
    for (int i = 0; i < 4 ; ++i )
    {
        connectRoom(vr[i] , vr[i+1]);
    }
}

void gen_map (int nor, int nol, std::ofstream &out)
{
    int n = nol;
    vector <Room> vr;
    srand (time(NULL));
    while (n > 0)
    {
        wall_ini();
        room_gen (nor,vr);
        createTunnel(vr);
        print_room(out);
        n--;
        vr.clear();
    }
}

void GenMap ()
{
    ofstream ofs {"rnfloor.txt"};
    if (ofs.is_open())
    {
        while (true)
        {
            int nol = 5;
            int nor = 5;
            try
            {
                gen_map(nor, nol, ofs);
                break;
            }
            catch (RoomFail ff)
            {
            }
        }

    }
    ofs.close();
}

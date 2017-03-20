//
//  maze.cpp
//  Homwork 3
//
//  Created by Qinhao Xu on 2/12/17.
//  Copyright © 2017 Qinhao Xukk. All rights reserved.
//

#include <iostream>
#include <string>
#include <assert.h>


using namespace std;

class Coord
{
public:
    Coord(int rr, int cc) : m_r(rr), m_c(cc) {}
    int r() const { return m_r; }
    int c() const { return m_c; }
private:
    int m_r;
    int m_c;
};

bool pathExists(string maze[],int sr, int sc, int er, int ec)
{
    if(sr == er && sc==ec)
        return true;
    maze[sr][sc]='@';
     if(sr!=0&&maze[sr-1][sc]!='X'&&maze[sr-1][sc]!='@')// move north
         if(pathExists(maze, sr-1, sc, er, ec))
             return true;
    if(sr!=9&&maze[sr][sc+1]!='X'&&maze[sr][sc+1]!='@')//move east
        if(pathExists(maze, sr, sc+1, er, ec))
            return true;
    if(sr!=9&&maze[sr+1][sc]!='X'&&maze[sr+1][sc]!='@')//move south
        if(pathExists(maze, sr+1, sc, er, ec))
            return true;
    if(sr!=0&&maze[sr][sc-1]!='X'&&maze[sr][sc-1]!='@')// move west
        if(pathExists(maze, sr, sc-1, er, ec))
            return true;
    return false;
}

int main()
{
    string maze1[10] = {
        "XXXXXXXXXX'",
        "X.X..X...X'",
        "X.XX.X.XXX'",
        "X....X.X.X'",
        "XX.X.X...X'",
        "XXX..X.X.X'",
        "X...X...XX'",
        "X.XX..X.XX'",
        "X....X...X'",
        "XXXXXXXXXX'",
    };
    
    string maze2[10] = {
        "XXXXXXXXXX'",
        "X.X..X...X'",
        "XXXX.X.XXX'",
        "X....X.X.X'",
        "XX.X.X...X'",
        "XXX..X.X.X'",
        "X...X...XX'",
        "X.XX..X.XX'",
        "X....X...X'",
        "XXXXXXXXXX'",
    };
    
    string maze3[10] = {
        "XXXXXXXXXX'",
        "XX.....XXX'",
        "X..XX....X'",
        "X...X...XX'",
        "X.X.XXX..X'",
        "XXXX..X..X'",
        "XX....X..X'",
        "X.......XX'",
        "X..XXXXXXX'",
        "XXXXXXXXXX'",
    };
    
    string maze4[10] = {
        "XXXXXXXXXX'",
        "XX.....XXX'",
        "X..XX....X'",
        "X...X...XX'",
        "X.X.XXX..X'",
        "XXXX..X..X'",
        "XX....X..X'",
        "X.X.....XX'",
        "X..XXXXXXX'",
        "XXXXXXXXXX'",
    };
    
    assert(pathExists(maze1, 8, 6, 1, 1));
    assert(!pathExists(maze2, 8, 6, 1, 1));
    assert(pathExists(maze3, 4, 3, 7, 1));
    assert(!pathExists(maze4,4, 3, 7, 1));
    /*
    string maze[10] = {
        "XXXXXXXXXX",
        "X........X",
        "XX.X.XXXXX",
        "X..X.X...X",
        "X..X...X.X",
        "XXXX.XXX.X",
        "X.X....XXX",
        "X..XX.XX.X",
        "X...X....X",
        "XXXXXXXXXX"
    };
    
    
    if (pathExists(maze, 6,4, 1,1))
    {
        
        cout << "Solvable!" << endl;
    }
    else
    {
        cout << "Out of luck!" << endl;
    }*/
}


/*
If the start location is equal to the ending location, then we've
solved the maze, so return true.
Mark the start location as visted.
For each of the four directions,
If the location one step in that direction (from the start
                                            location) is unvisited,
then call pathExists starting from that location (and
                                                  ending at the same ending location as in the
                                                  current call).
If that returned true,
then return true.
Return false.*/
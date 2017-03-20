//
//  mazequeue.cpp
//  Homework 2
//
//  Created by Qinhao Xu on 2/4/17.
//  Copyright © 2017 Qinhao Xukk. All rights reserved.
//

#include <iostream>
#include <string>
#include <queue>
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

bool pathExists(string maze[], int nRows, int nCols, int sr, int sc, int er, int ec)
{
    queue<Coord> isqueue;
    isqueue.push(Coord(sr,sc));
    maze[sr][sc]='@';
    
    while(!isqueue.empty())
    {
        Coord s= isqueue.front();
        int r=s.r();
        int c=s.c();
        isqueue.pop();
        
        if(r==er && c==ec)
        {
            return true;
        }
        if(r!=0&&maze[r-1][c]!='X'&&maze[r-1][c]!='@')// move to north
        {
            isqueue.push(Coord(r-1,c));
            maze[r-1][c]='@';
        }
        if(c!=9&&maze[r][c+1]!='X'&&maze[r][c+1]!='@')//move east
        {
            isqueue.push(Coord(r,c+1));
            maze[r][c+1]='@';
        }
        if(r!=9&&maze[r-1][c]!='X'&&maze[r-1][c]!='@') // move south
        {
            isqueue.push(Coord(r-1,c));
            maze[r+1][c]='@';
        }
        if(c!=0&&maze[r][c-1]!='X'&&maze[r][c-1]!='@')// move west
        {
            isqueue.push(Coord(r,c-1));
            maze[r][c-1]='@';
        }
        
    }
    
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
    
    //assert(pathExists(maze1, 10, 10, 8, 6, 1, 1));
    assert(!pathExists(maze2, 10, 0, 8, 6, 1, 1));
    //assert(pathExists(maze3, 10, 10, 4, 3, 7, 1));
    assert(!pathExists(maze4, 10, 10, 4, 3, 7, 1));
}

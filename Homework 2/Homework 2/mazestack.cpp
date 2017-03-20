//
//  main.cpp
//  Homework 2
//
//  Created by Qinhao Xu on 2/3/17.
//  Copyright © 2017 Qinhao Xukk. All rights reserved.
//

#include <iostream>
#include <string>
#include <stack>
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
    stack<Coord> istack;// initialize the empty stack
    istack.push(Coord(sr,sc));// push the coordinate into the stack
    maze[sr][sc]='@';
    
    
    while(!istack.empty())// while the stack is not empty
    {
        Coord s= istack.top();
        int r=s.r();
        int c=s.c();
        istack.pop();
    
        if(r==er && c==ec)
        {
            return true;
        }
        if(r!=0&&maze[r-1][c]!='X'&&maze[r-1][c]!='@')//If you can move NORTH and haven't encountered that cell yet,

        {
            istack.push(Coord (r-1,c));
            maze[r-1][c]='@';
        }
        if(c!=9&&maze[r][c+1]!='X'&&maze[r][c+1]!='@')// If you can move EAST and haven't encountered that cell yet,

        {
            
            istack.push(Coord (r,c+1));
            maze[r][c+1]='@';
        }
        if(r!=9&&maze[r+1][c]!='X'&&maze[r+1][c]!='@')//If you can move SOUTH and haven't encountered that cell yet,
        {
            
            istack.push(Coord (r+1,c));
            maze[r+1][c]='@';
        }
        if(c!=0&&maze[r][c-1]!='X'&&maze[r][c-1]!='@')//If you can move WEST and haven't encountered that cell yet,
        {
            
            istack.push(Coord (r,c-1));
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
    
    assert(pathExists(maze1, 10, 10, 8, 6, 1, 1));
    assert(!pathExists(maze2, 10, 0, 8, 6, 1, 1));
    assert(pathExists(maze3, 10, 10, 4, 3, 7, 1));
    assert(!pathExists(maze4, 10, 10, 4, 3, 7, 1));

    
}






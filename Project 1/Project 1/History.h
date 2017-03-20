//
//  History.hpp
//  Project 1
//
//  Created by Qinhao Xu on 1/10/17.
//  Copyright © 2017 Qinhao Xukk. All rights reserved.
//

#ifndef History_h
#define History_h

#include "globals.h"
class Arena;

class History
{
public:
    History(int nRows, int nCols);
    bool record(int r, int c);
    void display() const;

private:
    int m_nRows;
    int m_nCols;
    int m_grid[MAXROWS][MAXCOLS];// create a 2d array to record the unposisoned rat has eaten a posion pellet at a grid point
};

#endif /* History_hpp */

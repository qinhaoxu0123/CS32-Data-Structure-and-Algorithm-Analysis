//
//  History.cpp
//  Project 1
//
//  Created by Qinhao Xu on 1/10/17.
//  Copyright © 2017 Qinhao Xukk. All rights reserved.
//

#include "globals.h"
#include "History.h"
#include<iostream>
#include <cstdlib>

using namespace std;

History::History(int nRows, int nCols)
            :m_nRows(nRows), m_nCols(nCols)// initialization
{
 if(m_nRows> MAXROWS || m_nRows >MAXCOLS || m_nRows<= 0 || m_nCols <= 0)// check whether the the arugments are vaild or not
 {
     cout<< "The arugment is invaild, please enter the vaild arugument"<< endl;
     exit(1);
 }
    for(int i= 0; i<m_nRows;i++)// everytime it create a instance or object, initialize a 2D array to record the the unposioned rat that eats pellet
        for(int j =0; j<m_nCols;j++)
            m_grid[i][j]= 0;
    
}

bool History::record(int r, int c)
{
    if(r<=0 || c<=0 || r>m_nRows || c>m_nCols)// return false if it is not within bound.
        return false;
    else
        m_grid[r-1][c-1]++; //recording the unposioned rat that eat pellet.
    return true;
}

void History::display() const
{
    clearScreen();// clean the screen
    
    for(int i =0; i<m_nRows; i++)
    {
        for(int j =0; j<m_nCols; j++)
        {
            char letter='.';//at the grid point no rat has eaten a posioned pellle
            int k=m_grid[i][j];//create a k varibale of type int to store how many time a unposined rat has eaten a pellet at this grid spot.
            if(k>=26)//if greater than 26
                letter= 'Z';
            else if (k>0)// if it is between 1 and 25.
                letter= 'A' + k-1;//according to ascii table, A is 65, then if at this grid spot, only one unposined rat has a pellet. then print the leetter according to the letter. 
            cout<<letter;
        }
        cout<<endl;
    }
    cout<< endl;
}



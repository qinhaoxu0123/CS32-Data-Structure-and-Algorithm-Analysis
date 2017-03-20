//
//  ScoreList.cpp
//  Homework 1
//
//  Created by Qinhao Xu on 1/21/17.
//  Copyright © 2017 Qinhao Xukk. All rights reserved.
//

#include "ScoreList.h"
#include "Sequence.h"

#include <iostream>

using namespace std;

ScoreList::ScoreList()
:m_sequence()
{
}// Create an empty score list.

bool ScoreList::add(unsigned long score)// If the score is valid (a value from 0 to 100) and the score list has room for it
{
    if(score <=100 && size()<DEFAULT_MAX_ITEMS)// between 0 and 100 and size is less than the maxsize
    {
        m_sequence.insert(score);// insert the score using the function insert
        return true;
    }
    else
    {
        return false;
    }
}
// If the score is valid (a value from 0 to 100) and the score list
// has room for it, add it to the score list and return true.
// Otherwise, leave the score list unchanged and return false.

bool ScoreList::remove(unsigned long score)
{
    if(m_sequence.find(score)!=-1)// using find to return is not equal to -1 which means the score is in the seqeunce.
    {
    m_sequence.erase(m_sequence.find(score));// using the find function to find the pos of the score in the array and then return pos of score to erase function to have the fuction taking care of it .
    return true;
    }
    else
    {
        return false;
    }

}
// Remove one instance of the specified score from the score list.
// Return true if a score was removed; otherwise false.

int ScoreList::size() const
{
    /*unsigned long tmp =0;
   
    for (int i =0; i<m_sequence.size();i++)
    {
        m_sequence.get(i,tmp);
        cout << tmp << endl;
    }*/
    
    return m_sequence.size();
}
// Return the number of scores in the list.

unsigned long ScoreList::minimum() const
{
    if(size()==0)// if the array is empty
        return NO_SCORE;
    
    unsigned long lowestscore = 0;// create a varable that holds the lowest score
    unsigned long tmp1=0, tmp2=0;//  set the two variables to zero
    m_sequence.get(0,tmp1);// get the first elemenet of the array and then store into the tmp1
  
    
    for(int i=0;i<m_sequence.size();i++)// loop through the sequence
    {
        
        m_sequence.get(i,tmp2);// this variable will keep change
        
        if(tmp1<=tmp2)
        {
            lowestscore=tmp1;
        }
        else
        {
            lowestscore=tmp2;
            tmp1=tmp2;//upadate the tmp1 to the lowest score also because we want to continue to have the tmp2 score to compare with the tmp1 so tmp1 needs to be update for this purpose
        }
    }
    return lowestscore;
}
// Return the lowest score in the score list.  If the list is
// empty, return NO_SCORE.

unsigned long ScoreList::maximum() const
{
 
    if(size()==0)
    {
        return NO_SCORE;
    }
    
    unsigned long maxscore = 0;
    unsigned long tmp1=0, tmp2=0;
    m_sequence.get(0,tmp1);
    
    for(int i=0;i<m_sequence.size();i++)
    {
        
        m_sequence.get(i,tmp2);
        
        if(tmp1>=tmp2)
        {
            maxscore=tmp1;
        }
        else
        {
            maxscore=tmp2;
            tmp1=tmp2;
        }
    }
    return maxscore;
}


// Return the highest score in the score list.  If the list is
// empty, return NO_SCORE.

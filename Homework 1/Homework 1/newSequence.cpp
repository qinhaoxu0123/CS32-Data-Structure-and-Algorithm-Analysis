//
//  newSequence.cpp
//  Homework 1
//
//  Created by Qinhao Xu on 1/22/17.
//  Copyright © 2017 Qinhao Xukk. All rights reserved.
//

#include "newSequence.h"
#include <iostream>

Sequence::Sequence()
{
    max_size=DEFAULT_MAX_ITEMS;
    m_array= new ItemType[DEFAULT_MAX_ITEMS];
    itemcount=0;
    
}


Sequence::Sequence(int n)
{
    if(n<0)
    {
        std::cout<<"size must great than 0!\n";
    }
    itemcount=0;
    max_size=n;
    m_array= new ItemType[n];
}// Create an empty sequence (i.e., one whose size() is 0).

Sequence::~Sequence()
{
    delete [] m_array;
}

Sequence::Sequence(const Sequence& old)//copy constructor
{
    max_size=old.max_size;
    itemcount=old.itemcount;
    m_array= new ItemType[max_size];
    
    for(int i =0; i<itemcount; i++)
    {
         m_array[i]=old.m_array[i];
    }

}

Sequence &Sequence::operator=(const Sequence &assign)// assignemnt operator
{

    
    delete [] m_array;
    max_size=assign.max_size;
    m_array =new ItemType[max_size];
    for(int i =0; i<itemcount; i++)
    {
        m_array[i]=assign.m_array[i];
    }
    /*
    if(this != &assign)
    {
        Sequence tmp(assign);
        swap(tmp);
    }*/
    
    return(*this);
}


bool Sequence::empty() const
{
    if(itemcount==0)
        return true;
    else
        return false;
    
}// Return true if the sequence is empty, otherwise false.

int Sequence::size() const
{
 
    return itemcount;
}// Return the number of items in the sequence.

bool Sequence::insert(int pos, const ItemType& value)
{
    if(itemcount>=max_size)// m_array is full
        return false;
    
    if(pos>=0 && pos <=itemcount)
    {
        
        for(int i=itemcount; i>=pos+1; i--)//move one left and starting at the end
        {
            m_array[i]=m_array[i-1];
        }
        if(pos==itemcount)//f pos is equal to size(), the value is inserted at the
            // end.
        {
            m_array[pos]=value;
        }
        
        m_array[pos]=value;
        itemcount++;
        return true;
    }
    return false;
    
}
// Insert value into the sequence so that it becomes the item at
// position pos.  The original item at position pos and those that
// follow it end up at positions one higher than they were at before.
// Return true if 0 <= pos <= size() and the value could be
// inserted.  (It might not be, if the sequence has a fixed capacity,
// (e.g., because it's implemented using a fixed-size array) and is
// full.)  Otherwise, leave the sequence unchanged and return false.
// Notice that if pos is equal to size(), the value is inserted at the
// end.

//typedef unsigned long ItemType;
int Sequence::insert(const ItemType& value)
{
    if(size()==max_size)// if the array is full.
        return -1;
    
    int p=0;//Let p be the smallest integer
    
    if(itemcount<max_size)
    {
        for(int i=0; i<itemcount; i++)
        {
            if(m_array[i]>=value)
            {
                p=i;
                break;
            }
            else//if no such item exists (i.e., value > all items in the sequence), let p be size().
            {
                p=size();
            }
            
        }
        for(int k= itemcount;k >=p; k--)
        {
            m_array[k]=m_array[k-1];// store the previous value to the next value so that by the end it is one higher than before.
        }
        m_array[p]=value;//insert value into the sequence so that it becomes the item at position p.
        itemcount++;
        return 0;
    }
    
    return -1;
}
// Let p be the smallest integer such that value <= the item at
// position p in the sequence; if no such item exists (i.e.,
// value > all items in the sequence), let p be size().  Insert
// value into the sequence so that it becomes the item at position
// p.  The original item at position p and those that follow it end
// up at positions one higher than before.  Return p if the value
// was actually inserted.  Return -1 if the value was not inserted
// (perhaps because the sequence has a fixed capacity and is full).

bool Sequence::erase(int pos)
{
    if(pos>=0 && pos<itemcount)
    {
        //remove that item
        itemcount--;
        for(int i= pos;i<=itemcount;i++)
        {
            m_array[i]=m_array[i+1];
        }
        
        return true;
    }
    return false;
}
// If 0 <= pos < size(), remove the item at position pos from
// the sequence (so that all items that followed this item end up at
// positions one lower than they were at before), and return true.
// Otherwise, leave the sequence unchanged and return false.

int Sequence::remove(const ItemType& value)
{
    int itemremoved =0;
    
    if(itemcount==0)
        return 0;
    
    for(int i= 0; i<itemcount; i++)
    {
        if(m_array[i] ==value)
        {
            
            for(int j=i; j<itemcount;j++)
            {
                
                m_array[j]=m_array[j+1];
                
            }
            itemcount--;
            itemremoved++;
            i--;
        }
        
    }
    // std::cout<< itemremoved<<std::endl;
    return itemremoved;
}
// Erase all items from the sequence that == value.  Return the
// number of items removed (which will be 0 if no item == value).

bool Sequence::get(int pos, ItemType& value) const
{
    if(pos>=0 && pos <itemcount)
    {
        value=m_array[pos];
        return true;
    }
    return false;
    
}

// If 0 <= pos < size(), copy into value the item at position pos
// in the sequence and return true.  Otherwise, leave value unchanged
// and return false.

bool Sequence::set(int pos, const ItemType& value)
{
    if(pos>=0 && pos <itemcount)
    {
        m_array[pos]=value;
        return true;
    }
    return false;
    
}
// If 0 <= pos < size(), replace the item at position pos in the
// sequence with value and return true.  Otherwise, leave the sequence
// unchanged and return false.


int Sequence::find(const ItemType& value) const
{
    
    if(itemcount>0)
    {
        for(int i=0; i<itemcount; i++)
        {
            if (m_array[i]==value)
                return i;
        }
    }
    
    return -1;
}
// Let p be the smallest integer such that value == the item at
// position p in the sequence; if no such item exists, let p be -1.
// Return p.

void Sequence::swap(Sequence& other)
{
    int tmp1= itemcount;// swap the item
    itemcount=other.itemcount;
    other.itemcount=tmp1;
    
    int tmp2 =max_size;//swap the max_size;
    max_size=other.max_size;
    other.max_size=tmp2;
    
    ItemType *tmp;// swap the pointers
    tmp=m_array;
    m_array=other.m_array;
    other.m_array=tmp;
    
}
// Exchange the contents of this sequence with the other one.



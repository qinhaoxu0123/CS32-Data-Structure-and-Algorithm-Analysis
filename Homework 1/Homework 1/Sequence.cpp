//
//  main.cpp
//  Homework 1
//
//  Created by Qinhao Xu on 1/18/17.
//  Copyright © 2017 Qinhao Xukk. All rights reserved.
//

#include "Sequence.h"
#include <iostream>

Sequence::Sequence()
{
    itemcount=0;
   
    
}// Create an empty sequence (i.e., one whose size() is 0).

bool Sequence::empty() const
{
    if(itemcount==0)
        return true;
    else
        return false;
    
}// Return true if the sequence is empty, otherwise false.

int Sequence::size() const
{
    //std::cout<<itemcount<<std::endl;
    return itemcount;
}// Return the number of items in the sequence.

bool Sequence::insert(int pos, const ItemType& value)
{
   if(itemcount>=DEFAULT_MAX_ITEMS)// m_array is full
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
    if(itemcount==DEFAULT_MAX_ITEMS)// if the array is full.
        return -1;
    
    int p=0;//Let p be the smallest integer
    
  if(itemcount<DEFAULT_MAX_ITEMS)
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
    if(pos>=0 && pos<size())
    {
        //remove that item
        
        for(int i= pos;i<=size();i++)
        {
            m_array[i]=m_array[i+1];
        }
        itemcount--;
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

    
        for(int i=0; i<itemcount; i++)
        {
        if (m_array[i]==value)
            return i;
        }

    
    return -1;
}
// Let p be the smallest integer such that value == the item at
// position p in the sequence; if no such item exists, let p be -1.
// Return p.

void Sequence::swap(Sequence& other)
{
    ItemType tmp_array[DEFAULT_MAX_ITEMS];// create a tmp array that holds the m_array.
    
    int tmp_itemcount =itemcount;//have the tmp size's equals to the m_array size
    itemcount=other.itemcount;// have the m_array size equals to the other array size because we want the m_array size to be able to hold the item in other array.
    other.itemcount=tmp_itemcount;// have other array equals to the m_array size.
    
    
    for(int i=0 ; i<DEFAULT_MAX_ITEMS; i++)// loop through the array
        
    {
        tmp_array[i]=m_array[i];
        m_array[i]=other.m_array[i];
        other.m_array[i]=tmp_array[i];
    }
    
    
}
// Exchange the contents of this sequence with the other one.


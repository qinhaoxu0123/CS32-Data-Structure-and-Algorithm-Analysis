//
//  Sequence.cpp
//  Project 2
//
//  Created by Qinhao Xu on 1/27/17.
//  Copyright © 2017 Qinhao Xukk. All rights reserved.
//

#include "Sequence.h"
#include <iostream>
#include <cassert>

void Sequence::dump()
{
    node*p=head;
    while(p!=nullptr)
    {
        std::cerr<<p->value<<std::endl;
        p=p->next;
    }
}
Sequence::Sequence()//constructing the object when it creates a object
{
    head=nullptr;
    m_size=0;
}

Sequence::~Sequence()// destructiing all allocation memory in our program
{
 /*
    node* temp=head;// create a new node and equals points to the head
    while(temp!=nullptr)//loop through the linked list
    {
        node* m_delete= temp->next;// stop before the allocated node and then create another new node points to the node that we want to delete
        delete temp;
        temp=m_delete;
    }*/
    
    
    node* tmp= head;
    if(tmp!=nullptr)
    {
        while(tmp->next!=nullptr)
        {
            node*p=tmp->next;
            delete tmp;
            tmp=p;
        }
        delete tmp;
    }
}

 

Sequence::Sequence(const Sequence& old)//copy all the exsiting info into a new node
{
    /*
    head = new node;
    head->next = head;
    head->prev = head;
    
    for (node* p = old.head; p != nullptr; p = p->next)
    {
        node* add = new node;
        add->value = p->value;
        add->next = head;
        add->prev = head->prev;
        head->prev->next = add;
        head->prev = add;
    }*/
    
   /* m_size=old.m_size;
    node* curr=head;
    
    while(curr!=nullptr)
    {
        node *p1= new node;
        p1->value=curr->value;
        node *p2=p1;
        p1->prev=p2;
        p1->prev->next=p2;
        p2=p1;
        curr=curr->next;
    }*/
    m_size=0;
    head=nullptr;
    node *curr=old.head;
    for(int i=0; i<old.size();i++)
    {
        this->insert(i,curr->value);
        curr=curr->next;
    }
    curr=nullptr;
}


 Sequence &Sequence::operator=(const Sequence&old)//assign an exsiting node into another exsiting node
{
    /*
    node* temp;// delete the old allocated memory
    temp=head;
    while(temp!=nullptr)
    {
        node* m_delete= temp->next;
        delete temp;
        temp=m_delete;
    }*/
    
   if(this!= &old)//if they are not equaled to each other
   {
       Sequence temp(old);// using copy constructor and then swap them.
       swap(temp);
   }
    return *this;
}

bool Sequence::empty() const
{
    if(size()==0)// if the head is equaled to nullptr then it is a empty list
        return true;
    else
       
       /* for (node*p=head;p->next!=nullptr;p=p->next)
            std::cout << p->value << std::endl;*/
    
        return false;
}

int Sequence::size() const// return number of node in the linked list
{
    return m_size;
}

bool Sequence::insert(int pos,const ItemType& value)
{
    if(pos<0 || pos>m_size)// check the valid pos
        return false;
    else if(m_size==0)// empty list
    {
        node* p =new node;
        p->value=value;
        p->prev=nullptr;
        p->next=nullptr;
        head=p;
        m_size++;
        return true;
    }else if(pos>=0 && pos<m_size)// 0<=pos<m_size
    {
        node * global=head;// create a global node points to the head
        for(int i =0; i<m_size;i++)// loop through the list to get the position
        {
            if(pos==i)
            {
            if(pos==0)/// when the list is not empty and want to insert at position 0;
                {
                node*h= new node;
                h->value=value;
                h->prev=nullptr;
                h->next= global;
                global->prev=h;
                head=h;
                m_size++;
                return true;
                }
            else if(pos>0 && pos<=m_size-2)// when we want to insert a node after postion 0 in a not empty list
                {
                //;
                node* p =new node;
                p->value=value;
                p->prev=global;
                p->next=global->next;
                global->next=p;
                global->next->prev=p;
                m_size++;
                return true;
                }
                else // if list is not empty and we we want to insert at position 3 in a 4 item sequence;
                {
                    node*j=new node;
                    j->value=value;
                    j->prev=global;
                    j->next=nullptr;
                    global->next=j;
                    m_size++;
                    return true;
                
                }
            }
            global=global->next;
        }
    }
    else if(pos==m_size)
    {
        node*add=head;
        while(add->next!=nullptr)
        {
            add=add->next;
        }
        node* n=new node;
        n->value=value;
        n->prev=add;
        add->next=n;
        n->next=nullptr;
        m_size++;
        return true;
    }
    
    return false;
}

int Sequence::insert(const ItemType& value)// insert value into the list
{
    
    int p=0;
    node *dummy= head;
   
        for(int i=0;i<m_size;i++)//loop through the linked list
        {
    
            if(dummy->value>=value)// if the value in the linked list is greater and equal to the value
            {
                p=i;//break out with the positon index;
                break;
            }
            else
            {
                p=size();
            }
            dummy=dummy->next;
        }
    
        insert(p,value);// with the index and value, insert function will take care of it
    
        return true;
}

bool Sequence::erase(int pos)
{
    if(m_size==1&&pos==0)// if the list only have only item
    {
        head=nullptr;
        return true;
    }
    if(pos >=0 && pos<size())// 0<=pos<size()
    {
        node *dummy=head;
        for (int i=0; i<m_size; i++)
        {
            pos=i;
            if(pos==0)// if the list has item and want to remove pos 0;
            {
                node*kill=head;
                kill->next->prev=nullptr;
                head=kill;
                delete kill;
                m_size--;
                return true;
                
            }
            if(pos==i)// other wise this will take care of it
            {
                node*kill=head->next;
                dummy->next=kill->next;
                kill->next->prev=dummy;
                delete kill;
                return true;
            }
            dummy=dummy->next;
        
        }
    }

    return false;
}

int Sequence::remove(const ItemType& value)
{
    if(m_size==0)//if the list is empty
    {
        return 0;
    }
    
    int itemremoved=0;
    
    node*p =head;
    
    if(m_size==1 && p->value==value)// if the list has only one item and it is the tiem we want to remove
    {
        head=nullptr;
        m_size--;
        itemremoved++;
    }
    if(m_size>1 && p->value==value)//if the list has more than one item and the item is in the first item;
    {
        
        node * kill=head;
        kill->next->prev=nullptr;
        head=kill->next;
        delete kill;
        itemremoved++;
        m_size--;
        
        
    }
    while(p!=nullptr)/// no on the top and the end
    {
        
        if(p->next!=nullptr && p->next->value==value)
        {
            break;
        }
        p=p->next;
    }
    if(p!=nullptr)
    {
        node * killme=p->next;
        p->next=killme->next;
        killme->next->prev=p;
        delete killme;
        itemremoved++;
        m_size--;
    
    }
    
    
    return itemremoved;
}

bool Sequence::get(int pos, ItemType& value) const// store the value at pos into the value ;
{
    if(empty()==true)
        return false;
    if(pos>=0 || pos<m_size)
    {
        node* dummy=head;
        for(int m=0; m<m_size; m++)
        {
           
            if(pos==m)
            {
                value=dummy->value;
                return true;
            }
            dummy=dummy->next;
           
        }
    }
    return false;
}

bool Sequence::set(int pos, const ItemType& value)//replace the item at postion with the value
{
    if(pos>=0 || pos <m_size)
    {
        node *dummy= head;
        for(int i=0; i<m_size; i++)
        {
           
            if(pos==i)
            {
                dummy->value=value;
                return true;
            }
             dummy=dummy->next;
            
        }
        
    }
    return false;
}

int Sequence::find(const ItemType& value) const// when it finds the value, return the index of that value
{
    node *dummy= head;
    for(int i=0; i<m_size; i++)
    {
        
        if(dummy->value==value)
        {
            return i;// return the index when it finds the value
        }
        dummy=dummy->next;
    }
    return -1;
}
void Sequence::swap(Sequence& other)// swap two exsiting sequences
{
    node* tmp=head;// swap the head of each sequence
    head=other.head;
    other.head=tmp;
    
    int temp=m_size;// swap the size of each sequence
    m_size=other.m_size;
    other.m_size=temp;
    
}


int subsequence(const Sequence& seq1, const Sequence& seq2)// return the
{
    
    if(seq2.size()>=seq1.size()|| seq1.size()==0|| seq2.size()==0)// if the seq2 is greater than seq1 or seq1 or seq2 is empty
    {
        return -1;
    }
    
    int k=0;//the starting positon
    ItemType s1, s2;
    bool isSeqeunce=false;
    for(int i=0; i<seq1.size();i++)// loop through the seq1;
    {
        seq1.get(i,s1);//get the value of sequece 1 and then compare with the s2
        seq2.get(0,s2);
        if(s1==s2)// if they are equal, go into the if  otherwise keep finding the value in seq1 that matches with the seq2;
        {
            k=i;// rememebr the index
            for(int j=0,k=i;j<seq2.size();j++,k++)
            {
                
                    seq2.get(j,s2);
                    seq1.get(k,s1);
                    if(s1!=s2)// find inconsecutive sequence break the loop otherwise continue to seek the value
                    {
                    isSeqeunce=false;
                        break;
                    }
                isSeqeunce=true;
            }
            if(isSeqeunce==true)
            {
                return k;
            }
            else
                return -1;
        }
    }
    return -1;
}
void interleave(const Sequence& seq1, const Sequence& seq2, Sequence& result)
{
  
    
    Sequence s;// have another object that creating from the reuslt
    while(!result.empty())
        s.erase(0);// remove all the item in the s. 
    if(seq1.empty())// if sq1 is empty
    {
        s=seq2;// copy sq2 to the result
    } else if(seq2.empty())// if sq2 is empty
    {
        s=seq1;
        
        ItemType s1,s2;
        
        int a=0, b=0, c=0;
        while( a<seq1.size() || b < seq2.size())
        {
            if(a<seq1.size())
            {
            seq1.get(a,s1);
            s.insert(a,s1);
            a++;
            c++;
            
            }
        if(b<seq2.size())
            { //std::cout<<"p"<<std::endl;
            seq2.get(b,s2);
            s.insert(b,s2);
            b++;
            c++;
            }
        }
    }

    result.swap(s);
    
}








        
        
        

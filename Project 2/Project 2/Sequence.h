//
//  Sequence.hpp
//  Project 2
//
//  Created by Qinhao Xu on 1/27/17.
//  Copyright © 2017 Qinhao Xukk. All rights reserved.
//

#ifndef Sequence_h
#define Sequence_h
#include<string>

typedef std::string ItemType;

class Sequence
{
public:
    Sequence();
   ~Sequence();
    Sequence(const Sequence& old);
    Sequence &operator=(const Sequence&old);
    bool empty() const;
    int size() const;
    bool insert(int pos, const ItemType& value);
    int insert(const ItemType& value);
    bool erase(int pos);
    int remove(const ItemType& value);
    bool get(int pos, ItemType& value) const;
    bool set(int pos, const ItemType& value);
    int find(const ItemType& value) const;
    void swap(Sequence& other);
    void dump();
private:
   
    struct node{
        node * next;
        node * prev;
        ItemType value;
    };
    node*head;
    int m_size;
};

int subsequence(const Sequence& seq1, const Sequence& seq2);
void interleave(const Sequence& seq1, const Sequence& seq2, Sequence& result);

#endif /* Sequence_h */

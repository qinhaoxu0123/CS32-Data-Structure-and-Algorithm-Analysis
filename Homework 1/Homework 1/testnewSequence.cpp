//
//  testnewSeqeunce.cpp
//  Homework 1
//
//  Created by Qinhao Xu on 1/22/17.
//  Copyright © 2017 Qinhao Xukk. All rights reserved.
//
#include "newSequence.h"
#include <iostream>
#include <cassert>
using namespace std;

void test()
{
    Sequence s;
    assert(s.insert(0, 10));
    assert(s.insert(0, 20));
    assert(s.size() == 2);
    ItemType x = 999;
    assert(s.get(0, x) && x == 20);
    assert(s.get(1, x) && x == 10);
}


int main()
{
    test();
    cout << "Passed all tests" << endl;
    /*
    Sequence a(1000);
    Sequence b(5);
    Sequence c(5);
    Sequence e(4);
    Sequence f(1001);
    Sequence k;
    

    Sequence g;/////////////////////
    
    ///test for copy constrcutor
    
    f.insert(0);
    f.insert(1);
    f.insert(2);
     Sequence h(f);
    assert(h.size()==3);
    
    
    
    //test for assignment operator
    
    // a>b
    a.insert(0);
    a.insert(1);
    a.insert(2);
    b.insert(0);
    assert(a.size()==3);
    assert(b.size()==1);
    b=a;
    assert(a.size()==3);
    assert(b.size()==3);
    // b<a
    b.insert(0);
    b.insert(1);
    b.insert(2);
    a.insert(0);
    b=a;
    assert(a.size()==1);
    assert(b.size()==1);
    // b=a
    b.insert(0);
    b.insert(1);
    a.insert(2);
    a.insert(0);
    b=a;
    assert(a.size()==2);
    assert(b.size()==2);
    
    // test for copy constructor
    b.insert(0);
    b.insert(1);
    b.insert(2);
    b.insert(0);
    Sequence i(b);
    assert(b.size()==4);
     assert(i.size()==4);*/
    
    Sequence s;
   // unsigned long k;
   
   /* assert(s.empty());
    assert(s.find(42) == -1);
    //test for insert function;
    s.insert(42);
    s.insert(42);
    s.insert(5);
    s.insert(2020);
    s.insert(93);
    s.insert(93);
    assert(s.insert(7,1)==false);
    
    //test for erase fucntion;
    s.erase(0);
    s.erase(1);
    s.erase(4);*/
    //test for remove function
    //assert(s.remove(42)==2);
     //assert(s.remove(93)==2);
    //test for get function;
    /*assert(s.get(0,k)==true);
     assert(s.get(7,k)==false);
     // test for set function.....ask TA for help.
     assert(s.set(0,k)==true);*/
     //test for find function
     /*assert(s.find(5)==0);
     assert(s.find(9)==1);
     assert(s.find(19)==2);
     assert(s.find(42)==3);
     assert(s.find(93)==4);
     assert(s.find(2020)==5);
     assert(s.find(1)==6);*/
    
    
    //test for swap function
    
   /* Sequence tmp2;
    tmp2.insert(0);
    tmp2.insert(1);
    tmp2.insert(2);
  
    //s.swap(tmp2);
    
    
    
     ///test for set function\
    //s.set(0, 88);
     //assert(s.set(2,88)==true);
     assert(s.size()==6);
    assert(tmp2.size()==3);
    assert(s.empty()==false);
    assert(tmp2.empty()==false);
     //assert( s.find(42) == 0);
     //assert(s.find(200) == 1);
     //assert(s.find(50) == 2);
    
    //int tmp1[3]= {0,1,2};
    
     
     cout << "Passed all tests" << endl;

    
    
    
    
    
    
    
    
    
   
    
    ///test for swap function
    */
}
 
    
    
    
  




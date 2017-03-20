//
//  main.cpp
//  Project 2
//
//  Created by Qinhao Xu on 1/27/17.
//  Copyright © 2017 Qinhao Xukk. All rights reserved.
//

#include "Sequence.h"
#include <iostream>
#include <cassert>
using namespace std;

void test()
{
    
    /* Sequence k1;
    assert(k1.insert(0, 1));
    assert(k1.insert(1, 2));
   
    //assert(k1.size()==3);
     //assert(k1.insert(3, 4));
   Sequence k2(k1);
    
    //assert(k2.size()==4);
   // k1.dump();
    k2.dump();
   /* ItemType a=0;
    assert(k1.get(0,a)&&a==4);
    assert(k1.get(1,a)&&a==1);
    assert(k1.get(2,a)&&a==2);
    assert(k1.get(3,a)&&a==3);
    
    assert(k1.size()==4);*/
    
    /*assert(k1.insert(3, 4));
     assert(k1.insert(4, 5));
     assert(k1.insert(5, 6));*/
    //assert(k1.size()==6);
   /* Sequence k2;
        assert(k2.insert(0, 4));
    assert(k2.insert(1, 3));
    assert(k2.insert(2, 2));
     assert(k2.insert(3, 1));

    assert(subsequence(k1,k2)==-1);*/
    
    
    /*Sequence h2(k1);
    ItemType a=0;
    assert(h2.get(0,a)&&a==30);
    assert(h2.get(1,a)&&a==21);
    assert(h2.get(2,a)&&a==63);
    assert(h2.get(3,a)&&a==42);
    assert(h2.get(4,a)&&a==17);
    assert(h2.get(5,a)&&a==63);*/
   /*ItemType a=0;
    assert(k1.get(0,a)&&a==30);
     assert(k1.get(1,a)&&a==21);
    assert(k1.get(2,a)&&a==63);
    assert(k1.get(3,a)&&a==42);
     assert(k1.get(4,a)&&a==17);
     assert(k1.get(5,a)&&a==63);
 
    Sequence k2;
    assert(k2.insert(0, 42));
    assert(k2.insert(1, 63));
    assert(k2.insert(2, 84));
    assert(k2.insert(3, 19));
    ItemType b=0;
    assert(k2.get(0,b)&&b==42);
    assert(k2.get(1,b)&&b==63);
    assert(k2.get(2,b)&&b==84);
    assert(k2.get(3,b)&&b==19);
    

    Sequence r;
    interleave(k1,k2,r);
    ItemType x= 0;
    //assert(r.get(0,x)&& x==30);*/
    
    Sequence k1;
    assert(k1.insert(0, 1));
    assert(k1.insert(1, 2));
    assert(k1.insert(2, 3));
    Sequence k2;
    assert(k1.insert(0, 4));
    assert(k1.insert(1, 5));

    
   
    Sequence r;
    interleave(k1,k2,r);
    /*ItemType b=0;
    assert(r.get(0,b)&&b==1);
     assert(r.get(1,b)&&b==4);
    assert(r.get(2,b)&&b==2);
     assert(r.get(3,b)&&b==5);
    assert(r.get(4,b)&&b==3);*/
    
}

int main()
{
    test();
    cout << "Passed all tests" << endl;
}

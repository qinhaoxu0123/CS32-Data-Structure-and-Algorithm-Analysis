//
//  testScoreList.cpp
//  Homework 1
//
//  Created by Qinhao Xu on 1/21/17.
//  Copyright © 2017 Qinhao Xukk. All rights reserved.
//

#include "ScoreList.h"
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
    ScoreList s;
    //test case for he add function
    assert(s.add(20.55)==true);
    assert(s.add(100)==true);
    assert(s.add(0)==true);
    assert(s.add(0)==true);
    assert(s.add(100)==true);
     assert(s.add(50)==true);
      assert(s.add(101)==false);
    assert(s.add(-1)==false);
    assert(s.add(101)==false);
    //test case for the remove function
    assert(s.remove(20.55)==true);
    assert(s.remove(100)==true);
    assert(s.remove(0)==true);
    assert(s.remove(50)==true);
    
    
    //test case for the size
    assert(s.size()==2);
    
    
    
    
    
    //test case for the minimum
    assert(s.minimum()==0);
    
    //test case for the maximum
    assert(s.maximum()==100);
    
    //

 cout << "Passed all tests" << endl;*/
}
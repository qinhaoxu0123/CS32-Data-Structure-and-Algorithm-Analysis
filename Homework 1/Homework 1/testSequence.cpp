//
//  test.cpp
//  Homework 1
//
//  Created by Qinhao Xu on 1/19/17.
//  Copyright © 2017 Qinhao Xukk. All rights reserved.
//

#include "Sequence.h"
#include <string>
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
    /////test for number///////
    
    Sequence s;
    
    assert(s.empty());
    assert(s.find(42) == -1);
    //test for insert function;
    s.insert(42);
    s.insert(9);
    s.insert(5);
    s.insert(2020);
    s.insert(93);
    s.insert(19);
    assert(s.insert(7,1)==false);
    
    //test for erase fucntion;
    s.erase(0);
    s.erase(1);
    s.erase(4);*/
    //test for remove function
    /*assert(s.remove(42)==3);
    assert(s.remove(99)==2);*/
    //test for get function;
    /*assert(s.get(0,k)==true);
    assert(s.get(7,k)==false);
    // test for set function.....ask TA for help.
    assert(s.set(0,k)==true);
    //test for find function
    assert(s.find(5)==0);
    assert(s.find(9)==1);
    assert(s.find(19)==2);
    assert(s.find(42)==3);
    assert(s.find(93)==4);
    assert(s.find(2020)==5);
    assert(s.find(1)==6);*/
    //// test for swap function
    /*Sequence tmp2;
    tmp2.insert(0);
    tmp2.insert(1);
    tmp2.insert(2);
    s.swap(tmp2);
    assert(s.size()==3);
     assert(tmp2.size()==6);
    assert(s.empty()==false);
    //assert( s.find(42) == 0);
    //assert(s.find(200) == 1);
    //assert(s.find(50) == 2);
   
    cout << "Passed all tests" << endl;
    
    //////////test char like a-z//////
    Sequence s;
    string x;
   
    assert(s.empty());
    assert(s.find("a") == -1);
    //test for insert function;
    s.insert("a");
    s.insert("a");
    s.insert("a");
    s.insert("g");
    s.insert("g");
    s.insert("d");
    s.insert(6,"a");
    
    //test for erase fucntion;
    s.erase(0);
    s.erase(1);
    s.erase(4);
    //test for remove function
     assert(s.remove("a")==4);
    assert(s.remove("g")==2);
    //test for get function;
     assert(s.get(0,x)==true);
     assert(s.get(7,x)==false);
     assert(s.get(0, x)  &&  x == "a");
     assert(s.get(1, x)  &&  x == "a");
     assert(s.get(2, x)  &&  x == "a");
     // test for set function.....ask TA for help.
     assert(s.set(0,x)==true);
     //test for find function
     assert(s.find("a")==0);
     assert(s.find("b")==1);
     assert(s.find("c")==2);
     assert(s.find("d")==3);
     assert(s.find("f")==4);
     assert(s.find("g")==5);
     assert(s.find("a")==0 );// ask TA what if you we two same are we returning the index of the first item?
     
     
     assert(s.size()==1);
     assert(s.empty()==false);
     //assert( s.find(42) == 0);
     //assert(s.find(200) == 1);
     //assert(s.find(50) == 2);
     
     cout << "Passed all tests" << endl;*/
    
    
///test for string////
   
   /* Sequence s;
    s.insert(0, "dosa");
    s.insert(1, "pita");
    s.insert(2, "");
    s.insert(3, "matzo");
    assert(s.find("") == 2);
    s.remove("dosa");
    assert(s.size() == 3  &&  s.find("pita") == 0  &&  s.find("") == 1  &&
           s.find("matzo") == 2);
    assert(s.empty()==false);
    cout << "Passed all tests" << endl;*/
   
   
}

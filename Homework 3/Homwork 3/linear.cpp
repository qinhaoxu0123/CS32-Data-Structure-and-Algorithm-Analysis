//
//  linear.cpp
//  Homwork 3
//
//  Created by Qinhao Xu on 2/12/17.
//  Copyright © 2017 Qinhao Xukk. All rights reserved.
//

#include <iostream>
#include <assert.h>

using namespace std;

bool somePredicate(double n)
{
    return n<0;
}

// Return false if the somePredicate function returns false for at
// least one of the array elements; return true otherwise.
bool allTrue(const double a[], int n)
{
    
    //back to front ignore the first element using the magic function
    if(n<=0)// base case
        return true;
    if(somePredicate(a[0])==false)// if the somePredicate function returns false for at
    // least one of the array elements;
        return false;
    
   
    
    return allTrue(a+1,n-1);

    
}


// Return the number of elements in the array for which the
// somePredicate function returns false.
int countFalse(const double a[], int n)
{
    
    if(n<=0)
        return false;
    // front to back, the magic function ignore the first element in the array.
    if(somePredicate(a[0])==0)
    return 1+countFalse(a+1,n-1);
    else
        return countFalse(a+1,n-1);// recurssive until we find the match
    
    // This is incorrect.
}


// Return the subscript of the first element in the array for which
// the somePredicate function returns false.  If there is no such
// element, return -1.
int firstFalse(const double a[], int n)
{
    if(n<=0)
        return -1;
    
    
    if(somePredicate(a[0])==false)
        return 0;
    else
        if(firstFalse(a+1,n-1)==-1)
            return -1;
    return 1+firstFalse(a+1,n-1);
    
    return -1; // This is incorrect.
}


// Return the subscript of the smallest double in the array (i.e.,
// the one whose value is <= the value of all elements).  If more
// than one element has the same smallest value, return the smallest
// subscript of such an element.  If the array has no elements to
// examine, return -1.
int indexOfMin(const double a[], int n)
{
    if(n==1)/// if we have one item in the array
        return 0;
    if(n<=0)//If the array has no elements to
        // examine, return -1.
        return -1;
    if(a[n-1]<a[indexOfMin(a,n-1)])
    {
        /*
        int i =n-1;
        int j= indexOfMin(a,n-1);
        if(i==j)
        { return i;}*/
        return n-1;
    }
    

    return indexOfMin(a,n-1);
    // This is incorrect.
}


// If all n2 elements of a2 appear in the n1 element array a1, in
// the same order (though not necessarily consecutively), then
// return true; otherwise (i.e., if the array a1 does not include
// a2 as a not-necessarily-contiguous subsequence), return false.
// (Of course, if a2 is empty (i.e., n2 is 0), return true.)
// For example, if a1 is the 7 element array
//    10 50 40 20 50 40 30
// then the function should return true if a2 is
//    50 20 30
// or
//    50 40 40
// and it should return false if a2 is
//    50 30 20
// or
//    10 20 20

bool includes(const double a1[], int n1, const double a2[], int n2)
{
    if(n2<=0)
        return true;
    if(n1<=0)
        return false;
   
    if(a1[0]==a2[0])
        return includes(a1+1, n1-1, a2+1, n2-1);
    else
        return includes(a1+1, n1-1, a2, n2);
    
}


int main()
{
 
    double a1[7]={10,50,40, 20, 50, 40, 30};
    double a2[3]={50,40,20};
    double a3[3]={50,40,40};
    double a4[3]={50,30,20};
    double a5[3]={10,20,20};
    assert(includes(a1,7,a2,3)==true);
    assert(includes(a1,7,a3,3)==true);
       assert(includes(a1,7,a4,3)==false);
       assert(includes(a1,7,a5,3)==false);
    cout<<"passed"<<endl;
    
    
    double a6[7]={10,50,40, 20, 50, 40, 30};
    double a7[4]={1,0,-1,1};
    double a8[0];
     double a9[4]={1,0,-1,-2};
    double a10[4]={1,0,-1,-1};// duplicated test
    double a11[4]={-1,-1,-1,-1};
    assert(indexOfMin(a6,7)==0);
    assert(indexOfMin(a7,4)==2);
       assert(indexOfMin(a8,0)==-1);
      assert(indexOfMin(a9,4)==3);
     assert(indexOfMin(a10,4)==2);
     assert(indexOfMin(a11,4)==0);
      cout<<"passed indexOfMin"<<endl;
    
    double a12[3]={1,1,-1};
    double a13[3]={-1,-1,-1};
    double a14[3]={-1,-1,1};
    double a15[3]={-1,1,1};
    double a16[3]={1,1,1};
    double a17[0]={};
    double a18[3]={0,0,0};
    cout<< "passed alltrue"<<endl;
    // test for countFalse function
    assert(allTrue(a12,3)==false);
    assert(countFalse(a13,3)==0);
    assert(countFalse(a14,3)==1);
    assert(countFalse(a15,3)==2);
    assert(countFalse(a16,3)==3);
    assert(countFalse(a17,0)==0);
    assert(countFalse(a18,3)==3);
    cout<< "passed countFalse"<<endl;
    // test for the firstFalse function
    assert(firstFalse(a13,3)==-1);
    assert(firstFalse(a14,3)==2);
    assert(firstFalse(a15,3)== 1);
    assert(firstFalse(a16,3)== 0);
    assert(firstFalse(a17,0)== -1);
    assert(firstFalse(a18,3)== 0);
    cout<< "passed firstFalse"<<endl;
}
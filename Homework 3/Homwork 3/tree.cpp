//
//  tree.cpp
//  Homwork 3
//
//  Created by Qinhao Xu on 2/13/17.
//  Copyright © 2017 Qinhao Xukk. All rights reserved.
//

#include <iostream>
#include <string>
#include <assert.h>

using namespace std;

// Return the number of ways that all n2 elements of a2 appear
// in the n1 element array a1 in the same order (though not
// necessarily consecutively).  The empty sequence appears in a
// sequence of length n1 in 1 way, even if n1 is 0.
// For example, if a1 is the 7 element array
//	10 50 40 20 50 40 30
// then for this value of a2     the function must return
//	10 20 40			1
//	10 40 30			2
//	20 10 40			0
//	50 40 30			3
int countIncludes(const double a1[], int n1, const double a2[], int n2)
{
    if(n2<=0)//base case if the n2  has less than 0, that means that means we found the subsequence in the a1;
        return 1;
    if(n1<=0)// base case if the recurrsively go through and a1 size less than 0 that means we did not find the subseuqence in the array/
    {
        return 0;
    }
    
    if(a1[0]==a2[0])//if it is equal then we go into the recurrsive calls
    {
     int count= countIncludes(a1+1,n1-1,a2,n2) + countIncludes(a1+1,n1-1,a2+1,n2-1);
       return count;
    }
    else
    {
        return countIncludes(a1+1,n1-1,a2,n2);//otherwise we recurrsively go through a1 array until we find value that matches with the value in a2
    }
}


// Exchange two doubles
void exchange(double& x, double& y)
{
    double t = x;
    x = y;
    y = t;
}

// Rearrange the elements of the array so that all the elements
// whose value is > separator come before all the other elements,
// and all the elements whose value is < separator come after all
// the other elements.  Upon return, firstNotGreater is set to the
// index of the first element in the rearranged array that is
// <= separator, or n if there is no such element, and firstLess is
// set to the index of the first element that is < separator, or n
// if there is no such element.
// In other words, upon return from the function, the array is a
// permutation of its original value such that
//   * for 0 <= i < firstNotGreater, a[i] > separator
//   * for firstNotGreater <= i < firstLess, a[i] == separator
//   * for firstLess <= i < n, a[i] < separator
// All the elements > separator end up in no particular order.
// All the elements < separator end up in no particular order.
void separate(double a[], int n, double separator,
              int& firstNotGreater, int& firstLess)
{
    if (n < 0)
        n = 0;
    
    // It will always be the case that just before evaluating the loop
    // condition:
    //  firstNotGreater <= firstUnknown and firstUnknown <= firstLess
    //  Every element earlier than position firstNotGreater is > separator
    //  Every element from position firstNotGreater to firstUnknown-1 is
    //    == separator
    //  Every element from firstUnknown to firstLess-1 is not known yet
    //  Every element at position firstLess or later is < separator
    
    firstNotGreater = 0;
    firstLess = n;
    int firstUnknown = 0;
    while (firstUnknown < firstLess)
    {
        if (a[firstUnknown] < separator)
        {
            firstLess--;
            exchange(a[firstUnknown], a[firstLess]);
        }
        else
        {
            if (a[firstUnknown] > separator)
            {
                exchange(a[firstNotGreater], a[firstUnknown]);
                firstNotGreater++;
            }
            firstUnknown++;
        }
    }
}

// Rearrange the elements of the array so that
// a[0] >= a[1] >= a[2] >= ... >= a[n-2] >= a[n-1]
// If n <= 1, do nothing.
void order(double a[], int n)
{
 if(n<=1)
 return;
    int firsthalf, secondhalf;
    separate(a,n ,a[n/2], firsthalf,secondhalf );
    
    order(a,firsthalf);
    order(a+secondhalf,n-secondhalf);
    
    return;  // This is not always correct.
}



int main()
{
    double a6[7]={10, 50, 40, 20, 50, 40, 30};
    double a7[3]={10, 20, 40};
    double a8[3]={10, 40, 30};
    double a9[3]={20, 10, 40};
    double a10[3]={50, 40, 30};
    assert(countIncludes(a6,7,a7,3)==1);
    assert(countIncludes(a6,7,a8,3)==2);
    assert(countIncludes(a6,7,a9,3)==0);
    assert(countIncludes(a6,7,a10,3)==3);
    
    cout << "//test for countInclude function"<< endl;
    
    cout<<"//.......regular unsorted array........//"<<endl;
    double a1[7] ={9,88,55,8,100,4,3};
    order(a1,7);
    for(int i=0; i<7;i++)
        cout << a1[i]<<endl;
    

    cout<<"//.......odd size of array with duplicated values........//"<<endl;
    double a2[7] ={10, 50, 40, 20, 50, 40, 30};
    order(a2,7);
    for(int i=0; i<7;i++)
        cout << a2[i]<<endl;
     cout<<"//.....one item..........//"<<endl;
    double a3[1] ={10};
    order(a3,1);
    for(int i=0; i<1;i++)
        cout << a3[i]<<endl;
    
      cout<<"//......empty array.........//"<<endl;
    double a4[0];
    order(a4,0);
    for(int i=0; i<0;i++)
        cout << a3[i]<<endl;
    
    cout<<"//.......even size of array with duplicated values........//"<<endl;
    
    double a5[8] ={10, 50, 40, 20, 50, 40, 30,50};
    order(a5,8);
    for(int i=0; i<8;i++)
        cout << a5[i]<<endl;
    
}


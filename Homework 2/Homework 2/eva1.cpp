//
//  eva1.cpp
//  Homework 2
//
//  Created by Qinhao Xu on 2/4/17.
//  Copyright © 2017 Qinhao Xukk. All rights reserved.
//


#include <iostream>
#include <stack>
#include <cassert>
#include <string>
#include <cctype>
using namespace std;


string deletespace(string infix);/// delete all the spaces
bool isInfix(string infix);// check valid string
int precedence(char temp);// check  precedence
string toPostfix(string infix);// infix to postfix conversion
bool eva_posfix(string postfix);// eva the postfix


string deletespace(string infix)/// delete all the spaces
{
    string nospace_infix= "";// initialize the empty string
    for(int i =0 ;i < infix.size(); i++)// loop throught the infix
    {
        if(infix[i] != ' ')// if it is not equal to empty
        {
            nospace_infix +=infix[i];// add the char to the postfix
        }
    }
    return nospace_infix;
}
bool isInfix(string infix)// check valid string
{
    string tmp=deletespace(infix);// get the infix with no spaces
    //cout<<tmp;
    for(int i=0; i<tmp.size(); i++)// loop throught the string to check each char
    {
        switch(tmp[i])// check if the infix contains valid chars if none return false;
        {
            case '(':case ')':
            case '0':case '1':case '2':case '3':
            case '4':case '5':case '6':case '7':case '8':case '9':
            case '&':case '!':case '|':
            break;
            default:
            return false;
        }
        if(tmp.size()==1)// check if the string only have one char
        {
            if(tmp[i]=='&' ||tmp[i]=='!'|| tmp[i]=='|')/// run into only one operator return false;
                return false;
            else
            {
                return true;// run into a digit return true; and continue 
            }
            
        }
        
        
        if(tmp[tmp.size()-1]=='&' ||tmp[tmp.size()-1]=='!'|| tmp[tmp.size()-1]=='|')// check the last post in the string
            return false;
        
    
        if(tmp[i]=='&' || tmp[i]=='|')// run into operator & and |
        {
            if(i!=tmp.size()-1)// if it is not the last pos in the array.
            {
                if(i!=0){// if i is not equal to 0;
                    if(!isdigit(tmp[i-1]) && (!isdigit(tmp[i+1])||tmp[i+1]!='!'))
                        return false;
                }
                else// i 0
                {
                    if (!isdigit(tmp[i+1])||tmp[i+1]!='!')
                        {
                        return false;
                        }
                }
           
            }
           
        }
        if(tmp[i]=='!')// run into !
        {
            if(i!=tmp.size()-1)
            {
            if(!isdigit(tmp[i+1]))
                return false;
                
            }
           
        }
        if(tmp[i]=='('||tmp[i]==')') // run into paranthesis
        {
            if(tmp[i]=='(')
            {
                if(i!=tmp.size()-1)
                {
                if(tmp[i+1]==')')
                    return false;
                }
            }
            else
            {
                if(i!=0)
                {
               if(tmp[i-1]=='(')
                   return false;
                }
            }
        }
        if(isdigit(tmp[i]))// run into number
           {
               
               if(i!=tmp.size()-1)
               {
                   if(i==0)//if it is first pos
                   {
                       if(isdigit(tmp[i+1]) ||  tmp[i+1]=='(')
                          return false;
                   }
                   if(i!=0)
                   {
               if(isdigit(tmp[i-1])|| isdigit(tmp[i+1]) ||  tmp[i+1]=='(')//|| tmp[i+1]=='!'||tmp[i+1]=='&' || tmp[i+1]=='|' )
                  return false;
                   }
                
                   
               }
           }
    }
  
    return true;
}


int precedence(char temp)// check for the precedence
{
    switch(temp)
    {
      case '!':
            return 3;
      case '&':
            return 2;
      case '|':
            return 1;
        default:
            return 0;
    }
        
    return 0;
}
string toPostfix(string infix, string&postfix)// infix to postfix
{
    
        postfix= "";//Initialize postfix to empty
        stack <char> operand;//Initialize the operator stack to empty
        
        
        for(int n=0; n<infix.size();n++)//For each character ch in the infix string
        {
            switch(infix[n])//Switch (ch)
            {
                case '0':case '1':case '2':case '3':case '4':case '5':case '6':case '7':case '8':case '9'://case operand:
                    postfix +=infix[n];//append ch to end of postfix
                    break;//break
                case '('://case '(':
                    operand.push(infix[n]);//push ch onto the operator stack
                    break;
                case ')':
                   //// pop stack until matching '('
                
                    while(!operand.empty()&&operand.top()!='(')
                    {
                        postfix+=operand.top();//append the stack top to postfix
                        operand.pop();//pop the stack remove the '(
                    }
                    operand.pop();
                    break;
                case '!':case '&':case '|'://case operator:
                
                    while(!operand.empty()&& operand.top()!='(' && precedence(infix[n])<=precedence(operand.top()))//While the stack is not empty and the stack top is not '(' and precedence of ch <= precedence of stack top
                    {
                        postfix+=operand.top();//append the stack top to postfix
                        operand.pop();//pop the stack
                    }
                    operand.push(infix[n]);//push ch onto the stack
                    break;

                default:
                    break;
            }
        }
    while(!operand.empty())//while the stack is not empty
    {
        postfix+=operand.top();//append the stack top to postfix
        operand.pop();//pop the stack
    }
    return postfix;
}


bool evaluate(string infix, const bool value[], string& postfix, bool &result)// evaltuon postfix
{
    if(infix=="")// return 1 if the infix is empty
        return 1;
    if(isInfix(infix))// valid infix then go into the if to eva the infix
    {
        postfix= toPostfix(infix,postfix);// call the topostfix function and convert the infix to postfix
        stack <bool> isPost;// initialize the empty stack
    for(int n=0; n<postfix.size();n++)
    {
        if(isdigit(postfix[n]))// encounters the digits
        {
            char c = postfix[n];
            int i = c - '0';
            bool k= value[i];
            isPost.push(k);// push true or false into the stack
        }
        else if(postfix[n]=='!')
        {
            bool k= isPost.top();// see the top
                isPost.pop();// pop the top in the stack
                isPost.push(!k);// push the true or false into the stack
        }
        else
        {
            //apply the operation that ch represents to operand1 and operand2, and push the result onto the stack
            char operand2 = isPost.top();
            isPost.pop();
            if(isPost.empty())
                return 1;
            char operand1 = isPost.top();
            isPost.pop();
            if(postfix[n]=='&')
                isPost.push(operand1&&operand2);
            if(postfix[n]=='|')
                isPost.push(operand1||operand2);
            /*
           
            if(postfix[n]=='!')
            {
                char operand1 = isPost.top();
                 isPost.pop();
                isPost.push(operand1);
            }*/
                
        }
    }
        result=isPost.top();
        return 0;
    }
     return 1;
}


int main()
{
    bool ba[10] = {
        //  0      1      2      3      4      5      6      7      8      9
        true,  true,  true,  false, false, false, true,  false, true,  false
    };
    string pf;
    bool answer;
      assert(evaluate("0", ba, pf, answer) == 0  &&  pf =="22&" &&  answer);
      assert(evaluate("2&2", ba, pf, answer) == 0  &&  pf =="22&" &&  answer);
    /*
    assert(evaluate("dkkdkd", ba ,pf , answer)== 1);
    assert(evaluate("1&!(9|1&1|9) | !!!(9&1&9)", ba ,pf , answer)== 1 );

     assert(evaluate("09!&", ba ,pf , answer)== 1 );
    assert(evaluate("0&!9", ba ,pf , answer)== 0 && pf == "09!&" && answer);
    assert(evaluate("2| 3", ba, pf, answer) == 0  &&  pf =="23|" &&  answer);
    assert(evaluate("8|", ba, pf, answer) == 1);
    assert(evaluate("4 5", ba, pf, answer) == 1);
    assert(evaluate("01", ba, pf, answer) == 1);
    assert(evaluate("()", ba, pf, answer) == 1);
    assert(evaluate("2(9|8)", ba, pf, answer) == 1);
    assert(evaluate("2(&8)", ba, pf, answer) == 1);
    assert(evaluate("(6&(7|7)", ba, pf, answer) == 1);
    assert(evaluate("", ba, pf, answer) == 1);
    assert(isInfix("4  |  !3 & (0&3) ")==true);
     assert(evaluate("4  |  !3 & (0&3) ", ba, pf, answer) == 0
     &&  pf == "43!03&&|"  &&  !answer);
    
   assert(evaluate(" 9  ", ba, pf, answer) == 0  &&  pf == "9"  &&  !answer);
    ba[2] = false;
    ba[9] = true;
    
    
    assert(evaluate("((9))", ba, pf, answer) == 0  &&  pf == "9"  &&  answer);
    assert(evaluate("2| 3", ba, pf, answer) == 0  &&  pf == "23|" &&  !answer);
    
    */
    
    cout << "Passed all tests" << endl;
}


/*
And here is his pseudocode for the evaluation of the postfix expression:

Initialize the operand stack to empty
For each character ch in the postfix string
if ch is an operand
push the value that ch represents onto the operand stack
else // ch is a binary operator
set operand2 to the top of the operand stack
pop the stack
set operand1 to the top of the operand stack
pop the stack
apply the operation that ch represents to operand1 and
operand2, and push the result onto the stack
When the loop is finished, the operand stack will contain one item,
the result of evaluating the expression*/
























// MyMap.h
//
// Skeleton for the MyMap class template.  You must implement the first six
// member functions.

//template<typename KeyType, typename ValueType>
//struct Node
//{
//    Node(const KeyType &myType, const ValueType &myVal)
//    {
//        key=myType;
//        value=myVal;
//        left=right=nullptr;
//    }
//    ValueType value;
//    KeyType key;
//    Node *left, *right;
//};
#include <iostream>
#include "support.h"
template<typename KeyType, typename ValueType>
class MyMap
{
public:
    MyMap();
    ~MyMap();
    void clear();
    int size() const;
    void associate(const KeyType& key, const ValueType& value);
    

	  // for a map that can't be modified, return a pointer to const ValueType
    const ValueType* find(const KeyType& key) const;
    
    

	  // for a modifiable map, return a pointer to modifiable ValueType
	ValueType* find(const KeyType& key)
	{
		return const_cast<ValueType*>(const_cast<const MyMap*>(this)->find(key));
	}

	  // C++11 syntax for preventing copying and assignment
	MyMap(const MyMap&) = delete;
	MyMap& operator=(const MyMap&) = delete;

private:
    struct Node
    {
        Node(const KeyType &myType, const ValueType &myVal)
        {
            key=myType;
            value=myVal;
            left=right=nullptr;
        }
        ValueType value;
        KeyType key;
        Node *left, *right;
    };
    Node* rootPtr;
    int m_size =0;
    void deletePtr(Node *p);

};

template<typename KeyType, typename ValueType>
void MyMap<KeyType,ValueType>::deletePtr(Node *p)
{
    if(p==nullptr)
        return;
    deletePtr(p->left);
    deletePtr(p->right);
    
    delete p;
}


/// public function//////////////////////
template<typename KeyType, typename ValueType>
MyMap<KeyType,ValueType>::MyMap()
{
        rootPtr=nullptr;
}

template<typename KeyType, typename ValueType>
MyMap<KeyType,ValueType>::~MyMap()
{
     clear();
}
template<typename KeyType, typename ValueType>
void MyMap<KeyType,ValueType>::clear()
{
//    Node * curr=rootPtr;
//    if(curr==nullptr)
//        return;
//    while(curr!= nullptr)
//    {
//        if(curr->left!=nullptr)
//            curr=curr->left;
//        else if( curr->right!=nullptr)
//            curr=curr->right;
//        else
//            break;
//    }
//    delete curr;
    deletePtr(rootPtr);
    
}

template<typename KeyType, typename ValueType>
int  MyMap<KeyType,ValueType>::size() const
{
    return m_size;
}

template<typename KeyType, typename ValueType>
void MyMap<KeyType,ValueType>::associate(const KeyType& key, const ValueType& value)
{
    
    if(rootPtr==nullptr)// if root is nullptr
    {
        rootPtr= new Node(key,value);
        m_size++;
        return;
    }
    
    
    Node* cur=rootPtr;
    
    for(;;)
    {
//        std::cout<<&key<<std::endl;
//        std::cout<<&(cur->key)<<std::endl;
        if(key == (cur->key))
        {
            cur->value=value;
            return;
        }//if key is equal then we just change the value inside the node and then return;
        if(key < cur->key)// if the key li less than then we go to the left
        {
            if(cur->left!=nullptr)// if left has the child then we go to the left
                cur=cur->left;
            else
            {
                cur->left = new Node(key,value);// add the child to the left
                m_size++;
                return;
            }
        }
        else if(key>cur->key)// similar to the previosu left node
        {
            if(cur->right !=nullptr)
            { cur= cur->right;}
            else
            {
                cur->right=new Node(key,value);
                m_size++;
                return;
            }
        }
    }
}

template<typename KeyType, typename ValueType>
const ValueType* MyMap<KeyType,ValueType>::find(const KeyType& key) const
{
    Node* cur = rootPtr;
    while(cur!=nullptr)
    {
        if((key==cur->key))
            return(&cur->value);
        else if(key < cur->key)
            cur = cur->left;
        else
            cur = cur->right;
    }
    return nullptr;
}





















//#ifndef MYMAP_INCLUDED
//#define MYMAP_INCLUDED
//
//#include <map>  // YOU MUST NOT USE THIS HEADER IN CODE YOU TURN IN
//
//// In accordance with the spec, YOU MUST NOT TURN IN THIS CLASS TEMPLATE,
//// since you are not allowed to use any STL associative containers, and
//// this implementation uses std::map.
//
//// This code is deliberately obfuscated.
//
//// If you can not get your own MyMap class template working, you may use
//// this one during development in order to let you proceed with implementing
//// the other classes for this project; you can then go back to working on
//// fixing your own MyMap class template.
//
//template <typename KeyType, typename ValueType>
//class MyMap
//{
//public:
//    MyMap(const MyMap &other) = delete;
//    MyMap &operator=(const MyMap &other) = delete;
//    typedef KeyType O;using O1=int;void clear(){l01.clear();}
//    using l0=ValueType;MyMap(){}using l10=O const;O1 size()
//    const{return l01.size();}using ll0=l0 const;using Const=
//    MyMap<O,l0>;void associate(l10&Using,ll0&first){l01[
//                                                        Using]=first;}using l1=std::map<O,l0>;using l00=Const
//    const;ll0*find(l10&l11)const{auto first=l01.find(l11);
//        return(first!=l01.end()?&first->second:0);}l0*find(l10&
//                                                           l01){return(l0*)(*(l00*)(this)).find(l01);}private:l1
//    l01;
//};
//
//#endif // MYMAP_INCLUDED

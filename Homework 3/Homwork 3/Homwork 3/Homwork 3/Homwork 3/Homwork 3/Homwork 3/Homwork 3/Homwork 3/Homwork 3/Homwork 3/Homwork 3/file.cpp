//
//  main.cpp
//  Homwork 3
//
//  Created by Qinhao Xu on 2/11/17.
//  Copyright © 2017 Qinhao Xukk. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;

class File {
public:
    File(string f){m_string=f;}//constructor for base class
    virtual string name () const { return m_string;} //every file has their name
    virtual void open() const =0;
    virtual void redisplay() const { cout<< "refresh the screen";} // all the files have the their own redisplay
    virtual ~File(){}
    
private:
    string m_string;

    
};

class TextMsg: public File
{
public:
    TextMsg(string k):File(k)
    {}
    
    virtual void open () const {
        cout << "open text message";
    }
  
    virtual ~TextMsg(){
        cout << "Destroying " <<File::name()<< ", a text message"<<endl;
    }


};

class Video: public File
{
public:
    Video(string k, int n):File(k)
    {
        m_n=n;
    }
    virtual void redisplay ()const {
        cout<< "replay video";
    }
   
    virtual void open()const{
        cout << "play " << m_n << " second video";
    }
    virtual ~Video(){
        cout << "Destroying " <<File::name()<< ", a video"<<endl;
    }
    
private:
    int m_n;
    
};

class Picture: public File
{
public:
    Picture(string k):File(k)
    {}
    
    virtual void open()const{
        cout<< "show picture";
    }
    virtual ~Picture(){
        cout << "Destroying " << "the picture " << File::name() <<endl;
    }
    
};



void openAndRedisplay(const File* f)
{
    cout << f->name() << ": ";
    f->open();
    cout << endl << "Redisplay: ";
    f->redisplay();
    cout << endl;
}

int main()
{
    File* files[4];
    files[0] = new TextMsg("fromFred.txt");
    // Videos have a name and running time
    files[1] = new Video("goblin.mpg", 3780);
    files[2] = new Picture("kitten.jpg");
    files[3] = new Picture("baby.jpg");
    
    for (int k = 0; k < 4; k++)
        openAndRedisplay(files[k]);
    
    // Clean up the files before exiting
    cout << "Cleaning up." << endl;
    for (int k = 0; k < 4; k++)
       delete files[k];
}
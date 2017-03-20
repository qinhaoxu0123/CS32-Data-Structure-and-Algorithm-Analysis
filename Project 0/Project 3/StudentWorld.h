//
//  StudentWorld.hpp
//  Project 3
//
//  Created by Qinhao Xu on 2/18/17.
//  Copyright © 2017 Qinhao Xu. All rights reserved.
//

#ifndef StudentWorld_h
#define StudentWorld_h

#include"Actor.h"

class StudentWorld : public:GameWorld
{
    StudentWorld();
    ~StudentWorld();
    
    virtual int init();
    virtual int move();
    virtual void cleanUp();
    
private:
    Pebble* m_rock;
    babyGrasshoper* m_insect;
};

#endif /* StudentWorld_h */

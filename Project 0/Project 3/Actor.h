//
//  Actor.h
//  Project 3
//
//  Created by Qinhao Xu on 2/18/17.
//  Copyright © 2017 Qinhao Xu. All rights reserved.
//

#ifndef Actor_h
#define Actor_h

class GraphObject
{
public:
    GraphObject(int imageID, int startX, int startY, Direction startDirection=none);
    void setVisible(bool shouldDisplay);
    void getX() const;
    void getY() const;
    void moveTo(int x, int y);
    Direction getDirection() const;
    void setDirection(Direction d);
private:
    int m_id;
    int m_x;
    int m_y;
    Direction m_d;
    
};

class Actor: public GraphObject
{
public:
    Actor(int imageID, int startX, int startY, Direction startDirection=none);
    virtual void doSomething()=0;
};

class Pebble: public Actor
{
public:
    Pebble(int imageID, int startX, int startY, Direction startDirection=none);
};

class babyGrasshoper: public Actor
{
public:
    babyGrasshoper(int imageID, int startX, int startY, Direction startDirection=none);
    virtual void doSomething();
};
#endif /* Actor_h */

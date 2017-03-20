//
//  Player.hpp
//  Project 1
//
//  Created by Qinhao Xu on 1/10/17.
//  Copyright © 2017 Qinhao Xukk. All rights reserved.
//

#ifndef Player_hpp
#define Player_hpp

#include <string>

using namespace std;

class Arena;

class Player
{
public:
    // Constructor
    Player(Arena* ap, int r, int c);
    
    // Accessors
    int  row() const;
    int  col() const;
    bool isDead() const;
    
    // Mutators
    string dropPoisonPellet();
    string move(int dir);
    void   setDead();
    
private:
    Arena* m_arena;
    int    m_row;
    int    m_col;
    bool   m_dead;
};

#endif /* Player_hpp */

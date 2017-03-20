//
//  main.cpp
//  Project 1
//
//  Created by Qinhao Xu on 1/10/17.
//  Copyright © 2017 Qinhao Xukk. All rights reserved.
//

#include "Game.h"
//#include "History.h"
//#include "Rat.h"
//#include "Player.h"
//#include "Arena.h"
//#include "Player.h"
//#include "Arena.h"
//#include "History.h"
//#include "globals.h"
#include <iostream>

using namespace std;


int main()
{
    // Create a game
    //Use this instead to create a mini-game:
    //Game g(3, 5, 2);
    
    //History h(2, 2);
    //h.record(1, 1);
    //h.display();
      //Rat r(nullptr, 1, 1);
    //Player p(nullptr, 1, 1);
    
    //Arena a(10, 18);
    //a.addPlayer(2, 2);
    
    Game g(10, 12, 40);
    
    // Play the game
    g.play();
    //Arena a(10, 20);
    //Player p(&a, 2, 3);
    /*Arena a(1, 4);
    a.addPlayer(1, 4);
    for (int t = 1; t <= 2; t++)
    {
        a.addRat(1, 1);
        a.setCellStatus(1, 2, HAS_POISON);
        a.setCellStatus(1, 3, HAS_POISON);
        while (a.ratCount() > 0)
            a.moveRats();
    }
    a.history().display();*/
    /*Arena a(10, 20);
    Player p(&a, 2, 3);
    Rat r(&a, 1, 1);*/
    //History a;
}

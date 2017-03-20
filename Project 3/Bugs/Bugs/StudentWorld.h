#ifndef STUDENTWORLD_H_
#define STUDENTWORLD_H_

#include "GameWorld.h"
#include "GameConstants.h"
#include <string>
#include <list>

class Actor;
class Compiler;

class StudentWorld : public GameWorld
{
public:
    void AntHillStatus();
    
    int getTick()
    {
        return m_tick;
    }
    bool isDangerAt(int x, int y);
    bool checkAnt_hill(int x, int y);
    void createFood(int x, int y, int food);
    void deduction_food (int x, int y, int food);
    bool biteable_insect (int x, int y);
    bool checkTypeOfObject(int x,int y, int ID);
    void CreateP(int x, int y , int z);
    
    
    StudentWorld(std::string assetDir)
    : GameWorld(assetDir), m_tick(0)
    {
    }
    void removeandaddfood(int x, int y );
    virtual ~StudentWorld();
    
    virtual int init();
    virtual int move();
    virtual void cleanUp();
    
    void upLocation(Actor * p, int newX, int newY, int oldX, int old);
    
    Actor* getAnActorAtTheProposedLocation(int x, int y);
    
    
    void Ant_Dropfood(int x , int y, int food);
    
    bool MorethanOneObj(int x, int y);
    
     //Can an insect move to x,y?
    bool canMoveTo(int x, int y);
    
    bool checkPebble(int x, int y);
    
    ////////
    void addAdult(int x,int y);
    
    /////////
    bool foodObj(int x, int y);
    
    void removeDeadObj(int x, int y);
//
//    // Add an actor to the world
    void addActor(Actor* a);
//
    // If an item that can be picked up to be eaten is at x,y, return a
    // pointer to it; otherwise, return a null pointer.  (Edible items are
    // only ever going be food.)
     bool getEdibleAt1(int x, int y) ;
     Actor* getEdibleAt(int x, int y);
    //bool eatable(Actor *p, int x , int y);
//
//    // If a pheromone of the indicated colony is at x,y, return a pointer
//    // to it; otherwise, return a null pointer.
//    Actor* getPheromoneAt(int x, int y, int colony) const;
//    
//    // Is an enemy of an ant of the indicated colony at x,y?
//    bool isEnemyAt(int x, int y, int colony) const;
//    
//    // Is something dangerous to an ant of the indicated colony at x,y?
//    bool isDangerAt(int x, int y, int colony) const;
//
//    // Is the anthill of the indicated colony at x,y?
//    bool isAntHillAt(int x, int y, int colony) const;
//    
    // Bite an enemy of an ant of the indicated colony at me's location
    // (other than me; insects don't bite themselves).  Return true if an
    // enemy was bitten.
//    bool biteEnemyAt(Actor* me, int colony, int biteDamage);
     
//
    void addAnt(Actor* ant, int x, int y);
    // Poison all poisonable actors at x,y.
    bool poisonAllPoisonableAt(int x, int y);
//
    // Stun all stunnable actors at x,y.
    bool stunAllStunnableAt(int x, int y);
//
//    // Record another ant birth for the indicated colony.
//    void increaseScore(int colony);
//    
private:
    std::list<Actor*> arr[64] [64];//private data members to this class required to keep track of pebble objects as well as the baby grasshopper objects
    int m_tick;
    std::list<Actor *>::iterator kk;
    bool m_moved;
    
};

#endif // STUDENTWORLD_H_

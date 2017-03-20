#ifndef ACTOR_H_
#define ACTOR_H_

#include "GraphObject.h"
#include <list>
#include "Compiler.h"


using namespace std;

class StudentWorld;
class Compiler;

class Actor : public GraphObject
{
public:
    Actor(StudentWorld* world, int startX, int startY, Direction startDir, int imageID, int depth):GraphObject(imageID,startX, startY, right, 0, 0.25),m_w(world),m_stunned(0), m_ID(imageID)
    {}
// bitable object
    virtual bool bitable() {return false;}
    
    
    // Action to perform each tick.
    virtual void doSomething() = 0;
    
    // Is this actor dead?
    virtual bool isDead() const {return false;}
//
    // Does this actor block movement?
    virtual bool blocksMovement() const{return false;}
//
//    // Cause this actor to be be bitten, suffering an amount of damage.
//    virtual void getBitten(int amt);
//    
    // Cause this actor to be be poisoned.
    virtual void getPoisoned() {return;}
//
    // Cause this actor to be be stunned.
    virtual int getStunned(){ return m_stunned;}
    virtual void setTick(int x)
    {
        m_stunned+=x;
    }

     //Can this actor be picked up to be eaten?
    virtual bool isEdible() const{return false;}
//
//    // Is this actor detected by an ant as a pheromone?
//    virtual bool isPheromone() const;
//    
//    // Is this actor an enemy of an ant of the indicated colony?
//    virtual bool isEnemy(int colony) const;
//    
//    // Is this actor detected as dangerous by an ant of the indicated colony?
//    virtual bool isDangerous(int colony) const;
//    
//    // Is this actor the anthill of the indicated colony?
//    virtual bool isAntHill(int colony) const;
    
    // Get this actor's world.
    StudentWorld* getWorld() const
    {return m_w;}
    
    int getID() {return m_ID;}
private:
    StudentWorld* m_w;
    int m_stunned;
    int m_ID;
};

class Pebble : public Actor
{
public:
    Pebble(StudentWorld* sw, int startX, int startY): Actor(sw,startX, startY, right, IID_ROCK, 1)
    {}
    virtual void doSomething()   {cout << "~~~~~~~~~~~~~~~~~~~~~Pebble" << endl << endl; return;}
    virtual bool blocksMovement() const {return true;}
};

class EnergyHolder : public Actor
{
public:
    EnergyHolder(StudentWorld* sw, int startX, int startY, Direction startDir, int energy, int imageID, int depth):Actor(sw,startX, startY, right, imageID, 1),m_amt(energy),m_food(0)
    {}
    
    
    virtual void move(){return;}
//    virtual bool isDead() const;
//    
    // Get this actor's amount of energy (for a Pheromone, same as strength).
    int getEnergy() const {return m_amt;}
    
    
    // Adjust this actor's amount of energy upward or downward.
    void updateEnergy(int amt){m_amt=m_amt-amt;return;}
//
    // Add an amount of food to this actor's location.
    void addFood(int amt){
        m_amt=m_amt+amt;
        return;
        
    }
//
    // Have this actor pick up an amount of food.
    int pickupFood(int amt)
    {
       return m_food+=amt;
        
    }
    
    void setFood(int x)
    {
        m_food=x;
    }
    int getpickupFood()
    {
        return m_food;
    }
    
    // Have this actor pick up an amount of food and eat it.
    int pickupAndEatFood(int amt)
    {
        return m_amt=m_amt+amt;
    }
    
//
//    // Does this actor become food when it dies?
//    virtual bool becomesFoodUponDeath() const;
private:
    int m_amt;
    int m_food;
};
//
class Food : public EnergyHolder
{
public:
    Food(StudentWorld* sw, int startX, int startY, int energy): EnergyHolder(sw, startX, startY, right,energy,IID_FOOD, 2)
    {}
    virtual void doSomething() {   return;}
    virtual bool isEdible() const {return true;}
};
class Ant;
class AntHill : public EnergyHolder
{

public:
    AntHill(StudentWorld* sw, int startX, int startY, int colony, Compiler* program):EnergyHolder(sw, startX, startY, right,8999, IID_ANT_HILL, 2)
    {}
    virtual void doSomething();
    
    
    virtual int getColony()
    {
        return m_col;
    }
    
    void setTime(int x)
    {
        m_time+=x;
    }
    
    Ant* giveBirth();
    //virtual bool isMyHill(int colony) const;
    
private:
    int m_col;
    int m_time;
    Compiler * m_c;
    
    

};

class Pheromone : public EnergyHolder
{
public:
    Pheromone(StudentWorld* sw, int startX, int startY, int colony):EnergyHolder(sw, startX, startY, right,256, colony, 2)
            {}
    virtual void doSomething();
//    virtual bool isPheromone(int colony) const;
//    
//    // Increase the strength (i.e., energy) of this pheromone.
//    void increaseStrength();
//
};

class TriggerableActor : public Actor
{
public:
    TriggerableActor(StudentWorld* sw, int x, int y, int imageID):Actor(sw,x,y, right, imageID, 2)
    {}
    //virtual bool isDangerous(int colony) const;
};

class WaterPool : public TriggerableActor
{
public:
    WaterPool(StudentWorld* sw, int x, int y):TriggerableActor(sw, x, y,IID_WATER_POOL)
    {}
    virtual void doSomething();
};

class Poison : public TriggerableActor
{
public:
    Poison(StudentWorld* sw, int x, int y):TriggerableActor(sw, x, y,IID_POISON)
    {}
    virtual void doSomething();
};

class Insect : public EnergyHolder
{
public:
    Insect(StudentWorld* world, int startX, int startY, int energy, int imageID):EnergyHolder(world, startX, startY, right, energy, imageID, 1)
    {}
    virtual void doSomething() {return;}
    virtual bool isDead() const {return true;}
    virtual bool AmIBite () {return true;}
    virtual bool Ant_Bite() {return true;}
   
  
    Direction k()
    {
        int n= randInt(0,3);
        Direction dir=none;
        switch(n)
        {
            case 0:
                dir =up;
                break;
            case 1:
                dir=right;
                break;
            case 2:
                dir =down;
                break;
            case 3:
                dir =left;
                break;
            default:
                dir=none;
                break;
        }
        
      return dir;
    }
    void move();
    virtual void getPoisoned()
    {
        
        return;
    }
    virtual int getStunned()
    {
        setTick(2);
        return 0;
    }
    
    int getStuck()
    {
        return m_stunned;
    }
     void subtract_step(int x)
    {
        m_stunned+=x;
    }
    
    int getStep()
    {
        return m_step;
    }
    
    void setStep(int x)
    {
        m_step+=x;
    }
    
    virtual void getBitten(int amt) {return;};
    
    void Iwasbited (bool k)
    {
        m_bite=k;
    }
    bool getIwasbited()
    {
        return m_bite;
    }
   
  
private:
    int m_stunned =0;
    int m_step=0;
    bool m_bite=false;
    

//    virtual void getPoisoned();
//    virtual void getStunned();
//    virtual bool isEnemy(int colony);
//    virtual bool becomesFoodUponDeath() const;
//    
//    // Set x,y to the coordinates of the spot one step in front of this insect.
//    void getXYInFrontOfMe(int x, int y) const;
//    
//    // Move this insect one step forward if possible, and return true;
//    // otherwise, return false without moving.
//    virtual bool moveForwardIfPossible();
//    
//    // Increase the number of ticks this insect will sleep by the indicated amount.
//    void increaseSleepTicks(int amt);
};
//
class Ant : public Insect
{
public:
    Ant(StudentWorld* sw, int startX, int startY, int colony, Compiler* program, int imageID):Insect(sw, startX, startY, 1500, imageID)
    {}
    virtual void doSomething();
    virtual void getBitten(int amt) { updateEnergy(amt);}
    void Ant_BitEnemy();
    virtual bool Ant_Bite() {return false;}
    void dropFood();
    void runCommand(const Compiler::Command& c);
    
    bool interpreter();
    
    void emitNow();
    virtual int getColony()
    {
        return m_col;
    }
private:
    list<int> arr[64] [64];
    int m_col =0;
    Compiler *m_compile;
    int instructioncounter =0;
//    virtual void getBitten(int amt);
//    virtual bool isEnemy(colony) const;
//    virtual bool moveForwardIfPossible();
//     virtual bool bitable() {return false;}
};

class Grasshopper : public Insect
{
public:
    Grasshopper(StudentWorld* sw, int startX, int startY, int energy, int imageID):Insect(sw, startX, startY,energy,imageID),m_dis(0)
    {}
  

    virtual void doSomething() const {return;}
    
    int getDistance(){return m_dis;}
    Direction getRandomdir(){ m_dir=k(); return m_dir;}
    int getRanddomDistance(){
        m_dis=randInt(2,10);
        return m_dis;
    }
private:
    Direction m_dir;
    int m_dis;
    
};
//
class BabyGrasshopper : public Grasshopper
{
public:
    BabyGrasshopper(StudentWorld* sw, int startX, int startY):Grasshopper(sw,startX,startY,500, IID_BABY_GRASSHOPPER)
    {}
    virtual void doSomething();
    virtual void getBitten(int amt){
        updateEnergy(amt);
    }
    
    virtual bool bitable() {return true;}
    virtual void getPoisoned()
    {
        updateEnergy(150);
        return;
    }
    
    void randomDirection();
    
//    virtual bool isEnemy(int colony) const;
};

class AdultGrasshopper : public Grasshopper
{
public:
    AdultGrasshopper(StudentWorld* sw, int startX, int startY):Grasshopper(sw,startX,startY,1600, IID_ADULT_GRASSHOPPER)
    {}
    virtual int getStunned() {return 0;}
    virtual bool AmIBite () {return false;}

    virtual void doSomething();
    virtual void getPoisoned() {return;}
    
    virtual void getBitten(int amt) {
           updateEnergy(amt);
    
    };
   
   // virtual void getBitten(int amt);
};

#endif // ACTOR_H_

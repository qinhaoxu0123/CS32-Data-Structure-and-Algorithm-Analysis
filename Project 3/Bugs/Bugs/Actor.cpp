#include "Actor.h"
#include "StudentWorld.h"
#include <iostream>
#include "Compiler.h"
#include <list>
#include <string>
using namespace std;

///////////////////////////////Ant dosomething///////////////////////////////////////



void Ant::runCommand(const Compiler::Command& c) {return;}


void Ant::emitNow()
{
    getWorld()->CreateP(getX(), getY(), getColony());

    
}
void Pheromone::doSomething()
{
    updateEnergy(1);
    if(getEnergy()==0)
    {
        isDead();
        getWorld()->removeDeadObj(getX(),getY());
        return;
    }
}

bool Ant::interpreter()
{
    Compiler c;
    string error;
    if(!c.compile("dumbant.bug", error))
        return false;
    Compiler::Command cmd;
    int i;
    bool loop;
    for(i =0,loop=false;i<10, loop!=true; i++)
    {
        if(!c.getCommand(instructioncounter,cmd))
            return false;
        switch(cmd.opcode)
        {
            case Compiler::moveForward:
                
                if(!getWorld()->checkPebble(getX(),getY()+1))
                {
                    moveTo(getX(), getY()+1);
                    
                }
                else
                {
                    //remmeber the blocked movement
                }
                instructioncounter++,loop=true;
                break;
            case Compiler::eatFood:
              
                if(getpickupFood()<=100)
                    pickupAndEatFood(getpickupFood());
                else
                {
                    addFood(100);
                    pickupFood(-100);
                }
                  instructioncounter++,loop=true;
                break;
            case Compiler::dropFood:
              
                if(getWorld()->checkTypeOfObject(getX(),getY(), IID_FOOD))
                {
                    getWorld()->Ant_Dropfood(getX(), getY(), getpickupFood());
                }
                else
                {
                    getWorld()->createFood(getX(), getY(), getpickupFood());
                }
                  instructioncounter++,loop=true;
                break;
            case Compiler::bite:
           
                Ant_BitEnemy();
                  instructioncounter++,loop=true;
                break;
            case Compiler::pickupFood:
             
                if(getWorld()->checkTypeOfObject(getX(),getY(), IID_FOOD))
                {
                    if(getpickupFood()<1800)
                    {
                        pickupFood(400);
                        getWorld()->deduction_food (getX(),getY(),400);
                    }
                    if(getpickupFood()>1800)
                    {
                        setFood(1800);
                    }
                }
                  instructioncounter++,loop=true;
                break;
            case Compiler::emitPheromone:
                emitNow();
                  instructioncounter++,loop=true;
                break;
            case Compiler::faceRandomDirection:
               
                
                setDirection(k());
                  instructioncounter++,loop=true;
                break;
            case Compiler::rotateClockwise:
              instructioncounter++,loop=true;
                break;
            case Compiler::rotateCounterClockwise:
                instructioncounter++,loop=true;
                break;
            case Compiler::generateRandomNumber:
           
                // runCommand(const Compiler::Command& c)
                  instructioncounter++,loop=true;
                break;
            case Compiler::goto_command:
                instructioncounter++,loop=true;
                break;
            case Compiler::if_command:
            
                if(cmd.operand1 == "last_random_number_was_zero")
                    instructioncounter=stoi(cmd.operand2);
                else if(cmd.operand1 == "I_am_carrying_food" && getpickupFood()!=0)
                    instructioncounter=stoi(cmd.operand2);
                else if(cmd.operand1 == "I_am_hungry" && getEnergy()<25)
                    instructioncounter=stoi(cmd.operand2);
                else if(cmd.operand1 == "I_am_standing_with_an_enemy")
                    instructioncounter=stoi(cmd.operand2);
                else if(cmd.operand1 == "I_am_standing_on_food" && getWorld()->checkTypeOfObject(getX(),getY(), IID_FOOD))
                    instructioncounter=stoi(cmd.operand2);
                else if(cmd.operand1 == "I_am_standing_on_my_anthill" && getWorld()->checkAnt_hill(getX(), getY())==true)
                    instructioncounter=stoi(cmd.operand2);
                else if(cmd.operand1 == "I_smell_pheromone_in_front_of_me") //check )
                    instructioncounter=stoi(cmd.operand2);
                else if(cmd.operand1 == "I_smell_danger_in_front_of_me" && getWorld()->isDangerAt(getX(), getY()+1))
                        instructioncounter=stoi(cmd.operand2);
                        else if(cmd.operand1 == "I_was_bit" && getIwasbited()==true)// bite by some ant
                        instructioncounter=stoi(cmd.operand2);
                        else if(cmd.operand1 == "I_was_blocked_from_moving" && getWorld()->checkPebble(getX(),getY()+1))// bite by some ant
                        instructioncounter=stoi(cmd.operand2);
                        break;
                        default:
                        instructioncounter++;
                        if(cmd.opcode!=Compiler::goto_command ||cmd.opcode!=Compiler::generateRandomNumber )
                        return false;
                
                        if(instructioncounter>=10)
                            return false;
                        break;
            }
     
     }
    return false;
}

void Ant::doSomething()
{
    updateEnergy(1);
    if(getEnergy()==0)
    {
        isDead();
        getWorld()->removeDeadObj(getX(),getY());
        return;
    }
    
    if(getStuck()>0){
        subtract_step(-1);
        return;
    }
    

    if(!interpreter())
    {
        isDead();
        getWorld()->removeandaddfood(getX(),getY());
        return;
    }
        if(getWorld()->checkTypeOfObject(getX(),getY(), IID_POISON))
        {
            getWorld()->poisonAllPoisonableAt(getX(),getY());
            if(getEnergy()<=0)
            {
                isDead();
                getWorld()->removeandaddfood(getX(),getY());
                return;
            }
            
        }
        
        if(getWorld()->checkTypeOfObject(getX(),getY(), IID_WATER_POOL))
        {
            getWorld()->stunAllStunnableAt(getX(),getY());
            subtract_step(2);
        }
    
}

    //1.moveForward
   
    


void Ant::Ant_BitEnemy()
{
     if(getWorld()->checkTypeOfObject(getX(),getY(),IID_BABY_GRASSHOPPER) ||getWorld()->checkTypeOfObject(getX(),getY(),IID_ADULT_GRASSHOPPER))
        {
            getWorld()-> biteable_insect(getX(),getY());
        }
    
}
///////////////////////////////AntHilldosomething///////////////////////////////////////


Ant* AntHill::giveBirth()
{
    int antID =0;
    switch(m_col)
    {
        case 0:
            antID=IID_ANT_TYPE0;
            break;
        case 1:
            antID=IID_ANT_TYPE1;
            break;
        case 2:
            antID=IID_ANT_TYPE2;
            break;
        case 3:
            antID=IID_ANT_TYPE3;
            break;
    }
   // Ant(StudentWorld* sw, int startX, int startY, int colony, Compiler* program, int imageID)
    Ant* newAnt = new Ant(getWorld(), getX(), getY(),m_col, m_c,antID);
    setTime(getWorld()->getTick());
  
    return newAnt;
    
}
void AntHill::doSomething()
{
    updateEnergy(1);
    if(getEnergy()==0)
    {
        isDead();
        getWorld()->removeDeadObj(getX(),getY());
        return;
    }
    if(getWorld()->checkTypeOfObject(getX(),getY(), IID_FOOD))
    {
         getWorld()->deduction_food (getX(),getY(), 10000);
        addFood(10000);/// problem here what if the spot food has 9000
        return;
    }
    if(getEnergy()>=2000)
    {
        giveBirth();
        //a. It adds a new ant of the same colony number to its square in the simulation.
        updateEnergy(1500);
//        . It asks StudentWorld to increase the count of the total number of ants that this
//        colony has produced. This needs to be tracked in order to determine the winner ant colony.
        return;
    }
    return;
}
// Students:  Add code to this file (if you wish), Actor.h, StudentWorld.h, and StudentWorld.cpp
///////////////////////////////waterpooldosomething///////////////////////////////////////
void WaterPool::doSomething()
{
    getWorld()->stunAllStunnableAt(getX(),getY());
    
    return;
   
}
///////////////////////////////adultgrasshopperdosomething///////////////////////////////////////
void Poison::doSomething()
{
    getWorld()->poisonAllPoisonableAt(getX(),getY());
    return;
}

///////////////////////////////grasshopper Move function///////////////////////////////////////




void BabyGrasshopper::randomDirection()
{
    Direction dir;
    int n= rand() % 4 +1;
    switch(n)
    {
        case 1:
            dir =up;
            break;
        case 2:
            dir=right;
            break;
        case 3:
            dir =down;
            break;
        case 4:
            dir =left;
            break;
        default:
            dir=none;
    }
    setDirection(dir);
}

void Insect::move()
{
    Direction dir=k();
    int m_dis= randInt(2,10);
    
    
    int newX =getX();
    int newY=  getY();
    if(newX <=0 ||newX >=63 ||newY <=0 ||newY >= 63)
    {
    switch(dir)
    {
        case up:
            if(newY<=62)
            {
            if(!getWorld()->checkPebble(getX(),getY()+1))
            {
               
                    setDirection(up);
                
                    moveTo(getX(),getY()+1);
                
                
              
            }
            else
            {
                m_dis=0;
            }
            }
            break;
        case right:
            if(newX<=62)
            {
            if(!getWorld()->checkPebble(getX()+1,getY()))
            {
               
                 setDirection(right);
               
                   
                    moveTo(getX()+1,getY());
                
                
            }
            else
            {
                m_dis= 0;
            
            }
            }
            break;
        case down:
            if(newY>=1)
            {
            if(!getWorld()->checkPebble(getX(),getY()-1))
            {
                
                setDirection(down);
                
                    moveTo(getX(),getY()-1);
                    
                
            }
            else
            {
                m_dis=0;
        
            }
            }
            
            break;
        case left:
            if(newX>=1)
            {
            if(!getWorld()->checkPebble(getX()-1,getY()))
            {
                
                setDirection(left);
                
                    
                    moveTo(getX()-1,getY());
                   
            
            }
            else
            {
                m_dis=0;
            }
            }
            
            break;
    }
    }
    
    return;
}
///////////////////////////////adultgrasshopperdosomething///////////////////////////////////////
void  AdultGrasshopper::doSomething()
{    
    updateEnergy(1);
  
    //2.
    if(getEnergy()<=0)
    {
        cout <<"become adult" <<endl;
        isDead();
        getWorld()->removeandaddfood(getX(),getY());
        return;
    }
    //3.
    if(getStuck()>0){
        subtract_step(-1);
        return;
    }
    
     move();
    if(getDistance()==0)
    {
        move();
    }
    if(getWorld()->biteable_insect(getX(),getY()))// how to bite random insect in the same square
    {
        int chancetobite=randInt(0,2);
        if(chancetobite==0)
        {
            if(getWorld()->checkTypeOfObject(getX(),getY(), IID_BABY_GRASSHOPPER)||getWorld()->checkTypeOfObject(getX(),getY(), IID_ANT_TYPE0) ||getWorld()->checkTypeOfObject(getX(),getY(), IID_ANT_TYPE1)||getWorld()->checkTypeOfObject(getX(),getY(), IID_ANT_TYPE2)||getWorld()->checkTypeOfObject(getX(),getY(), IID_ANT_TYPE3))
            {
                getWorld()-> biteable_insect(getX(),getY());
            }
           
        }
        subtract_step(2);
    }
     int jump = randInt(0,9);
    if(jump==0)
    {
        int currX= getX();
        int currY =getY();
        int randomX=randInt(1,10);
        int randomY=randInt(1,10);
        int jumpX = currX + randomX;
        int jumpY = currY + randomY;
          if(jumpX >=/* DISABLES CODE */ (0) ||jumpX <= 63 ||jumpY >=0 ||jumpY <=63)
          {
                if(!getWorld()->checkPebble(jumpX,jumpY))
                {
                     setDirection(k());
                     moveTo(jumpX,jumpY);
                }
               else
              {
                    subtract_step(2);
              }
            
          }
      }

    
   
    if(getWorld()->checkTypeOfObject(getX(),getY(), IID_FOOD))
    {
        getWorld()->deduction_food (getX(),getY(),200);
        if(getEnergy()<=200)
        {
            addFood(200);
            int ChancetoSleep = randInt(0,1);
            if(ChancetoSleep==0)
            {
                subtract_step(2);
            }
            
        }
    }
    if(getWorld()->checkTypeOfObject(getX(),getY(), IID_POISON))
       {
           getWorld()->poisonAllPoisonableAt(getX(),getY());
           if(getEnergy()<=0)
           {
               isDead();
               getWorld()->removeandaddfood(getX(),getY());
               return;
           }
           
       }
    
     if(getWorld()->checkTypeOfObject(getX(),getY(), IID_WATER_POOL))
     {
         getWorld()->stunAllStunnableAt(getX(),getY());
         subtract_step(2);
     }
    
    if(getIwasbited()==true)
    {
        int n= randInt(0,1);
        if( n==0)
        {
            getWorld()-> biteable_insect(getX(),getY());
             subtract_step(2);
        }
    }
    
    
    subtract_step(2);

}

///////////////////////////////babygrasshopper dosomething///////////////////////////////////////
void  BabyGrasshopper::doSomething()
{
    
    
    //1.
    updateEnergy(1);

    //2.
    if(getEnergy()<=0)
    {

        isDead();
        getWorld()->removeandaddfood(getX(),getY());
        return;
        
    }
    //3.
    if (getStuck() > 0) {
        //        cout << "---------------------- " << getStuck() << endl << endl;
        subtract_step(-1);
        return;
    }

    if(getEnergy()>=1600)// check if hitpoitn is greater than 1600
    {
       
        isDead();
        getWorld()->addAdult(getX(),getY());
        return;
    }
  
   // 6 and 7
    if(getWorld()->checkTypeOfObject(getX(),getY(), IID_FOOD))
    {
        getWorld()->deduction_food (getX(),getY(), 200);
        if(getEnergy()<=200)
        {
            addFood(200);
            int ChancetoSleep = randInt(0,1);
            if(ChancetoSleep==0)
            {
                subtract_step(2);
            }
            
        }
    }
    
    move();
    if(getDistance()==0)
    {
        move();
    }
    
    
    if(getWorld()->checkTypeOfObject(getX(),getY(), IID_POISON))
    {
        getWorld()->poisonAllPoisonableAt(getX(),getY());
        if(getEnergy()<=0)
        {
            isDead();
            getWorld()->removeandaddfood(getX(),getY());
            return;
        }
        
    }
    
    if(getWorld()->checkTypeOfObject(getX(),getY(), IID_WATER_POOL))
    {
        getWorld()->stunAllStunnableAt(getX(),getY());
        subtract_step(2);
    }
    
    subtract_step(2);
   
    
}


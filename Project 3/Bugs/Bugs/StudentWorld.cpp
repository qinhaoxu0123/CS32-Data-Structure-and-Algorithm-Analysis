#include "StudentWorld.h"
#include "Field.h"
#include "GraphObject.h"
#include <string>
#include "Actor.h"
#include <iostream>
#include <sstream>
#include <vector>
#include "Compiler.h"


using namespace std;

GameWorld* createStudentWorld(string assetDir)
{
	return new StudentWorld(assetDir);
}

// Students:  Add code to this file (if you wish), StudentWorld.h, Actor.h and Actor.cpp

void StudentWorld::CreateP(int x, int y, int z)
{
//    IID_PHEROMONE_TYPE0 = 11;
//    const int IID_PHEROMONE_TYPE1 = 12;
//    const int IID_PHEROMONE_TYPE2 = 13;
//    const int IID_PHEROMONE_TYPE3 = 14;
    int ID =0;
    switch(z)
    {
        case 0:
            ID=IID_PHEROMONE_TYPE0;
            break;
        case 1:
            ID=IID_PHEROMONE_TYPE1;
            break;
        case 2:
            ID=IID_PHEROMONE_TYPE2;
            break;
        case 3:
            ID=IID_PHEROMONE_TYPE3;
            break;
            
    }
    Actor * Obj= getAnActorAtTheProposedLocation(x, y);
    if(Obj !=nullptr)
    {
        Pheromone *pp = dynamic_cast<Pheromone*>(Obj);
        if(pp->getEnergy()+256<=768)
            pp->updateEnergy(256);
        else
            pp->addFood(768);
    }
    else
    {
        //Pheromone(StudentWorld* sw, int startX, int startY, int colony)
        Pheromone *pp= new  Pheromone(this, x, y, z);
        arr[y][x].push_back(pp);
        
    }
    
}


void StudentWorld::addAnt(Actor* ant, int x, int y)
{
    Actor* pp=dynamic_cast<Ant*>(ant);
    arr[y][x].push_back(pp);
}

    
    

 bool StudentWorld::isDangerAt(int x, int y) 
{
    Actor*ap = getAnActorAtTheProposedLocation(x,y);
    if(ap!=nullptr)
    {
        Insect *pp = dynamic_cast<Insect *>(ap);
        if(pp !=nullptr)
            return true;
        TriggerableActor *kk = dynamic_cast<TriggerableActor *>(ap);
        if(kk != nullptr)
            return true;
    }
    return false;
    
}
bool StudentWorld::checkAnt_hill(int x, int y)
{
    Actor*ap = getAnActorAtTheProposedLocation(x,y);
    if(ap!=nullptr)
    {
        AntHill *pp = dynamic_cast<AntHill *>(ap);
        if(pp !=nullptr)
        {
            return true;
            
        }
    }
    return false;
    
}

void StudentWorld::createFood(int x, int y, int food)
{
    for(int i=0;i<64;i++)
    {
        for(int j=0; j<64;j++)
        {
            for(list<Actor*>::iterator it = arr[j][i].begin(); it!=arr[j][i].end(); it++)
            {
                if(x==i && y==j)
                {
                   (arr[y][x]).push_back(new Food(this,x,y,food));
                   
                }
                
            }
        }
    }

}

void StudentWorld::Ant_Dropfood(int x , int y, int food)
{
    Actor*ap = getAnActorAtTheProposedLocation(x,y);
    if(ap!=nullptr)
    {
        Food *pp = dynamic_cast<Food*>(ap);
        if(pp !=nullptr)
        {
            pp->addFood(food);
            
        }
    }
}
bool StudentWorld::biteable_insect (int x, int y)
{
   Actor*ap = getAnActorAtTheProposedLocation(x,y);
    if(ap!=nullptr)
    {
        Insect *pp = dynamic_cast<Insect*>(ap);
        if(pp !=nullptr)
        {
            if(pp->bitable())
            {
                pp->getBitten(50);
                pp->Iwasbited (true);
                return true;
            }
            if(pp->Ant_Bite())
            {
                pp->Iwasbited (true);
                pp->getBitten(15);
                return true;
            }
        }
    }
    return false;
}

void StudentWorld::deduction_food (int x, int y, int food)
{
    Actor*ap = getAnActorAtTheProposedLocation(x,y);
    if(ap!=nullptr)
    {
        Food *pp = dynamic_cast<Food*>(ap);
        if(pp !=nullptr)
        {
            if(pp->getEnergy()>=400)
            {
                pp->updateEnergy(food);
            }
            else
            {
                pp->isDead();
                removeDeadObj(x,y);
            }
            
        }
    }
    
}
StudentWorld:: ~StudentWorld()
{
    cleanUp();
}


bool StudentWorld::checkTypeOfObject(int x,int y, int ID)
{
    for(int i=0;i<64;i++)
    {
        for(int j=0; j<64;j++)
        {
            for(list<Actor*>::iterator it = arr[j][i].begin(); it!=arr[j][i].end(); it++)
            {
              if(x==i && y==j)
              {
                  switch(ID)
                  {
                      case 5: case 7:
                      case 0: case 1: case 2: case 3: case 9:case 10:
                          return true;
                          break;
                      default:
                          break;
                  }
              }
                
            }
        }
    }
    return false;
}


bool StudentWorld::stunAllStunnableAt(int x, int y)
{
    
    
    
    Actor*ap = getAnActorAtTheProposedLocation(x,y);
    if(ap!=nullptr)
    {
       
        Insect *pp = dynamic_cast<Insect*>(ap);
        
        if(pp !=nullptr)
        {
            return true;
        }
    }
   
    return false;
    
}
bool StudentWorld::poisonAllPoisonableAt(int x, int y)
{
    Actor*ap = getAnActorAtTheProposedLocation(x,y);
    if(ap!=nullptr)
    {
        Insect *pp = dynamic_cast<Insect*>(ap);
        if(pp !=nullptr)
        {
            cout << "i get fucking posion" << endl;
            pp->getPoisoned();
            return true;
        }
    }
    return false;
}
void  StudentWorld::removeDeadObj(int x, int y)
{
    for(int i=0;i<64;i++)
    {
        for(int j=0; j<64;j++)
        {
            for(list<Actor*>::iterator it = arr[j][i].begin(); it!=arr[j][i].end();it++ )
            {
                if(x==i && y==j)
                {
                    delete *it;
                    (arr[j][i]).erase(it);
                }
            }
            
        }
        
    }
}

void StudentWorld::removeandaddfood(int x, int y )
{
    for(int i=0;i<64;i++)
    {
        for(int j=0; j<64;j++)
        {
            for(list<Actor*>::iterator it = arr[j][i].begin(); it!=arr[j][i].end();it++ )
            {
                if(x==i && y==j)
                {
                    
                    delete *it;
                    (arr[j][i]).erase(it);
                    (arr[y][x]).push_back(new Food(this,x,y,100));
                }
            }
            
        }
        
    }
    return;
}





int StudentWorld::init()
{
    
    m_tick=0;
    Field f;
    string fieldFile = getFieldFilename();
    
    
    if(f.loadField(fieldFile)!=Field::LoadResult::load_success)
    {
        setError(fieldFile + " ");
        return false;
    }
    Compiler *compilerForEntrant0,*compilerForEntrant1,
             *compilerForEntrant2,*compilerForEntrant3;
    AntHill *ah0, *ah1, *ah2, *ah3;
    vector<string> fileNames = getFilenamesOfAntPrograms();
    compilerForEntrant0 = new Compiler;
    string error;
    
    
    
    for(int x=0; x<VIEW_HEIGHT; x++)//col
    {
        for( int y=0; y<VIEW_WIDTH; y++)//row
        {
            Field::FieldItem item =f.getContentsOf(x,y);
            
            if(item == Field::FieldItem::rock)
                (arr[y][x]).push_back(new Pebble(this,x,y));
            else if(item == Field::FieldItem::grasshopper)
                (arr[y][x]).push_back(new BabyGrasshopper(this, x,y));
            else if(item == Field::FieldItem::grasshopper)
                (arr[y][x]).push_back(new AdultGrasshopper(this,x,y));
            else if(item == Field::FieldItem::food)
                (arr[y][x]).push_back(new Food(this, x,y,6000));
            else if(item == Field::FieldItem::water)
                (arr[y][x]).push_back(new WaterPool(this, x,y));
            else if(item == Field::FieldItem::poison)
                (arr[y][x]).push_back(new Poison(this, x,y));
            else if(item == Field::FieldItem::anthill0)
            {
                if(!compilerForEntrant0->compile(fileNames[0], error))
                {
                    setError(fileNames[0] + "" + error);
                    return GWSTATUS_LEVEL_ERROR;
                }
            ah0 =new AntHill(this, x,y,0,compilerForEntrant0);
                (arr[y][x]).push_back(ah0);
           
            }
            else if(item == Field::FieldItem::anthill1)
            {
                if(!compilerForEntrant0->compile(fileNames[1], error))
                {
                    setError(fileNames[1] + "" + error);
                    return GWSTATUS_LEVEL_ERROR;
                }
                
                ah1 =new AntHill(this, x,y,1,compilerForEntrant1);
                (arr[y][x]).push_back(ah1);
            }
            else if(item == Field::FieldItem::anthill2)
            {
                if(!compilerForEntrant0->compile(fileNames[2], error))
                {
                    setError(fileNames[2] + "" + error);
                    return GWSTATUS_LEVEL_ERROR;
                }
                
                ah1 =new AntHill(this, x,y,2,compilerForEntrant2);
                (arr[y][x]).push_back(ah2);
            }
//            else if(item == Field::FieldItem::anthill3)
//            {
//                if(!compilerForEntrant0->compile(fileNames[3], error))
//                {
//                    setError(fileNames[3] + "" + error);
//                    return GWSTATUS_LEVEL_ERROR;
//                }
//                
//                ah1 =new AntHill(this, x,y,3,compilerForEntrant3);
//                (arr[y][x]).push_back(ah3);
//            }
        }
    }

    return GWSTATUS_CONTINUE_GAME;
}
bool StudentWorld::getEdibleAt1(int x, int y)
{
    for(int i=0;i<64;i++)
    {
        for(int j=0; j<64;j++)
        {
            
            for(list<Actor*>::iterator it = arr[j][i].begin(); it!=arr[j][i].end(); it++)
            {
                if(x==i && y==j)
                {
                    if((*it)->isEdible())
                        return true;
                }
            }
        }
        
    }
    return false;
}

Actor* StudentWorld::getEdibleAt(int x, int y)
{
    for(int i=0;i<64;i++)
    {
        for(int j=0; j<64;j++)
        {
            
            for(list<Actor*>::iterator it = arr[j][i].begin(); it!=arr[j][i].end(); it++)
            {
                if(x==i && y==j)
                {
                    if((*it)->isEdible())
                        return (*it);
                }
            }
        }
        
    }
    return nullptr;
}



Actor*  StudentWorld::getAnActorAtTheProposedLocation(int x, int y) 
{

    for(int i=0;i<64;i++)
    {
        for(int j=0; j<64;j++)
        {
            
            for(list<Actor*>::iterator it = arr[j][i].begin(); it!=arr[j][i].end(); it++)
            {
                if(x==i && y==j)
                {
                    return (*it);
                    
                }
            }
        }
        
    }
    return nullptr;
}

bool StudentWorld::MorethanOneObj(int x, int y)
{
    for(int i=0;i<64;i++)
    {
        for(int j=0; j<64;j++)
        {
            for(list<Actor*>::iterator it = arr[j][i].begin(); it!=arr[j][i].end(); it++)
            {
                if(x==i && y==j)
                {
                if(!arr[j][i].empty())
                    if((*it)->bitable())
                        return true;
                }
            }
        }
        
    }
    return false;
}

bool StudentWorld::foodObj(int x, int y)
{
    
    Actor*ap = getEdibleAt(x, y);
    Food *bb = dynamic_cast<Food*>(ap);
      if(ap!=nullptr)
      {
          
                  if(bb->getEnergy()>=200)
                  {
                      bb->updateEnergy(200);
                  }
                  if(bb->getEnergy()<=0)
                  {
                      removeDeadObj(x,y);
                      
                  }
          
           return true;
        }
    return false;
}


//    for(int i=0;i<64;i++)
//    {
//        for(int j=0; j<64;j++)
//        {
//            for(list<Actor*>::iterator it = arr[j][i].begin(); it!=arr[j][i].end(); it++)
//            {
//                if(x==i && y==j)
//                {
//                    if((*it)->isEdible())
//                        (*it)->();
//                        return true;
//                }
//            }
//        }
//        
//    }
//    return false;


void StudentWorld::addAdult(int x,int y)
{
    for(int i=0;i<64;i++)
    {
        for(int j=0; j<64;j++)
        {
            for(list<Actor*>::iterator it = arr[j][i].begin(); it!=arr[j][i].end();)
            {
                if(x==i && y==j)
                {
                    delete *it;
                    it = (arr[j][i]).erase(it);
    
                   (arr[y][x]).push_back(new AdultGrasshopper(this,x,y));
                }
            }
        }
        
    }
    return;
}

void StudentWorld::addActor(Actor *p)
{
    
}

 bool StudentWorld::checkPebble(int x, int y)
{
    Actor*ap = getAnActorAtTheProposedLocation(x,y);
    if(ap!=nullptr)
    {
        Pebble *pp = dynamic_cast<Pebble*>(ap);
        if(pp !=nullptr)
            return true;
    }
    return false;
}
//StudentWorld* sw, int startX, int startY, int energy
bool StudentWorld::canMoveTo(int x, int y)
{
    Actor*ap = getAnActorAtTheProposedLocation(x,y);
    BabyGrasshopper *bb = dynamic_cast<BabyGrasshopper*>(ap);
    if(ap!=nullptr)
    {
        if(bb!=nullptr)//found a food object at the position
            if((bb)->getEnergy()>=1600)
            {
            (arr[y][x]).push_back(new AdultGrasshopper(this,x,y));
                
            }
         if((bb)->getEnergy()==0)
         {
             removeDeadObj(x, y);
            
         }
        return true;
    }
    
    
    
    
    Actor*ff = getAnActorAtTheProposedLocation(x,y);
    Food *kk = dynamic_cast<Food*>(ff);
    if(kk!=nullptr)
    {
        if((kk)->getEnergy()<=200)
        {
            (kk)->updateEnergy(0);
            removeDeadObj(x, y);
           
        }
        else
        {
            (kk)->updateEnergy(200);
        }
       return true;  
    }
    return false;
}
//bool biteEnemyAt(Actor* me, int colony, int biteDamage)
//{
//    
//}


void StudentWorld::upLocation(Actor * p, int newX, int newY, int oldX, int oldY)
{
    list<Actor *>::iterator k;
    for( k= arr[oldY][oldX].begin(); k!=arr[oldY][oldX].end();k++)
    {
        if(*k==p)//find the insect
            break;
    }
    kk=++k;
    k--;
    
    arr[newY][newX].splice(arr[newY][newX].end(),arr[oldY][oldX],k);
    m_moved=true;
    return;
}

int StudentWorld::move()
{
    m_tick++;
    for(int i=0;i<64;i++)
    {
        for(int j=0; j<64;j++)
        {
            for(list<Actor*>::iterator it = arr[j][i].begin(); it!=arr[j][i].end();)
            {
                if ((*it) == nullptr) { break;}
                if ((*it)->getID() == IID_ROCK) {it++;continue;}
                    int oldX = (*it)->getX(), oldY=(*it)->getY();
                if ((*it) != nullptr||(*it)->getID() != IID_ROCK)
                {
                    (*it)->doSomething();
                }
                
                
                Actor* k = *it;
                int newX = (k)->getX(), newY=(k)->getY();
               
              
                if(newX != oldX || newY!=oldY)
                {
                    upLocation(k,newX, newY,oldX, oldY);
                }
                
                if(m_moved)
                {
                 
                    it=kk;
                    m_moved=false;
                }
                else      {              
                    it++;
                }
                
            }
        }
    }
    
    
    
    
    ostringstream s;
    s << "Ticks " << m_tick;
    string k =s.str();
    setGameStatText(k);
    
    if(m_tick !=2000)
        return GWSTATUS_CONTINUE_GAME;
    else
        return GWSTATUS_PLAYER_WON;
}


void StudentWorld::cleanUp()
{
    for(int i=0;i<64;i++)
    {
        for(int j=0; j<64;j++)
        {
            for(list<Actor*>::iterator it = arr[j][i].begin(); it!=arr[j][i].end();it++ )
            {
                if (!arr[j][i].empty())
                    {arr[j][i].pop_front();
//                    delete *it;
//                    (arr[j][i]).erase(it);
            }
            
        }
        
        }
    }
}
//    for(int i=0;i<VIEW_HEIGHT;i++)
//    {
//        for(int j=0; j<VIEW_WIDTH;j++)
//        {
//            if (!arr[j][i].empty())
//            {arr[j][i].pop_front();}
//            
//        }
//    }


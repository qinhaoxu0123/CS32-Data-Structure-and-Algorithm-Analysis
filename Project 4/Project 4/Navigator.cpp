#include "provided.h"
#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include "support.h"
#include "MyMap.h"

using namespace std;

class NavigatorImpl
{
public:
    NavigatorImpl();
    ~NavigatorImpl();
    bool loadMapData(string mapFile);
    NavResult navigate(string start, string end, vector<NavSegment>& directions) const;
private:
    MapLoader ml_map;
    AttractionMapper am_map;
    SegmentMapper sm_map;
};

NavigatorImpl::NavigatorImpl()
{
}

NavigatorImpl::~NavigatorImpl()
{
}

bool NavigatorImpl::loadMapData(string mapFile)
{
   if(!ml_map.load(mapFile))
 	return false;  // This compiles, but may not be correct
    
    am_map.init(ml_map);
    sm_map.init(ml_map);
    
    return true;
    
    
}

NavResult NavigatorImpl::navigate(string start, string end, vector<NavSegment> &directions) const
{
    
   
///////////coverting string start and end into lower case, char by char for the case insensitve requirement//////////////////
//    for(int i=0; i<start.size(); i++)
//    {
//        start[i] = tolower(start[i]);
//      
//    }
//    for(int i=0; i<start.size(); i++)
//    {
//        end[i] = tolower(end[i]);
//        
//    }
    
 ///////////checking whether the string start and end is valid or not///////////////////////
    GeoCoord Start_Loc;
    GeoCoord End_Loc;
    int str_index=0;
    if(!am_map.getGeoCoord(start,Start_Loc))
    {
        return NAV_BAD_SOURCE;
    }
    if(!am_map.getGeoCoord(end,End_Loc))
    {
        return NAV_BAD_DESTINATION;
    }
    directions.clear();
    
 ///////////////compare them whether the the start geocoord and end geocoord are on the same if so then return success///////////
    
    if(Start_Loc==End_Loc)
    {
        return NAV_SUCCESS;
    }
/////////////otherwise start to push  "start" geocoordinate to our priority queue and start to find the shortest path in our data structure //////////////
    vector<StreetSegment> Start_Loc_related_segment;
    vector<geoCoordinate*> geoCoordinateSet;
     priority_queue<geoCoordinate*, vector<geoCoordinate*>, cmp>pq;
/// create a new object of geodistance by intialize all the varibale and then push back to my priority queue//////////////
    geoCoordinate *begin =new geoCoordinate;
    begin->geoCoor=Start_Loc;
    begin->start=-1;
    begin->gDis=0;
    begin->fDis=distanceEarthMiles(Start_Loc,End_Loc);
    begin->streetVisted ="";
    pq.push(begin);
/////// marked  the geocoord in our myMap using associate/////////////////////////
    MyMap <GeoCoord, GeoCoord> visited;
    visited.associate(begin->geoCoor,Start_Loc);
    
//     cout << "visited item:" << lindasGPA<<endl;
///get all the streetsegemnt that related to the start geocoord////////////
    vector<StreetSegment> temp(sm_map.getSegments(End_Loc));
    
/////////////assign all the into the vector that holds all the streetsegment of the start geocoor//////
 
    Start_Loc_related_segment.assign(temp.begin(),temp.end());
    
/////////loop throught the data until it is empty/////////////////////
    while(!pq.empty())
    {
        geoCoordinate curr = *(pq.top());
        geoCoordinate* t= pq.top();
        pq.pop();
        str_index++;
        geoCoordinate* temp;
        geoCoordinateSet.push_back(t);
        
        vector<StreetSegment> relatedSegment(sm_map.getSegments(curr.geoCoor));
        GeoCoord adjacent_geoCoordinate;
        for(int j =0; j<relatedSegment.size();j++)
        {
            if(CanIReach(relatedSegment[j],Start_Loc_related_segment))
            {
                geoCoordinate * k =new geoCoordinate;
                k->geoCoor=End_Loc;
                k->start=str_index-1;
                k->streetVisted =relatedSegment[j].streetName;
                 geoCoordinateSet.push_back(k);
             
                getDirection(str_index-1, geoCoordinateSet.size()-1, directions, geoCoordinateSet);
 //////////////freee memory....///////////////////////////////////////////////////////////
                for(vector<geoCoordinate*>::iterator it =  geoCoordinateSet.begin(); it!= geoCoordinateSet.end() ; it++)
                    delete(*it);
                
                while(!pq.empty())
                {
                    geoCoordinate* killme=pq.top();
                    pq.pop();
                    delete killme;
                }
  
                return NAV_SUCCESS;
            }
            
  ///////checking the adjacentCoordinate that asscoiate with the vertex/////////////
            adjacent_geoCoordinate= relatedSegment[j].segment.start;
            const GeoCoord *ptr_start=visited.find( adjacent_geoCoordinate);
            if(ptr_start==nullptr)// if the near geocoord we haven't visited yet then we should visited
            {
         
                temp =new geoCoordinate;
                temp ->geoCoor= adjacent_geoCoordinate;
                temp->start=str_index-1;
                temp->streetVisted = relatedSegment[j].streetName;
                temp->gDis= curr.gDis + distanceEarthMiles(curr.geoCoor, adjacent_geoCoordinate);
                temp->fDis=temp->gDis+distanceEarthMiles(adjacent_geoCoordinate,End_Loc);
                 pq.push(temp);
                visited.associate( temp->geoCoor,adjacent_geoCoordinate);
            }
            
            
            adjacent_geoCoordinate = relatedSegment[j].segment.end;
            const GeoCoord *ptr_end=visited.find(adjacent_geoCoordinate);
            if(ptr_end==nullptr)// if the near geocoord we haven't visited yet then we should visited
            {
                temp =new geoCoordinate;
                temp->geoCoor=adjacent_geoCoordinate;
                temp->start=str_index-1;
                temp->streetVisted = relatedSegment[j].streetName;
                temp->gDis= curr.gDis + distanceEarthMiles(curr.geoCoor, adjacent_geoCoordinate);
                temp->fDis= temp->gDis+distanceEarthMiles(adjacent_geoCoordinate,End_Loc);
                pq.push(temp);
                visited.associate(temp ->geoCoor,adjacent_geoCoordinate);
            }
        }
       
        
    }

	return NAV_NO_ROUTE;  // This compiles, but may not be correct
}

//******************** Navigator functions ************************************

// These functions simply delegate to NavigatorImpl's functions.
// You probably don't want to change any of this code.

Navigator::Navigator()
{
    m_impl = new NavigatorImpl;
}

Navigator::~Navigator()
{
    delete m_impl;
}

bool Navigator::loadMapData(string mapFile)
{
    return m_impl->loadMapData(mapFile);
}

NavResult Navigator::navigate(string start, string end, vector<NavSegment>& directions) const
{
    return m_impl->navigate(start, end, directions);
}

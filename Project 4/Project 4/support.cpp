//
//  support.cpp
//  Project 4
//
//  Created by Qinhao Xu on 3/13/17.
//  Copyright © 2017 Qinhao Xu. All rights reserved.
//

#include "support.h"
#include <vector>
#include "provided.h"
#include <iostream>
using namespace std;

bool operator ==(const GeoCoord &a, const GeoCoord &b)
{
    
    if(a.latitude==b.latitude && b.longitude==b.longitude)
    {
        return true;
    }
    return false;
}

bool operator >(const GeoCoord &a, const GeoCoord&b)
{
    
    if(a.latitude>b.latitude)
    {
        return true;
    }
    if(a.latitude<b.latitude)
    {
        return false;
    }
    if(a.longitude>b.longitude)
    {
        return true;
    }
    if(a.longitude<b.longitude)
    {
        return false;
    }
    return false;
}

bool operator <(const GeoCoord &a, const GeoCoord&b)
{
    
    if(a.latitude<b.latitude)
    {
        return true;
    }
    if(a.latitude>b.latitude)
    {
        return false;
    }
    if(a.longitude<b.longitude)
    {
        return true;
    }
    if(a.longitude>b.longitude)
    {
        return false;
    }
    return false;
}
bool CanIReach(StreetSegment seg, std::vector<StreetSegment>&relatedsegment)
{
    for(int i=0; i<relatedsegment.size();i++)
    {
        if(relatedsegment[i].segment.start.latitude==seg.segment.start.latitude &&
           relatedsegment[i].segment.start.longitude==seg.segment.start.longitude &&
           relatedsegment[i].segment.end.longitude==seg.segment.end.longitude&&
           relatedsegment[i].segment.end.latitude==seg.segment.end.latitude)
            return true;
    }
    return false;
    
}


void getDirection(int curr_index, int prev_index, vector<NavSegment> & directions, vector<geoCoordinate*>&geoCoordinateSet)

{
    if(curr_index==-1) return;
    
    getDirection((*(geoCoordinateSet[curr_index])).start,curr_index,directions,geoCoordinateSet);
    
    NavSegment dir;
    
    GeoSegment tmp(geoCoordinateSet[curr_index]->geoCoor,geoCoordinateSet[prev_index]->geoCoor);
    
    dir.m_geoSegment =tmp;
    
    double m_degree = angleOfLine(tmp);
    
    if(0<=m_degree && m_degree <=22.5) dir.m_direction= "east";
    if(22.5<m_degree && m_degree <=67.5) dir.m_direction= "northeast";
    if(67.5<m_degree && m_degree <=112.5) dir.m_direction= "north";
    if(112.5<m_degree && m_degree <=157.5) dir.m_direction= "northwest";
    if(157.5<m_degree && m_degree <=202.5) dir.m_direction= "west";
    if(202.5<m_degree && m_degree <=247.5) dir.m_direction= "southwest";
    if(247.5<m_degree && m_degree <=292.5) dir.m_direction= "south";
    if(292.5<m_degree && m_degree <=337.5) dir.m_direction= "southeast";
    if(337.5<m_degree && m_degree <360) dir.m_direction= "east";
    
    dir.m_streetName =geoCoordinateSet[prev_index]->streetVisted;
    double distance = distanceEarthMiles(geoCoordinateSet[curr_index]->geoCoor,geoCoordinateSet[prev_index]->geoCoor);
    
    if(directions.empty())
        dir.m_command = NavSegment::PROCEED;
    else
    {
        if(geoCoordinateSet[prev_index]->streetVisted== directions[directions.size()-1].m_streetName)
            dir.m_command = NavSegment::PROCEED;
        else
        {
            NavSegment turnDir;
            turnDir.m_command = NavSegment::TURN;
            m_degree= angleBetween2Lines(directions[directions.size()-1].m_geoSegment, tmp);
            if(m_degree>180)
            {
                turnDir.m_direction= "right";
            }
            else
            {
                turnDir.m_direction= "left";
            }
            turnDir.m_streetName=dir.m_streetName;
            directions.push_back(turnDir);
            dir.m_command = NavSegment::PROCEED;
            
        }
    }
    
    dir.m_distance=distance ;
    
    directions.push_back(dir);
    // cout <<directions.size()<< endl;
    
}

//////////checking if the segement int the vector are reachable if not return false////////////////
//bool m_reachable(StreetSegment seg, std::vector<StreetSegment>&related_segment)
//{
//    for(int i=0; i<related_segment.size();i++)
//    {
//        if(related_segment[i].segment.start.latitude==seg.segment.start.latitude &&
//           related_segment[i].segment.start.longitude==seg.segment.start.longitude &&
//           related_segment[i].segment.end.longitude==seg.segment.end.longitude&&
//           related_segment[i].segment.end.latitude==seg.segment.end.latitude)
//            return true;
//    }
//    return false;
//}
//
///////////get the dirctions of each movement, and determine where to proceed on the same streetsegment or turn left or right /////////////////////////////////////
//void getDirection(int current_index, int prev_index, vector<NavSegment> & directions, vector<GeoDistance*>&GeoDistance_set)
//{
//    if(current_index==-1) return;
//    getDirection((*(GeoDistance_set[current_index])).Distance,current_index,directions,GeoDistance_set);
//    NavSegment direction;
//    
//    GeoSegment tmp(GeoDistance_set[current_index]->k,GeoDistance_set[prev_index]->k);
//    
//    direction.m_geoSegment =tmp;
//    
//    double m_degree = angleOfLine(tmp);
//    
//    if(0<=m_degree && m_degree <=22.5) direction.m_direction= "east";
//    if(22.5<=m_degree && m_degree <=67.5) direction.m_direction= "northeast";
//    if(67.5<=m_degree && m_degree <=112.5) direction.m_direction= "north";
//    if(112.5<=m_degree && m_degree <=157.5) direction.m_direction= "northwest";
//    if(157.5<=m_degree && m_degree <=202.5) direction.m_direction= "west";
//    if(202.5<=m_degree && m_degree <=247.5) direction.m_direction= "southwest";
//    if(292.5<=m_degree && m_degree <=337.5) direction.m_direction= "south";
//    if(337.5<=m_degree && m_degree <=360) direction.m_direction= "east";
//    
//    direction.m_streetName =GeoDistance_set[prev_index]->streetsegPassed;
//    double distance = distanceEarthMiles(GeoDistance_set(current_index)->k,GeoDistance_set[prev_index]->k);
//    
//    if(directions.empty())
//        direction.m_command = NavSegment::PROCEED;
//    else
//    {
//        if(GeoDistance_set[prev_index]->streetsegPassed== directions[directions.size()-1].m_streetName)
//            direction.m_command = NavSegment::PROCEED;
//        else
//        {
//            NavSegment turnDirection;
//            turnDirection.m_command = NavSegment::TURN;
//            m_degree= angleBetween2Lines(directions[directions.size()-1].m_geoSegment, tmp);
//            if(m_degree<180)
//            {
//                turnDirection.m_direction= "left";
//            }
//            else
//            {
//                turnDirection.m_direction= "right";
//            }
//            turnDirection.m_streetName=direction.m_streetName;
//            
//        }
//    }
//    
//    direction.m_distance=distance ;
//    directions.push_back(direction);
//    
//}


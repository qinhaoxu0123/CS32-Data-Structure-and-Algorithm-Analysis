//
//  support.hpp
//  Project 4
//
//  Created by Qinhao Xu on 3/13/17.
//  Copyright © 2017 Qinhao Xu. All rights reserved.
//

#ifndef support_h
#define support_h

#include <stdio.h>
#include "provided.h"
#include <vector>
struct geoCoordinate
{
    GeoCoord geoCoor;
    int start;
    std::string streetVisted;
    double gDis;
    double fDis;
    
};
struct cmp
{
    bool operator()(const geoCoordinate * a, const geoCoordinate *b) const
    {
        return (a->fDis > b->fDis);
        
    }
};


bool operator ==(const GeoCoord &a, const GeoCoord&b);
bool operator <(const GeoCoord &a, const GeoCoord&b);
bool operator >(const GeoCoord &a, const GeoCoord&b);
bool CanIReach(StreetSegment seg, std::vector<StreetSegment>&relatedsegment);
void getDirection(int curr_index, int prev_index, std::vector<NavSegment> & directions, std::vector<geoCoordinate*>&geoCoordinateSet);


#endif /* support_hpp */

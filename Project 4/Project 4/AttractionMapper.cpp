#include "provided.h"

#include <string>
#include "MyMap.h"
#include <iostream>
using namespace std;


class AttractionMapperImpl
{
public:
	AttractionMapperImpl();
	~AttractionMapperImpl();
	void init(const MapLoader& ml);
	bool getGeoCoord(string attraction, GeoCoord& gc) const;
    
private:
    MyMap<string, GeoCoord> Atrract_map;
    
};

AttractionMapperImpl::AttractionMapperImpl()
{
}

AttractionMapperImpl::~AttractionMapperImpl()
{
}

void AttractionMapperImpl::init(const MapLoader& ml)
{
    StreetSegment seg;
//    Attraction att;
    
    for(int i =0; i<ml.getNumSegments();i++)
    {
        ml.getSegment(i, seg);
        for(int k=0; k<seg.attractions.size();k++)
        {
//            string finalname;
            string name=seg.attractions[k].name;
//            int i;
//            for(i=0;i < name.size() && name[i]!=' ';i++)
//            {
//                finalname+=tolower(name[i]);
//            }
//            for(i++;i < name.size();i++)
//            {
//                finalname+=tolower(name[i]);
//            }
            GeoCoord coordinate=seg.attractions[k].geocoordinates;
            Atrract_map.associate(name, coordinate);
        }
    }
    
}

bool AttractionMapperImpl::getGeoCoord(string attraction, GeoCoord& gc) const
{
    const GeoCoord *ptr=Atrract_map.find(attraction);
    if(ptr==nullptr)
    {
        return false;
    }
       gc=(*ptr);
    
	return true;  // This compiles, but may not be correct
}

//******************** AttractionMapper functions *****************************

// These functions simply delegate to AttractionMapperImpl's functions.
// You probably don't want to change any of this code.

AttractionMapper::AttractionMapper()
{
	m_impl = new AttractionMapperImpl;
}

AttractionMapper::~AttractionMapper()
{
	delete m_impl;
}

void AttractionMapper::init(const MapLoader& ml)
{
	m_impl->init(ml);
}

bool AttractionMapper::getGeoCoord(string attraction, GeoCoord& gc) const
{
	return m_impl->getGeoCoord(attraction, gc);
}

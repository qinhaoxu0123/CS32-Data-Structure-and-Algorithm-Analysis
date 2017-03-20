#include "provided.h"
#include <string>
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

class MapLoaderImpl
{
public:
	MapLoaderImpl();
	~MapLoaderImpl();
	bool load(string mapFile);
	size_t getNumSegments() const;
	bool getSegment(size_t segNum, StreetSegment& seg) const;
private:
    vector <StreetSegment*> myvector;
    int m_count =0;
    
};

MapLoaderImpl::MapLoaderImpl()
{
    myvector.clear();
}

MapLoaderImpl::~MapLoaderImpl()
{
    for(auto it=myvector.begin(); it!=myvector.end(); it++)
    {
        delete(*it);
    }
}

bool MapLoaderImpl::load(string mapFile)
{
    ifstream f(mapFile);
    if(!f)
    {
        cout << "error while opening file"<< endl;
        return false;
    }
    else
    {
    string Name, Coordinate,attractionLine, start_lati, start_long, end_lati, end_long;
    int i, att;
    while(getline(f,Name))
    {
        start_lati= ""; start_long= ""; end_lati= ""; end_long= "";
        getline(f,Coordinate);// get the second line
        
        for(i =0;  i<Coordinate.size()&&Coordinate[i] !=','; i++)// add start_lati to a string
            start_lati+=Coordinate[i];
        for(i++;  i<Coordinate.size()&&Coordinate[i] !=' '; i++)// add start_long to
            start_long+=Coordinate[i];
        for(i++;  i<Coordinate.size()&&Coordinate[i] !=','; i++)
            end_lati+=Coordinate[i];
        for(i++;  i<Coordinate.size(); i++)
            end_long+=Coordinate[i];
        
        f >> att;// when we hit 0;
        f.ignore(1000,'\n');
        
        GeoCoord str(start_lati, start_long);// get the specifc starting location
        GeoCoord end(end_lati, end_long);// get the ending location
        GeoSegment segment(str, end); //create the segment
        
        StreetSegment * street= new StreetSegment;
        street->streetName=Name;
        street->segment=segment;
        street->attractions.clear();// empty a vector when the vector is created.
        
        int k;
        
     
        for(int i=0; i< att;i++)
        {
            Name ="";
            /// reading each line char by char and add them into different category
            string lati="", longti="";
            getline(f,attractionLine);
            for(k=0; k<attractionLine.size()&&attractionLine[k]!='|'; k++)
                Name+=attractionLine[k];
            for(k++; k<attractionLine.size()&&attractionLine[k]!=','; k++)
                lati+=attractionLine[k];
            for(k++; k<attractionLine.size(); k++)
                longti+=attractionLine[k];
            
            Attraction p;
            GeoCoord coordinates(lati, longti);// use geocoord converts it into specific coordiantes.
            p.geocoordinates = coordinates;// set the attraction coordinates
            p.name=Name;// set the attractions name;
            
            street->attractions.push_back(p);// push the attraction segemnet into the attractions vector;
        }
       
        
        myvector.push_back(street);
        m_count++;
    }
    }
    return true;;  // This compiles, but may not be correct
}

size_t MapLoaderImpl::getNumSegments() const
{
    return m_count; // This compiles, but may not be correct
}

bool MapLoaderImpl::getSegment(size_t segNum, StreetSegment &seg) const
{
    if(segNum<0 || segNum >getNumSegments()-1)// check for boundary
        return false;
    
    seg=*(myvector[segNum]);
    return true;
    
}

//******************** MapLoader functions ************************************

// These functions simply delegate to MapLoaderImpl's functions.
// You probably don't want to change any of this code.

MapLoader::MapLoader()
{
	m_impl = new MapLoaderImpl;
}

MapLoader::~MapLoader()
{
	delete m_impl;
}

bool MapLoader::load(string mapFile)
{
	return m_impl->load(mapFile);
}

size_t MapLoader::getNumSegments() const
{
	return m_impl->getNumSegments();
}

bool MapLoader::getSegment(size_t segNum, StreetSegment& seg) const
{
   return m_impl->getSegment(segNum, seg);
}

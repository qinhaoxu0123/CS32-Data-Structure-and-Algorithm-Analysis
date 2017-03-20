#include "provided.h"
#include <vector>
#include "MyMap.h"
#include <string>
using namespace std;

class SegmentMapperImpl
{
public:
	SegmentMapperImpl();
	~SegmentMapperImpl();
	void init(const MapLoader& ml);
	vector<StreetSegment> getSegments(const GeoCoord& gc) const;
private:
    MyMap<GeoCoord,vector<StreetSegment>> Segment_map;
};

SegmentMapperImpl::SegmentMapperImpl()
{
}

SegmentMapperImpl::~SegmentMapperImpl()
{
}

void SegmentMapperImpl::init(const MapLoader& ml)
{
     StreetSegment seg;
    for(int i =0; i<ml.getNumSegments();i++)
    {
     
       if( ml.getSegment(i, seg))
       {
           
        if(Segment_map.find(seg.segment.start)==nullptr)// check the segement start if we find there is a empty spot then we assoicate the geocoord with the streetsegement vector.
        {
             vector<StreetSegment> myvec;
            myvec.push_back(seg);
            Segment_map.associate(seg.segment.start,myvec);
        }
        else
        { 
            Segment_map.find(seg.segment.start)->push_back(seg);// else we push back to the streetsegment 
        }
        
        if(Segment_map.find(seg.segment.end)==nullptr)// check the segement end;
        {
            
             vector<StreetSegment> myvec;
            myvec.push_back(seg);
            Segment_map.associate(seg.segment.end,myvec);
        }
        else
        {
        
            Segment_map.find(seg.segment.end)->push_back(seg);//Push to the Vector<StreetSegment> found by map
        }
        for(int k=0; k<seg.attractions.size();k++)
        {
       
            if(Segment_map.find(seg.attractions[k].geocoordinates)==nullptr)
            {
                vector<StreetSegment> myvec;
                myvec.push_back(seg);
                Segment_map.associate(seg.attractions[k].geocoordinates,myvec);
            }
            else
            {
                Segment_map.find(seg.attractions[k].geocoordinates)->push_back(seg);
                
            }
       
        }
       }
        
    }
    
    
}

vector<StreetSegment> SegmentMapperImpl::getSegments(const GeoCoord& gc) const
{

	const vector<StreetSegment> *segments=Segment_map.find(gc);
    if(!segments->empty())
    {
        return *segments;
    }
    
    return {};
}

//******************** SegmentMapper functions ********************************

// These functions simply delegate to SegmentMapperImpl's functions.
// You probably don't want to change any of this code.

SegmentMapper::SegmentMapper()
{
	m_impl = new SegmentMapperImpl;
}

SegmentMapper::~SegmentMapper()
{
	delete m_impl;
}

void SegmentMapper::init(const MapLoader& ml)
{
	m_impl->init(ml);
}

vector<StreetSegment> SegmentMapper::getSegments(const GeoCoord& gc) const
{
	return m_impl->getSegments(gc);
}

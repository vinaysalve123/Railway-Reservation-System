//19CS30019 GIRISH KUMAR    
#ifndef __RAILWAYS_H
#define __RAILWAYS_H


#include<iostream>
#include "Station.h"
#include<string>
#include<map>
using namespace std;

class Station;

class Railways{
    Railways();
    ~Railways();

    //list of stations
    static map<const string , const Station*> sStation; 
    //list of pair of stations and distance between them
    static map<pair<const Station* , const Station*>, int>  sDistance;
   
    
    public:
    //singleton Railways IndianRailways
    static const Railways& IndianRailways()
    {
        static const Railways TheIndianrailways;
        return TheIndianrailways;
    }
    //getdistance between two station from sDistance map
    int GetDistance(const Station& srcName , const Station& dstname) const;
    //get station from Station map 
    const Station* GetStation(const Station& name) const ;


    //unit test function
    static void unitTestRailways();

};
#endif


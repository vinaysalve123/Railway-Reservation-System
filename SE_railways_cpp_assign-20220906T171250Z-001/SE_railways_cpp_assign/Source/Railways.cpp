#ifndef _RAILWAYS_H
#define _RAILWAYS_H

#include<iostream>
#include<string>
#include<map>
using namespace std;
//#include "SimpleDataClasses.hxx"
#include "Railways.h"

//static definitions
map<const string , const Station*>Railways::sStation;
map<pair<const Station*, const Station*>,int > Railways ::sDistance;

//implementation of railways
//constructor
Railways::Railways(){
    //map for stations in indianrailways
    sStation["Mumbai"]=new Station("Mumbai");
    sStation["Delhi"]=new Station("Delhi");
    sStation["Bangalore"]=new Station("Bangalore");
    sStation["Kolkata"]=new Station("Kolkata");

    //unordered map between pair of stations and distance between them
    sDistance[make_pair(sStation["Mumbai"],sStation["Delhi"])] =1447;
    sDistance[make_pair(sStation["Mumbai"],sStation["Bengalore"])] =981;
    sDistance[make_pair(sStation["Mumbai"],sStation["Kolkata"])] =2014;
    sDistance[make_pair(sStation["Mumbai"],sStation["Chennai"])] =1338;
    sDistance[make_pair(sStation["Delhi"],sStation["Bangalore"])] =2150;
    sDistance[make_pair(sStation["Delhi"],sStation["Kolkata"])] =1472;
    sDistance[make_pair(sStation["Delhi"],sStation["Chennai"])] =2180;
    sDistance[make_pair(sStation["Bangalore"],sStation["Kolkata"])] =1871;
    sDistance[make_pair(sStation["Bangalore"],sStation["Chennai"])] =350;
    sDistance[make_pair(sStation["Kolkata"],sStation["Chennai"])] =1659;

    
}

//destructor 
Railways::~Railways(){
    map<const string, const Station*>::iterator it;
    for(it=sStation.begin();it!=sStation.end();++it)
        delete it->second;

}
//get station from station list byt name 
const Station* Railways :: GetStation(const Station& name) const {
    map<const string ,const Station*> ::iterator it;
    for(it = sStation.begin();it != sStation.end();++it)
        if(it->first == name.GetName())
            
        return it->second;
    return it->second;
}

//get distance between two stations 
int Railways :: GetDistance(const Station& srcName, const Station& dstName) const
{
    int Distance =0;
        const Station* psStation= GetStation(srcName);
        const Station* pdStation = GetStation(dstName);

        //get the Distance  between the Station if they are connected
        map<pair<const Station*,const Station*>,int> ::iterator Distance_it;
        Distance_it = sDistance.find(make_pair(psStation,pdStation));
        if(Distance_it == sDistance.end()){
            //if station are in reverse order
            Distance_it = sDistance.find(make_pair(pdStation,psStation));
            if(Distance_it == sDistance.end())
                cout<<"station are not connected\n";
        }
        Distance = Distance_it->second;
    return Distance;
}

void Railways::unitTestRailways(){
    //creation of a singleton object a indianrailways
    Railways indianrailways =Railways::IndianRailways();

    //checking for get station function
    const  Station *p = indianrailways.GetStation(Station("Mumbai"));
    if(p->GetName()!="Mumbai")
    cout<<"Error in GetStation Function in Railways"<<endl;

    //checking for Get distance function
    int d = indianrailways.GetDistance(Station("Kolkata"),Station("Delhi"));
    if(d!=1472)
    cout<<"Error in Get distance Function in Railways"<<endl;
}
#endif


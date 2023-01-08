//19CS30019 Girish Kumar

#ifndef __STATION_H 
#define __STATION_H
#include<iostream>
#include<string>
using namespace std;
#include "Railways.h"

class Station{
    
    const string name_;

    public:
    // static void unitTestStation(){
    //     Station a("Mumbai");       //object construction
    //     if(a.GetName()!="Mumbai")
    //     cout<<"Station Construction error / or Error in Getname Function "<<endl;   
    //     if(a.GetDistance("Delhi")!=1447)    
    //     cout<<"Error in Getdistance function"<<endl;     }
    
    Station(const string& name):name_(name){}
    ~Station(){}
    string GetName() const{
        return name_;
    }
    friend ostream& operator<<(ostream& os, const Station &s){
        os<<s.name_;
        return os;
    }
    int GetDistance(const string& name);
    
};




#endif
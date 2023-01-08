

#include<iostream>
using namespace std;
#include<string>
#include "Date.h"


char monthNames[][4] = { "Jan", "Feb", "Mar", "Apr", "May", "Jun","Jul", "Aug", "Sep", "Oct", "Nov", "Dec" };
char dayNames[][10] = { "Monday", "Tuesday", "Wednesday", "Thursday","Friday", "Saturday", "Sunday" };

// class Date {
    // enum Month { Jan = 1, Feb, Mar, Apr, May, Jun, Jul, Aug, Sep, Oct, Nov, Dec };
    // enum Day { Mon, Tue, Wed, Thr, Fri, Sat, Sun };
//     typedef unsigned int UINT;
//     UINT date_;    
//     Month month_; 
//     UINT year_;

    
    Date::Date(UINT d, UINT m, UINT y) : date_(d), month_((Month)m), year_(y){}
    
    // void Date::print() { cout << date_ << "/" << monthNames[month_ - 1] << "/" << year_ << endl; }
   
        ostream& operator<<(ostream &os, const Date& d){
            os<<d.date_ << "/" << monthNames[d.month_ - 1] << "/" << d.year_ ;
            return os;
        }  
        void Date::unitTestDate(){
            Date a(2,5,2021);
            if(a.month_!=5||a.date_!=2||a.year_!=2021)
            cout<<"Error in date construction in Date"<<endl;


        }  
        //Day day() { /* Compute day from date using time.h */ return Mon; } // Not implemented



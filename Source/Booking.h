
#ifndef __BOOKING_H
#define __BOOKING_H

#include<vector>
#include<string>
#include "Date.h"
#include "Station.h"
#include "BookingClasses.h"

class Booking{
    const Station fromStation_;
    const Station toStation_;
    const Date date_;
    const BookingClass& p_;
    int fare_;

    public:
    static const double sBareFarePerKM, sACSurcharge,sLuxuryTaxPercent ; 
    static int sBookingPNRSerial;    
    static vector< Booking* >sBooking ;
    
    Booking(const Station& fromStation,const Station& toStation,const Date date,const BookingClass &p);
    ~Booking(){}
    int ComputeFare();
    int GetFare();
    friend ostream& operator<<(ostream& os, const Booking &s);
};

#endif



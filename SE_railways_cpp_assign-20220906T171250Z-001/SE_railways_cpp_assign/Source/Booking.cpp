

#include "Booking.h"
#include "BookingClasses.h"
#include<string>
#include<vector>


    
    
    
Booking::Booking(const Station& fromStation,const Station& toStation,const Date date,const BookingClass& p):
fromStation_(fromStation),toStation_(toStation),date_(date),p_(p)
{
    // Booking ::sBookingPNRSerial++;
    sBooking.push_back(this);
    ComputeFare();
}


int Booking:: ComputeFare(){
    int distance ;
    if(fromStation_.GetName()== toStation_.GetName())
    return 0 ;
    distance = Railways::IndianRailways().GetDistance(fromStation_,toStation_);
    int baseFare = distance*sBareFarePerKM;
    int laodedFare = baseFare*(p_.GetLoadFactor());
    if(p_.IsAC() == true)
    fare_ = laodedFare + sACSurcharge;
    else
    fare_  = laodedFare;
    return fare_;
}

int Booking :: GetFare(){
    return fare_;
}
 ostream& operator<<(ostream& os, const Booking &s){
    os<<"PNR Number = "<<++s.sBookingPNRSerial<<"\n";
    os<<"From Station = "<<s.fromStation_<<"\n";
    os<<"To Station = "<<s.toStation_<<"\n";
    os<<"Travel Date = "<<s.date_<<"\n";
    os<<"Travel Class = "<<s.p_.GetName()<<"\n";
    if(s.p_.IsSitting()!=1)
        os<<"  : Mode : Sleeping\n";
    else
        os<<"  : Mode : Sitting\n";

    if(s.p_.IsAC()!=1)
        os<<"  : Comfort : Non-AC\n";
    else
        os<<"  : Comfort : AC\n";

    os<<"  : Bunks : "<<s.p_.GetNumberOfTiers()<<"\n";
    if(s.p_.IsLuxury()!=0)
        os<<"  : Luxury : No\n";
    else
        os<<"  : Luxury : Yes\n" ;
    os<<"Fare = "<<s.fare_<<"\n\n\n";    

    return os;
}


const double Booking :: sBareFarePerKM = 0.50;
int Booking::sBookingPNRSerial =0;
const double Booking ::sACSurcharge = 50.00;
const double Booking ::sLuxuryTaxPercent = 25;
vector< Booking* >Booking::sBooking ;






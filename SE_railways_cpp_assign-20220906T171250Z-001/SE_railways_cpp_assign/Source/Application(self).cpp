
#include "Railways.h"
#include "BookingClasses.h"
#include "Station.h"
#include "Date.h"
#include "Booking.h"
#include<string>
#include<vector>

//test application for booking class
void BookinApplicationSelf(){
    //booking by diffrent booking classes

    //<BookingClasses>::Type() returns the constant object of the respective type
    //two stations are fare should be zero
    Booking b1(Station("Mumbai"), Station("Mumbai"), Date(12, 5, 2021), ACFirstClass::Type());
    if(b1.GetFare() == 0)
    cout<<("fare for two same stations is 0.\n\n");

    //two stations are swapped fare should be same
    Booking b2(Station("Kolkata"), Station("Delhi"), Date(13, 6, 2021), AC2Tier::Type());
    Booking b3(Station("Delhi"), Station("Kolkata"), Date(17, 7, 2021), AC2Tier::Type());
    if(b2.GetFare()== b3.GetFare())
    cout<<"Fare is same, stations are swapped given bookingclass is same ,date may be different\n\n";

    Booking b4(Station("Mumbai"), Station("Delhi"), Date(23, 8, 2021), AC3Tier::Type());
    Booking b5(Station("Chennai"), Station("Delhi"), Date(15, 9, 2021), ACChairCar::Type());
    Booking b6(Station("Chennai"), Station("Kolkata"), Date(7, 10, 2021), Sleeper::Type());
    Booking b7(Station("Mumbai"), Station("Delhi"), Date(20, 11, 2021), SecondSitting::Type());
    Booking b8(Station("Delhi"), Station("Mumbai"), Date(22, 5, 2021), FirstClass::Type());
    Booking b9(Station("Kolkata"), Station("Bengalore"), Date(22, 5, 2021), ACChairCar::Type());
    Booking b10(Station("Bangalore"), Station("chennai"), Date(22, 5, 2021), AC2Tier::Type());
    Booking b11(Station("Delhi"), Station("Bangalore"), Date(22, 5, 2021), SecondSitting::Type());
    //Output the booking done where sBooking is the collection of Bookings done 
    vector<Booking*>::iterator it;
    for(it = Booking::sBooking.begin(); it<Booking:: sBooking.end();++it){
        cout<<*(*it);

    }
    return ;

}
int main(){
    BookinApplicationSelf();
    return 0;
}
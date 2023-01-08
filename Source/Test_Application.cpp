
#include "Railways.h"
#include "BookingClasses.h"
#include "Station.h"
#include "Date.h"
#include "Booking.h"
#include<string>
#include<vector>

//test application for booking class
void BookinApplication(){
    //booking by diffrent booking classes

    //<BookingClasses>::Type() returns the constant object of the respective type

    Booking b1(Station("Mumbai"), Station("Delhi"), Date(15, 2, 2021), ACFirstClass::Type());
    Booking b2(Station("Kolkata"), Station("Delhi"), Date(5, 3, 2021), AC2Tier::Type());
    Booking b3(Station("Mumbai"), Station("Kolkata"), Date(17, 3, 2021), FirstClass::Type());
    Booking b4(Station("Mumbai"), Station("Delhi"), Date(23, 3, 2021), AC3Tier::Type());
    Booking b5(Station("Chennai"), Station("Delhi"), Date(25, 4, 2021), ACChairCar::Type());
    Booking b6(Station("Chennai"), Station("Kolkata"), Date(7, 5, 2021), Sleeper::Type());
    Booking b7(Station("Mumbai"), Station("Delhi"), Date(19, 5, 2021), SecondSitting::Type());
    Booking b8(Station("Delhi"), Station("Mumbai"), Date(22, 5, 2021), SecondSitting::Type());


    //Output the booking done where sBooking is the collection of Bookings done 
    vector<Booking*>::iterator it;
    for(it = Booking::sBooking.begin(); it<Booking:: sBooking.end();++it){
        cout<<*(*it);

    }
    return ;

}
int main(){
    BookinApplication();
    return 0;
}
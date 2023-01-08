//19CS30019 Girish Kumar
#include "Railways.h"
#include "BookingClasses.h"
#include "Station.h"
#include "Date.h"
#include "Booking.h"
#include<string>
#include<vector>

void unitTest(){
    // Station::unitTestStation();
    Date::unitTestDate();
    Railways::unitTestRailways();
    AC2Tier::unitTestAC2Tier();
    AC3Tier::unitTestAC3Tier();
    ACFirstClass::unitTestACFirstClass();
    SecondSitting::unitTestSecondSitting();
    FirstClass::unitTestFirstClass();
    Sleeper::unitTestSleeper();
}

int main(){
    unitTest();
    cout<<"if nothing is printed unit test is passed\n";
    return 0 ;
}

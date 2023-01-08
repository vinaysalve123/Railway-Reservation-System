#ifndef __DATE_H
#define __DATE_H
using namespace std;
// char monthNames[][4] = { "Jan", "Feb", "Mar", "Apr", "May", "Jun","Jul", "Aug", "Sep", "Oct", "Nov", "Dec" };
// char dayNames[][10] = { "Monday", "Tuesday", "Wednesday", "Thursday","Friday", "Saturday", "Sunday" };
class Date {
    enum Month { Jan = 1, Feb, Mar, Apr, May, Jun, Jul, Aug, Sep, Oct, Nov, Dec };
    // enum Day { Mon, Tue, Wed, Thr, Fri, Sat, Sun };
    typedef unsigned int UINT;
    UINT date_;    
    Month month_; 
    UINT year_;

    public:
        Date(UINT d, UINT m, UINT y);
        ~Date(){}
        // void print() ;
        // bool validDate() ;
        friend ostream& operator<<(ostream &os, const Date& d) ;
        static void unitTestDate();
        //Day day() { /* Compute day from date using time.h */ return Mon; } // Not implemented
};
#endif
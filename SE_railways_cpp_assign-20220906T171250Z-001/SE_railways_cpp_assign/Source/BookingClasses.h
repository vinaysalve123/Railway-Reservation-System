#ifndef __BOOKINGCLASSES_H
#define __BOOKINGCLASSES_H
#include<string>
using namespace std;
// #include<iostream>
// using namespace std;

class BookingClass{
    protected:
    string name_;
    double FareLoadFactor_;  
    const string seat;        
    const int AC;
    const int NoTiers;        
    const int Luxury ; 

public:
    BookingClass(const string& name,double FLF,const string& seat,const int& ac,const int& tier,const int& lx);
    virtual ~BookingClass(){}
    
    
    virtual double GetLoadFactor() const = 0;
    virtual string GetName()const =0;
    virtual bool IsSitting()const =0;
    virtual bool IsAC()const =0;
    virtual int GetNumberOfTiers()const=0;
    virtual bool IsLuxury() const =0;
    static void unitTestBookingclass();
};




class Seat : public BookingClass{
protected:
    Seat(const string& name,double FLF,const string& seat,const int& ac,const int& tier,const int& lx);
    virtual ~Seat(){}
public:
    static const string sName;
    virtual bool IsSitting()const{return 1;}  
    static void unitTestSeat();     
};




class Berth : public BookingClass{
protected:
    Berth(const string& name,double FLF,const string& seat,const int& ac,const int& tier,const int& lx);
    virtual ~Berth(){}
    
public:
    static const string sName;
    bool IsSitting() const{return 0;}
    static void unitTestBerth();
    
};




//tier 0 for sitting class
class Tier0:public Seat{
    protected:
    Tier0(const string& name,double FLF,const string& seat,const int& ac,const int& tier,const int& lx);
    virtual ~Tier0(){}
    static const int sTier;     //static constant for number of tiers = 0
    public:

    int GetNumberOfTiers() const; 
    static void unitTestTier0();
};
 



//berth has two derived classes tier 2 and tier 3
class Tier2:public Berth{
protected:
    Tier2(const string& name,double FLF,const string& seat,const int& ac,const int& tier,const int& lx);
    virtual ~Tier2(){}
        
public:
    static const int sTier;
    int GetNumberOfTiers()const;
    static void unitTestTier2();
};





// berth class derived tier 3
class Tier3:public Berth{
protected:
    Tier3(const string& name,double FLF,const string& seat,const int& ac,const int& tier,const int& lx);
    virtual ~Tier3(){}        
public:
    static const int sTier;
    int GetNumberOfTiers()const;
    static void unitTestTier3();
};




// tier 0 has two derived class AC CHAIR CAR and second sitting 
class ACChairCar: public Tier0{
    ACChairCar(const string& name,double FLF,const string& seat,const int& ac,const int& tier,const int& lx);
public:
    ~ACChairCar(){}
    static const BookingClass& Type();
    bool IsAC()const{return true;}
    double GetLoadFactor() const {
        return FareLoadFactor_;
    }
    string GetName()const{
        return name_;
    }
    bool IsLuxury() const{
        return false ;
    }
    static void unitTestACChairCar();
};



////// ********** second sitting ************//////////
class SecondSitting: public Tier0{
    SecondSitting(const string& name,double FLF,const string& seat,const int& ac,const int& tier,const int& lx);

    public:
    ~SecondSitting(){}
    static const BookingClass& Type();
    bool IsAC()const{
        return false;
    }
    double GetLoadFactor() const {
        return FareLoadFactor_;
    }
    string GetName()const{
        return name_;
    }
    bool IsLuxury()const {
        return false ;
    }
    static void unitTestSecondSitting();
};



//////////******** AC First Class **********//////////
class ACFirstClass : public Tier2{
    ACFirstClass(const string& name,double FLF,const string& seat,const int& ac,const int& tier,const int& lx);
    
    public:
        ~ACFirstClass(){}
        static const BookingClass& Type();
        bool IsAC()const{
            return true;
        }
        double GetLoadFactor() const {
            return FareLoadFactor_;
        }
        string GetName()const{
            return name_;
        }
        bool IsLuxury()const {
            return true ;
        }
        static void unitTestACFirstClass();
};



////////// ********* AC 2 Tier ***********//////////////
class AC2Tier : public Tier2{
    AC2Tier(const string& name,double FLF,const string& seat,const int& ac,const int& tier,const int& lx);
    
    public:
        ~AC2Tier(){}
        static const BookingClass& Type();
        bool IsAC()const{
            return true;
        }
        double GetLoadFactor() const {
            return FareLoadFactor_;
        }
        string GetName()const{
            return name_;
        }
        bool IsLuxury()const {
            return false ;
        }
    static void unitTestAC2Tier();
};

//////////********* First class **********//////////

class FirstClass : public Tier2{
    FirstClass(const string& name,double FLF,const string& seat,const int& ac,const int& tier,const int& lx);
    
public:
    ~FirstClass(){}
    static const BookingClass& Type();
    bool IsAC() const{
        return false;
    }
    double GetLoadFactor() const {
        return FareLoadFactor_;
    }
    string GetName()const{
        return name_;
    }
    bool IsLuxury() const{
        return true ;
    }
    static void unitTestFirstClass();
};



// ////////******** AC 3 Tier **********////////

class AC3Tier : public Tier3{
    AC3Tier(const string& name,double FLF,const string& seat,const int& ac,const int& tier,const int& lx);
    
public:
    ~AC3Tier(){}
    static const BookingClass& Type();
    bool IsAC()const{
        return true;
    }
    double GetLoadFactor() const{
        return FareLoadFactor_;
    }
    string GetName() const{
        return name_;
    }
    bool IsLuxury() const
    {
        return false ;
    }
    static void unitTestAC3Tier();
};


//////////******** Sleeper ****** ///////////
class Sleeper : public Tier3{
    Sleeper(const string& name,double FLF,const string& seat,const int& ac,const int& tier,const int& lx);
    
public:
    ~Sleeper(){}
    static const BookingClass& Type();
    bool IsAC() const{
        return false;
    }
    double GetLoadFactor()const {
        return FareLoadFactor_;
    }
    string GetName() const{
        return name_;
    }
    bool IsLuxury() const {
        return false ;
    }
    static void unitTestSleeper();
};



// int main()
// {
//     const  BookingClass  *p;
//     p = ACChairCar::Type();
//     cout<<(p->GetLoadFactor())<<endl;
//     cout<<(p->GetName());
//     return 0;

// }
#endif
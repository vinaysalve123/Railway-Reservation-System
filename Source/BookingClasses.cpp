
#include "BookingClasses.h"
#include<string>

#include<iostream>
using namespace std;

 
    BookingClass::BookingClass(const string& name,double FLF,const string& seat,const int& ac,const int& tier,const int& lx): 
    name_(name),FareLoadFactor_(FLF),seat(seat),AC(ac),NoTiers(tier),Luxury(lx){}
    


    Seat::Seat(const string& name,double FLF,const string& seat,const int& ac,const int& tier,const int& lx):BookingClass(name ,FLF,sName,ac,tier,lx){}
    
    const string Seat ::sName ="Sitting";

    Berth ::Berth(const string& name,double FLF,const string& seat,const int& ac,const int& tier,const int& lx):BookingClass(name,FLF,sName,ac,tier,lx){}
    
    const string Berth ::sName = "Sleeping";
    

        





    Tier0::Tier0(const string& name,double FLF,const string& seat,const int& ac,const int& tier,const int& lx):Seat(name,FLF,Seat::sName,ac,Tier0::sTier,lx){}
    
    int Tier0::GetNumberOfTiers()const{return 0;}
    const int Tier0::sTier = 0;

//berth has two derived classes tier 2 and tier 3

    Tier2::Tier2(const string& name,double FLF,const string& seat,const int& ac,const int& tier,const int& lx):Berth(name,FLF,Berth::sName,ac,Tier2::sTier,lx){}
    
   
    int Tier2::GetNumberOfTiers()const{return 2;}
    const int Tier2::sTier = 2;


// berth class derived tier 3

    Tier3::Tier3(const string& name,double FLF,const string& seat,const int& ac,const int& tier,const int& lx):Berth(name,FLF,Seat::sName,ac,Tier3::sTier,lx){}
    
    int Tier3:: GetNumberOfTiers() const {return 3;}
    const int Tier3::sTier = 3;
    

// tier 0 has two derived class AC CHAIR CAR and second sitting 


    ACChairCar::ACChairCar(const string& name,double FLF,const string& seat,const int& ac,const int& tier,const int& lx):
    Tier0(name,FLF,Seat::sName,ac,Tier0::sTier,lx){}
    
    const BookingClass& ACChairCar:: Type(){
        static const ACChairCar obj("AC Chair Car",3.00,Seat::sName,1,0,0);
        return obj;
    }
    
    void ACChairCar::unitTestACChairCar(){
        const BookingClass& p = ACChairCar::Type();
        
        if(p.GetName()!="AC Chair Car")
        cout<< "Error in get name in AC CHair car"<<endl;
        if(p.GetLoadFactor()!=1.25)
        cout<<"Error in GetLoad Factor in AC CHair car"<<endl;
        if(p.GetNumberOfTiers()!=0)
        cout<<"Error in Get no of tiers in AC CHair car"<<endl; 
        if(p.IsAC()!=false)
        cout<<"Error in  Is AC in AC CHair car"<<endl;
        if(p.IsLuxury()!=false)
        cout<<"Error in Is Luxury in AC CHair car"<<endl;
        if(p.IsSitting()!=1)
        cout<<"Error in Is sitting in AC CHair car"<<endl;
        


    }
    

////// ********** second sitting ************//////////


    SecondSitting::SecondSitting(const string& name,double FLF,const string& seat,const int& ac,const int& tier,const int& lx): Tier0(name,FLF,Seat::sName,ac,Tier0::sTier,lx){}
    
    const BookingClass&SecondSitting:: Type(){
        static const SecondSitting obj("Second Sitting",0.50,Seat::sName,0,0,0);
        return obj;
    }
    
    void SecondSitting::unitTestSecondSitting(){
        const BookingClass& p = SecondSitting::Type();
        
        if(p.GetName()!="Second Sitting")
        cout<< "Error in get name in Second Sitting"<<endl;
        if(p.GetLoadFactor()!=0.50)
        cout<<"Error in GetLoad Factor in Second Sitting"<<endl;
        if(p.GetNumberOfTiers()!=0)
        cout<<"Error in Get no of tiers in Second Sitting"<<endl; 
        if(p.IsAC()!=false)
        cout<<"Error in  Is AC in Second Sitting"<<endl;
        if(p.IsLuxury()!=false)
        cout<<"Error in Is Luxury in Second Sitting"<<endl;
        if(p.IsSitting()!=1)
        cout<<"Error in Is sitting in Second Sitting"<<endl;
        


    }

//////////******** AC First Class **********//////////

    ACFirstClass:: ACFirstClass(const string& name,double FLF,const string& seat,const int& ac,const int& tier,const int& lx):Tier2(name,FLF,Berth::sName,ac,Tier2::sTier,lx){}
    
        const BookingClass& ACFirstClass::Type(){
            static const ACFirstClass obj("AC First Class",3.00,Berth::sName,1,Tier2::sTier,1);
            return obj;
        }
    void ACFirstClass::unitTestACFirstClass(){
        const BookingClass& p = ACFirstClass::Type();
        
        if(p.GetName()!="AC First Class")
        cout<< "Error in get name in AC First Class"<<endl;
        if(p.GetLoadFactor()!=3.00)
        cout<<"Error in GetLoad Factor in AC First Class"<<endl;
        if(p.GetNumberOfTiers()!=2)
        cout<<"Error in Get no of tiers in AC First Class"<<endl; 
        if(p.IsAC()!=true)
        cout<<"Error in  Is AC in AC First Class"<<endl;
        if(p.IsLuxury()!=true)
        cout<<"Error in Is Luxury in AC First Class"<<endl;
        if(p.IsSitting()!=0)
        cout<<"Error in Is sitting in AC First Class"<<endl;
        


    }

////////// ********* AC 2 Tier ***********//////////////

    AC2Tier::AC2Tier(const string& name,double FLF,const string& seat,const int& ac,const int& tier,const int& lx):Tier2(name,FLF,Berth::sName,ac,Tier2::sTier,lx){}
    
        const BookingClass& AC2Tier:: Type(){
            static const AC2Tier obj("AC 2 Tier",2.00,Berth::sName,1,Tier2::sTier,1);
            return obj;
        }
        void AC2Tier::unitTestAC2Tier(){
        const BookingClass& p = AC2Tier::Type();
        
        if(p.GetName()!="AC 2 Tier")
        cout<< "Error in get name"<<endl;
        if(p.GetLoadFactor()!=2.00)
        cout<<"Error in GetLoad Factor in AC2Tier "<<endl;
        if(p.GetNumberOfTiers()!=2)
        cout<<"Error in Get no of tiers in AC2Tier"<<endl; 
        if(p.IsAC()!=true)
        cout<<"Error in  Is AC in AC2Tier"<<endl;
        if(p.IsLuxury()!=false)
        cout<<"Error in Is Luxury in AC2Tier"<<endl;
        if(p.IsSitting()!=0)
        cout<<"Error in Is sitting in AC2Tier"<<endl;
        


    }



//////////********* First class **********//////////

    FirstClass::FirstClass(const string& name,double FLF,const string& seat,const int& ac,const int& tier,const int& lx):Tier2(name,FLF,Berth::sName,ac,Tier2::sTier,lx){}
    
        const BookingClass& FirstClass:: Type(){
            static const FirstClass obj("First Class",2.00,Berth::sName,0,Tier2::sTier,1);
            return obj;
        }
        void FirstClass::unitTestFirstClass(){
        const BookingClass& p = FirstClass::Type();
        
        if(p.GetName()!="First Class")
        cout<< "Error in get name in FirstClass"<<endl;
        if(p.GetLoadFactor()!=2.00)
        cout<<"Error in GetLoad Factor in FirstClas"<<endl;
        if(p.GetNumberOfTiers()!=2)
        cout<<"Error in Get no of tiers in FirstClas"<<endl; 
        if(p.IsAC()!=false)
        cout<<"Error in  Is AC in FirstClas"<<endl;
        if(p.IsLuxury()!=true)
        cout<<"Error in Is Luxury in FirstClas"<<endl;
        if(p.IsSitting()!=0)
        cout<<"Error in Is sitting in FistClas"<<endl;
       


    }




////////******** AC 3 Tier **********////////

AC3Tier::AC3Tier(const string& name,double FLF,const string& seat,const int& ac,const int& tier,const int& lx):Tier3(name,FLF,Berth::sName,ac,Tier3::sTier,lx){}
    
         const BookingClass& AC3Tier::Type(){
            static const AC3Tier obj("AC 3 Tier",1.75,Berth::sName,1,Tier3::sTier,0);
            return obj;
        }
        void AC3Tier::unitTestAC3Tier(){
        const BookingClass& p = AC3Tier::Type();
        
        if(p.GetName()!="AC 3 Tier")
        cout<< "Error in get name in AC 3 Tier"<<endl;
        if(p.GetLoadFactor()!=1.75)
        cout<<"Error in GetLoad Factor in AC 3 Tier"<<endl;
        if(p.GetNumberOfTiers()!=3)
        cout<<"Error in Get no of tiers in AC 3 Tier"<<endl; 
        if(p.IsAC()!=true)
        cout<<"Error in  Is AC in AC 3 Tier"<<endl;
        if(p.IsLuxury()!=false)
        cout<<"Error in Is Luxury in AC 3 Tier"<<endl;
        if(p.IsSitting()!=0)
        cout<<"Error in Is sitting in AC 3 Tier"<<endl;
        


    }




//////////******** Sleeper ****** ///////////

    Sleeper::Sleeper(const string& name,double FLF,const string& seat,const int& ac,const int& tier,const int& lx):Tier3(name,FLF,Berth::sName,ac,Tier3::sTier,lx){}
    
        const BookingClass& Sleeper:: Type(){
            static const Sleeper obj("Sleeper",1.00,Berth::sName,0,Tier3::sTier,0);
            return obj;
        }
    void Sleeper::unitTestSleeper(){
        const BookingClass& p = Sleeper::Type();
        
        if(p.GetName()!="Sleeper")
        cout<< "Error in get name in Sleeper"<<endl;
        if(p.GetLoadFactor()!=1.00)
        cout<<"Error in GetLoad Factor in Sleeper "<<endl;
        if(p.GetNumberOfTiers()!=3)
        cout<<"Error in Get no of tiers in Sleeper"<<endl; 
        if(p.IsAC()!=false)
        cout<<"Error in  Is AC in Sleeper"<<endl;
        if(p.IsLuxury()!=false)
        cout<<"Error in Is Luxury in Sleeper"<<endl;
        if(p.IsSitting()!=0)
        cout<<"Error in Is sitting in Sleeper"<<endl;
       


    }






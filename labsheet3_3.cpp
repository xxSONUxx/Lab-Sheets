// 3.Create a class called carpark that has int data member for car id, int data member for charge/hour, and float data member for the parked time. Make functions to set data members and show the charges and parked hours of the corresponding car id. Make functions for setting and showing the data members. Member function should be called from other functions

#include<iostream>
using namespace std;
class carpark{
    private:
        int carid,chargeperhour;
        float parkedtime;
    
    public:
        setdata()
            {
            cout<<"Enter car id" <<endl;
            cin>>carid;
            cout<<"Enter charge per hour" <<endl;
            cin>>chargeperhour;
            cout<<"Enter parked time" <<endl;
            cin>>parkedtime;
            return 0;
            }
        getdata()
            {
            cout<<"Your car id is "<<carid <<" with charge per hour "<<chargeperhour<<" with parked time "<<parkedtime <<".";
            return 0;
            }
};

void callingfunction(carpark x){
    x.setdata();
    x.getdata();

}

int main()
{
    carpark c;
    // carpark c;
    callingfunction(c);
    return 0;
}
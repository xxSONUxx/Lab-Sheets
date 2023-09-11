//1.Write a program that can convert the Distance (meter, centimeter) to meters measurement in float and vice versa. Make a class distance with two data members, meter and centimeter. You can add function members as per your requirement.

#include<iostream>
using namespace std;

class conversion{
    private:
    float m;
    float cm;
    float x,y;

    public:
    
    getdata(){
        cout<<"Please enter the distance in meters :"<<endl;
        cin>>m;
        cout<<"Please enter the distance in centi-meters :"<<endl;
        cin>>cm;
        return 0;
    }

    toMeters(){
        x = m + (cm/100);
        return x;

    }

    toCentimeters(){
        y = (m*100)+cm;
        return y;
        
    }

    showdata(){
        cout<<"Your disntace in meters is :" <<x <<endl;
        cout<<"Your disntace in centi-meters is :" <<y <<endl;
        return 0;
    }




};

int main()
{
    conversion c;
    c.getdata();
    c.toMeters();
    c.toCentimeters();
    c.showdata();
    
    return 0;
}
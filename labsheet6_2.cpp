//2.Write two classes to store distances in meter-centimeter and feet-inch systems respectively. Write conversions functions so that the program can convert objects of both types.

#include<iostream>
using namespace std;

class x{
    private:
    float m,cm;
    float m1,cm1;

    public:

    void getdata(){
        cout<<"please enter the distance in meters :"<<endl;
        cin>>m;
        cout<<"please enter the distance in centi-meters :"<<endl;
        cin>>cm;
    }

    toMeters(){
        m1 = m + (cm/100);
        return m1;
    }
    toCentiMeters(){
        cm1 = (m*100) + cm;
        return cm1;
    }

    void showdata(){
        cout<<"Your converted distance in meters is :"<<toMeters() <<endl;
        cout<<"Your converted distance in centi-meters is :"<<toCentiMeters() <<endl;

    }

};

class y{
    private:
    float feet,inch;
    float f1,i1;

    public :
    void getdata(){
        cout<<"Please enter your distance in feets :"<<endl;
        cin>>feet;
        cout<<"Please enter your distance in inches :"<<endl;
        cin>>inch;
    }
    toFeets(){
        f1 = feet + (inch/12);
        return f1;

    }

    toInches(){
        i1 = (feet*12) + inch; 
        return i1;

    }
    void showdata(){
        cout<<"Your converted distance in different parameters are :"<<endl;
        cout<<"Your converted distance is :"<<toFeets() <<"feets."<<endl;
        cout<<"Your converted distance is :"<<toInches() <<"inches."<<endl;
    }

};

int main()
{
    x x1;
    y y1;
    x1.getdata();
    x1.showdata();
    y1.getdata();
    y1.showdata();

    
    return 0;
}
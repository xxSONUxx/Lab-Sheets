// 4. Create a polymorphic class Vehicle and create other derived classes Bus, Car, and Bike from Vehicle. Illustrate RTTI by the use of dynamic_cast and typeid operators in this program.

#include <iostream>
#include <typeinfo>

using namespace std;

class Vehicle {
public:
    virtual void displayInfo() const {
        cout << "This is a generic vehicle." << endl;
    }
};

class Bus : public Vehicle {
public:
    void displayInfo() const override {
        cout << "This is a bus." << endl;
    }
};

class Car : public Vehicle {
public:
    void displayInfo() const override {
        cout << "This is a car." << endl;
    }
};

class Bike : public Vehicle {
public:
    void displayInfo() const override {
        cout << "This is a bike." << endl;
    }
};

int main() {
    Vehicle* vehicles[4];
    vehicles[0] = new Bus();
    vehicles[1] = new Car();
    vehicles[2] = new Bike();
    vehicles[3] = new Vehicle(); // Generic vehicle

    for (int i = 0; i < 4; i++) {
        if (Bus* bus = dynamic_cast<Bus*>(vehicles[i])) {
            cout << "Using dynamic_cast to check if it's a Bus: ";
            bus->displayInfo();
        } else if (Car* car = dynamic_cast<Car*>(vehicles[i])) {
            cout << "Using dynamic_cast to check if it's a Car: ";
            car->displayInfo();
        } else if (Bike* bike = dynamic_cast<Bike*>(vehicles[i])) {
            cout << "Using dynamic_cast to check if it's a Bike: ";
            bike->displayInfo();
        } else {
            cout << "Using dynamic_cast: Unknown vehicle type." << endl;
        }

        // Using typeid operator
        cout << "Using typeid operator: ";
        if (typeid(*vehicles[i]) == typeid(Bus)) {
            cout << "It's a Bus." << endl;
        } else if (typeid(*vehicles[i]) == typeid(Car)) {
            cout << "It's a Car." << endl;
        } else if (typeid(*vehicles[i]) == typeid(Bike)) {
            cout << "It's a Bike." << endl;
        } else {
            cout << "Unknown vehicle type." << endl;
        }

        delete vehicles[i];
    }

    return 0;
}

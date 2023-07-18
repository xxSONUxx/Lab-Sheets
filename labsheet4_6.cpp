// 6.Create a class with a data member to hold a "serial number" for each object created from the class. That is, the first object created will be numbered 1, the second 2, and so on by using the basic concept of static data members. Use static member function if it is useful in the program. Otherwise, make a separate program that demonstrates the use of static member function.

#include <iostream>

using namespace std;

class SerialNumberGenerator {
private:
    static int serialNumber;

public:
    SerialNumberGenerator() {
        serialNumber++;
    }

    int getSerialNumber() const {
        return serialNumber;
    }
};

int SerialNumberGenerator::serialNumber = 0;

int main() {
    SerialNumberGenerator obj1;
    SerialNumberGenerator obj2;
    SerialNumberGenerator obj3;

    cout << "Object 1 Serial Number: " << obj1.getSerialNumber() << endl;
    cout << "Object 2 Serial Number: " << obj2.getSerialNumber() << endl;
    cout << "Object 3 Serial Number: " << obj3.getSerialNumber() << endl;

    return 0;
}

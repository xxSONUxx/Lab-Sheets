//3.Write a program to compare two objects of a class that contains an integer value as its data member. Make overloading functions to overload equality(==), less than(<), greater than(>), not equal (!=), greater than or equal to (>=), and less than or equal to(<=) operators using member operator functions.

#include <iostream>
using namespace std;

class MyClass {
private:
    int value;

public:
    MyClass(int val) : value(val) {}

    // Overload the equality operator (==)
    bool operator==(const MyClass& other) const {
        return value == other.value;
    }

    // Overload the less than operator (<)
    bool operator<(const MyClass& other) const {
        return value < other.value;
    }

    // Overload the greater than operator (>)
    bool operator>(const MyClass& other) const {
        return value > other.value;
    }

    // Overload the not equal operator (!=)
    bool operator!=(const MyClass& other) const {
        return value != other.value;
    }

    // Overload the greater than or equal to operator (>=)
    bool operator>=(const MyClass& other) const {
        return value >= other.value;
    }

    // Overload the less than or equal to operator (<=)
    bool operator<=(const MyClass& other) const {
        return value <= other.value;
    }

    int getValue() const {
        return value;
    }
};

int main() {
    using namespace std;

    MyClass obj1(5);
    MyClass obj2(10);

    cout << "obj1: " << obj1.getValue() << endl;
    cout << "obj2: " << obj2.getValue() << endl;

    // Comparison using overloaded operators
    if (obj1 == obj2) {
        cout << "obj1 is equal to obj2" << endl;
    } else {
        cout << "obj1 is not equal to obj2" << endl;
    }

    if (obj1 < obj2) {
        cout << "obj1 is less than obj2" << endl;
    } else {
        cout << "obj1 is not less than obj2" << endl;
    }

    if (obj1 > obj2) {
        cout << "obj1 is greater than obj2" << endl;
    } else {
        cout << "obj1 is not greater than obj2" << endl;
    }

    if (obj1 != obj2) {
        cout << "obj1 is not equal to obj2" << endl;
    } else {
        cout << "obj1 is equal to obj2" << endl;
    }

    if (obj1 >= obj2) {
        cout << "obj1 is greater than or equal to obj2" << endl;
    } else {
        cout << "obj1 is not greater than or equal to obj2" << endl;
    }

    if (obj1 <= obj2) {
        cout << "obj1 is less than or equal to obj2" << endl;
    } else {
        cout << "obj1 is not less than or equal to obj2" << endl;
    }

    return 0;
}

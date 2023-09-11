//2.Write a class to store x, y, and z coordinates of a point in three-dimensional space. Overload addition and subtraction operators for addition and subtraction of two coordinate objects. Implement the operator functions as non-member functions (friend operator functions).

#include <iostream>
using namespace std;

class Point3D {
private:
    double x;
    double y;
    double z;

public:
    Point3D(double xCoord = 0.0, double yCoord = 0.0, double zCoord = 0.0)
        : x(xCoord), y(yCoord), z(zCoord) {}

    // Friend function declaration for addition
    friend Point3D operator+(const Point3D& p1, const Point3D& p2);

    // Friend function declaration for subtraction
    friend Point3D operator-(const Point3D& p1, const Point3D& p2);

    void display() const {
        cout << "Point (" << x << ", " << y << ", " << z << ")" << endl;
    }
};

// Definition of the friend function for addition
Point3D operator+(const Point3D& p1, const Point3D& p2) {
    return Point3D(p1.x + p2.x, p1.y + p2.y, p1.z + p2.z);
}

// Definition of the friend function for subtraction
Point3D operator-(const Point3D& p1, const Point3D& p2) {
    return Point3D(p1.x - p2.x, p1.y - p2.y, p1.z - p2.z);
}

int main() {
    using namespace std;

    Point3D p1(2.5, 3.5, 4.5);
    Point3D p2(1.5, 2.5, 3.5);

    // Demonstrate addition using the friend function
    Point3D sum = p1 + p2;
    cout << "Sum: ";
    sum.display();

    // Demonstrate subtraction using the friend function
    Point3D difference = p1 - p2;
    cout << "Difference: ";
    difference.display();

    return 0;
}

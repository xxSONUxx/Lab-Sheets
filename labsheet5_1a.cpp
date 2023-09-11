//1.Write a class for instantiating the objects that represent the two-dimensional Cartesian coordinate system.

//A.Make a particular member function of one class as a friend function of another class for addition

#include <iostream>
using namespace std;

class Point {
private:
    double x;
    double y;

public:
    Point(double xCoord = 0.0, double yCoord = 0.0) : x(xCoord), y(yCoord) {}

    // Friend function declaration for addition
    friend Point operator+(const Point& p1, const Point& p2);

    void display() const {
        cout << "Point (" << x << ", " << y << ")" << endl;
    }
};

// Definition of the friend function for addition
Point operator+(const Point& p1, const Point& p2) {
    return Point(p1.x + p2.x, p1.y + p2.y);
}

int main() {
    Point p1(2.5, 3.5);
    Point p2(1.5, 2.5);

    // Demonstrate addition using the friend function
    Point sum = p1 + p2;
    cout << "Sum: ";
    sum.display();

    return 0;
}

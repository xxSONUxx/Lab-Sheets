// B.Make the other three functions to work as a bridge between the classes for multiplication, division, and subtraction.

#include <iostream>
using namespace std;

class Point
{
private:
    double x;
    double y;

public:
    Point(double xCoord = 0.0, double yCoord = 0.0) : x(xCoord), y(yCoord) {}

    // Friend function declaration for addition
    friend Point operator+(const Point &p1, const Point &p2);

    // Member functions to work as a bridge for multiplication, division, and subtraction
    Point multiply(const Point &other) const;
    Point divide(const Point &other) const;
    Point subtract(const Point &other) const;

    void display() const
    {
        cout << "Point (" << x << ", " << y << ")" << endl;
    }
};

// Definition of the friend function for addition
Point operator+(const Point &p1, const Point &p2)
{
    return Point(p1.x + p2.x, p1.y + p2.y);
}

// Member function definition for multiplication
Point Point::multiply(const Point &other) const
{
    return Point(x * other.x, y * other.y);
}

// Member function definition for division
Point Point::divide(const Point &other) const
{
    return Point(x / other.x, y / other.y);
}

// Member function definition for subtraction
Point Point::subtract(const Point &other) const
{
    return Point(x - other.x, y - other.y);
}

int main()
{
    using namespace std;

    Point p1(2.5, 3.5);
    Point p2(1.5, 2.5);

    // Demonstrate addition using the friend function
    Point sum = p1 + p2;
    cout << "Sum: ";
    sum.display();

    // Demonstrate multiplication, division, and subtraction
    Point product = p1.multiply(p2);
    Point quotient = p1.divide(p2);
    Point difference = p1.subtract(p2);

    cout << "Product: ";
    product.display();

    cout << "Quotient: ";
    quotient.display();

    cout << "Difference: ";
    difference.display();

    return 0;
}

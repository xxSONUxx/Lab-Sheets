// 1.Write a program to create a class shape with functions to find the area of the shapes and display the names of the shapes and other essential components of the class. Create derived classes circle, rectangle, and trapezoid each having overriding functions area() and display(). Write a suitable program to illustrate virtual functions and virtual destructors.

#include <iostream>
#include <string>

using namespace std;

class Shape {
protected:
    string name;

public:
    Shape(const string& n) : name(n) {}

    virtual double area() const = 0;
    virtual void display() const {
        cout << "Shape: " << name << endl;
    }

    virtual ~Shape() {
        cout << "Destroying Shape: " << name << endl;
    }
};

class Circle : public Shape {
private:
    double radius;

public:
    Circle(const string& n, double r) : Shape(n), radius(r) {}

    double area() const override {
        return 3.14159 * radius * radius;
    }

    void display() const override {
        Shape::display();
        cout << "Type: Circle" << endl;
        cout << "Radius: " << radius << endl;
    }

    ~Circle() override {
        cout << "Destroying Circle: " << name << endl;
    }
};

class Rectangle : public Shape {
private:
    double length;
    double width;

public:
    Rectangle(const string& n, double l, double w) : Shape(n), length(l), width(w) {}

    double area() const override {
        return length * width;
    }

    void display() const override {
        Shape::display();
        cout << "Type: Rectangle" << endl;
        cout << "Length: " << length << endl;
        cout << "Width: " << width << endl;
    }

    ~Rectangle() override {
        cout << "Destroying Rectangle: " << name << endl;
    }
};

class Trapezoid : public Shape {
private:
    double base1;
    double base2;
    double height;

public:
    Trapezoid(const string& n, double b1, double b2, double h) : Shape(n), base1(b1), base2(b2), height(h) {}

    double area() const override {
        return 0.5 * (base1 + base2) * height;
    }

    void display() const override {
        Shape::display();
        cout << "Type: Trapezoid" << endl;
        cout << "Base1: " << base1 << endl;
        cout << "Base2: " << base2 << endl;
        cout << "Height: " << height << endl;
    }

    ~Trapezoid() override {
        cout << "Destroying Trapezoid: " << name << endl;
    }
};

int main() {
    Shape* shapes[3];
    shapes[0] = new Circle("Circle1", 10.0);
    shapes[1] = new Rectangle("Rectangle1", 5.0, 8.0);
    shapes[2] = new Trapezoid("Trapezoid1", 8.0, 10.0, 12.0);

    for (int i = 0; i < 3; i++) {
        shapes[i]->display();
        cout << "Area: " << shapes[i]->area() << endl;
        delete shapes[i];
        cout << endl;
    }

    return 0;
}

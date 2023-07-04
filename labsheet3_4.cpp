// 4.Write a program with classes to represent a circle, rectangle, and triangle. Each class should have data members to represent the actual objects and member functions to read and display objects, find perimeter and area of the objects, and other useful functions. Use the classes to create objects in your program


#include <iostream>
#include <cmath>

const double PI = 3.14159;

class Circle {
private:
    double radius;

public:
    void read() {
        std::cout << "Enter the radius of the circle: ";
        std::cin >> radius;
    }

    void display() {
        std::cout << "Circle - Radius: " << radius << std::endl;
    }

    double calculatePerimeter() {
        return 2 * PI * radius;
    }

    double calculateArea() {
        return PI * pow(radius, 2);
    }
};

class Rectangle {
private:
    double length;
    double width;

public:
    void read() {
        std::cout << "Enter the length of the rectangle: ";
        std::cin >> length;
        std::cout << "Enter the width of the rectangle: ";
        std::cin >> width;
    }

    void display() {
        std::cout << "Rectangle - Length: " << length << ", Width: " << width << std::endl;
    }

    double calculatePerimeter() {
        return 2 * (length + width);
    }

    double calculateArea() {
        return length * width;
    }
};

class Triangle {
private:
    double side1;
    double side2;
    double side3;

public:
    void read() {
        std::cout << "Enter the length of side 1 of the triangle: ";
        std::cin >> side1;
        std::cout << "Enter the length of side 2 of the triangle: ";
        std::cin >> side2;
        std::cout << "Enter the length of side 3 of the triangle: ";
        std::cin >> side3;
    }

    void display() {
        std::cout << "Triangle - Side 1: " << side1 << ", Side 2: " << side2 << ", Side 3: " << side3 << std::endl;
    }

    double calculatePerimeter() {
        return side1 + side2 + side3;
    }

    double calculateArea() {
        double s = calculatePerimeter() / 2;
        return sqrt(s * (s - side1) * (s - side2) * (s - side3));
    }
};

int main() {
    Circle circle;
    circle.read();
    circle.display();
    std::cout << "Circle Perimeter: " << circle.calculatePerimeter() << std::endl;
    std::cout << "Circle Area: " << circle.calculateArea() << std::endl;

    Rectangle rectangle;
    rectangle.read();
    rectangle.display();
    std::cout << "Rectangle Perimeter: " << rectangle.calculatePerimeter() << std::endl;
    std::cout << "Rectangle Area: " << rectangle.calculateArea() << std::endl;

    Triangle triangle;
    triangle.read();
    triangle.display();
    std::cout << "Triangle Perimeter: " << triangle.calculatePerimeter() << std::endl;
    std::cout << "Triangle Area: " << triangle.calculateArea() << std::endl;

    return 0;
}

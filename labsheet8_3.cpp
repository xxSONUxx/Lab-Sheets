// 3. Write a program to overload stream operators to read a complex number and display the complex number in a+ib format.

#include <iostream>
using namespace std;

class Complex {
private:
    double real;
    double imag;

public:
    Complex(double r = 0.0, double i = 0.0) : real(r), imag(i) {}

    // Overloading the >> operator to read a complex number
    friend istream& operator>>(istream& in, Complex& c) {
        cout << "Enter real part: ";
        in >> c.real;
        cout << "Enter imaginary part: ";
        in >> c.imag;
        return in;
    }

    // Overloading the << operator to display a complex number in a+ib format
    friend ostream& operator<<(ostream& out, const Complex& c) {
        out << c.real;
        if (c.imag >= 0)
            out << " + " << c.imag << "i";
        else
            out << " - " << -c.imag << "i";
        return out;
    }
};

int main() {
    Complex c1, c2;

    cout << "Enter the first complex number:" << endl;
    cin >> c1;

    cout << "Enter the second complex number:" << endl;
    cin >> c2;

    cout << "First complex number: " << c1 << endl;
    cout << "Second complex number: " << c2 << endl;

    return 0;
}

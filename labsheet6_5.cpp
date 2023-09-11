// 5. Write a base class that asks the user to enter a complex number and make a derived class that adds the complex number of its own with the base. Finally, make a third class that is a friend of derived and calculate the difference of the base complex number and its own complex number.

#include <iostream>

using namespace std;

class ComplexNumber {
protected:
    double real;
    double imag;

public:
    ComplexNumber() {
        cout << "Enter real part: ";
        cin >> real;
        cout << "Enter imaginary part: ";
        cin >> imag;
    }

    void display() const {
        cout << "Complex Number: " << real << " + " << imag << "i" << endl;
    }
};

class DerivedComplex : public ComplexNumber {
public:
    void addToBase(ComplexNumber& base) {
        base.real += real;
        base.imag += imag;
    }
};

class FriendComplex {
public:
    void calculateDifference(ComplexNumber& base, ComplexNumber& friendComplex) {
        double diff_real = base.real - friendComplex.real;
        double diff_imag = base.imag - friendComplex.imag;
        
        cout << "Difference: " << diff_real << " + " << diff_imag << "i" << endl;
    }
};

int main() {
    ComplexNumber baseComplex;
    DerivedComplex derivedComplex;
    FriendComplex friendComplex;

    baseComplex.display();
    derivedComplex.addToBase(baseComplex);
    baseComplex.display();
    
    friendComplex.calculateDifference(baseComplex, derivedComplex);

    return 0;
}

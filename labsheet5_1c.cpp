//C. Also write a small program to demonstrate that all the member functions of one class are the friend functions of another class if the former class is made friend to the latter.

#include <iostream>
using namespace std;

class ClassB; // Forward declaration of ClassB

class ClassA {
private:
    int valueA;

public:
    ClassA(int val) : valueA(val) {}

    // Making all member functions of ClassA friends of ClassB
    friend void addValueB(ClassB& objB, int num);
    friend void subtractValueB(ClassB& objB, int num);
    friend void displayValueB(ClassB& objB);
};

class ClassB {
private:
    

public:
    int valueB;
    ClassB(int val) : valueB(val) {}

    void display() {
        std::cout << "Value in ClassB: " << valueB << std::endl;
    }

    // Member function of ClassB to add a value
    void addValue(int num) {
        valueB += num;
    }

    // Member function of ClassB to subtract a value
    void subtractValue(int num) {
        valueB -= num;
    }
};

// Friend function definitions to access private members of ClassB
void addValueB(ClassB& objB, int num) {
    objB.valueB += num;
}

void subtractValueB(ClassB& objB, int num) {
    objB.valueB -= num;
}

void displayValueB(ClassB& objB) {
    std::cout << "Value in ClassB: " << objB.valueB << std::endl;
}

int main() {
    ClassB objB(10);

    // Use friend function to add a value to ClassB
    addValueB(objB, 5);

    // Use friend function to subtract a value from ClassB
    subtractValueB(objB, 3);

    // Use friend function to display the value of ClassB
    displayValueB(objB);

    // Access ClassB's member functions directly
    objB.addValue(2);
    objB.subtractValue(1);
    objB.display();

    return 0;
}

/*5. Write a program that illustrates the following relationship and comment on them. 

i) const_object.non_const_mem_function

ii) const_object.const_mem_function

iii) non_const_object.non_const_mem_function

iv) non_const_object.const_mem_function */


#include <iostream>

using namespace std;

class MyClass {
public:
    void nonConstMemberFunction() {
        cout << "Non-const member function called." << endl;
    }

    void constMemberFunction() const {
        cout << "Const member function called." << endl;
    }
};

int main() {
    const MyClass constObject; // Creating a const object
    MyClass nonConstObject;    // Creating a non-const object

    // i) const_object.non_const_mem_function
    // The const object cannot call non-const member functions directly.
    // This will result in a compilation error.
    // constObject.nonConstMemberFunction(); // Error: Member function cannot be called on a const object

    // ii) const_object.const_mem_function
    // The const object can call const member functions.
    constObject.constMemberFunction();

    // iii) non_const_object.non_const_mem_function
    // The non-const object can call non-const member functions directly.
    nonConstObject.nonConstMemberFunction();

    // iv) non_const_object.const_mem_function
    // The non-const object can also call const member functions.
    nonConstObject.constMemberFunction();

    return 0;
}

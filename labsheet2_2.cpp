//2.Write a program using the function overloading that converts feet to inches. Use function with no argument, one argument and two arguments. Decide yourself the types of arguments. Use pass by reference in any one of the function above.

#include <iostream>

// Function to convert feet to inches (no arguments)
int convertToInches() {
    int feet;
    std::cout << "Enter feet: ";
    std::cin >> feet;
    return feet * 12;
}

// Function to convert feet to inches (one argument)
int convertToInches(int feet) {
    return feet * 12;
}

// Function to convert feet to inches (two arguments) using pass by reference
void convertToInches(int feet, int& inches) {
    inches = feet * 12;
}

int main() {
    int feet, inches;

    // Function call with no arguments
    inches = convertToInches();
    std::cout << "Inches: " << inches << std::endl;

    // Function call with one argument
    std::cout << "Enter feet: ";
    std::cin >> feet;
    inches = convertToInches(feet);
    std::cout << "Inches: " << inches << std::endl;

    // Function call with two arguments
    std::cout << "Enter feet: ";
    std::cin >> feet;
    convertToInches(feet, inches);
    std::cout << "Inches: " << inches << std::endl;

    return 0;
}


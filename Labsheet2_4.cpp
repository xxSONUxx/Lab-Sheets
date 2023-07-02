//4.Write a function that passes two temperatures by reference and sets the larger of the two numbers to a value entered by user by using return by reference.

#include <iostream>
using namespace std;

// Function to set the larger of two temperatures to a user-defined value
double& setLargerTemperature(double& temp1, double& temp2) {
    double userInput;
    
    cout << "Enter a new temperature value: ";
    cin >> userInput;

    if (temp1 > temp2) {
        if (userInput > temp1) 
        {
            temp1 = userInput;
        }
    } 
    else 
        {
        if (userInput > temp2) 
            {
            temp2 = userInput;
            }
        }
    
    // Return the larger temperature by reference
    return (temp1 > temp2) ? temp1 : temp2;
}

int main() {
    double temperature1, temperature2;

    // Get input temperatures from the user
    cout << "Enter temperature 1: ";
    cin >> temperature1;

    cout << "Enter temperature 2: ";
    cin >> temperature2;

    // Call the function and get the reference to the larger temperature
    double& largerTemperature = setLargerTemperature(temperature1, temperature2);

    // Print the larger temperature
    cout << "Larger temperature: " << largerTemperature << std::endl;

    return 0;
}

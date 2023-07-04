// 1.Write a simple program that converts the temperature in Celsius scale to Fahrenheit scale and vice versa using the basic concept of class and object. Make separate classes for Celsius and Fahrenheit which will have the private members that hold the temperature value and make conversion functions in each class for conversion from one to another. For example, you need to have a function toFahrenheit() in class Celsius that converts to Fahrenheit scale and returns the value.


#include <iostream>
using namespace std;

class Celsius {
private:
    double temperature;

public:
    Celsius(double temp) {
        temperature = temp;
    }

    double toFahrenheit() {
        return (temperature * 9 / 5) + 32;
    }
};

class Fahrenheit {
private:
    double temperature;

public:
    Fahrenheit(double temp) {
        temperature = temp;
    }

    double toCelsius() {
        return (temperature - 32) * 5 / 9;
    }
};

int main() {
     float celsiusTemp, fahrenheitTemp;

    
    cout << "Enter temperature in Celsius: ";
    cin >> celsiusTemp;
    Celsius celsius(celsiusTemp);
    fahrenheitTemp = celsius.toFahrenheit();
    cout << "Temperature in Fahrenheit: " << fahrenheitTemp << std::endl;

    
    cout << "Enter temperature in Fahrenheit: ";
    cin >> fahrenheitTemp;
    Fahrenheit fahrenheit(fahrenheitTemp);
    celsiusTemp = fahrenheit.toCelsius();
    cout << "Temperature in Celsius: " << celsiusTemp << std::endl;

    return 0;
}

// 1.Create a function called sum() that returns the sum of the elements of an array. Make this function into a template so it will work with any numerical type. Write a program that applies this function to data of various types.

#include <iostream>
#include <vector>

using namespace std;

template <typename T>
T sum(const vector<T>& arr) {
    T result = 0;
    for (const T& element : arr) {
        result += element;
    }
    return result;
}

int main() {
    // Example with integers
    vector<int> intArray = {1, 2, 3, 4, 5};
    int intSum = sum(intArray);
    cout << "Sum of integers: " << intSum << endl;

    // Example with floating-point numbers
    vector<double> doubleArray = {1.1, 2.2, 3.3, 4.4, 5.5};
    double doubleSum = sum(doubleArray);
    cout << "Sum of doubles: " << doubleSum << endl;

    return 0;
}

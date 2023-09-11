// 2. Write a program to create a user-defined manipulator that will format the output by setting the width, precision, and fill character at the same time by passing arguments.

#include <iostream>
#include <iomanip> // for setw and setprecision

using namespace std;

// User-defined manipulator function
ostream& customFormat(ostream& os, int width, int precision, char fillChar) {
    os << setw(width) << fixed << setprecision(precision) << setfill(fillChar);
    return os;
}

int main() {
    double value = 123.45678;

    // Use the custom manipulator to format output
    cout << "Formatted Output: " << customFormat << setw(10) << 2 << setw(5) << 3 << setw(6) << '0' << value << endl;

    return 0;
}

// 1.Write a program to demonstrate the use of different ios flags and functions to format the output. Create a program to generate the bill invoice of a department store by using different formatting.

#include <iostream>
#include <iomanip> // for formatting

using namespace std;

int main() {
    // Sample bill details
    string department = "Electronics Store";
    string cashier = "Sonu Kumar Gupta";
    string date = "2023-09-05";

    // Items purchased
    string items[] = {"Laptop", "Smartphone", "Headphones"};
    double prices[] = {800.0, 500.0, 50.0};
    int quantities[] = {2, 3, 1};

    // Calculate total
    double total = 0.0;
    for (int i = 0; i < 3; i++) {
        total += prices[i] * quantities[i];
    }

    // Output bill invoice
    cout << "--------------------------------------------" << endl;
    cout << setw(30) << department << endl;
    cout << "--------------------------------------------" << endl;
    cout << "Cashier: " << cashier << endl;
    cout << "Date: " << date << endl;
    cout << "--------------------------------------------" << endl;

    cout << left << setw(20) << "Item" << setw(10) << "Qty" << right << setw(15) << "Price" << setw(15) << "Total" << endl;
    cout << "--------------------------------------------" << endl;

    cout << fixed << setprecision(2); // Set floating-point precision
    for (int i = 0; i < 3; i++) {
        cout << left << setw(20) << items[i] << setw(10) << quantities[i] << right << setw(15) << prices[i] << setw(15) << prices[i] * quantities[i] << endl;
    }

    cout << "--------------------------------------------" << endl;
    cout << left << setw(30) << "Total" << right << setw(30) << total << endl;
    cout << "--------------------------------------------" << endl;

    return 0;
}

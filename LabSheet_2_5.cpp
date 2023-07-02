// 5. Assume that employee will have to pay 10 percent income tax to the government. Ask user to enter the employee salary. Use inline function to display the net payment to the employee by the company.

#include <iostream>

// Inline function to calculate net payment after deducting income tax
inline double calculateNetPayment(double salary) {
    return salary - (salary * 0.1);
}

int main() {
    double salary;

    std::cout << "Enter employee salary: ";
    std::cin >> salary;

    double netPayment = calculateNetPayment(salary);

    std::cout << "Net payment to the employee: " << netPayment << std::endl;

    return 0;
}

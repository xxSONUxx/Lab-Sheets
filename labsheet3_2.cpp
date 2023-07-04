// 2.Assume that you want to check whether the number is prime or not. Write a program that asks for numbers repeatedly. When it finishes checking a number the program asks if the user wants to do another calculation. The response can be 'y' or 'n'. Don't forget to use the object-oriented concept.


#include <iostream>
using namespace std;

class PrimeChecker {
private:
    int number;

public:
    PrimeChecker(int num) {
        number = num;
    }

     bool isPrime() {
        if (number <= 1) {
            return false;
        }

        for (int i = 2; i * i <= number; i++) {
            if (number % i == 0) {
                return false;
            }
        }

        return true;
    }
};

int main() {
    char continueCalculation = 'y';
     do
     {
        int num;

        cout << "Enter a number: ";
        cin >> num;

        PrimeChecker primeChecker(num);

        if (primeChecker.isPrime()) {
            cout << num << " is a prime number." << std::endl;
        } else {
            cout << num << " is not a prime number." << std::endl;
        }

        cout << "Do you want to perform another calculation? (y/n): ";
        cin >> continueCalculation;
    }while (continueCalculation == 'y');

    return 0;
}

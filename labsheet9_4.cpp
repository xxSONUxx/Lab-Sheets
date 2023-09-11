// 4. Write any program that demonstrates the use of multiple catch handling, re-throwing an exception, and catching all exceptions.

#include <iostream>
#include <stdexcept>

using namespace std;

// Function that throws different types of exceptions
void throwException(int choice) {
    switch (choice) {
        case 1:
            throw logic_error("Logic error occurred");
        case 2:
            throw runtime_error("Runtime error occurred");
        case 3:
            throw invalid_argument("Invalid argument exception");
        default:
            throw exception();
    }
}

int main() {
    try {
        cout << "Enter a number (1-4): ";
        int choice;
        cin >> choice;

        // Call the function that throws exceptions based on user's choice
        throwException(choice);

    } catch (const logic_error& e) {
        cerr << "Caught logic_error: " << e.what() << endl;

    } catch (const runtime_error& e) {
        cerr << "Caught runtime_error: " << e.what() << endl;

    } catch (const invalid_argument& e) {
        cerr << "Caught invalid_argument: " << e.what() << endl;

    } catch (const exception& e) {
        cerr << "Caught unknown exception: " << e.what() << endl;
        
        // Re-throw the exception
        throw;
    }

    cout << "Program continues after exception handling." << endl;

    return 0;
}

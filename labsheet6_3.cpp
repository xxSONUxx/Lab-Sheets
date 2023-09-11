/*Create a class called Musicians to contain three methods string(), wind(), and perc(). Each of these methods should initialize a string array to contain the following instruments

-  veena, guitar, sitar, sarod and mandolin under string()
-  flute, clarinet saxophone, nadhaswaram, and piccolo under wind()
-  tabla, mridangam, bangos, drums and tambour under perc()

It should also display the contents of the arrays that are initialized. Create a derived class called TypeIns to contain a method called get() and show(). The get() method must display a  menu as follows

Type of instruments to be displayed

a.  String instruments
b.  Wind instruments
c.  Percussion instruments

The show() method should display the relevant detail according to our choice. The base class variables must be accessible only to their derived classes.*/


#include <iostream>
#include <string>
using namespace std;

class Musicians {
protected:
    string stringInstruments[5] = { "veena", "guitar", "sitar", "sarod", "mandolin" };
    string windInstruments[5] = { "flute", "clarinet", "saxophone", "nadhaswaram", "piccolo" };
    string percInstruments[5] = { "tabla", "mridangam", "bongos", "drums", "tambour" };

public:
    void displayStringInstruments() {
        cout << "String instruments: ";
        for (const string& instrument : stringInstruments) {
            cout << instrument << ", ";
        }
        cout << endl;
    }

    void displayWindInstruments() {
        cout << "Wind instruments: ";
        for (const string& instrument : windInstruments) {
            cout << instrument << ", ";
        }
        cout << endl;
    }

    void displayPercInstruments() {
        cout << "Percussion instruments: ";
        for (const string& instrument : percInstruments) {
            cout << instrument << ", ";
        }
        cout << endl;
    }
};

class TypeIns : public Musicians {
public:
    void getMenuChoice() {
        char choice;
        cout << "Type of instruments to be displayed:" << endl;
        cout << "a. String instruments" << endl;
        cout << "b. Wind instruments" << endl;
        cout << "c. Percussion instruments" << endl;
        cout << "Enter your choice (a/b/c): ";
        cin >> choice;

        switch (choice) {
        case 'a':
            displayStringInstruments();
            break;
        case 'b':
            displayWindInstruments();
            break;
        case 'c':
            displayPercInstruments();
            break;
        default:
            cout << "Invalid choice!" << endl;
        }
    }

    void show() {
        getMenuChoice();
    }
};

int main() {
    TypeIns t;
    t.show();

    return 0;
}

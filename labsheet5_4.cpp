//4.Write a class Date that overloads prefix and postfix operators to increase the Date object by one day, while causing appropriate increments to the month and year (use the appropriate condition for leap year). The prefix and postfix operators in the Date class should behave exactly like the built-in increment operators.

#include <iostream>
using namespace std;

class Date {
private:
    int day;
    int month;
    int year;

public:
    Date(int d, int m, int y) : day(d), month(m), year(y) {}

    // Prefix increment operator (++Date)
    Date& operator++() {
        incrementDate();
        return *this;
    }

    // Postfix increment operator (Date++)
    Date operator++(int) {
        Date temp = *this;
        incrementDate();
        return temp;
    }

    void display() const {
        cout << day << "/" << month << "/" << year << endl;
    }

private:
    bool isLeapYear(int year) const {
        return ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0);
    }

    bool isLastDayOfMonth() const {
        int daysInMonth = 31;

        if (month == 4 || month == 6 || month == 9 || month == 11) {
            daysInMonth = 30;
        } else if (month == 2) {
            daysInMonth = isLeapYear(year) ? 29 : 28;
        }

        return (day == daysInMonth);
    }

    void incrementDate() {
        if (isLastDayOfMonth()) {
            if (month == 12) {
                day = 1;
                month = 1;
                year++;
            } else {
                day = 1;
                month++;
            }
        } else {
            day++;
        }
    }
};

int main() {
    using namespace std;

    Date date(31, 12, 2022);

    cout << "Original Date: ";
    date.display();

    // Using prefix increment operator
    ++date;
    cout << "Date after prefix increment: ";
    date.display();

    // Using postfix increment operator
    date++;
    cout << "Date after postfix increment: ";
    date.display();

    return 0;
}

//1.Write a program that has a class to represent time. The class should have constructors to initialize data members hour, minute, and second to 0 and to initialize them to values passed as arguments. The class should have a member function to add time objects and return the result as a time object. There should be functions to display time in 12-hour and 24-hour format.


#include <iostream>
#include <iomanip>

using namespace std;

class Time {
private:
    int hour;
    int minute;
    int second;

public:
    Time() {
        hour = 0;
        minute = 0;
        second = 0;
    }

    Time(int h, int m, int s) {
        hour = h;
        minute = m;
        second = s;
    }

    Time addTime(const Time& t) const {
        Time result;
        result.second = second + t.second;
        result.minute = minute + t.minute + (result.second / 60);
        result.hour = hour + t.hour + (result.minute / 60);
        result.second %= 60;
        result.minute %= 60;
        result.hour %= 24;
        return result;
    }

    void display12HourFormat() const {
        int displayHour = hour % 12;
        string amPm = (hour < 12) ? "AM" : "PM";

        if (displayHour == 0)
            displayHour = 12;

        cout << setfill('0') << setw(2) << displayHour << ":"
             << setfill('0') << setw(2) << minute << ":"
             << setfill('0') << setw(2) << second << " " << amPm << endl;
    }

    void display24HourFormat() const {
        cout << setfill('0') << setw(2) << hour << ":"
             << setfill('0') << setw(2) << minute << ":"
             << setfill('0') << setw(2) << second << endl;
    }
};

int main() {
    Time t1; // Default constructor
    Time t2(4, 30, 15); // Constructor with arguments

    Time t3 = t1.addTime(t2); // Add two time objects

    t1.display12HourFormat();
    t1.display24HourFormat();

    t2.display12HourFormat();
    t2.display24HourFormat();

    t3.display12HourFormat();
    t3.display24HourFormat();

    return 0;
}

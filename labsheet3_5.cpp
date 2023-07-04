// 5.Assume that an object represents an employee report that contains information like employee id, total bonus, total overtime in a particular year. Use an array of objects to represent n employees' reports. Write a program that displays the report. Use setpara() member function to set report attributes by passing the arguments and member function displayreport() to show the report according to the parameter passed. Display the report in the following format.

// An employee with ... ... ... has received Rs ... ... ...as a bonus

// and

// had worked ... ... ... hours as overtime in the year ... ... ..

#include <iostream>
#include <string>
using namespace std;

class EmployeeReport {
private:
    int employeeId;
    double totalBonus;
    int totalOvertime;
    int year;

public:
    void setParams(int id, double bonus, int overtime, int reportYear) {
        employeeId = id;
        totalBonus = bonus;
        totalOvertime = overtime;
        year = reportYear;
    }

    void displayReport() {
        cout << "An employee with ID " << employeeId << " has received Rs " << totalBonus
                  << " as a bonus" << endl;
        cout << "and" << endl;
        cout << "had worked " << totalOvertime << " hours as overtime in the year " << year << endl;
    }
};

int main() {
    int n;
    cout << "Enter the number of employee reports: ";
    cin >> n;

    EmployeeReport* reports = new EmployeeReport[n];

    for (int i = 0; i < n; ++i) {
        int employeeId, totalOvertime, year;
        double totalBonus;

        cout << "Enter details for employee report #" << i + 1 <<endl;
        cout << "Employee ID: ";
        cin >> employeeId;
        cout << "Total Bonus: ";
        cin >> totalBonus;
        cout << "Total Overtime: ";
        cin >> totalOvertime;
        cout << "Year: ";
        cin >> year;

        reports[i].setParams(employeeId, totalBonus, totalOvertime, year);
    }

    cout << endl << "Employee Reports:" <<endl;
    for (int i = 0; i < n; ++i) {
        cout << "Report #" << i + 1 << ":" <<endl;
        reports[i].displayReport();
        cout << endl;
    }

    delete[] reports;

    return 0;
}

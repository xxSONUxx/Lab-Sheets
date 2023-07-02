#include <iostream>
using namespace std;

const int MAX_STUDENTS = 50;

struct Student {
    string name;
    double marks;
};

void inputStudentsData(Student students[], int numStudents) {
    for (int i = 0; i < numStudents; i++) {
        cout << "Enter the name of student " << i+1 << ": ";
        cin >> students[i].name;
        
        cout << "Enter the marks obtained by student " << i+1 << ": ";
        cin >> students[i].marks;
    }
}

void displayStudentsData(const Student students[], int numStudents) {
    cout << "Student Data:" << endl;
    for (int i = 0; i < numStudents; i++) {
        cout << "Name: " << students[i].name << ", Marks: " << students[i].marks << endl;
    }
}

int main() {
    Student students[MAX_STUDENTS];
    int numStudents;

    cout << "Enter the number of students: ";
    cin >> numStudents;

    if (numStudents > MAX_STUDENTS) {
        cout << "Maximum number of students exceeded." << endl;
        return 1;
    }

    inputStudentsData(students, numStudents);
    cout << endl;

    displayStudentsData(students, numStudents);

    return 0;
}

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

struct Student {
    string name;
    int rollNo;
    string address;
    string phoneNumber;
};

bool compareByName(const Student& student1, const Student& student2) {
    return student1.name < student2.name;
}

void inputStudentsData(vector<Student>& students) {
    int numStudents;
    cout << "Enter the number of students: ";
    cin >> numStudents;

    for (int i = 0; i < numStudents; i++) {
        Student student;
        
        cout << "Enter the name of student " << i+1 << ": ";
        cin >> student.name;

        cout << "Enter the roll number of student " << i+1 << ": ";
        cin >> student.rollNo;

        cout << "Enter the address of student " << i+1 << ": ";
        cin.ignore();
        getline(cin, student.address);

        cout << "Enter the phone number of student " << i+1 << ": ";
        cin >> student.phoneNumber;

        students.push_back(student);
    }
}

void storeStudentsDataToFile(const vector<Student>& students, const string& filename) {
    ofstream outputFile(filename);

    if (outputFile.is_open()) {
        for (const Student& student : students) {
            outputFile << student.name << ","
                        << student.rollNo << ","
                        << student.address << ","
                        << student.phoneNumber << endl;
        }

        outputFile.close();
        cout << "Data stored in file successfully." << endl;
    } else {
        cout << "Unable to open the file." << endl;
    }
}

void recoverAndSortStudentsDataFromFile(vector<Student>& students, const string& filename) {
    ifstream inputFile(filename);

    if (inputFile.is_open()) {
        students.clear();

        string line;
        while (getline(inputFile, line)) {
            Student student;
            size_t pos1 = line.find(",");
            size_t pos2 = line.find(",", pos1 + 1);
            size_t pos3 = line.find(",", pos2 + 1);

            student.name = line.substr(0, pos1);
            student.rollNo = stoi(line.substr(pos1 + 1, pos2 - pos1 - 1));
            student.address = line.substr(pos2 + 1, pos3 - pos2 - 1);
            student.phoneNumber = line.substr(pos3 + 1);

            students.push_back(student);
        }

        inputFile.close();

        sort(students.begin(), students.end(), compareByName);

        cout << "Data recovered from file and sorted successfully." << endl;
    } else {
        cout << "Unable to open the file." << endl;
    }
}

void displayStudentsData(const vector<Student>& students) {
    cout << "Student Data:" << endl;
    for (const Student& student : students) {
        cout << "Name: " << student.name << ", Roll No: " << student.rollNo
            << ", Address: " << student.address << ", Phone No: " << student.phoneNumber << endl;
    }
}

int main() {
    vector<Student> students;
    string filename = "student_data.txt";

    inputStudentsData(students);
    storeStudentsDataToFile(students, filename);

    cout << endl;

    recoverAndSortStudentsDataFromFile(students, filename);
    displayStudentsData(students);

    return 0;
}
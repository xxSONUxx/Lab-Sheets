// 4. Write a program that stores the information about students (name, student id, department, and address) in a structure and then transfers the information to a file in your directory. Finally, retrieve the information from your file and print it in the proper format on your output screen.

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// Define a structure to store student information
struct Student {
    string name;
    int studentId;
    string department;
    string address;
};

int main() {
    // Create an array of students
    Student students[2];

    // Populate student information
    students[0].name = "Sonu";
    students[0].studentId = 101;
    students[0].department = "Computer Science";
    students[0].address = "Biratnagar";

    students[1].name = "Sakxam";
    students[1].studentId = 102;
    students[1].department = "Electrical Engineering";
    students[1].address = "Dharan";

    // Write student information to a file
    ofstream outFile("student_info.txt");
    if (!outFile) {
        cerr << "Error: Cannot open the file for writing." << endl;
        return 1;
    }

    for (int i = 0; i < 2; i++) {
        outFile << "Name: " << students[i].name << endl;
        outFile << "Student ID: " << students[i].studentId << endl;
        outFile << "Department: " << students[i].department << endl;
        outFile << "Address: " << students[i].address << endl;
        outFile << endl;
    }

    outFile.close();

    // Read and print student information from the file
    ifstream inFile("student_info.txt");
    if (!inFile) {
        cerr << "Error: Cannot open the file for reading." << endl;
        return 1;
    }

    cout << "Student Information:" << endl;
    cout << "-------------------" << endl;

    string line;
    while (getline(inFile, line)) {
        cout << line << endl;
    }

    inFile.close();

    return 0;
}

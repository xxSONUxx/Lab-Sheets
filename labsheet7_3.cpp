// 3. Write a program with an abstract class Student and create derive classes Engineering, Medicine and Science from base class Student. Create the objects of the derived classes and process them and access them using an array of pointers of type base class Student.

#include <iostream>
#include <string>

using namespace std;

class Student {
protected:
    string name;
    int rollNumber;

public:
    Student(const string& n, int roll) : name(n), rollNumber(roll) {}

    virtual void displayDetails() const = 0;
};

class Engineering : public Student {
private:
    string branch;

public:
    Engineering(const string& n, int roll, const string& b) : Student(n, roll), branch(b) {}

    void displayDetails() const override {
        cout << "Engineering Student" << endl;
        cout << "Name: " << name << ", Roll Number: " << rollNumber << endl;
        cout << "Branch: " << branch << endl;
    }
};

class Medicine : public Student {
private:
    string specialization;

public:
    Medicine(const string& n, int roll, const string& spec) : Student(n, roll), specialization(spec) {}

    void displayDetails() const override {
        cout << "Medicine Student" << endl;
        cout << "Name: " << name << ", Roll Number: " << rollNumber << endl;
        cout << "Specialization: " << specialization << endl;
    }
};

class Science : public Student {
private:
    string field;

public:
    Science(const string& n, int roll, const string& f) : Student(n, roll), field(f) {}

    void displayDetails() const override {
        cout << "Science Student" << endl;
        cout << "Name: " << name << ", Roll Number: " << rollNumber << endl;
        cout << "Field: " << field << endl;
    }
};

int main() {
    const int numStudents = 3;
    Student* students[numStudents];

    students[0] = new Engineering("Sonu", 101, "Computer Science");
    students[1] = new Medicine("Astafar", 102, "Obsestrics");
    students[2] = new Science("Priyanka", 103, "Chemistry");

    for (int i = 0; i < numStudents; i++) {
        students[i]->displayDetails();
        cout << endl;
    }

    // Cleanup
    for (int i = 0; i < numStudents; i++) {
        delete students[i];
    }

    return 0;
}

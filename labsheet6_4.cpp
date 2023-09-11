// 4. Write three derived classes inheriting functionality of base class person (should have a member function that asks to enter name and age) and with added unique features of student, and employee, and functionality to assign, change and delete records of student and employee. And make one member function for printing the address of the objects of classes (base and derived) using this pointer. Create two objects of the base class and derived classes each and print the addresses of individual objects. Using a calculator, calculate the address space occupied by each object and verify this with address spaces printed by the program.

#include <iostream>
#include <string>

using namespace std;

class Person {
private:
    string name;
    int age;

public:
    Person() {
        cout << "Enter name: ";
        cin >> name;
        cout << "Enter age: ";
        cin >> age;
    }

    virtual ~Person() {}

    virtual void printAddress() const {
        cout << "Address of Person object: " << this << endl;
    }
};

class Student : public Person {
private:
    int studentID;

public:
    Student() {
        cout << "Enter student ID: ";
        cin >> studentID;
    }

    void assignStudentRecord() {
        cout << "Student record assigned." << endl;
    }

    void changeStudentRecord() {
        cout << "Student record changed." << endl;
    }

    void deleteStudentRecord() {
        cout << "Student record deleted." << endl;
    }

    void printAddress() const override {
        cout << "Address of Student object: " << this << endl;
    }
};

class Employee : public Person {
private:
    int employeeID;

public:
    Employee() {
        cout << "Enter employee ID: ";
        cin >> employeeID;
    }

    void assignEmployeeRecord() {
        cout << "Employee record assigned." << endl;
    }

    void changeEmployeeRecord() {
        cout << "Employee record changed." << endl;
    }

    void deleteEmployeeRecord() {
        cout << "Employee record deleted." << endl;
    }

    void printAddress() const override {
        cout << "Address of Employee object: " << this << endl;
    }
};

int main() {
    Person person1;
    Student student1;
    Employee employee1;

    Person person2;
    Student student2;
    Employee employee2;

    person1.printAddress();
    student1.printAddress();
    employee1.printAddress();

    person2.printAddress();
    student2.printAddress();
    employee2.printAddress();

    // Calculate address space occupied by each object
    size_t personSize = sizeof(person1);
    size_t studentSize = sizeof(student1);
    size_t employeeSize = sizeof(employee1);

    cout << "Address space occupied by Person object: " << personSize << " bytes" << endl;
    cout << "Address space occupied by Student object: " << studentSize << " bytes" << endl;
    cout << "Address space occupied by Employee object: " << employeeSize << " bytes" << endl;

    return 0;
}

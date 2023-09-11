// 2. Create a class Person and two derived classes Employee and Student, inherited from class Person. Now create a class Manager which is derived from two base classes Employee and Student. Show the use of the virtual base class.
#include <iostream>
#include <string>

using namespace std;

class Person {
protected:
    string name;

public:
    Person(const string& n) : name(n) {}

    void display() const {
        cout << "Person: " << name << endl;
    }
};

class Employee : virtual public Person {
protected:
    int employeeId;

public:
    Employee(const string& n, int id) : Person(n), employeeId(id) {}

    void display() const {
        cout << "Employee: " << name << ", ID: " << employeeId << endl;
    }
};

class Student : virtual public Person {
protected:
    string studentId;

public:
    Student(const string& n, const string& id) : Person(n), studentId(id) {}

    void display() const {
        cout << "Student: " << name << ", Student ID: " << studentId << endl;
    }
};

class Manager : public Employee, public Student {
public:
    Manager(const string& n, int empId, const string& stuId)
        : Person(n), Employee(n, empId), Student(n, stuId) {}

    void display() const {
        cout << "Manager: " << name << ", Employee ID: " << employeeId
             << ", Student ID: " << studentId << endl;
    }
};

int main() {
    Manager manager("SONU KUMAR GUPTA", 100, "PUR078BCT084");
    manager.display();
    Student student("Sonu", "PUR078BCT084");
    student.display();

    return 0;
}

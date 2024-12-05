#include <iostream>
#include <string>

using namespace std;

class Student {
public:
    string name;
    int studentID;

    Student(string name, int studentID) : name(name), studentID(studentID) {
        cout << "Student constructor called for " << name << endl;
    }

    ~Student() {
        cout << "Student destructor called for " << name << endl;
    }

    string toString() const {
        return "Name: " + name + ", Student ID: " + to_string(studentID);
    }
};

class Staff {
public:
    string name;
    int staffID;

    Staff(string name, int staffID) : name(name), staffID(staffID) {
        cout << "Staff constructor called for " << name << endl;
    }

    ~Staff() {
        cout << "Staff destructor called for " << name << endl;
    }

    string toString() const {
        return "Name: " + name + ", Staff ID: " + to_string(staffID);
    }
};

class Tutor : public Student, public Staff {
public:
    Tutor(string name, int studentID, int staffID) : Student(name, studentID), Staff(name, staffID) {
        cout << "Tutor constructor called for " << Student::name << endl;
    }

    ~Tutor() {
        cout << "Tutor destructor called for " << Student::name << endl;
    }

    void consultation() const {
        cout << "Doing consultation!" << endl;
    }

    void setName(const string& name) {
        Student::name = name;
    }

    string toString() const {
        return Student::toString() + ", " + Staff::toString();
    }
};

// External functions
void showInfoStudent(Student &stu) {
    cout << stu.toString() << endl;
}

void showInfoStaff(Staff &staff) {
    cout << staff.toString() << endl;
}

int main() {
    // a) Constructor and destructor calls
    Tutor tutor("John Doe", 12345, 67890); 

    // b) setName() method
    tutor.setName("Jane Smith"); 

    // c) toString() method and external functions
    cout << tutor.toString() << endl;
    showInfoStudent(tutor);
    showInfoStaff(tutor);

    return 0;
}
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
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
class SchoolSystem {
public:
    vector<Student> students;

    SchoolSystem() {
        loadStudents();
    }

    ~SchoolSystem() {
        saveStudents();
    }

    void addStudent() {
        string name;
        int studentID;
        cout << "Enter name: ";
        cin.ignore(); // Clear the buffer
        getline(cin, name);
        cout << "Enter student ID: ";
        cin >> studentID;
        students.push_back(Student(name, studentID));
    }

    void removeStudent() {
        int studentID;
        cout << "Enter student ID to remove: ";
        cin >> studentID;
        for (auto it = students.begin(); it != students.end(); ++it) {
            if (it->studentID == studentID) {
                students.erase(it);
                return;
            }
        }
        cout << "Student not found." << endl;
    }

    void viewStudents() const {
        if (students.empty()) {
            cout << "No students in the system." << endl;
            return;
        }
        for (const auto& student : students) {
            cout << student.toString() << endl;
        }
    }

private:
    void saveStudents() {
        ofstream outputFile("students.dat");
        if (outputFile.is_open()) {
            for (const auto& student : students) {
                outputFile << student.name << "," << student.studentID << endl;
            }
            outputFile.close();
        } else {
            cerr << "Error saving student data." << endl;
        }
    }

    void loadStudents() {
        ifstream inputFile("students.dat");
        if (inputFile.is_open()) {
            string line;
            while (getline(inputFile, line)) {
                string name;
                int studentID;
                stringstream ss(line);
                getline(ss, name, ',');
                ss >> studentID;
                students.push_back(Student(name, studentID));
            }
            inputFile.close();
        }
    }
};

int main() {
    SchoolSystem schoolSystem;

    int choice;
    do {
        cout << "\nSchool Management System" << endl;
        cout << "1. View all students" << endl;
        cout << "2. Add Student" << endl;
        cout << "3. Remove Student" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter Your Choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                schoolSystem.viewStudents();
                break;
            case 2:
                schoolSystem.addStudent();
                break;
            case 3:
                schoolSystem.removeStudent();
                break;
            case 4:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice." << endl;
        }
    } while (choice != 4);

    return 0;
}
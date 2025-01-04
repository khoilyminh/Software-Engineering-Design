#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    string studentName, studentID;

    cout << "Input your student name: ";
    getline(cin, studentName);

    cout << "Input your student id: ";
    getline(cin, studentID);

    // Save to file
    ofstream file(studentName + ".dat");
    if (file.is_open()) {
        file << "Student Name: " << studentName << endl;
        file << "Student ID: " << studentID << endl;
        file.close();
        cout << "Your data is saved!" << endl;
    } else {
        cout << "Error opening file!" << endl;
    }

    return 0;
}

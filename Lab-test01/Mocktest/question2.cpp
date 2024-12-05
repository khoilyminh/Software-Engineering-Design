/*
    RMIT University Vietnam
    Course: EEET2482/COSC2082
    Semester: 2022-3
    Lab Assessment: 1
    Author: Your name (e.g. Nguyen Van Minh)
    ID: Your student id (e.g. 1234567)
    Compiler used: Compiler version (e.g. g++ 8.1.0, type "g++ --version" to
    check) Created  date: dd/mm/yyyy (e.g. 12/11/2021) Acknowledgement: List the
    resources that you use to complete this assessment (write 'None' if you don't
    use any).
*/

#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>

using namespace std;

class Student {
private:
    string name;
    int scores[3];

public:
    // Constructor
    Student() : name(""), scores{0, 0, 0} {}

    // Input data
    void inputData() {
        cout << "Enter name: ";
        getline(cin, name);
        cout << "Enter 3 scores: ";
        for (int &score : scores) {
            cin >> score;
        }
        cin.ignore(); // Clear the newline character
    }

    // Show information
    void showInfo() const {
        cout << "Name: " << name << ", Scores: ";
        for (int score : scores) {
            cout << score << " ";
        }
        cout << endl;
    }

    // Calculate average score
    double averageScore() const {
        return (scores[0] + scores[1] + scores[2]) / 3.0;
    }

    // Make the operators friend functions
    friend istream &operator>>(istream &is, Student &student);
    friend ostream &operator<<(ostream &os, const Student &student);
    friend Student operator+(int n, const Student &student);

    // Add a getter for the name
    string getName() const { return name; }
};

// Overload >> operator outside the class
istream &operator>>(istream &is, Student &student) {
    cout << "Enter name: ";
    getline(is, student.name); // Use getline to read the whole name
    cout << "Enter 3 scores: ";
    for (int &score : student.scores) {
        is >> score;
    }
    is.ignore(); // Clear the newline after reading scores
    return is;
}

// Overload << operator outside the class
ostream &operator<<(ostream &os, const Student &student) {
    os << "Name: " << student.name << ", Scores: ";
    for (int score : student.scores) {
        os << score << " ";
    }
    return os;
}

// Overload > operator as a non-member function
bool operator>(const Student &s1, const Student &s2) {
    return s1.averageScore() > s2.averageScore();
}

// Overload + operator outside the class
Student operator+(int n, const Student &student) {
    Student result = student;
    for (int &score : result.scores) {
        score += n;
    }
    return result;
}

int main() {
    // Testing part (a) and (b)
    Student s1, s2;
    cin >> s1;
    cin >> s2;

    cout << s1 << endl;
    cout << s2 << endl;

    if (s1 > s2) {
        // Use the getName() method to access the name
        cout << s1.getName() << " has a higher average score.\n";
    } else {
        cout << s2.getName() << " has a higher average score.\n";
    }

    Student s3 = 5 + s1;
    cout << "Scores after adding 5: " << s3 << endl;

    // Part (c): Read from a file
    Student students[10];
    ifstream file("data.txt");
    if (file.is_open()) {
        for (int i = 0; i < 10; ++i) {
            file >> students[i];
        }
        file.close();
    }

    Student topStudent = students[0];
    for (int i = 1; i < 10; ++i) {
        if (students[i] > topStudent) {
            topStudent = students[i];
        }
    }
    cout << "Top student: " << topStudent << endl;

    return 0;
}
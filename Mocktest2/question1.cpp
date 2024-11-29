#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

// Function to calculate the sum of digits of an integer
int sumDigit(int num) {
    int sum = 0;
    while (num > 0) {
        sum += num % 10;
        num /= 10;
    }
    return sum;
}

// Function to check if the sum of digits is a palindrome
bool checkPal(int num) {
    int sum = sumDigit(num);
    string str = to_string(sum);
    string reversedStr = str;
    reverse(reversedStr.begin(), reversedStr.end());
    return str == reversedStr;
}

// Function to recommend addition or subtraction for palindrome
string recPal(int sum) {
    string str = to_string(sum);
    string reversedStr = str;
    reverse(reversedStr.begin(), reversedStr.end());
    int diff = stoi(reversedStr) - stoi(str);
    if (diff > 0) {
        return "Add " + to_string(diff) + " to make it a palindrome.";
    } else {
        return "Minus " + to_string(-diff) + " to make it a palindrome.";
    }
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        cerr << "Error: Incorrect number of arguments." << endl;
        return 1;
    }

    ifstream inputFile(argv[1]);
    ofstream outputFile("Result.txt");

    if (!inputFile.is_open()) {
        cerr << "Error: Cannot open file " << argv[1] << endl;
        return 1;
    }

    int num;
    while (inputFile >> num) {
        cout << num << ": Result " << sumDigit(num) << " is ";
        outputFile << num << ": Result " << sumDigit(num) << " is ";
        if (checkPal(num)) {
            cout << "a palindrome." << endl;
            outputFile << "a palindrome." << endl;
        } else {
            cout << "not a palindrome." << endl;
            outputFile << "not a palindrome." << endl;
            cout << recPal(sumDigit(num)) << endl;
            outputFile << recPal(sumDigit(num)) << endl;
        }
    }

    inputFile.close();
    outputFile.close();
    return 0;
}

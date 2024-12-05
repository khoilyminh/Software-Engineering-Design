#include <iostream>
#include <stdexcept>

using namespace std;

int main() {
    // a. Division with exception handling
    double a, b;
    cout << "Enter two double values for division (a/b): ";
    cin >> a >> b;

    try {
        if (b == 0) {
            throw runtime_error("Division by zero!");
        }
        cout << "Result of " << a << "/" << b << " is: " << a / b << endl;
    } catch (const runtime_error& error) {
        cerr << "Error: " << error.what() << endl;
        cout << "Re-enter value for b: ";
        cin >> b;
        cout << "Result of " << a << "/" << b << " is: " << a / b << endl;
    }

    // b. Continuous memory allocation
    size_t totalAllocated = 0;
    try {
        while (true) {
            const size_t blockSize = 1024 * 1024; // 1MB
            char* block = new char[blockSize];
            if (block == nullptr) {
                throw bad_alloc();
            }
            totalAllocated += blockSize;
        }
    } catch (const bad_alloc& error) {
        cerr << "Memory allocation failed: " << error.what() << endl;
        cout << "Total memory allocated: " << totalAllocated << " bytes" << endl;
    }

    return 0;
}

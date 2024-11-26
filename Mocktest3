#include <iostream>
#include <sstream>
#include <iomanip>
#include <string>

// Overloaded function to double an integer
int doubleVal(int num) {
    return num * 2;
}

// Overloaded function to double a floating-point number
double doubleVal(double num) {
    return num * 2;
}

// Overloaded function to double a hexadecimal number
int doubleVal(const std::string &hexStr) {
    int num;
    std::stringstream ss;
    ss << std::hex << hexStr;
    ss >> num;
    return num * 2;
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        std::cerr << "Error: Incorrect number of arguments.\n";
        return 1;
    }

    std::string input = argv[1];
    if (input.find("0x") == 0 || input.find("0X") == 0) {
        // Hexadecimal input
        int doubledHex = doubleVal(input);
        std::cout << "0x" << std::hex << std::uppercase << doubledHex << std::endl;
    } else if (input.find('.') != std::string::npos) {
        // Floating-point input
        double num = std::stod(input);
        std::cout << std::fixed << std::setprecision(2) << doubleVal(num) << std::endl;
    } else {
        // Integer input
        int num = std::stoi(input);
        std::cout << doubleVal(num) << std::endl;
    }

    return 0;
}

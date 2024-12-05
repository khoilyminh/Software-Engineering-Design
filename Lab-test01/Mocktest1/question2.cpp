#include <iostream>
#include <sstream>
#include <string>
#include <cctype>

// Function to check if a string is a valid hexadecimal number
bool checkHex(const std::string &hexNum) {
    if (hexNum.size() < 3 || (hexNum[0] != '0' || (hexNum[1] != 'x' && hexNum[1] != 'X'))) {
        return false;
    }
    for (size_t i = 2; i < hexNum.size(); ++i) {
        if (!std::isxdigit(hexNum[i])) {
            return false;
        }
    }
    return true;
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        std::cerr << "Insufficient arguments." << std::endl;
        return 1;
    }

    std::string num1 = argv[1];
    std::string op = argv[2];
    std::string num2 = argv[3];

    if (!checkHex(num1) || !checkHex(num2)) {
        std::cerr << "Argument(s) provided is(are) not hexadecimal." << std::endl;
        return 1;
    }

    int hex1, hex2;
    std::stringstream ss1(num1), ss2(num2);
    ss1 >> std::hex >> hex1;
    ss2 >> std::hex >> hex2;

    int result = (op == "+") ? (hex1 + hex2) : (hex1 - hex2);
    std::cout << "Result is " << result << std::endl;

    return 0;
}

#include <iostream>
#include <string>
#include <cctype>

int main() {
    std::string input;
    std::cout << "Enter a string: ";
    std::getline(std::cin, input);

    char highestDigit = '\0';
    for (char c : input) {
        if (std::isdigit(c)) {
            if (highestDigit == '\0' || c > highestDigit) {
                highestDigit = c;
            }
        }
    }

    if (highestDigit != '\0') {
        std::cout << "The highest digit value is " << highestDigit << "." << std::endl;
    } else {
        std::cout << "There’s no digit in the string." << std::endl;
    }

    return 0;
}

#include <iostream>
#include <iomanip>
#include <string>


// using std::cout;
// using std::cin;

#define SIZE 50

int main()
{
    /*(a) Read a string from the console input, 
    store the string in character array str. 
    Then print out its all characters, separated by a space. */

    char str[SIZE];
    int i;

    std::cout << "Please enter a string: ";
    std::cin.getline(str, SIZE);

    for(i=0; str[i] != '\0'; i++)
        std::cout << str[i] << ' ';
    
    std::cout << "\n\n";    
    /*(b) Print 1.234 with 9-character width, padded by zeros. */  
    std::cout << std::setw(9) << std::setfill('0') << 1.234 << "\n\n";

    /*(c) Print 1.234 with precision is 2 digits of fractional part 
    (after decimal point).*/
    std::cout << std::fixed << std::setprecision(2) << 1.234 << "\n\n";
    
    /*(d) Read a hexadecimal value (preceded by 0x) into variable hex, 
    then print out its decimal value and hexa form.
    Input: 0x10
    Output: 16 0x10 */
    int hexValue;
    std::cout << "Please enter hexadecimal number (in \"0x\" format)\n";
    std::cout << "Input: 0x";
    std::cin >> std::hex >> hexValue;
    std::cout << "Output: " << std::dec << std::showbase << hexValue;
    std::cout << std::hex << std::showbase << " " << hexValue << "\n\n";
    
    return 0;
}

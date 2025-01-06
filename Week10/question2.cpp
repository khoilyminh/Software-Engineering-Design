#include <iostream>

template <typename T>
T min3(T num1, T num2, T num3){
    T min = num1;
    if(min > num2) min = num2;
    if(min > num3) min = num3;
    return min;
}

int main()
{
    std::cout << "The min of 1, 0, 2 is " << min3<int>(1, 0, 2) << "\n";
    std::cout << "The min of 1.5, 0.5, 3.0 is " << min3<double>(1.5, 0.5, 3.0) << "\n";
    std::cout << "The min of Hello, Hi, Morning is " << min3<std::string>("Hello", "Hi", "Morning") << "\n";
    
    return 0;
}
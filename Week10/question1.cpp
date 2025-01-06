#include <iostream>

template<typename T>
void swap(T &num1, T &num2){
    T temp = num1;
    num1 = num2;
    num2 = temp;
}

int main(){
    int num1 = 2, num2 = 3;
    swap<int>(num1, num2);

    std::cout << "num1 = " << num1;
    std::cout << ", num2 = " << num2;

    return 0;
}
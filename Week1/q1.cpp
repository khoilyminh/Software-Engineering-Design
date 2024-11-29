#include <iostream>
using std::cin;
using std::cout;

int main()
{
    int a, b;
    double x; //you can use float as well

    cout << "Please enter coefficient values a and b of a linear equation ax + b = 0: ";
    cin >> a >> b;

    //while loop here (optional) is to make sure that the denominator a is not 0 to avoid
    //divide-by-zero error
    while(a == 0)
    {
        cout << "a cannot be 0. Please enter coefficient a again: ";
        cin >> a;
    }

    x = (double) -b / a; //using cast operator    
    //x = (-1.0)*b / a;  //Or you can make either the numerator or denominator a double 

    cout << "x is " << x << "\n";

    return 0;
}

#include <iostream>
using std::cin;
using std::cout;

#define SIZE 5

int main()
{
    int array[SIZE], i, max, total = 0;

    cout << "Please enter values of 5 integers: ";

    for(i=0; i<SIZE; i++)
    {
        cin >> array[i];
    }
    
    max = array[0];
    for(i=0; i<SIZE; i++)
    {
        if(array[i] > max)
        {
            max = array[i];
        }
        total += array[i];
    }

    cout << "Your 5 integers are as follows: ";
    for(i=0; i<SIZE; i++)
    {
        cout << array[i] << ' ';
    }
    
    cout << "\nMax value: " << max;
    cout << "\nAverage value: " << (double)total/SIZE;
    cout << "\n";

    return 0;
}

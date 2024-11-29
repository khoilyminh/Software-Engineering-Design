#include <iostream>

using std::cout;
using std::cin;

int findMin(int arr[], int size)
{
    int min = arr[0];
    int i;

    for(i=1; i<size; i++)
        if(min > arr[i])
            min = arr[i];

    return min;
}

//Test findMin() in main()
int main()
{
    int arrInt[5] = {2, 3, 4, 1, 5};
    int minValue = findMin(arrInt, 5);

    cout << "Minimum value is " << minValue << "\n\n";

    return 0;
}

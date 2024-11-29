#include <iostream>
using std::cin;
using std::cout;

/* Note: There are many methods to do this. 
The sample here is only one of the methods used.
*/
int main()
{
    int num, temp, count=1, j, revNum, lastDigit, k, frontNum;

    cout << "Enter an integer: ";
    cin >> num;

    temp = num;
    
    //while loop to get the number of digits for the integer num entered by the user
    while(temp >= 10)
    {
        temp /= 10;
        count++;
    }   
    //if num < 10, then the reverse number is the same as the num
    if(num < 10)
    {
        revNum = num;
    }
    else  //else, do the following to reverse the number
    {
        revNum = 0; //set revNum to 0
        /* e.g. if num = 123, for each iteration, we will be doing 
        revNum = 300 (1st iteration) + 20 (2nd iteration) + 1 (3rd iteration)
        to get revNum = 321 */
        for(j=count; j>0; j--) //start from j=count until j=0
        {               
            lastDigit = num % 10; //get the last digit of num
            
            for(k=1; k<j; k++)  //multiply by 10 j-1 times
                lastDigit *= 10;

            revNum += lastDigit; //add lastDigit to revNum
            
            num = num / 10; 
        }
    }       

    cout << "Reverse number is " << revNum << '\n';

    return 0;
}

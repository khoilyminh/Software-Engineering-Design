#include <iostream>
#include <string>
#include <cstring>
using namespace std;

#define SIZE 50

//reverse() for string class
string reverse(string str){
    int i; 
    int len = str.length();
    int lastInd = len-1;
    char temp;
    for(i=0; i<len/2; i++)
    {
        temp = str[i];
        str[i] = str[lastInd];
        str[lastInd] = temp;

        lastInd--;
    }
    return str;
}

//convert() for string class
string convert(string str){
    int i;
    for(i=0; i<str.length(); i++){
        if(str[i] >= 'a' && str[i] <= 'z')
            str[i] -= ('a' - 'A');
        else if(str[i] >= 'A' && str[i] <= 'Z')
            str[i] += ('a' - 'A');
    }
    return str;
}

//reverse() for C-type string
void reverse(char str[]){
    int i; 
    int len = strlen(str);
    int lastInd = len-1;
    char temp;
    for(i=0; i<len/2; i++)
    {
        temp = str[i];
        str[i] = str[lastInd];
        str[lastInd] = temp;

        lastInd--;
    }
}

//convert() for C-type string
void convert(char str[]){
    int i;
    for(i=0; i<strlen(str); i++){
        if(str[i] >= 'a' && str[i] <= 'z')
            str[i] -= ('a' - 'A');
        else if(str[i] >= 'A' && str[i] <= 'Z')
            str[i] += ('a' - 'A');
    }
}

int main()
{
    /*This is for user input in C-type string and then convert to 
    C++ string class to be used with C++ string class functions reverse()
    and convert() */
    
    char cstr1[SIZE], cstr2[SIZE];

    cout << "Enter string 1: ";
    cin.getline(cstr1, sizeof(cstr1));

    cout << "Enter string 2: ";
    cin.getline(cstr2, sizeof(cstr2));

    string str1(cstr1);
    string str2(cstr2);

    cout << "Reverse string 1 with string " << str1 << " is " 
        << reverse(str1) << endl;

    cout << "Convert string 2 with string " << str2 << " is " 
        << convert(str2) << endl;

    /*This is for user input in C++ string class and then convert to 
    C-type string to be used with C-type string functions reverse()
    and convert() */
    /*uncomment to use it */
    /*
    string str1, str2;
    
    cout << "Enter string 1: ";
    getline(cin, str1);
    
    cout << "Enter string 2: ";
    getline(cin, str2);

    char * cstr1 = new char [str1.length()+1];
    char * cstr2 = new char [str2.length()+1];
    
    strcpy(cstr1, str1.c_str());
    strcpy(cstr2, str2.c_str());
        
    reverse(cstr1);
    cout << "Reverse string 1 with string " << str1 << " is " 
        << cstr1 << endl;
   
    convert(cstr2);
    cout << "Convert string 2 with string " << str2 << " is " 
        << cstr2 << endl;
    */
    return 0;
    
}

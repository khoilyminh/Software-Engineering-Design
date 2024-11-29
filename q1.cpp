#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    int opt;
    string pwd;
    fstream myfile;

    cout << "Password management program:\n";
    cout << "1. Save your password\n";
    cout << "2. Read your password\n";
    
    cout << "Your choice: ";
    cin >> opt;

    switch(opt)
    {
        case 1:
            myfile.open("pwd.dat", ios::out);
            
            if(!myfile.is_open()){
               cerr << "Fail to create/open file.\n";
               break; 
            }
            
            cout << "Enter the password: ";
            //cin >> pwd; //this will get one word for the password only
            cin.ignore(1,'\n'); //Ignore previous "\n" character
            getline(cin, pwd); //this will get password that has spaces
            myfile << pwd;  //store the password to the file
            
            cout << "Saved to the file!";
            myfile.close();
            break;
        case 2:
            myfile.open("pwd.dat", ios::in);
            
            if(!myfile.is_open()){
               cerr << "Fail to open file.\n";
               break; 
            }
            cout << "Your password: ";
            //myfile >> pwd; //this will get only one word from the file and store it to pwd
            getline(myfile, pwd); //this will get one line from the file and store it to pwd
            cout << pwd << endl;  //output pwd to the terminal/console
            
            myfile.close();

            break;
        default:
            cout << "Wrong option entered.\n";
    }
    
    return 0;
}
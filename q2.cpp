#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
using namespace std;

#define SIZE 3

class BankAcc{
    public:
        string name;
        float amount;

        BankAcc(string name="", float amount=0.0){
            this->name = name;
            this->amount = amount;
        }

        int withdraw(float num){
            int code = 1; 
            if(amount >= num)
                amount -= num;
            else{
                code = 2;
            }
            return code;
        }

        void display(){
            cout << "Name: " << name << ", Amount: " << fixed << setprecision(2) << amount << "\n";
        }
};

int main(int argc, char *argv[])
{
    BankAcc bankAcc[SIZE] = {BankAcc("ABC", 1000), BankAcc("DEF", 2000), BankAcc("GHI", 2500)};
    string accName, output;
    float wAmount;
    int i, notFound = 1, code;
    
    cout << "Bank account information: " << "\n";
    for(i=0; i<SIZE; i++)
        bankAcc[i].display();
    
    cout << "Please enter account name: ";
    cin >> accName;

    for(i=0; i<SIZE; i++)
    {
        if(accName == bankAcc[i].name){
            cout << "Please enter amount to withdraw: ";
            cin >> wAmount;
            code = bankAcc[i].withdraw(wAmount);
            notFound = 0;
            break;
        }
    }
    if(notFound == 1)
        cout << "Account name not found.\n";
            
    if(code == 1)
        cout << "Amount has been withdrawn successfully.\n";
    else if(code == 2)
        cout << "Insufficient amount for withdrawal.\n";

    if(argc == 2)
    {
        ofstream filePtr;
        filePtr.open(argv[1]); //default of ofstream is ios::out
        if(!filePtr.is_open()){
            cerr << "Error in opening/creating file.\n";
            return -1;
        }
        
        for(i=0; i<SIZE; i++)
        {
            filePtr << "Name: " << bankAcc[i].name << ", Amount: " 
                << fixed << setprecision(2) << bankAcc[i].amount << "\n";           
        }
        cout << "Account info successfully saved into " << argv[1] << "\n";
        filePtr.close();
    }
    
    return 0;
}
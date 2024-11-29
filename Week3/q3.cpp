#include <iostream>
#include <fstream>
using namespace std;

class Student{
    private: 
        int score;
        string password;

    public:
        string name;
        
        int get_score()
        {
            return score;
        }
        
        void changePwd(string nameParam, string passwordNew)
        {
            string content, passwordExist;
            string filename = nameParam + ".dat"; //filename based on the nameParam argument
            ifstream myfile1;
            ofstream myfile2;
        
            myfile1.open(filename); //default mode of ifstream is ios::in 
            if(!myfile1.is_open())
            {
                cout << "There's no file related to " << filename << " yet" << endl;
                cout << "Your password will be saved into " << filename << endl; 
                
                myfile2.open(filename); //default mode of ofstream is ios::out
                myfile2 << passwordNew;
                myfile2.close();

                password = passwordNew;
                cout << "Your password has been saved!" << endl;
            }
            else
            {
                myfile1 >> content;
                myfile1.close();
                
                if(content.length() == 0)
                {
                    cout << "There's no content in the file.\n";
                    cout << "Your password will be saved into " << filename << endl;
                    
                    myfile2.open(filename, ios::out);
                    myfile2 << passwordNew;
                    password = passwordNew;
                    myfile2.close();

                    cout << "Your password has been saved!" << endl;            
                }
                else
                {
                    cout << "Please enter your existing password to continue: ";
                    cin >> passwordExist;
                    //check the password in the content of the file with the existing password
                    if(passwordExist == content)   
                    {
                        myfile2.open(filename);
                        myfile2 << passwordNew;  //save the new password into the file
                        password = passwordNew; //update the password data member
                        myfile2.close();

                        cout << "Your password has been saved!" << endl;
                    }
                    else
                    {
                        cout << "Your existing password does not match.\n";
                    }
                }
            }
        }
        
    Student(string nameValue, int scoreValue)
    {
        name = nameValue;
        score = scoreValue;
    }
};

int main()
{
    Student s1("Ling Huo Chong", 80); //example student s1 to test the function   
    string password;

    cout << "Please enter new password: ";
    getline(cin, password);
    
    s1.changePwd(s1.name, password);
    
    return 0;
}

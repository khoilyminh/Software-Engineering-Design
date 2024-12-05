#include <iostream>
using namespace std;

#define SIZE 3

class Student{
    private: 
        int score;
    
    public:
        string name;
        //int score; //for the part where score is public

        int get_score()  //get method for private member score
        {
            return score;
        }
    
        Student(string nameValue, int scoreValue)
        {
            name = nameValue;
            score = scoreValue;
        }
};

int main()
{
    /*(b)
    Student s1("Ling Huo Chong", 50);
    Student s2("Nguyen Linh", 85);

    cout << "Student s1 info\n"; 
    cout << "Name: " << s1.name << "\n";
    cout << "Score: " << s1.score << "\n\n";

    cout << "Student s2 info\n"; 
    cout << "Name: " << s2.name << "\n";
    cout << "Score: " << s2.score << "\n\n";
    */

    /*(c)
    Student stud[SIZE] = {{"Ling Huo Chong", 50}, {"Nguyen Linh", 85}, {"Michael Jordan", 60}};
    int max = stud[0].score;
    int maxIndex = 0;
    //int noElement = sizeof(stud) / sizeof(stud[0]); 
    for(int i=1; i<SIZE; i++)
        if(stud[i].score > max)
        {
            max = stud[i].score;
            maxIndex = i;
        }

    cout << "Student info with highest score" << endl;
    cout << "Name: " << stud[maxIndex].name << endl;
    cout << "Score: " << stud[maxIndex].score << endl;
    */
   

    /*Additional*/
    Student stud[SIZE] = {{"Ling Huo Chong", 50}, {"Nguyen Linh", 85}, {"Michael Jordan", 60}};
    //find the max index, maxIndex that has the highest score
    int max = stud[0].get_score();
    int maxIndex = 0;

    for(int i=1; i<SIZE; i++)
        if(stud[i].get_score() > max)
        {
            max = stud[i].get_score();
            maxIndex = i;
        }

    cout << "Student info with highest score" << endl;
    cout << "Name: " << stud[maxIndex].name << endl;
    cout << "Score: " << stud[maxIndex].get_score() << endl;
     
    return 0;
}

#include <iostream>
using namespace std;

#define NUMPEOPLE 3

class Cat{
    public:
        string name;
        int age;
    
    Cat(){
    }

    Cat(string nameParam, int ageParam)
    {
        name = nameParam;
        age = ageParam;
    }
};

class Person{
    public:
        Cat cat;
        string name;
    
    Person(){
    }

    Person(Cat catParam, string nameParam){
        cat = catParam;
        name = nameParam;
    }
};

int main()
{
    Person people[NUMPEOPLE] = {{Cat("Cat1",20), "Person1"}, 
                                {Cat("Cat2",30), "Person2"}, 
                                {Cat("Cat3",22), "Person3"}};
    int i, maxIndex, max;

    //Determine the person with the highest age for cat and
    //store the maxIndex for that person 
    max = people[0].cat.age;

    for(i=1; i<NUMPEOPLE; i++)
        if(people[i].cat.age > max){
            max = people[i].cat.age;
            maxIndex = i;
        }
    
    cout << "Info of person with highest age of cat\n";
    cout << "Name: " << people[maxIndex].name << endl;
    cout << "Cat name: " << people[maxIndex].cat.name << endl;
    cout << "Cat age: " << people[maxIndex].cat.age << endl;
    
    return 0;
}
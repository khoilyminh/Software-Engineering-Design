#include <iostream>
#include <vector>

using std::vector;
using std::cout;
using std::string;

template <typename T>
class VectorT{
    private:
        vector<T> myVector;
    public:
        VectorT(vector<T> myVector={}):myVector(myVector){}

        bool findElement(T value){
            for(T elementValue: myVector){
                if(elementValue == value){
                    return true;
                }
            }
            return false;
        }

        void insert(T value){
            myVector.push_back(value);
        }

        void remove(T value){
            for(int i = 0; i<myVector.size(); i++)
                if(myVector[i] == value)
                    myVector.erase(myVector.begin()+i);                    
        }

        void showVector(){
            for(T elementValue : myVector){
                cout << elementValue << " ";
            }
        }
};

int main(){
    VectorT<int> myVec(vector<int>{2,3,4});
    
    myVec.showVector();
    cout << "\n";
    
    myVec.insert(5);
    myVec.showVector();
    cout << "\n";
    
    myVec.remove(3);
    myVec.showVector();
    cout << "\n";

    if(myVec.findElement(5))
        cout << "Found\n";
    else
        cout << "Not found\n";

    VectorT<string> myVec2(vector<string>{"Hello", "Hi", "Morning"});

    myVec2.showVector();
    cout << "\n";
    
    myVec2.insert("Great");
    myVec2.showVector();
    cout << "\n";
    
    myVec2.remove("Hi");
    myVec2.showVector();
    cout << "\n";

    if(myVec2.findElement("Morning"))
        cout << "Found\n";
    else
        cout << "Not found\n";

    return 0;
}
#include <iostream>

template<int N>
class factorial{
    public:
        int value;
        
        factorial(){  //constructor
            int result = 1;
            for(int i=1; i<=N; i++){
                result = result * i;
            }
            value = result;
        }
};

template<>
class factorial<0>{
    public:
        int value = 1;

        factorial(){} //constructor
};

int main(){
    factorial<0> myFac1;
    std::cout << myFac1.value;
    
    std::cout << "\n";

    factorial<3> myFac2;
    std::cout << myFac2.value;

    return 0;
}
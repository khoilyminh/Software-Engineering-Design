#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>
using namespace std;

class ComplNum{
    private:
        double real;
        double imag;
    
    public:
        ComplNum(){
            real = 0.0;
            imag = 0.0;
        }

        ComplNum(double real, double imag){
            this->real = real;
            this->imag = imag;
        }

        //object - object
        ComplNum operator - (ComplNum &cn){
            ComplNum temp;
            temp.real = this->real - cn.real;
            temp.imag = this->imag - cn.imag;
            return temp;
        }

        //object - double
        ComplNum operator - (double num){
            ComplNum temp;
            temp.real = this->real - num;
            temp.imag = this->imag;
            return temp;
        }

        //object--
        ComplNum operator -- (int){
            real--;
            imag--;
            return *this;
        }

        //--object
        ComplNum operator -- (){
            real--;
            imag--;
            return *this;
        }

        //double - object
        friend ComplNum operator - (double num, ComplNum cn);
        
        //Absolute value of complex number, a + ib is defined as the 
        //distance between the origin(0,0) and the point(a,b) in the complex
        //plane, i.e. |a+ib| = square root of a square + b square
        friend double absolute(ComplNum cn);
        
        string toString(){
            if(imag >= 0) 
                return to_string(real) + "+i" + to_string(imag);
            else 
                return to_string(real) + "-i" + to_string(-imag);  
        }
};

ComplNum operator - (double num, ComplNum cn){
    ComplNum temp;
    temp.real = num - cn.real;
    temp.imag = num - cn.imag;
    return temp;
}

double absolute(ComplNum cn){
    return sqrt((cn.real*cn.real) + (cn.imag*cn.imag));
}

int main()
{
    ComplNum cn1(3.0, 4.0), cn2(1.0, 2.0);
    ComplNum result;

    cout << "Complex number cn1: " << cn1.toString() << "\n";
    cout << "Complex number cn2: " << cn2.toString() << "\n";
    
    result = cn1 - cn2;
    cout << "Result of cn1 - cn2: " << result.toString() << "\n";

    result = cn1 - 2.0;
    cout << "Result of cn1 - 2.0: " << result.toString() << "\n";

    result = 2.0 - cn1;
    cout << "Result of 2.0 - cn1: " << result.toString() << "\n";

    result = --cn1;
    cout << "Result of pre-decrement of cn1: " << result.toString() << "\n";

    result = cn1--;
    cout << "Result of post-decrement of cn1: " << result.toString() << "\n";

    cout << "Complex number cn1: " << cn1.toString() << "\n";
    cout << "Result of absolute value of cn1: " << absolute(cn1) << "\n";

    return 0;
}

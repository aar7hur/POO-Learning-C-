
#include <iostream>
#include <string>

using namespace std;

class ComplexNumber {
    private:
        double real_part;
        double imaginary_part;
        double module;
        double angle;
        char sign;
    
    public:
        ComplexNumber(){};
        ComplexNumber(double real, double imaginary);
        ~ComplexNumber(){};
        double get_real_part(void);
        double get_imaginary_part(void);
        double get_module(void);
        double get_angle(void);
        char get_sign(void);
        void set_sign(const char signal);
        ComplexNumber operator+(ComplexNumber& complex);
        ComplexNumber operator-(const ComplexNumber& complex);
        ComplexNumber operator*(const ComplexNumber& complex);
        ComplexNumber operator/(const ComplexNumber& complex);
        friend ostream & operator << (ostream &out, const ComplexNumber& complex); 
};

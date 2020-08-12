#include "Complexo.h"
#include <iostream>
#include <cmath>
#include <stdio.h>

#define PI 3.1415952

using namespace std;

double ComplexNumber::get_imaginary_part(void)
{
    return this->imaginary_part;
}

double ComplexNumber::get_real_part(void)
{
    return this->real_part;
}

char ComplexNumber::get_sign(void)
{
    return this->sign;
}

void ComplexNumber::set_sign(const char signal)
{
    this->sign = signal;
}

double ComplexNumber::get_module(void)
{
    return this->module;
}
double ComplexNumber::get_angle(void)
{
    return this->angle;
}

ComplexNumber::ComplexNumber(double real, double imaginary)
{
    real_part =  real;
    imaginary_part = imaginary;
    module =  sqrt((real*real + imaginary*imaginary));
    angle = atan2(imaginary, real) * 180/PI;
}

ComplexNumber ComplexNumber::operator+(ComplexNumber& complex)
{
    ComplexNumber Result(
        real_part + complex.real_part,
        imaginary_part + complex.imaginary_part
    );
    return Result;
}

ComplexNumber ComplexNumber::operator-(const ComplexNumber& complex)
{
    ComplexNumber Result(
        (real_part - complex.real_part),
        (imaginary_part - complex.imaginary_part)
    );
    return Result;
}

ComplexNumber ComplexNumber::operator*(const ComplexNumber& complex)
{
    ComplexNumber Result(
        (real_part* complex.real_part - (imaginary_part*complex.imaginary_part)),
        ((imaginary_part*complex.real_part) + (complex.imaginary_part* real_part))
    );
    return Result;
}

ComplexNumber ComplexNumber::operator/(const ComplexNumber& complex)
{
    ComplexNumber Result(
        (real_part*complex.real_part + imaginary_part*complex.imaginary_part) / (pow(complex.real_part,2) + pow(complex.imaginary_part,2)),
        (imaginary_part*complex.real_part - complex.imaginary_part*real_part) / (pow(complex.real_part,2) + pow(complex.imaginary_part,2))
    );
    return Result;
}

ostream& operator << (ostream& out, ComplexNumber& complex)
{   
    if (complex.get_imaginary_part() >= 0)
    {
        complex.set_sign('+');
    }

    // print complex number in rectangular form
    out << "\n\t Valor na forma retangular: ";
    out << "(" << complex.get_real_part();
    out << complex.get_sign() << complex.get_imaginary_part() <<"i" << ")" << endl;

    // Print complex number in polar form
    out << "\t Valor na forma polar: ";
    out << "(" << complex.get_module() << " /_ " << complex.get_angle() <<  ")" << endl;

    return out;
}

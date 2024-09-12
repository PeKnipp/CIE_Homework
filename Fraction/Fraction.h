/////////////////////////////////////////////////////////////
//
// Programmer: Peter Knipper
// Date: 02/05/2024
// Name: Fraction.h
// Description: Declares functions and variables for Fraction class
//
/////////////////////////////////////////////////////////////

#ifndef HW2_FRACTION_H
#define HW2_FRACTION_H

#include <iostream>
using namespace std;

class Fraction {

    //declare public variables and functions
    public:
        Fraction(int numeratorIn = 1, int denominatorIn = 1);
        void setFraction(int newNumerator, int newDenominator);
        int getNumerator() const;
        int getDenominator() const;
        float toFloat() const;
        void print() const;
        void add(Fraction addend);
        void subtract(Fraction subtrahend);
        void multiply(Fraction factor);
        void divide(Fraction divisor);
        void simplify();

    //declare private variables and functions
    private:
        int numerator;
        int denominator;
        int GCD(int num1, int num2);
};


#endif //HW2_FRACTION_H

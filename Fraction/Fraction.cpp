/////////////////////////////////////////////////////////////
//
// Programmer: Peter Knipper
// Date: 02/05/2024
// Name: Fraction.cpp
// Description: Defines functions for Fraction class
//
/////////////////////////////////////////////////////////////
using namespace std;

#include <iostream>
#include "Fraction.h"

//constructor function for Fraction class
Fraction::Fraction(int numeratorIn, int denominatorIn) {
    setFraction(numeratorIn, denominatorIn);
}

/////////////////////////////////////////////////////////////
// Function Name: setFraction
// Description: sets the private variables numerator and denominator for the Fraction class
// Inputs:
//      int newNumerator - the new integer value the user wants to set the numerator as
//
//      int newDenominator - the new integer value the user wants to set the denominator as; SHOULD NOT BE ZERO
//
// Output:
//      int numerator - this private variable will take on the value assigned to newNumerator
//
//      int denominator - this private variable will take on the value assigned to newDenominator
//
// Contingencies:
//      negative denominator - if the denominator is negative, both the numerator and denominator will be
//      multiplied by negative one to ensure that the negative sign is in the numerator or to ensure that a fraction
//      with a negative value on top and bottom becomes positive
//
//      divide by zero - if the denominator is zero, message will be displayed to the user alerting them to an invalid
//      input. The denominator will be set to one instead of zero.
/////////////////////////////////////////////////////////////
void Fraction::setFraction(int newNumerator, int newDenominator) {

    //check for division by zero
    if (newDenominator == 0){
        denominator = 1;
        numerator = newNumerator;
        cout << "INVALID DENOMINATOR! DENOMINATOR MUST NOT EQUAL ZERO!" << endl << "Fraction denominator set to 1. Fraction value = " <<numerator<<"/"<< denominator<<endl;
        return;
    }

    //if negative denominator: multiply numerator and denominator (i.e. 3/-4 -> -3/4; -3/-4 -> 3/4)
    else if (newDenominator < 0){
        denominator = newDenominator * -1;
        numerator = newNumerator * -1;
        return;
    }

    //if no problems set variables as they are input
    else{
        denominator = newDenominator;
        numerator = newNumerator;
        return;
    }
}

//getter functions for Fraction class
int Fraction::getDenominator() const {return denominator;}
int Fraction::getNumerator() const {return numerator;}

//convert Fraction to float
float Fraction::toFloat() const {return static_cast<float>(numerator)/static_cast<float>(denominator);}

// display the current values of Fraction
void Fraction::print() const {cout <<numerator<<"/"<<denominator<<endl;}

//add one Fraction to another
void Fraction::add(Fraction addend) {

    //if same denominator, just add numerators
    if (denominator == addend.getDenominator()){
        numerator += addend.getNumerator();

        //put into lowest terms
        this->simplify();
    }

        //if different denominators, create common denominator by multiplying numerator a by denominator b and vice versa
        //then multiply the denominators by each other
    else {
        numerator = (numerator * addend.getDenominator()) + (addend.getNumerator() * denominator);
        denominator = denominator * addend.getDenominator();

        //put into lowest terms
        this->simplify();
    }
}

//subtract one Fraction from the other
void Fraction::subtract(Fraction subtrahend) {

    //if same denominator, just subtract numerators
    if (denominator == subtrahend.getDenominator()){
        numerator -= subtrahend.getNumerator();

        //put into lowest terms
        this->simplify();
    }

    //if different denominators, create common denominator by multiplying numerator a by denominator b and vice versa
    //then multiply the denominators by each other
    else{
        numerator = (numerator * subtrahend.getDenominator()) - (subtrahend.getNumerator() * denominator);
        denominator = denominator * subtrahend.getDenominator();

       //put into lowest terms
        this->simplify();
    }
}

//multiply Fractions with each other
void Fraction::multiply(Fraction factor) {
    denominator = denominator*factor.getDenominator();
    numerator = numerator*factor.getNumerator();

    //put into lowest terms
    this->simplify();
}

//divide one Fraction by another
void Fraction::divide(Fraction divisor) {
    //if the numerator is 0, then cancel operation to avoid division by zero
    if (divisor.getNumerator() == 0){
        cout << "OPERATION CANCELED: DIVISION BY ZERO"<< endl;
        return;
    }

    denominator = denominator*divisor.getNumerator();
    numerator = numerator*divisor.getDenominator();

    //if negative denominator: multiply numerator and denominator (i.e. 3/-4 -> -3/4; -3/-4 -> 3/4)
    if (denominator < 0){
        denominator = denominator * -1;
        numerator = numerator * -1;
    }

    //put fraction in lowest terms
    this->simplify();
}


void Fraction::simplify() {
    // find greatest common denominator
    int gcd = GCD(numerator, denominator);

    //divide numerator and denominator by gcd to put fraction in lowest terms
    numerator = numerator / gcd;
    denominator = denominator / gcd;
}

/////////////////////////////////////////////////////////////
// Function Name: GCD
// Description: finds the greatest common denominator between two numbers using a recursive form of Euclid's Algorithm
// Inputs: two numbers of type int (num1 and num2)
// Output: one number of type int that is the greatest common denominator of the two numbers
// Contingency: negative numbers - multiplies a negative number by negative one to ensure the function logic does not break
// Source: Kahn Academy
/////////////////////////////////////////////////////////////
int Fraction::GCD(int num1, int num2) {

    //absolute val of num1
    if (num1 < 0){
       num1 = num1 * -1;
   }

    //absolute val of num2
   if (num2 < 0){
       num2 = num2 * -1;
   }

   //if first number is larger
    if (num1 > num2){
        //if the remainder of a/b is zero, b is the GCD;
        if (num2 == 0){
            return num1;
        }
        //recursively divide the divisor by the remainder until return
        else return GCD(num2, num1%num2);
    }

    //if second number is larger
    else if (num2 > num1){
        //if the remainder of a/b is zero, b is the GCD;
        if (num1 == 0){
            return num2;
        }
        //recursively divide the divisor by the remainder until return
        else return GCD(num2%num1, num1);
    }
}
/////////////////////////////////////////////////////////////
//
// Programmer: Peter Knipper
// Date: 02/13/2024
// Name: Mathler.h
// Description: Declares functions and variables for Mathler class
//
/////////////////////////////////////////////////////////////

#ifndef HW3_MATHLER_H
#define HW3_MATHLER_H
#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

bool isValidEquation(const string& testEquation);
int evaluateEquation(const string& equation);
bool isOperator(const char testOperator);
bool isNumber(const char testNumber);

const int MAX_GUESS_NUM = 6;

class Mathler {
public:
    Mathler(string equationIn = "01+01");
    void printEquation(){cout << secretEquation << endl;}
    string getSecretEquation() const {return secretEquation;}
    int getGuessNumber() const {return guessNumber;}
    void setSecretEquation(string newEquation);
    void generateSecreteEquation();
    bool makeGuess(string guessEquation);
    void printFeedback();

private:
    string secretEquation;
    int guessNumber = 0;
    vector<string> guess;
};

#endif //HW3_MATHLER_H

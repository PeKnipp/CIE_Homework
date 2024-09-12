/////////////////////////////////////////////////////////////
//
// Programmer: Peter Knipper
// Date: 02/13/2024
// Name: Mathler.cpp
// Description: Defines functions for Fraction class
//
/////////////////////////////////////////////////////////////

#include "Mathler.h"



Mathler::Mathler(string equationIn){
    srand(time(nullptr));
    setSecretEquation(equationIn);
}

 bool isValidEquation(const string& testEquation){
    //ensure five character string
    if (testEquation.size() != 5){
        return false;
    }

    //set up a counter for the number of operators in the string
    int operatorCounter = 0;

    //set up loop logic
    char currentChar = 'a';

    //iterate through string
    for (int i = 0; i < 5; i++){
        currentChar = testEquation.at(i);

       //ensure numbers at beginning/end of string
        if (i == 0 || i == 4){
            if (!isNumber(currentChar)){
                return false;
            }
        }

        //ensure all other characters are valid
        else {
            if (!(isNumber(currentChar) || isOperator(currentChar))) {
                return false;
            }

            //increase operator counter if an operator is encountered
            if (isOperator(testEquation.at(i))) {
                operatorCounter++;
            }
        }
    }

    //check for only one operator
    if (operatorCounter != 1){
        return false;
    }

    return true;
}

/////////////////////////////////////////////////////////////
// Function Name: isOperator
// Description: checks if character is a valid operator. helper function for isValidEquation
// Inputs: one character - testOperator
// Output: boolean value: true if a valid operator (+, -, *), false if not (/)
/////////////////////////////////////////////////////////////
bool isOperator(const char testOperator){
    if (testOperator == '+' || testOperator == '-' || testOperator == '*'){
        return true;
    }
    else return false;
}

/////////////////////////////////////////////////////////////
// Function Name: isNumber
// Description: checks if character is a number. helper function for isValidEquation
// Inputs: one character - testNumber
// Output: boolean value: true if a number, false if not
/////////////////////////////////////////////////////////////
bool isNumber(const char testNumber){
    if (testNumber >= '0' && testNumber <= '9'){
        return true;
    }
    else return false;
}

int evaluateEquation(const string& equation){
    if (!isValidEquation(equation)){return INT_MIN;}

    //given stringstream application
    stringstream ss(equation);
    int num1, num2;
    char oper;
    ss >> num1 >> oper >> num2;


    //perform the correct operation depending on operator
    switch (oper) {
        case '+':
            return num1 + num2;
        case '-':
            return num1 - num2;
        case '*':
            return num1 * num2;
    }


}

void Mathler::setSecretEquation(string newEquation){
    if (isValidEquation(newEquation)){
        secretEquation = newEquation;
    } else setSecretEquation("01+01");
}

void Mathler::generateSecreteEquation() {

    string secretEquationBuilder = "";
    int tempValHolder = 0;
    bool hasOperator = false;
    //generate random numbers and operator

    tempValHolder = (rand()+1)%10;
    if (tempValHolder == 0){
        secretEquationBuilder = secretEquationBuilder + '0';
    }else secretEquationBuilder.append(to_string(tempValHolder));

    while (!hasOperator && secretEquationBuilder.length() < 3) {
        if (rand() % 2 == 1) {
            switch (rand() % 3) {

                case 0:
                    secretEquationBuilder.append("+");
                    hasOperator = true;
                    break;

                case 1:
                    secretEquationBuilder.append("-");
                    hasOperator = true;
                    break;

                case 2:
                    secretEquationBuilder.append("*");
                    hasOperator = true;
                    break;
            }
        }
        else {
            tempValHolder = rand() % 10;
            if (tempValHolder == 0) {
                secretEquationBuilder = secretEquationBuilder + '0';
            } else secretEquationBuilder.append(to_string(tempValHolder));
        }
    }

    if (!hasOperator) {
        switch (rand() % 3) {

            case 0:
                secretEquationBuilder.append("+");
                hasOperator = true;
                break;

            case 1:
                secretEquationBuilder.append("-");
                hasOperator = true;
                break;

            case 2:
                secretEquationBuilder.append("*");
                hasOperator = true;
                break;
        }
    }

    while (secretEquationBuilder.size() < 5) {
        tempValHolder = rand() % 10;
        if (tempValHolder == 0) {
            secretEquationBuilder = secretEquationBuilder + '0';
        } else secretEquationBuilder.append(to_string(tempValHolder));
    }
    secretEquation = secretEquationBuilder;
}

/////////////////////////////////////////////////////////////
// Function Name: makeGuess
// Description: allows the user to make a guess on the secret equation
// Inputs: one string - guessEquation
// Output: boolean value: true if the guess is equal to the secret equation, false else
/////////////////////////////////////////////////////////////
bool Mathler::makeGuess(string guessEquation) {

    if (!isValidEquation(guessEquation) || (evaluateEquation(guessEquation) != evaluateEquation(secretEquation))){
        if (evaluateEquation(guessEquation) != evaluateEquation(secretEquation)) {
            cout << "Does not evaluate to same value as secret equation! Try again." << endl;
        }
        return false;
    }

    if (guessNumber < MAX_GUESS_NUM) {
        guess.push_back(guessEquation);
        guessNumber++;

        if (guessEquation == secretEquation) {
            return true;
        }
        else if (guessNumber == MAX_GUESS_NUM) {
            cout << "MAX NUMBER OF GUESSES REACHED"<<endl;
            cout << "GAME OVER: YOU DID NOT FIND THE SECRET EQUATION: " << secretEquation << endl;
            return false;
        }
        else return false;
    }
}

/////////////////////////////////////////////////////////////
// Function Name: printFeedback
// Description: prints the guesses made by the user
// Inputs: no inputs
// Output: prints guesses to terminal
/////////////////////////////////////////////////////////////
void Mathler::printFeedback() {
    int i = 1;
    for(string userInput:guess){

        cout << i << ": " << userInput <<endl;
        i++;
    }
}
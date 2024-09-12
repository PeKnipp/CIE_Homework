/////////////////////////////////////////////////////////////
//
// Programmer: Peter Knipper
// Date: 02/13/2024
// Name: main.cpp
// Description: Base code for the Mathler game
//
/////////////////////////////////////////////////////////////

#include <iostream>
#include "Mathler.h"

int main() {
    //Test Bench

    //Test 1
    //isValidEquation

    //1.1 valid equations
    if (isValidEquation("32+12")) {
        cout << "Test 1.1.1 passed! 32+12 is a valid equation." << endl;
    } else cout << "*Test 1.1.1 failed! 32+12 is a valid equation." << endl;

    if (isValidEquation("580-7")) {
        cout << "Test 1.1.2 passed! 58-07 is a valid equation." << endl;
    } else cout << "*Test 1.1.2 failed! 58-07 is a valid equation." << endl;

    if (isValidEquation("7*137")) {
        cout << "Test 1.1.3 passed! 7*137 is a valid equation." << endl;
    } else cout << "*Test 1.1.3 failed! 7*137 is a valid equation." << endl;

    //1.2 invalid equations
    //1.2.1 number of characters
    if (!isValidEquation("467-38")) {
        cout << "Test 1.2.1.1 passed! 467-38 is an invalid equation." << endl;
    } else cout << "*Test 1.2.1.1 failed! 467-38 is an invalid equation." << endl;

    if (!isValidEquation("98+2")) {
        cout << "Test 1.2.1.2 passed! 98+2 is an invalid equation." << endl;
    } else cout << "*Test 1.2.1.2 failed! 98+2 is an invalid equation." << endl;

    //1.2.2 invalid characters
    if (!isValidEquation("39/13")) {
        cout << "Test 1.2.2.1 passed! 39/13 is an invalid equation." << endl;
    } else cout << "*Test 1.2.2.1 failed! 39/13 is an invalid equation." << endl;

    if (!isValidEquation("73-4x")) {
        cout << "Test 1.2.2.2 passed! 73-4x is an invalid equation." << endl;
    } else cout << "*Test 1.2.2.2 failed! 73 - 4x is an invalid equation." << endl;

    if (!isValidEquation("6 + 2")) {
        cout << "Test 1.2.2.2 passed! 6 + 2 is an invalid equation." << endl;
    } else cout << "*Test 1.2.2.2 failed! 6 + 2 is an invalid equation." << endl;

    //1.2.3 operators
    if (!isValidEquation("12345")) {
        cout << "Test 1.2.3.1 passed! 12345 has no operators." << endl;
    } else cout << "*Test 1.2.3.1 failed! 12345 has no operators." << endl;

    if (!isValidEquation("1+8*5")) {
        cout << "Test 1.2.3.2 passed! 1+8*5 has too many operators." << endl;
    } else cout << "*Test 1.2.3.2 failed! 1+8*5 has too many operators" << endl;

    if (!isValidEquation("*5678")) {
        cout << "Test 1.2.3.3 passed! *5678 has operator in an incorrect position." << endl;
    } else cout << "*Test 1.2.3.3 failed! *5678 has operator in an incorrect position." << endl;

    if (!isValidEquation("1357-")) {
        cout << "Test 1.2.3.4 passed! 1357- has operator in an incorrect position." << endl;
    } else cout << "*Test 1.2.3.4 failed! 1357- has operator in an incorrect position." << endl;


    //Test 2
    // evaluateEquation

    //2.1 valid equations
    if (evaluateEquation("35+35") == 70) {
        cout << "Test 2.1.1 passed! Expected 70; 35+35 = " << evaluateEquation("35+35") << endl;
    } else cout << "*Test 2.1.1 failed! Expected 70; 35+35 != " << evaluateEquation("35+35") << endl;

    if (evaluateEquation("50*11") == 550) {
        cout << "Test 2.1.2 passed! Expected 550; 50*11 = " << evaluateEquation("50*11") << endl;
    } else cout << "*Test 2.1.2 failed! Expected 550; 50*11 != " << evaluateEquation("50*11") << endl;

    if (evaluateEquation("20-34") == -14) {
        cout << "Test 2.1.3 passed! Expected -14; 20-34 = " << evaluateEquation("20-34") << endl;
    } else cout << "*Test 2.1.3 failed! Expected -14; 50*11 != " << evaluateEquation("20-34") << endl;

    //2.2 invalid equations
    if (evaluateEquation("4+87") == INT_MIN) {
        cout << "Test 2.2.1 passed! 4+87 is an invalid equation" << endl;
    } else cout << "*Test 2.2.1 failed! 4+87 should have been flagged as an invalid equation" << endl;

    if (evaluateEquation("84/02") == INT_MIN) {
        cout << "Test 2.2.2 passed! 84/02 is an invalid equation" << endl;
    } else cout << "*Test 2.2.2 failed! 84/02 should have been flagged as an invalid equation" << endl;

    if (evaluateEquation("147-45") == INT_MIN) {
        cout << "Test 2.2.3 passed! 147-45 is an invalid equation" << endl;
    } else cout << "*Test 2.2.3 failed! 147-45 should have been flagged as an invalid equation" << endl;


    //Test 3
    //constructors, getters, setters

    Mathler m;
    if (m.getSecretEquation() == "01+01") {
        cout << "Test 3.1 passed! Expected 01+01; Correctly initialized without arguments: " << m.getSecretEquation()
             << endl;
    } else
        cout << "*Test 3.1 failed! Expected 01+01; Incorrectly initialized without arguments: " << m.getSecretEquation()
             << endl;

    Mathler n("69+42");
    if (n.getSecretEquation() == "69+42") {
        cout << "Test 3.2 passed! Expected 69+42; Correctly initialized without arguments: " << n.getSecretEquation()
             << endl;
    } else
        cout << "*Test 3.2 failed! Expected 69+42; Incorrectly initialized without arguments: " << n.getSecretEquation()
             << endl;

    m.setSecretEquation("23*09");
    if (m.getSecretEquation() == "23*09") {
        cout << "Test 3.3 passed! Expected 23+09; Correctly set m to " << m.getSecretEquation() << endl;
    } else cout << "*Test 3.3 failed! Expected 23+09; Incorrectly set m to " << m.getSecretEquation() << endl;

    n.setSecretEquation("255/5");
    if (n.getSecretEquation() == "01+01") {
        cout << "Test 3.4 passed! Expected 01+01 Correctly recognized invalid equation and set n to "
             << n.getSecretEquation() << endl;
    } else cout << "*Test 3.4 failed! Expected 01+01; Incorrectly set m to " << n.getSecretEquation() << endl;


    //Test 4
    //generateRandomEquation
    m.generateSecreteEquation();
    if (isValidEquation(m.getSecretEquation())) {
        cout << "Test 4.1 passed! A valid equation was generated: " << m.getSecretEquation() << endl;
    } else cout << "*Test 4.1 failed! An invalid equation was generated: " << m.getSecretEquation() << endl;

    n.generateSecreteEquation();
    if (isValidEquation(n.getSecretEquation())) {
        cout << "Test 4.2 passed! A valid equation was generated: " << n.getSecretEquation() << endl;
    } else cout << "*Test 4.2 failed! An invalid equation was generated: " << n.getSecretEquation() << endl;

    //Test 5
    //makeGuess and printFeedback

    //valid guesses
    Mathler test5("11+11");
    test5.setSecretEquation("13+15");
    cout << "Setting secret equation to 13+15. The secret equation is " <<test5.getSecretEquation() << "." << endl;
    test5.makeGuess("10+18");
    test5.makeGuess("30-02");
    test5.printFeedback();
    cout<<endl;

    //invalid guesses
    test5.makeGuess("1+18");
    test5.makeGuess("100*18");
    test5.makeGuess("30/02");
    test5.makeGuess("28-04");
    test5.printFeedback();
    cout<< "The above sets of two print feedback should out put the same value."<<endl<<endl;

    //correct guess
    test5.makeGuess("13+15");

    //test max amount of guesses
    Mathler testMaxAmount("72-24");

    //add guesses until reach max and print results
    testMaxAmount.makeGuess("04*12");
    testMaxAmount.printFeedback();
    cout<<endl;

    testMaxAmount.makeGuess("50-02");
    testMaxAmount.printFeedback();
    cout<<endl;

    testMaxAmount.makeGuess("36+12");
    testMaxAmount.printFeedback();
    cout<<endl;

    testMaxAmount.makeGuess("40+08");
    testMaxAmount.printFeedback();
    cout<<endl;

    testMaxAmount.makeGuess("65-17");
    testMaxAmount.printFeedback();
    cout<<endl;
    //should be last guess displayed to terminal
    testMaxAmount.makeGuess("83-35");
    testMaxAmount.printFeedback();
    cout<<endl;

//    //neither of the following guesses should be displayed or added to guess; error message should be displayed
//    testMaxAmount.makeGuess("24*02");
//    testMaxAmount.printFeedback();
//    cout<<endl;
//
//    testMaxAmount.makeGuess("35+13");
//    testMaxAmount.printFeedback();
//    cout<<endl<<endl<<endl;


    //END TEST BENCH

    //welcome and instructions
    cout<<"Guess the Mathler in 6 attempts!"<<endl<<endl;
    cout<<"RULES:"<<endl;
    cout<<"Each guess must a five characters equation with only one operator (division is not allowed)"<<endl;
    cout<<"The guess must evaluate to the same value as the secret equation"<<endl;
    cout<<"Hit enter after typing your guess to submit it"<<endl<<endl;

    Mathler gameEquation;
    gameEquation.generateSecreteEquation();
    string userGuess = "";

    cout<<"The secret equation is: "<<gameEquation.getSecretEquation()<<endl;
    cout<<"Guess an equation that evaluates to "<<evaluateEquation(gameEquation.getSecretEquation())<<endl;
    while(gameEquation.getGuessNumber() < MAX_GUESS_NUM){
        cout<<"Enter Guess: ";
        cin >> userGuess;
        if (gameEquation.makeGuess(userGuess)){
            cout<<"CONGRATULATIONS! YOU FOUND THE SECRET EQUATION: "<<gameEquation.getSecretEquation()<<endl<<endl;
            gameEquation.printFeedback();
            return 0;
        }
        cout<<endl;
        gameEquation.printFeedback();
        cout<<endl;
    }

    return 0;
}
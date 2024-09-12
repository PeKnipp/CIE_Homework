/////////////////////////////////////////////////////////////
//
// Programmer: Peter Knipper
// Date: 04/04/2024
// Name: main.cpp
// Description: Tests for Book, Audiobook, and Magazine classes
//
/////////////////////////////////////////////////////////////

#include <iostream>
#include <string>
#include "Item.h"
#include "Book.h"
#include "Audiobook.h"
#include "Magazine.h"
using namespace std;

int main() {
    Book A("C++ for Dummies", "Stephen R. Davis", 2009, "How-To", 432);
    Book B("Hitchhikers Guide to the Galaxy", "Douglas Adams", 1979, "Sci-Fi", 224);
    Audiobook C("Green Eggs and Ham", "Dr. Seuss", 1960, "David Attenborough", 5);
    Audiobook D("Goodnight Moon", "Margaret Wise", 1947, "James Earl Jones", 3);

    cout << "Testing Book Constructor" << endl;
    A.print();
    cout << endl;

    cout << "Testing Audiobook Constructor" << endl;
    C.print();
    cout << endl;

    cout << "Testing Inheritance Access for Book" << endl;
    cout << "Original Output:" << endl;
    B.print();
    B.setTitle("The Universe and Its Inhabitants");
    B.setAuthor("Al Ien");
    cout << endl << "New Output" << endl;
    B.print();
    cout <<endl;

    cout << "Testing Inheritance Access for Audiobook" << endl;
    cout << "Original Output:" << endl;
    D.print();
    D.setTitle("Good Morning Sun");
    D.setAuthor("Peggy Foolish");
    cout << endl << "New Output" << endl;
    D.print();
    cout << endl;

    cout << "Testing Copy Constructor" << endl;
    Magazine E("National Geographic", 1);
    Magazine copyOfE(E);
    cout << endl << "Expected Output:" << endl;
    E.print();
    cout << endl << "Actual Output: " << endl;
    copyOfE.print();
    cout << endl;

    cout << "Testing Copy Assignment Operator" << endl;
    Magazine F("Vogue", 17);
    Magazine copyOfF;
    copyOfF = F;

    cout << endl <<"Expected Output:" << endl;
    F.print();
    cout << endl << "Actual Output:" << endl;
    copyOfF.print();
    cout << endl;

    return 0;
}

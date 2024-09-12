/////////////////////////////////////////////////////////////
//
// Programmer: Peter Knipper
// Date: 04/05/2024
// Name: main.cpp
// Description: Declares functions and variables for Magazine class
//
/////////////////////////////////////////////////////////////

using namespace std;
#ifndef HW6_MAGAZINE_H
#define HW6_MAGAZINE_H
#include <iostream>

class Magazine {
public:
    Magazine(char* nameIn= "default", int issueNumberIn = 0);

    Magazine(const Magazine &origObject);

    Magazine& operator=(const Magazine& objToCopy);

    ~Magazine();

    char *getName() const;

    void setName(char *name);

    int getIssueNumber() const;

    void setIssueNumber(int issueNumber);

    void print() const;

private:
    char* name;
    int issueNumber;
};


#endif //HW6_MAGAZINE_H

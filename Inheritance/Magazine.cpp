/////////////////////////////////////////////////////////////
//
// Programmer: Peter Knipper
// Date: 04/05/2024
// Name: item.cpp
// Description: Defines functions for Magazine class
//
/////////////////////////////////////////////////////////////

#include <cstring>
#include "Magazine.h"
Magazine::Magazine(char* nameIn, int issueNumberIn) {
    cout << "in constructor" << endl;
    Magazine::name = nameIn;
    Magazine::issueNumber = issueNumberIn;
}

Magazine::Magazine(const Magazine &origObject) {
    cout << "in copy constructor" << endl;
    Magazine::name = new char[strlen(origObject.name)+1];
    for (int i = 0; i < strlen(origObject.name); i++){
        name[i] = origObject.name[i];
    }

    name[strlen(origObject.name)] = '\0';
    *name = *origObject.name;
    Magazine::issueNumber = origObject.getIssueNumber();
}

Magazine& Magazine::operator=(const Magazine &objToCopy) {
    cout << "in copy assignment operator" << endl;
    if (this != &objToCopy){
        name = nullptr;
        delete[] name;
        Magazine::name = new char[strlen(objToCopy.name)+1];
        for (int i = 0; i < strlen(objToCopy.name); i++){
            name[i] = objToCopy.name[i];
        }

        name[strlen(objToCopy.name)] = '\0';
        *name = *objToCopy.name;
        Magazine::issueNumber = objToCopy.getIssueNumber();
    }
    return *this;
}

Magazine::~Magazine() {
    cout << "destroying " << this->getName() << endl;
    name = nullptr;
    delete[] name;
}

char *Magazine::getName() const {
    return name;
}

void Magazine::setName(char *name) {
    Magazine::name = name;
}

int Magazine::getIssueNumber() const {
    return issueNumber;
}

void Magazine::setIssueNumber(int issueNumber) {
    Magazine::issueNumber = issueNumber;
}

void Magazine::print() const{
    cout << "Magazine" << endl << "Name: " << name << endl << "Issue Number: " << issueNumber << endl;
}
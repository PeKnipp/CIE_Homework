/////////////////////////////////////////////////////////////
//
// Programmer: Peter Knipper
// Date: 04/05/2024
// Name: main.cpp
// Description: Declares functions and variables for Item class
//
/////////////////////////////////////////////////////////////

using namespace std;
#ifndef HW6_ITEM_H
#define HW6_ITEM_H
#include <string>
#include <iostream>


class Item {
public:
    Item(string titleIn = "default", string authorIn = "default", int yearIn = 0);

    void setTitle(const string &title);

    void setAuthor(const string &author);

    void setYear(int year);

    const string &getTitle() const;

    const string &getAuthor() const;

    int getYear() const;

    void print() const;

private:
    string title;
    string author;
    int year;
};


#endif //HW6_ITEM_H

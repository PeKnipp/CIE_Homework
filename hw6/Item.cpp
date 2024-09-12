/////////////////////////////////////////////////////////////
//
// Programmer: Peter Knipper
// Date: 04/05/2024
// Name: item.cpp
// Description: Defines functions for Item class
//
/////////////////////////////////////////////////////////////

#include "Item.h"

Item::Item(string titleIn, string authorIn, int yearIn) {
    Item::title = titleIn;
    Item::author = authorIn;
    Item::year = yearIn;
}

void Item::setTitle(const string &title) {
    Item::title = title;
}

void Item::setAuthor(const string &author) {
    Item::author = author;
}

void Item::setYear(int year) {
    Item::year = year;
}

const string &Item::getTitle() const {
    return title;
}

const string &Item::getAuthor() const {
    return author;
}

int Item::getYear() const {
    return year;
}

void Item::print() const {
    cout << "Title: " << title << endl << "Author: " << author << endl << "Year: " << year << endl;
}
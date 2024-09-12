/////////////////////////////////////////////////////////////
//
// Programmer: Peter Knipper
// Date: 04/05/2024
// Name: main.cpp
// Description: Declares functions and variables for Book class
//
/////////////////////////////////////////////////////////////

#ifndef HW6_BOOK_H
#define HW6_BOOK_H
#include "Item.h"


class Book: public Item{
public:
    Book(string titleIn = "default", string authorIn = "default", int yearIn = 0, string genreIn = "default", int pagesIn = 0);

    const string & getGenre() const;

    void setGenre(const string &genre);

    int getPages() const;

    void setPages(int pagesIn);

    void print() const;

private:
    string genre;
    int pages;
};


#endif //HW6_BOOK_H

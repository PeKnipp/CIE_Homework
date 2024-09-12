/////////////////////////////////////////////////////////////
//
// Programmer: Peter Knipper
// Date: 04/05/2024
// Name: item.cpp
// Description: Defines functions for Book class
//
/////////////////////////////////////////////////////////////

#include "Book.h"

Book::Book(string titleIn, string authorIn, int yearIn, string genreIn, int pagesIn):
Item{titleIn, authorIn, yearIn}, genre{genreIn}, pages{pagesIn} {}

const string &Book::getGenre() const {
    return genre;
}

void Book::setGenre(const string &genre) {
    Book::genre = genre;
}

int Book::getPages() const {
    return pages;
}

void Book::setPages(int pages) {
    Book::pages = pages;
}

void Book::print() const{
    cout<< "Book" << endl;
    Item::print();
    cout << "Genre: " << genre << endl << "Pages: " << pages << endl;
}
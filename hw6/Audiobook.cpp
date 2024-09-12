/////////////////////////////////////////////////////////////
//
// Programmer: Peter Knipper
// Date: 04/05/2024
// Name: item.cpp
// Description: Defines functions for Audiobook class
//
/////////////////////////////////////////////////////////////

#include "Audiobook.h"

Audiobook::Audiobook(string titleIn, string authorIn, int yearIn, string narratorIn, int durationIn):
Item{titleIn, authorIn, yearIn}, narrator{narratorIn}, duration{durationIn} {}

const string &Audiobook::getNarrator() const {
    return narrator;
}

void Audiobook::setNarrator(const string &narrator) {
    Audiobook::narrator = narrator;
}

int Audiobook::getDuration() const {
    return duration;
}

void Audiobook::setDuration(int duration) {
    Audiobook::duration = duration;
}

void Audiobook::print() const {
    cout << "Audiobook" << endl;
    Item::print();
    cout << "Narrator: " << narrator << endl << "Duration: " << duration << " minutes" << endl;
}
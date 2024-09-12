/////////////////////////////////////////////////////////////
//
// Programmer: Peter Knipper
// Date: 04/05/2024
// Name: main.cpp
// Description: Declares functions and variables for Audiobook class
//
/////////////////////////////////////////////////////////////

#ifndef HW6_AUDIOBOOK_H
#define HW6_AUDIOBOOK_H
#include "Item.h"

class Audiobook: public Item{
public:
    Audiobook(string titleIn = "default", string authorIn = "default", int yearIn = 0, string narratorIn = "default", int durationIn = 0);

    const string &getNarrator() const;

    void setNarrator(const string &narrator);

    int getDuration() const;

    void setDuration(int duration);

    void print() const;

private:
    string narrator;
    int duration;
};


#endif //HW6_AUDIOBOOK_H

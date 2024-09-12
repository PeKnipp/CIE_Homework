//
// Created by peter on 4/27/2024.
//

#ifndef HW8_MYLIST_H
#define HW8_MYLIST_H
#include <iostream>
#include "Node.h"

class MyList {
public:
    MyList();

    void printAscending();

    void printDescending();

    void insert(int inputValue);

    void remove(int inputValue);

    void clear();

    ~MyList();

    Node *getCurrPtr() const;

    void setCurrPtr(Node *currPtr);

private:
    Node* currPtr;
};


#endif //HW8_MYLIST_H

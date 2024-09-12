//
// Created by peter on 4/27/2024.
//

#include "MyList.h"

MyList::MyList() {
    currPtr = nullptr;
}

void MyList::printAscending() {

    //in case of empty list
    if (currPtr == nullptr){
        cout << "The list is empty." << endl;
        return;
    }

    //move pointer to first node
    while (currPtr->getPrevPtr() != nullptr){
        currPtr = currPtr->getPrevPtr();
    }

    //print every node until last node is reached
    while (currPtr->getNextPtr() != nullptr){
        currPtr->print();
        currPtr = currPtr->getNextPtr();
    }

    //print last node
    currPtr->print();
}

void MyList::printDescending() {

    //in case of empty list
    if (currPtr == nullptr){
        cout << "The list is empty." << endl;
        return;
    }

    //move pointer to last node
    while (currPtr->getNextPtr() != nullptr){
        currPtr = currPtr->getNextPtr();
    }

    //print every node until first node is reached
    while (currPtr->getPrevPtr() != nullptr){
        currPtr->print();
        currPtr = currPtr->getPrevPtr();
    }

    //print first node
    currPtr->print();
}

void MyList::insert(int inputValue) {

    // create new Node
    Node* newPtr = new Node(inputValue);

    //Ensure Node created successfully
    if (newPtr == nullptr){
        cout << "Could not create node" << endl;
        return;
    }

    //if empty list, set currPtr to the new Node
    if (currPtr == nullptr){
        currPtr = newPtr;
        return;
    }

    //check if the new value is a duplicate of the current value, do not insert, alert user
    if (currPtr->getData() == newPtr->getData()){
        cout << "Value already in list" << endl;
        delete newPtr;
        return;
    }

    //if the new value is greater than the current value
    if (newPtr->getData() > currPtr->getData()){
        //move currPtr up until new value is no longer greater than current values or reached last node
        while (newPtr->getData() > currPtr->getData() && currPtr->getNextPtr() != nullptr){

            //if value already in list, do not insert, alert user
            if (currPtr->getData() == newPtr->getData() || currPtr->getNextPtr()->getData() == newPtr->getData()){
                cout << "Value already in list" << endl;
                delete newPtr;
                return;
            }

            //increment currPtr
            else{
                currPtr = currPtr->getNextPtr();
            }
        }

        //adding value to the end of the list
        if (newPtr->getData() > currPtr->getData() && currPtr->getNextPtr() == nullptr){
            currPtr->setNextPtr(newPtr);
            newPtr->setPrevPtr(currPtr);
            currPtr = newPtr;
        }

        //adding value between existing values
        else{
            newPtr->setNextPtr(currPtr);
            newPtr->setPrevPtr(currPtr->getPrevPtr());
            currPtr->getPrevPtr()->setNextPtr(newPtr);
            currPtr->setPrevPtr(newPtr);
            currPtr = newPtr;
        }
        return;
    }

    //if new value is less than current value
    else if (newPtr->getData() < currPtr->getData()){
        //move currPtr down until new value is no longer less than current values or reached last node
        while (newPtr->getData() < currPtr->getData() && currPtr->getPrevPtr() != nullptr){

            //if value already in list, do not insert, alert user
            if (currPtr->getData() == newPtr->getData() || currPtr->getPrevPtr()->getData() == newPtr->getData()){
                cout << "Value already in list" << endl;
                delete newPtr;
                return;
            }

            //decrement currPtr
            else{
                currPtr = currPtr->getPrevPtr();
            }
        }

        //adding value to start of list
        if (newPtr->getData() < currPtr->getData() && currPtr->getPrevPtr() == nullptr){
            currPtr->setPrevPtr(newPtr);
            newPtr->setNextPtr(currPtr);
            currPtr = newPtr;
        }

        //adding value between existing values
        else{
            newPtr->setNextPtr(currPtr->getNextPtr());
            newPtr->setPrevPtr(currPtr);
            currPtr->getNextPtr()->setPrevPtr(newPtr);
            currPtr->setNextPtr(newPtr);
            currPtr = newPtr;
        }

        return;
    }



}

void MyList::remove(int inputValue) {

    //if value to be deleted is greater than current value
    if (inputValue > currPtr->getData()){

        //increment until at or above value to be deleted
        while (inputValue > currPtr->getData() && currPtr->getNextPtr() != nullptr){
            currPtr = currPtr->getNextPtr();
        }

        //if value to be deleted is passed or is higher than last values in list, it cannot be in list
        if (inputValue < currPtr->getData() || (inputValue != currPtr->getData() && currPtr->getNextPtr() == nullptr)){
            cout << "Value not in list" << endl;
            return;
        }
    }

    //if value to be deleted is less than current value
    else if (inputValue < currPtr->getData()){

        //decrement until at or below
        while (inputValue < currPtr->getData() && currPtr->getPrevPtr() != nullptr){
            currPtr = currPtr->getPrevPtr();
        }

        //if value to be deleted is passed or is lower than first value in list, it cannot be in list
        if (inputValue > currPtr->getData() || (inputValue != currPtr->getData() && currPtr->getPrevPtr() == nullptr)){
            cout << "Value not in list" << endl;
        }
    }

    //deleting last value
    if (currPtr->getPrevPtr() == nullptr && currPtr->getNextPtr() == nullptr){
        Node* temp = currPtr;
        currPtr = nullptr;
        delete temp;
    }

    //deleting first value
    else if(currPtr->getNextPtr() == nullptr){
        Node* temp = currPtr;
        currPtr->getPrevPtr()->setNextPtr(nullptr);
        currPtr = currPtr->getPrevPtr();
        delete temp;
    }

    //deleting only value in list
    else if (currPtr->getPrevPtr() == nullptr){
        Node* temp = currPtr;
        currPtr->getNextPtr()->setPrevPtr(nullptr);
        currPtr = currPtr->getNextPtr();
        delete temp;
    }

    //deleting between two existing values
    else{
        Node* temp = currPtr;
        currPtr->getPrevPtr()->setNextPtr(currPtr->getNextPtr());
        currPtr->getNextPtr()->setPrevPtr(currPtr->getPrevPtr());
        currPtr = currPtr->getPrevPtr();
        delete temp;
    }

    //alert user to deletion
    cout << inputValue << " deleted from list." << endl;
}

void MyList::clear() {
    //call remove until no values remain in list
    while (currPtr != nullptr){
        remove(currPtr->getData());
    }
}

MyList::~MyList(){
    clear();
}

Node *MyList::getCurrPtr() const {
    return currPtr;
}

void MyList::setCurrPtr(Node *currPtr) {
    MyList::currPtr = currPtr;
}


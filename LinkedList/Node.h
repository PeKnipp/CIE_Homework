//
// Created by peter on 4/27/2024.
//

#ifndef HW8_NODE_H
#define HW8_NODE_H
#include <iostream>

using namespace std;

class Node {
public:
    Node(int dataIn = 0, Node* nextPtrIn = nullptr, Node* prevPtrIn = nullptr);

    void print();

    int getData() const;

    void setData(int data);

    Node *getNextPtr() const;

    void setNextPtr(Node *nextPtr);

    Node *getPrevPtr() const;

    void setPrevPtr(Node *prevPtr);

private:
    int data;
    Node* nextPtr;
    Node* prevPtr;
};


#endif //HW8_NODE_H

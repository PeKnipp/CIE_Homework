//
// Created by peter on 4/27/2024.
//

#include "Node.h"
Node::Node(int dataIn, Node* nextPtrIn, Node* prevPtrIn){
    setData(dataIn);
    setNextPtr(nextPtrIn);
    setPrevPtr(prevPtrIn);
};

void Node::print(){
    cout<<getData()<<endl;
}

int Node::getData() const {
    return data;
}

void Node::setData(int data) {
    Node::data = data;
}

Node *Node::getNextPtr() const {
    return nextPtr;
}

void Node::setNextPtr(Node *nextPtr) {
    Node::nextPtr = nextPtr;
}

Node *Node::getPrevPtr() const {
    return prevPtr;
}

void Node::setPrevPtr(Node *prevPtr) {
    Node::prevPtr = prevPtr;
}
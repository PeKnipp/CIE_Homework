#include <iostream>
#include "Node.h"
#include "MyList.h"

using namespace std;

int main() {
    //Test Node Class
    cout << endl << "Testing Node Class" << endl;

    //Test default constructor
    Node d = Node();

    cout << endl << "Testing default constructor for Node class" << endl;
    if (d.getData() == 0){
        cout << "Correctly initialized d.data to 0" << endl;
    } else cout << endl << "Incorrectly initialized d.data" << endl << "Expected value: 0" << endl << "Actual value: " << d.getData() << endl << endl;

    if (d.getPrevPtr() == nullptr){
        cout << "Correctly initialized d.prevPtr to nullPtr" << endl;
    } else cout << endl << "Incorrectly initialized d.prevPtr" << endl << "Expected value: "<< nullptr << endl << "Actual value: " << d.getPrevPtr() << endl << endl;

    if (d.getNextPtr() == nullptr){
        cout << "Correctly initialized d.nextPtr to nullPtr" << endl;
    } else cout << endl << "Incorrectly initialized d.nextPtr" << endl << "Expected value: " << nullptr << endl << "Actual value: " << d.getNextPtr() << endl << endl;

    //Test detailed constructor
    Node a = Node(2);
    Node b = Node(1,&a);
    Node c = Node(3, &b,&a);

    cout << endl << "Testing detailed constructor for node class" << endl;
    if(b.getNextPtr()->getData() == a.getData()){
        cout << "Correctly initialized b.nextPtr to a" << endl;
    }else cout << endl << "Incorrectly initialized b.nextPtr" << endl << "Expected value: " << a.getData() << endl << "Actual value: " << b.getNextPtr()->getData() << endl << endl;

    if(c.getNextPtr()->getData() == b.getData() && c.getPrevPtr()->getData() == a.getData()){
        cout << "Correctly initialized c.nextPtr to b and c.prevPtr to a" << endl;
    }else cout << endl << "Incorrectly initialized c.nextPtr or c.prevPtr" << endl << "Expected value for c.nextPtr: " << b.getData() << endl << "Actual value for c.nextPtr: " << c.getNextPtr()->getData() << endl << "Expected value for c.PrevPtr: " << a.getData() << endl << "Actual value for c.PrevPtr: " << c.getPrevPtr()->getData()<< endl << endl;

    //Test Node::print
    cout << endl << "Testing Node::print" << endl;
    cout << "Correct output: " << endl << 2 << endl << 1 << endl << 3 << endl<< 0 << endl << endl;
    cout << "Actual output: " << endl;
    a.print();
    b.print();
    c.print();
    d.print();


    //Test MyList class
    cout << endl << "Testing MyList Class" << endl;

    //Test constructor
    MyList myList = MyList();

    cout << endl << "Testing constructor for MyList Class" << endl;
    if (myList.getCurrPtr() == nullptr){
        cout << "Correctly initialized myClass.currPtr to nullPtr" << endl;
    } else cout << endl << "Incorrectly initialized myClass.currPtr" << endl << "Expected value: " << nullptr << endl << "Actual value: " << myList.getCurrPtr();


    //Test MyList::insert
    myList.insert(5);

    cout << endl << "Testing MyClass::insert" << endl;
    if (myList.getCurrPtr()->getData() == 5 && myList.getCurrPtr()->getPrevPtr() == nullptr && myList.getCurrPtr()->getNextPtr() == nullptr){
        cout << "Correctly inserted 5 into myList" << endl;
    } else cout << endl << "Incorrectly inserted 5 into myList" << endl
                << endl << "Expected output:" << endl << "currPtr.data = " << 5 << "currPtr.prevPtr = " << nullptr << endl << "currPtr.nextPtr = " << nullptr << endl
                << endl << "Actual output:" << endl << "currPtr.data = " << myList.getCurrPtr()->getData() << "currPtr.prevPtr = " << myList.getCurrPtr()->getPrevPtr() << endl << "currPtr.nextPtr = " << myList.getCurrPtr()->getNextPtr() << endl << endl;

    myList.insert(3);
    if (myList.getCurrPtr()->getData() == 3 && myList.getCurrPtr()->getPrevPtr() == nullptr && myList.getCurrPtr()->getNextPtr()->getData() == 5){
        cout << "Correctly inserted 3 into myList" << endl;
    } else cout << endl << "Incorrectly inserted 3 into myList" << endl
                << endl << "Expected output:" << endl << "currPtr.data = " << 3 << "currPtr.prevPtr = " << nullptr << endl << "currPtr.nextPtr = " << 5 << endl
                << endl << "Actual output:" << endl << "currPtr.data = " << myList.getCurrPtr()->getData() << "currPtr.prevPtr = " << myList.getCurrPtr()->getPrevPtr() << endl << "currPtr.nextPtr = " << myList.getCurrPtr()->getNextPtr()->getData() << endl << endl;

    myList.insert(7);
    if (myList.getCurrPtr()->getData() == 7 && myList.getCurrPtr()->getPrevPtr()->getData() == 5 && myList.getCurrPtr()->getNextPtr() == nullptr){
        cout << "Correctly inserted 7 into myList" << endl;
    } else cout << endl << "Incorrectly inserted 7 into myList" << endl
                << endl << "Expected output:" << endl << "currPtr.data = " << 7 << "currPtr.prevPtr = " << 5 << endl << "currPtr.nextPtr = " << nullptr << endl
                << endl << "Actual output:" << endl << "currPtr.data = " << myList.getCurrPtr()->getData() << "currPtr.prevPtr = " << myList.getCurrPtr()->getPrevPtr()->getData() << endl << "currPtr.nextPtr = " << myList.getCurrPtr()->getNextPtr() << endl << endl;

    myList.insert(6);
    if (myList.getCurrPtr()->getData() == 6 && myList.getCurrPtr()->getPrevPtr()->getData() == 5 && myList.getCurrPtr()->getNextPtr()->getData() == 7){
        cout << "Correctly inserted 6 into myList" << endl;
    } else cout << endl << "Incorrectly inserted 6 into myList" << endl
                << endl << "Expected output:" << endl << "currPtr.data = " << 6 << "currPtr.prevPtr = " << 5 << endl << "currPtr.nextPtr = " << 7 << endl
                << endl << "Actual output:" << endl << "currPtr.data = " << myList.getCurrPtr()->getData() << "currPtr.prevPtr = " << myList.getCurrPtr()->getPrevPtr()->getData() << endl << "currPtr.nextPtr = " << myList.getCurrPtr()->getNextPtr()->getData() << endl << endl;

    myList.insert(4);
    if (myList.getCurrPtr()->getData() == 4 && myList.getCurrPtr()->getPrevPtr()->getData() == 3 && myList.getCurrPtr()->getNextPtr()->getData() == 5){
        cout << "Correctly inserted 4 into myList" << endl;
    } else cout << endl << "Incorrectly inserted 4 into myList" << endl
                << endl << "Expected output:" << endl << "currPtr.data = " << 4 << "currPtr.prevPtr = " << 3 << endl << "currPtr.nextPtr = " << 5 << endl
                << endl << "Actual output:" << endl << "currPtr.data = " << myList.getCurrPtr()->getData() << "currPtr.prevPtr = " << myList.getCurrPtr()->getPrevPtr()->getData() << endl << "currPtr.nextPtr = " << myList.getCurrPtr()->getNextPtr()->getData() << endl << endl;

    //Test MyList::printAscending and MyList::printDescending
    cout << endl << "Testing MyClass::printAscending" << endl;
    cout << "Correct output: " << endl << 3 << endl << 4 << endl << 5 << endl << 6 << endl << 7 << endl << endl;
    cout << "Actual output: " << endl;
    myList.printAscending();

    cout << endl << "Testing MyClass::printDescending" << endl;
    cout << "Correct output: " << endl << 7 << endl << 6 << endl << 5 << endl << 4 << endl << 3 << endl << endl;
    cout << "Actual output: " << endl;
    myList.printDescending();

    //add more values to myList
    cout << endl << "Populating myList" << endl;
    myList.insert(0);
    myList.insert(1);
    myList.insert(2);
    myList.insert(8);
    myList.insert(9);
    myList.printAscending();

    //Test MyClass::remove
    cout << endl << "Testing MyList::remove" << endl;

    myList.remove(0);
    cout << endl << "If 0 not in following list, test passed." << endl;
    myList.printAscending();
    cout << endl;

    myList.remove(9);
    cout << "If 9 not in following list, test passed." << endl;
    myList.printAscending();
    cout << endl;

    myList.remove(5);
    cout << "If 5 not in following list, test passed." << endl;
    myList.printAscending();
    cout << endl;

    //Test MyList::clear
    cout << endl << "Testing MyList::clear" << endl << "Messages should print for values from 8-6 and 4-1" << endl;
    myList.clear();
    if (myList.getCurrPtr() == nullptr){
        cout << "Correctly cleared list and set currPtr to nullptr." << endl;
    } else cout << endl << "Incorrectly cleared list; currPtr not set to nullptr." << endl << "Expected value: " << nullptr << endl << "Actual value: " << myList.getCurrPtr();

    //add more values to myList
    cout << endl << "Populating myList" << endl;
    myList.insert(0);
    myList.insert(1);
    myList.insert(2);
    myList.insert(3);
    myList.insert(4);
    myList.insert(5);
    myList.insert(6);
    myList.insert(7);
    myList.insert(8);
    myList.insert(9);
    myList.printAscending();

    //Test MyList class destructor
    cout << endl << "Testing MyList class destructor" << endl << "Messages should print for values from 9-0" << endl;
    return 0;
}

//------------------------------------------------------------------------------
// List.h : class declaration
// 
// Linked list with manual pointers
// 
// Author: Coursera
// Modified by: Prof. Linda C
//------------------------------------------------------------------------------
#pragma once

#include "Node.h"

//------------------------------------------------------------------------------
// List : linked list of items
//------------------------------------------------------------------------------
class List {
private:
    Node* pHead;
    Node* pTail;
    int size;

public:
    // constructor
    List();

    // destructor
    ~List();

    // copy constructor
    List(const List& rhs);

    // assignment operator
    const List& operator=(const List& rhs);

    // move constructor
    List(List&& rhs) noexcept;

    // create list node
    void createNode(int value);

    // display list nodes
    void displayList();

    // insert a list node at the beginning of the list
    void insertAtHead(int value);

    // insert a list node at the passed position, or at the end of the list
    void insertAtPosition(int pos, int value);

    // delete the node at the pHead of the list (first node in the list)
    void deleteHeadNode();

    // delete the node at the pTail of the list (last node in the list)
    void deleteTailNode();

    // delete a list node at the passed position, or at the end of the list
    void deleteAtPosition(int pos);

    // return the number of items in the list
    int getSize() const;
};

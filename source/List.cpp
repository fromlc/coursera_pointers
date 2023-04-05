//------------------------------------------------------------------------------
// List.cpp : class definition
// 
// Linked list with manual pointers
// 
// Author: Coursera
// Modified by: Prof. Linda C
//------------------------------------------------------------------------------
#include "List.h"

#include <iostream>
#include <memory>

using std::cout;
using std::min;
using std::move;

//------------------------------------------------------------------------------
// constructor
//------------------------------------------------------------------------------
List::List() : size(0), pHead(nullptr), pTail(nullptr) { }

// destructor
List::~List() {
    Node* current = pHead;
    Node* pTemp = nullptr;

    // delete each node starting from the pHead node
    while (current != nullptr) {

        pTemp = current;
        current = current->pNext;
        delete pTemp;
    }

    pHead = pTail = nullptr;
}

// copy constructor
List::List(const List& rhs) {

    pHead = rhs.pHead;
    pTail = rhs.pTail;
    size = rhs.size;
}

// assignment operator
const List& List::operator=(const List& rhs) {

    if (this != &rhs) {

        pHead = rhs.pHead;
        pTail = rhs.pTail;
        size = rhs.size;
    }

    return *this;
}

// move constructor
List::List(List&& rhs) noexcept {

    this->pHead = this->pTail = nullptr;
    this->size = 0;

    if (this != &rhs)
        *this = move(rhs);
}

// create list node
void List::createNode(int value) {

    Node* pTemp = new Node(value);

    if (pHead == nullptr) {
        pHead = pTail = pTemp;
    }
    else {
        pTail->pNext = pTemp;
        pTail = pTemp;
    }

    size++;
}

// display list nodes
void List::displayList() {

    Node* pTemp = pHead;

    while (pTemp != nullptr) {
        cout << pTemp->data << '\t';
        pTemp = pTemp->pNext;
    }
}

// insert a list node at the beginning of the list
void List::insertAtHead(int value) {

    Node* pTemp = new Node(value);
    pTemp->pNext = pHead;
    pHead = pTemp;

    size++;
}

// insert a list node at the passed position, or at the end of the list
void List::insertAtPosition(int pos, int value) {

    Node* pTemp = new Node(value);

    if (pHead == nullptr) {

        pHead = pTemp;
        size = 1;
        return;
    }

    Node* pCur = pHead;
    Node* pPre = nullptr;

    // find the position to insert the new node
    pos = min(pos, size);
    int i = 1;
    while (i < pos && pCur != nullptr) {

        pPre = pCur;
        pCur = pCur->pNext;
        i++;
    }

    // insert the new node
    if (pPre != nullptr) {
        pPre->pNext = pTemp;
        pTemp->pNext = pCur;
    }

    // set new pTail if needed
    if (pCur == nullptr) {
        pTail = pTemp;
    }

    size++;
}

// delete the node at the pHead of the list (first node in the list)
void List::deleteHeadNode() {

    if (pHead != nullptr) {

        Node* pTemp = pHead;
        pHead = pHead->pNext;
        delete pTemp;
        size--;
    }
}

// delete the node at the pTail of the list (last node in the list)
void List::deleteTailNode() {

    if (pHead == nullptr) {
        return;
    }

    Node* pCur = pHead;
    Node* pPre = nullptr;

    // find the node before the pTail node
    while (pCur->pNext != nullptr) {
        pPre = pCur;
        pCur = pCur->pNext;
    }

    // set the new pTail node
    pPre->pNext = nullptr;
    pTail = pPre;

    // delete the old pTail node
    delete pCur;

    size--;
}

// delete a list node at the passed position, or at the end of the list
void List::deleteAtPosition(int pos) {

    if (pHead == nullptr) {
        return;
    }

    Node* pCur = pHead;
    Node* pPre = nullptr;

    pos = min(pos, size);
    int i = 1;

    while (i < pos && pCur != nullptr) {

        pPre = pCur;
        pCur = pCur->pNext;
        i++;
    }

    // set previous node pointer to skip over the node to delete
    pPre->pNext = pCur->pNext;

    // delete the requested node
    delete pCur;

    // set the new pTail and size
    if (pPre->pNext == nullptr) {
        pTail = pPre;
    }

    size--;
}


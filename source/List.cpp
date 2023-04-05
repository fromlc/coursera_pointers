//------------------------------------------------------------------------------
// List.cpp : class definition
// 
// Linked list with manual pointers
// 
// Author: Coursera
// Modified by: Prof. Linda C
//------------------------------------------------------------------------------
#include "List.h"

//#define NDEBUG        // uncomment to disable assert()
#include <cassert>
#include <iostream>
#include <memory>

using std::cout;
using std::move;

//------------------------------------------------------------------------------
// constructor
//------------------------------------------------------------------------------
List::List() : size(0), pHead(nullptr), pTail(nullptr) { }

//------------------------------------------------------------------------------
// destructor
//------------------------------------------------------------------------------
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

//------------------------------------------------------------------------------
// copy constructor
//------------------------------------------------------------------------------
List::List(const List& rhs) {

    pHead = rhs.pHead;
    pTail = rhs.pTail;
    size = rhs.size;
}

//------------------------------------------------------------------------------
// assignment operator
//------------------------------------------------------------------------------
const List& List::operator=(const List& rhs) {

    if (this != &rhs) {

        pHead = rhs.pHead;
        pTail = rhs.pTail;
        size = rhs.size;
    }

    return *this;
}

//------------------------------------------------------------------------------
// move constructor
//------------------------------------------------------------------------------
List::List(List&& rhs) noexcept {

    this->pHead = this->pTail = nullptr;
    this->size = 0;

    if (this != &rhs)
        *this = move(rhs);
}

//------------------------------------------------------------------------------
// create list node and make it the new list head
//------------------------------------------------------------------------------
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

//------------------------------------------------------------------------------
// display list nodes
//------------------------------------------------------------------------------
void List::displayList() {

    Node* pTemp = pHead;

    while (pTemp != nullptr) {
        cout << pTemp->data << '\t';
        pTemp = pTemp->pNext;
    }
}

//------------------------------------------------------------------------------
// insert a list node at the beginning (head) of the list
//------------------------------------------------------------------------------
void List::insertAtHead(int value) {

    Node* pTemp = new Node(value);
    pTemp->pNext = pHead;
    pHead = pTemp;

    size++;
}

//------------------------------------------------------------------------------
// insert a list node at the passed position, 
// or at the tail of the list if passed position is beyond the list end
//------------------------------------------------------------------------------
void List::insertAtPosition(int pos, int value) {

    Node* pTemp = new Node(value);

    // check for empty list
    if (pHead == nullptr) {

        pHead = pTemp;
        size = 1;
        return;
    }

    // check for new tail
    if (pos > size) {
        pTail->pNext = pTemp;
        size++;
        return;
    }

    Node* pCur = pHead;
    Node* pPre = nullptr;

    // find the position to insert the new node
    int i = 1;
    while (i < pos && pCur != nullptr) {

        pPre = pCur;
        pCur = pCur->pNext;
        i++;
    }

    // insert the new node
    assert(pPre != nullptr);
    pPre->pNext = pTemp;
    pTemp->pNext = pCur;
    size++;
}

//------------------------------------------------------------------------------
// delete the head node (first node in the list)
//------------------------------------------------------------------------------
void List::deleteHeadNode() {

    if (pHead != nullptr) {

        // if the list has one node it will have zero
        if (pHead == pTail) {
            pTail = nullptr;
        }

        Node* pTemp = pHead;
        pHead = pHead->pNext;
        delete pTemp;
        size--;
    }
}

//------------------------------------------------------------------------------
// delete the tail node (last node in the list)
//------------------------------------------------------------------------------
void List::deleteTailNode() {

    if (pHead == nullptr) {
        return;
    }

    Node* pCur = pHead;
    Node* pPre = pHead;

    // find the node before the tail node
    while (pCur->pNext != nullptr) {
        pPre = pCur;
        pCur = pCur->pNext;
    }

    // set the new tail node
    pTail = pPre;
    pTail->pNext = nullptr;

    // delete the old tail node
    delete pCur;

    size--;
}

//------------------------------------------------------------------------------
// delete the list node at the passed position,
// or delete the tail (last) node if position is beyond the end of the list
//------------------------------------------------------------------------------
void List::deleteAtPosition(int pos) {

    if (pHead == nullptr) {
        return;
    }

    if (pos > size) {
        deleteTailNode();
        return;
    }

    Node* pCur = pHead;
    Node* pPre = nullptr;

    int i = 1;
    while (i < pos) {

        pPre = pCur;
        pCur = pCur->pNext;
        i++;
    }

    // set previous node pointer to skip over the node to delete
    assert(pPre != nullptr && pCur != nullptr);
    pPre->pNext = pCur->pNext;

    // delete the requested node
    delete pCur;

    size--;
}

//------------------------------------------------------------------------------
// return the number of items in the list
//------------------------------------------------------------------------------
int List::getSize() const { return size; }


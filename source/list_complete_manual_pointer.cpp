//------------------------------------------------------------------------------
// list_complete_manual_pointer.cpp
// 
// Author: Coursera
// Modified by: Prof. Linda C
//------------------------------------------------------------------------------
#include "List.h"

#include <cstring>
#include <iostream>
#include <memory>

using std::cout;
using std::string;

//------------------------------------------------------------------------------
// constants
//------------------------------------------------------------------------------
const string DASHES =
"\n -------------------------------------------------------\n";

//------------------------------------------------------------------------------
// globals
//------------------------------------------------------------------------------
namespace app {
    List* pList = nullptr;
    int nodeValues[] = { 25, 50, 90, 40 };
}

//------------------------------------------------------------------------------
// local function prototypes
//------------------------------------------------------------------------------
List* generateList();
void displayList(const string&);

//------------------------------------------------------------------------------
// entry point
//------------------------------------------------------------------------------
int main() {

    cout << "\n Linked List demo with insertion and deletion at";
    cout << "\n position numbers that start with 1.\n";

    app::pList = generateList();
    displayList("Initial List");

    app::pList->createNode(55);
    displayList("Insert 55 At List Tail");

    app::pList->insertAtHead(50);
    displayList("Insert 50 At List Head");

    app::pList->insertAtPosition(5, 60);
    displayList("Insert 60 At Position 5");

    app::pList->deleteHeadNode();
    displayList("Delete Head Node");

    app::pList->deleteTailNode();
    displayList("Delete Tail Node");

    app::pList->deleteAtPosition(4);
    displayList("Delete Node At Position 4");

    app::pList->deleteAtPosition(app::pList->getSize() + 1);
    displayList("Delete At Position > List Size Deletes Tail Node");

    app::pList->insertAtPosition(app::pList->getSize() + 1, 85);
    displayList("Insert 85 At Position > List Size Sets New Tail");

    cout << DASHES;

    delete app::pList;

    return 0;
}

//------------------------------------------------------------------------------
// create nodes to generate initial list
//------------------------------------------------------------------------------
List* generateList() {

    List* pL = new List;

    int itemCount = sizeof(app::nodeValues) / sizeof(int);

    for (int i = 0; i < itemCount; ++i) {
        pL->createNode(app::nodeValues[i]);
    }

    return pL;
}

//------------------------------------------------------------------------------
// display list items with passed message string
//------------------------------------------------------------------------------
void displayList(const string& message) {

    //cout << DASHES;
    cout << "\n " << message;
    cout << DASHES << ' ';
    app::pList->displayList();
    cout << "\n List size: " << app::pList->getSize() << '\n';
}
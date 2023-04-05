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
    List listObj;
}

//------------------------------------------------------------------------------
// local function prototypes
//------------------------------------------------------------------------------
void generateList();
void displayList(const string&);

//------------------------------------------------------------------------------
// entry point
//------------------------------------------------------------------------------
int main() {

    cout << "\n Linked List demo with insertion and deletion at";
    cout << "\n position numbers that start with 1.\n";

    generateList();
    displayList("Initial List");

    app::listObj.createNode(55);
    displayList("Insert 55 At List Tail");

    app::listObj.insertAtHead(50);
    displayList("Insert 50 At List Head");

    app::listObj.insertAtPosition(5, 60);
    displayList("Insert 60 At Position 5");

    app::listObj.deleteHeadNode();
    displayList("Delete Head Node");

    app::listObj.deleteTailNode();
    displayList("Delete Tail Node");

    app::listObj.deleteAtPosition(4);
    displayList("Delete Node At Position 4");

    app::listObj.deleteAtPosition(app::listObj.getSize() + 1);
    displayList("Delete At Position > List Size Deletes Tail Node");

    app::listObj.insertAtPosition(app::listObj.getSize() + 1, 85);
    displayList("Insert 85 At Position > List Size Sets New Tail");

    cout << DASHES;

    return 0;
}

//------------------------------------------------------------------------------
// create nodes to generate initial list
//------------------------------------------------------------------------------
void generateList() {
 
    app::listObj.createNode(25);
    app::listObj.createNode(50);
    app::listObj.createNode(90);
    app::listObj.createNode(40);
}

//------------------------------------------------------------------------------
// display list items with passed message string
//------------------------------------------------------------------------------
void displayList(const string& message) {

    //cout << DASHES;
    cout << "\n " << message;
    cout << DASHES << ' ';
    app::listObj.displayList();
    cout << "\n List size: " << app::listObj.getSize() << '\n';
}
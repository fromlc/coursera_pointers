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
"\n-------------------------------------------------------\n";

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

    cout << "\nLinked List demo with insertion and deletion at";
    cout << "\nposition numbers that start with 1.\n";

    generateList();
    displayList("Initial List");

    app::listObj.createNode(55);
    displayList("Inserting 55 At pTail");

    app::listObj.insertAtHead(50);
    displayList("Inserting 50 At pHead");

    app::listObj.insertAtPosition(5, 60);
    displayList("Inserting 60 At Position 5");

    app::listObj.deleteHeadNode();
    displayList("Deleting Head Node");

    app::listObj.deleteTailNode();
    displayList("Deleting Tail Node");

    app::listObj.deleteAtPosition(4);
    displayList("Deleting Node At Position 4");

    app::listObj.deleteAtPosition(app::listObj.getSize() + 1);
    displayList("Deleting At Position Beyond List End Deletes Tail Node");

    app::listObj.insertAtPosition(app::listObj.getSize() + 1, 85);
    displayList("Inserting 85 At Position Beyond List End Sets New Tail");

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
    cout << '\n' << message;
    cout << DASHES;
    app::listObj.displayList();
    cout << "\nList size: " << app::listObj.getSize() << '\n';
}
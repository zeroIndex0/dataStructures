//
//
//
// hashTableTester.cpp

// testing out the the hash table
// Nothing serious or i would not add quit into the table and i would give better options for exiting and handling special characters, etc...
// Now with sizing!  You can create the hash table with a custom size via its constructor


#include <iostream>
#include <string>
#include "hashTable.h"

using namespace std;

int main(void) {

    string name = "RyanK";
    //HashTable table(2);
    //HashTable table(4);
    HashTable table(8);

    cout << "Add names to the table.  Stop by typing quit. " << endl;

    do {
    getline(cin, name);

    table.Insert(name);
    } while(name != "quit"); //etc...

    cout << "What name would you like to look up? " << endl;
    getline(cin, name);
    if(table.DoesExist(name))
        cout << endl << "Yup, " << name << " is in there! " << endl << endl;
    else
        cout << name << " is not in the list. " << endl << endl;

    table.PrintTable();


return 0;
}

//
//
// A program to test out binaryTree.h
// using a binary tree insert algorithm


#include <iostream>
#include "binaryTree.h"


using namespace std;


//binary tree insert algorithm
void btInsert(BinaryTree<int> *t, int data) {
    if(data <= t->getData()) {
        //insert left
        if(!t->getLeft()) {
            t->linkLeft(new BinaryTree<int>(data));
        } else {
            btInsert(t->getLeft(), data);
        }
    } else {
        //insert right
        if(!t->getRight()) {
            t->linkRight(new BinaryTree<int>(data));
        } else {
            btInsert(t->getRight(), data);
        }
    }

}


int main(void) {

    BinaryTree<int> *t = NULL;
    int data;

    do {

        cout << "Enter Number To Add To The Tree (-1 to quit): ";
        cin >> data;
        if(data == -1) {
            break;
        }

        if(!t) {
            t = new BinaryTree<int>(data);
        } else {
            btInsert(t, data);
        }

    } while(data != -1);

    //Testing out the search function added to binaryTree.h
    int option;
    cout << "\nOkay, lets do a little search! \nWhat number are you looking for? ";
    cin >> option;

    BinaryTree<int> *searchNodes = NULL;
    searchNodes = t->search(option);
    if(searchNodes == NULL) {
        cout << option << " is not in the tree" << endl;
    } else {
        cout << "Found " << searchNodes->getData() << endl;
    }

return 0;
}

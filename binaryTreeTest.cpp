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


//an interesting observation: the only thing that changes in these three functions is the location of the cout

//in-order traversal
void inOrder(BinaryTree<int> *t) {
    if(t) {
        if(t->getLeft())
            inOrder(t->getLeft());
        cout << t->getData() << " ";
        if(t->getRight())
            inOrder(t->getRight());
    }
}

//post-order traversal
void postOrder(BinaryTree<int> *t) {
    if(t) {
        if(t->getLeft())
            postOrder(t->getLeft());
        if(t->getRight())
            postOrder(t->getRight());
        cout << t->getData() << " ";
    }
}

//pre-order traversal
void preOrder(BinaryTree<int> *t) {
    if(t) {
        cout << t->getData() << " ";
        if(t->getLeft())
            preOrder(t->getLeft());
        if(t->getRight())
            preOrder(t->getRight());

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

    BinaryTree<int> *searchNodes = nullptr;
    searchNodes = t->search(option);
    if(searchNodes == nullptr) {
        cout << option << " is not in the tree" << endl;
    } else {
        cout << "Found " << searchNodes->getData() << endl;
    }

    cout << endl;  //giving some space between outputs

    //Testing out the getHeight function added to binaryTree.h
    cout << "The tree height is: " << t->getHeight() << endl;



    // ============== Testing Out Tree Traversals ================\\

    cout << "In Order Traversal: " << endl;
    inOrder(t);

    cout << endl << "Post Order Traversal: " << endl;
    postOrder(t);

    cout << endl << "Pre Order Traversal: " << endl;
    preOrder(t);



return 0;
}

//
//
// A class to create a binary tree
// binaryTree.h


#ifndef BINARYTREE_H
#define BINARYTREE_H

//#include <iostream>

template<typename T>
class BinaryTree {
public:

//constructor
    BinaryTree(T data) {
        left = right = parent = nullptr;
        this->data = data;
    }

//destructor
    ~BinaryTree() {
        delete left;
        delete right;
    }

//linkLeft
    void linkLeft(BinaryTree<T> *node) {
        left = node;
        //make sure to attach the parent
        node->parent = this;
        //left->parent = this;  //would this be node->parent = this;
        // They are the same thing, but 'node' makes a bit more sense when you read it
        // Since its actually this->left->parent = this
        // and (the newly created) node->parent = this; just reads better
    }


//linkRight
    void linkRight(BinaryTree<T> *node) {
        right = node;
        //make sure to attach the parent
        node->parent = this;
    }


//getLeft   returns a BinaryTree pointer
    BinaryTree<T> *getLeft() {
        return left;
    }

//getRight  returns a BinaryTree pointer
    BinaryTree<T> *getRight() {
        return right;
    }

//getData
    T getData() {
        return data;
    }


//A search function for the binary tree that returns a binarytree pointer
//returns NULL if the data is not in the tree
    BinaryTree<T> *search(T data) {
        if(data == this->getData())
            return this;
        if(data < this->getData()) {
            if(!this->getLeft()) {
                return nullptr;
            }
            this->getLeft()->search(data);
        } else {
            if(!this->getRight()) {
                return nullptr;
            }
            this->getRight()->search(data);
        }
        //leaving off a return throws a complier warning, but this is a recursive function and the return here is not needed
    }

//a function that returns the height of the tree
    int getHeight() {
        int leftHeight = 0, rightHeight = 0;

        //std::cout << "Debug: " << this->getData() << std::endl;
        if(left) {
            leftHeight = left->getHeight();
        }
        if(right) {
            rightHeight = right->getHeight();
        }

    return 1 + (leftHeight > rightHeight ? leftHeight : rightHeight);
    }


//TODO add a way to get ancestors and what not, like getParent(), getUncle()
//     also a way to print out the tree to make sure its working properly so I can stop looking in the debugger

private:
    //data elements
    T data;
    BinaryTree<T> *left;
    BinaryTree<T> *right;
    BinaryTree<T> *parent;

};


#endif // BINARYTREE_H

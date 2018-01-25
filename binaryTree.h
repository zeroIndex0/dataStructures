//
//
// A class to create a binary tree
// binaryTree.h


#ifndef BINARYTREE_H
#define BINARYTREE_H


template<typename T>
class BinaryTree {
public:

//constructor
    BinaryTree(T data) {
        left = right = parent = NULL;
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
        //right->parent = this;  //would this be node->parent = this;
        // They are the same thing, but 'node' makes a bit more sense when you read it
        // Since its actually this->right->parent = this
        // and (the newly created) node->parent = this; just reads better
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
                return NULL;
            }
            this->getLeft()->search(data);
        } else {
            if(!this->getRight()) {
                return NULL;
            }
            this->getRight()->search(data);
        }
    }


//TODO add a way to get ancestors and what not, like getParent(), getUncle()
//     also a way to print out the tree to make sure its working properly so I can stop looking in the debugger
//     also add a way to get the height.  I think its importat for printing the tree and I have an idea as to how to do it

private:
    //data elements
    T data;
    BinaryTree<T> *left;
    BinaryTree<T> *right;
    BinaryTree<T> *parent;

};


#endif // BINARYTREE_H

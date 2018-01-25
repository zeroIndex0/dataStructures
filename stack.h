//
//
// stack.h
// a class for creating a stack


#ifndef STACK_H
#define STACK_H

#include <iostream>  //needed for printing out the stack and an error message for an empty pop


template<typename T>
class Stack {

public:

    //constructor
    Stack() {
        top = NULL;
    }

    //destructor
    ~Stack() {
        Node *current;

        //start at the top of the stack
        current = top;

        //While there is something in the stack, delete it
        while(current) {
            current = current->previous;
            delete top;
            top = current;
        }
    }

    //push data onto the top of the stack
    void push(T data) {
        //push the data element to the top of the stack, kinda like a list
        Node *node = createNode(data);

        //this is the old top of the stack
        node->previous = top;
        //now top points to the new top of the stack
        top = node;


    }

    //remove the top element from the top of the stack 'pop'
    void pop() {
        //remove the data element from the top of the stack
        if(isEmpty()) {
            std::cout << "Stack is empty, sorry but you cannot pop an empty stack. " << std::endl;
        } else {
            //set top to point to the previous item in the stack
            //and delete the object currently on the top of the stack
            Node *tempTop = top;
            tempTop = tempTop->previous;
            delete top;
            top = tempTop;
            //the top node should be deleted
            //top = top->previous; creates a leak
         }
    }

    //check if the stack is empty
    bool isEmpty() {
        return (!top);
    }

    //return the size of the stack
    int getSize() {
        int size = 0;

        if(isEmpty()){
            //the stack is empty and has no size
            return 0;
        } else {
            Node *current;
            //start at the top
            current = top;

            //and each time you advance in the stack, increment size
            while(current) {
                current = current->previous;
                size++;
            }
        }
        return size;
    }

    //print the stack
    void printStack() {
        if(!top) {
            std::cout << "Empty stack, nothing to print out. " << std::endl;
        } else {
            Node *current;
            //start at the top of the stack
            current = top;

            //cycle through the whole stack and output the data
            while(current) {
                std::cout << current->data << " ";
                current = current->previous;
            }
            std::cout << std::endl;
        }
    }

    //you MUST error check this when calling the function.  There is no built in error check!
    //example: <in some other file> if(!Stack<T> CreatedVar.isEmpty()) then get the topElement.
    //I would like to know if there is a better way. If anyone is reading this and knows a way, please let me know.
    T topElement() {
        return top->data;
    }
    /*
    T topElement(){
        if(isEmpty()) {
            //This currently returns a garbage value if the list is empty
            //there must be a better way to handle the empty case, but the thing is, T can be anything.
            T value;
            return value;
        } else {
            return top->data;
        }
    }
    */




private:

    //private class Node for storage
    class Node {
    public:
        T data;
        Node *previous;

        //constructor makes sure previous is null to start with
        Node() {
            previous = NULL;
        }

    };
    //=======End private class=========\\

    // private function to create a new node, returns a node pointer
    Node *createNode(T data) {
        Node *node = new Node();
        node->data = data;
        return node;
    }

    //private pointer to keep track of the top of the stack
    Node *top;

};



#endif // STACK_H)

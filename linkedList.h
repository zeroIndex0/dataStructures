//
//
//
// linkedList.h

// a linked list class
// TODO:  Add a delete function

#ifndef LINKEDLIST_H
#define LINKEDLIST_H


#include<iostream>  //used for the print function

template <typename T>
class List {

public:

    //constructor
    List() {
        head = tail = NULL;
    }

    List(T data) {
        head = tail = NULL;
        append(data);
    }

    //destructor deletes the nodes
    ~List() {
        Node *current;

        //start at the head
        current = head;

        //delete all the nodes
        while(current) {
            current = current->next;
            delete head;
            head = current;
        }
    }

    //append to the end of the list
    void append(T data) {
        Node *node = createNode(data);

        //special case of having an empty list
        if(isEmpty()) {
            head = tail = node;
            return;
        }

        //current node's previous pointer now points to what tail was pointing at
        node->prev = tail;
        //set the next node of the old tail ( last node in the list ) to point to the newest node ( the now last node in the list )
        tail->next = node;
        //update tail to the current node
        tail = node;
    }

    //prepend to the front of the list
    void prepend(T data) {
        Node *node = createNode(data);

        //special case is when the list is empty
        if(isEmpty()) {
            head = tail = node;
            return;
        }

        //this is at the front of the list and there will be nothing in previous
        node->prev = NULL;
        //the current nodes next pointer will point to the old head
        node->next = head;
        //update the head to the current node witch is now the front of the list
        head = node;

    }

    //function that returns true if the list is empty
    bool isEmpty() {
        //if the head is empty, we have nothing in the list
        if(head == NULL) //I had a semi colon here to begin with, what a nasty bug that turned out to be
        return true;
        //else
        return false;
    }


    //Returns true if the data is found in the list
    bool Search(T data) {
        Node *current;

        current = head;

        while(current) {
            if(current->data == data)
                return true;
            current = current->next;
        }
        return false;
    }


    void printList() {
        Node *current;

        //start at the head
        current = head;

        //go through all the nodes and print them out
        while(current) {
            std::cout << current->data << ", ";
            current = current->next;
        }
    }



private:
    //a private class Node to give the list its storage
    class Node {

    public:
        T data; //the data
        Node *next;  //link for whats next in line
        Node *prev;  //link for the previous node

        //constructor builds the node with each next as null
        Node () {
        next = NULL;
        }

    };


    //private data elements for List
    Node *head;
    Node *tail;

    //private create new node function
    Node *createNode(T data) {
        Node *node = new Node();
        node->data = data;
        return node;
    }

};


#endif

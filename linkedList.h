//
//
//
// linkedList.h

// a linked list class
// TODO:  Add a delete function and an insert function
//        Keep adding to iterators as I believe that's how ill be able to create my delete and insert functions

#ifndef LINKEDLIST_H
#define LINKEDLIST_H


#include<iostream>  //used for the print function

template <typename T>
class List {

private:
    class Node;  //forward declaration to appease the iterator class

public:

    //constructor
    List() {
        head = tail = nullptr;
    }

    //Im still a little torn on having a constructor like this. I'm currently not really seeing a purpose for it
    List(T data) {
        head = tail = nullptr;
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
            node->prev = nullptr;   //the very fist node must show there is nothing before it
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
        node->prev = nullptr;
        //the current nodes next pointer will point to the old head
        node->next = head;
        //need to reset the connection of the old front that pointed to null, to point to the new front of the list
        node->next->prev = node;
        //update the head to the current node witch is now the front of the list
        head = node;

    }

    //in order to insert data i have to know the location to add the data to, that will be the tricky part.
    void addData(T data) {

    }

    void eliminate(T data) {

    }

    //function that returns true if the list is empty
    bool isEmpty() {
        //if the head is empty, we have nothing in the list
        if(head == nullptr) //I had a semi colon here to begin with, what a nasty bug that turned out to be
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


    //iterator class
    class iterator {
    //class Node;   //I suppose this is like a function header for classes 'Forward Declaration' I believe is what its called
    //forward declaration here was not enough.  I had to place it at the very start of the List<T> class itself.
    public:
        //constructor
        iterator(Node *node) {
            current = node;
        }

        T &operator*() {
            return current->data;
        }

        iterator &operator++() {
            if(current->next)
                current = current->next;
            return *this;
        }

        iterator &operator++(int) {
            iterator tmp(*this);
            if(current->next)
                current = current->next;
            return tmp;
        }

        iterator &operator--() {
            if(current->prev) {
                current = current->prev;
            } // else { could i return something and eliminate the bool check from node class...}
            return *this;
        }

        iterator &operator--(int) {
            iterator tmp(*this);
            if(current->prev)
                current = current->prev;
            return tmp;
        }

        bool operator==(const iterator &rhs) {
            return current == rhs.current;
        }

        bool operator!=(const iterator &rhs) {
            return current != rhs.current;
        }


        /*
                                    ==== Until i can fix the addressing issue, i cannot use comparison operators   ====
                                    ---- Adding items to the front of the list puts a larger address at the start  ----
                                      -- Which makes any kind of comparison completely useless..                   --
                                       - Ive spent a lot of time so far trying to figure out a fix, with no result -



        bool operator<(iterator rhs) {
            return (current < rhs.current);
        }

        bool operator>(iterator rhs) {
            return (current > rhs.current);
        }

        bool operator<=(const iterator &rhs) {
            //The only thing i can think of right now is to have a way to check if my last pass over was == and that would mean that i have to create
            //a data member in Node just for this function and that honestly seems a bit sloppy to me.  It would be nice if i knew someone i could ask
            if(current <= rhs.current){
                    std::cout << "Current: " << current << "    rhs.current: " << rhs.current << std::endl;
                    //something kind of interesting to note here is that even though rhs is const i can still modify the boolean value in Node
                    if(current == rhs.current && rhs.current->check == true) {
                        //if we are there then we have hit the end of the list and need to return false;
                        rhs.current->check = false;
                        return false;
                    }
                    if(current == rhs.current && rhs.current->check == false){
                        rhs.current->check = true;
                    }
                return true;
            }
            return false;
        }

        //TODO:  Figure out how to sequence addressing, otherwise operation comparison on addresses will be useless
        //INTERESTING... If i prepend data it shoves the value in the front and messes up the addressing
        //               so if i prepend my data i cannot use this function, how could that problem be fixed?
        //               I have no idea as to how i can fix this addressing issue.  I have found nothing online about something like this.
        bool operator>=(const iterator &rhs) {
            std::cout << "Current: " << current << "    rhs.current: " << rhs.current << std::endl;
            if(current >= rhs.current){
                    //std::cout << "Current: " << current << "    rhs.current: " << rhs.current << std::endl;
                    //something kind of interesting to note here is that even though rhs is const i can still modify the boolean value in Node
                    if(current == rhs.current && rhs.current->check == true) {
                        //if we are there then we have hit the end of the list and need to return false;
                        rhs.current->check = false;
                        return false;
                    }
                    if(current == rhs.current && rhs.current->check == false){
                        rhs.current->check = true;
                    }
                return true;
            }
            return true;
        }
        */

    private:
        Node *current;

    };


    iterator begin() {
        return iterator(head);
    }

    iterator end() {
        return iterator(tail);
    }



private:
    //a private class Node to give the list its storage
    class Node {

    public:
        T data; //the data
        Node *next;  //link for whats next in line
        Node *prev;  //link for the previous node
        bool check = false;  //used currently for overloaded operator <=

        //constructor builds the node with each next as null
        Node () {
        next = nullptr;
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

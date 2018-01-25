//
// Testing out the linkedList.h FILE
//
// currently just prints out a typical hello world and a simple list of ints using a linked list
//
// It would be nice to have a way to add data to the list without calling the append and prepend directly
// or even a better way to cycle through the list without the printList() which uses a call to cout in the header file
//  maybe something like creating custom iterators, but I'm not very familiar with something like that

#include <iostream>
#include "linkedList.h"



int main(void) {

    List<std::string> list;
    List<int> anotherList;

    //hello world
    list.append("Hello ");
    list.append("World");
    list.printList();


    std::cout << "  |  "; /* just to give the newly printed line a little space */

    //hello, hello world!
    list.prepend("Hello, ");
    list.append("!");
    list.printList();


    std::cout << "  |  "; /* just to give the newly printed line a little space */

    //a list of ints
    anotherList.append(2);
    anotherList.prepend(1);
    anotherList.append(3);
    anotherList.printList();

return 0;
}

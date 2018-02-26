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

    List<std::string> list("Construct Data");
    List<int> anotherList;

    list.append("Hello");
    list.append("World");
    list.printList();


    std::cout << std::endl;

    list.prepend("Hello");
    list.append("!");
    list.printList();

    std::cout << std::endl;

    if(list.Search("World")) {
        std::cout << "World is in the list " << std::endl;
    } else {
        std::cout << "Item not found " << std::endl;
    }



    //a list of ints
    anotherList.append(1);
    anotherList.append(2);
    anotherList.prepend(0);
    anotherList.append(3);
    anotherList.printList();

    std::cout << std::endl;

    if(anotherList.Search(5)) {
        std::cout << "5 is in the list " << std::endl;
    } else {
        std::cout << "Item not found " << std::endl;
    }



                                    ///// ======= TESTING OUT CUSTOM ITERATORS ====== //////

    std::cout << std::endl << " === Testing Iterators === " << std::endl;

    List<int>::iterator it = anotherList.end();
    //std::cout << "it " << it << std::endl;    //so this wont work, but *it will work..what... why?  It should print out an address..
    std::cout << "*it = " << *it << std::endl;

    List<std::string>::iterator ite = list.begin();
    std::cout << "*ite = " << *ite << std::endl;

    std::cout << std::endl;


    //Interesting issue for these... my begin() and end() return the head and tail, so they behave a little different than i was expecting
    //If i say != then ill never get the head value or tail value, so i >= <= comparisons in order to properly traverse the whole list.
    //or some sort of dummy value at the beginning or end, I think the dummy values would be better actually and have begin and end return just past themselves
    for(List<int>::iterator itr = anotherList.begin(); itr != anotherList.end(); itr++) {
        std::cout << "*itr = " << *itr << std::endl;
    }

    std::cout << std::endl;

    for(List<int>::iterator itr = anotherList.end(); itr != anotherList.begin(); itr--) {
        std::cout << "*itr = " << *itr << std::endl;
    }


    /*  I need to solve an addressing issue before i can use these for loops since <, >, <=, >= will not perform with my current prepend function, sadly
    for(List<int>::iterator itr = anotherList.begin(); itr <= anotherList.end(); itr++) {
        std::cout << *itr << std::endl;
    }
    std::cout << std::endl;  //give a gap
    for(List<int>::iterator itre = anotherList.end(); itre >= anotherList.begin(); --itre) {
        std::cout << *itre << std::endl;
    }
    */


return 0;
}

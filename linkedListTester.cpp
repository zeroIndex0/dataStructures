//
// Testing out the linkedList.h FILE
//
// currently just prints out a typical hello world and a simple list of ints using a linked list
//
// It would be nice to have a way to add data to the list without calling the append and prepend directly
// or even a better way to cycle through the list without the printList() which uses a call to cout in the header file
//  maybe something like creating custom iterators, but I'm not very familiar with something like that


//I updated the linked list class, so this will now print commas which will make the output of this look a little funny
//But I feel that its a more logical way to print the list and will update this test file at some point to match the new output
//I also added a constructor if data is passed in, so i could test that now as well

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
    anotherList.append(2);
    anotherList.prepend(1);
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

    //Look how beautiful this for loop is!  Overloaded entertainment
    for(List<int>::iterator itr = anotherList.begin(); itr <= anotherList.end(); ++itr) {
            std::cout << *itr << std::endl;
    }

    List<std::string>::iterator ite = list.begin();
    std::cout << "*ite = " << *ite << std::endl;


return 0;
}

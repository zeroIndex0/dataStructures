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
    //Whatever i set the start to is fine.  But with != to the end, it stops when they are equal and will not spit out the correct last value
    //but if i return a value just after the tail or before the head, ill run into the issue of which ever one is created first wont work
    //i.e. x.begin() != x.end()+1   x.end() != x.begin()+1  but they cant natively be +1 or the first value will be incorrect
    for(List<int>::iterator itr = anotherList.begin(); itr != anotherList.end(); itr++) {
        std::cout << "*itr = " << *itr << std::endl;
    }
    std::cout << std::endl;


    //a while loop works with boolean checks.  The thing i really dont like about this though is im no longer able to scope my variables
    //and having to maintain them for life seems annoying and not the functionality I was hoping for
    bool check = false;
    List<int>::iterator iter = anotherList.begin();

    while(!check) {
        std::cout << "*iter = " << *iter << std::endl;
        if(iter == anotherList.end())
            check = true;
        else
            iter++;
    }

    std::cout << std::endl;
    check = false;

    while(!check) {
        std::cout << "*iter = " << *iter << std::endl;
        if(iter == anotherList.begin())
            check = true;
        else
            iter--;
    }

    std::cout << std::endl;

    for(List<int>::iterator itr = anotherList.end(); itr != anotherList.begin(); itr--) {
        std::cout << "*itr = " << *itr << std::endl;
    }

return 0;
}

//
//
// stackTest.cpp
// testing the stack class


#include <iostream>
#include "stack.h"

using namespace std;

int main(void) {

    Stack<int> is, ais;
    Stack<string> ss;
    Stack<double> ds;

    is.push(3);
    is.push(4);
    is.push(6);

    //must handle the error check ourselves in this file.
    if(!is.isEmpty()) {
    cout << "This is what's on the top of the stack: " << is.topElement() << endl;
    }
    is.printStack();

    is.pop();

    //must handle the error check ourselves in this file.
    if(!is.isEmpty()) {
    cout << "This is what's on the top of the stack: " << is.topElement() << endl;
    }
    is.printStack();

    cout << endl  << endl;  //give some room between outputs

    //must handle the error check ourselves in this file.
    if(!ss.isEmpty()) {
    cout << "This is what's on the top of the stack: " << ss.topElement() << endl;
    }
    ss.push("Hey ");
    ss.push("There");
    ss.push("!");

    ss.printStack();

    ss.pop();
    ss.printStack();
    ss.pop();
    ss.printStack();

    cout << endl  << endl;  //give some room between outputs

    ds.pop();
    ds.push(8.4);
    ds.push(5.2);
    ds.push(2.5);
    ds.push(6.8);
    cout << "this is the size of ds : " << ds.getSize() << endl;
    ds.printStack();

    cout << endl  << endl;  //give some room between outputs


    for(int i =1; i <=100; i++) {
        ais.push(i);
    }

    cout << "this is the size of ais : " << ais.getSize() << endl;

    for(int i =1; i <=100; i++) {
        ais.pop();
    }

    cout << "this is the size of ais : " << ais.getSize() << endl;



return 0;
}

//
//
//
// hashTable.h

// my attempt at a hash table with a hashing function thats not special
// and ill be using a liked list to handle collision instead of growing or shrinking the table
// mainly since I have never created a hash table and am still trying to learn about its properties


#ifndef HASHTABLE_H
#define HASHTABLE_H

#include "linkedList.h"
#include <iostream>
#include <string>


//TODO:  I would like to figure out a way to adjust the size of the hashTable
//       It would be nice to figure out some of the more advanced hashing functions
//       Possibly template this out, but i cant currently think of a reason as to why yet

class HashTable {
public:

    //constructor
    HashTable() {}

    //destructor
    ~HashTable() {}


    //incase you know what position you want to insert the data into
    void Insert(std::string data, int key) {
        hashTable[key].append(data);
    }

    void Insert(std::string data) {
        int key = Hash(data);
        hashTable[key].append(data);
    }

    //returns true if the item exits in the table
    bool DoesExist(std::string data) {
        int key = Hash(data);
        return(hashTable[key].Search(data));

    }

    void PrintTable() {
        for(int i = 0; i < hashTableSize; i++) {
            std::cout << "Table " << i << ": ";
            hashTable[i].printList();
            std::cout << std::endl;
        }

    }

private:

    static const int hashTableSize = 10;    //currently a fixed size, which is annoying and not practical
    List<std::string> hashTable[hashTableSize];

    //hash function, I understand this is not the best solution
    int Hash(std::string key) {

        int hash = 0;
        int index = 0;

        for(unsigned int i = 0; i < key.length(); i++) {
            hash += (int)key[i];
        }

        index = hash % hashTableSize;

     return index;
    }

};

#endif // HASHTABLE_H

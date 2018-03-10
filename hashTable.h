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


//TODO:    It would be nice to figure out some of the more advanced hashing functions


class HashTable {
public:

    //constructor
    HashTable() {}


    //allows you to create a hash table with a size of size
    HashTable(int size) {
        hashTableSize = size;
        hashTable = new List<std::string>[size];
    }


    //destructor
    ~HashTable() {
        delete hashTable;
    }


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

    int hashTableSize;
    List<std::string> *hashTable;

    //hash function, I do understand this is not the best solution for a hashing function
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

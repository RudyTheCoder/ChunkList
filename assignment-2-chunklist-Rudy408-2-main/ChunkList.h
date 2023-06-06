//
// Created by Varick Erickson 2/3/2021.
//

#ifndef CHUNKLIST_H
#define CHUNKLIST_H

#include <iostream>

using namespace std;

const int ARRAY_SIZE = 8;

// These error classes are done. No modifications are required.
// See ChunkList_driver.cpp for an example of how they are used.
class InvalidArrayLength{
public:
    string Msg() {
        return "Invalid array length used for constructor.";
    }
};

class IndexOutOfBounds {
public:
    string Msg() {
        return "Index is out of bounds";
    }
};

class IteratorOutOfBounds {
public:
    string Msg() {
        return "Iterator is out of bounds.  Nothing left to iterate over.";
    }
};

class EmptyList {
public:
    string Msg() {
        return "List is empty";
    }
};

// Put your pre/post conditions here.

template<class T>
class ChunkList {
public:
    // Constructors

/*
 * Function: Default Constructor initializes all the variables.
 *
 * Precondition: N/A
 *
 * Post-condition: All private variables have been initialized.
*/
    ChunkList();

/*
* Function: Second constructor initializes the list and adds values from arr[].
*
* Precondition: arr[] cannot be less than zero.
*
* Post-condition: This will use the append function to input values into the array.
*  Throws and error message if arr[] is less than zero.
*/
    ChunkList(T arr[], int arrLen);

    // Deconstructor

/*
* Function: This function will free up memory.
*
* precondition: N/A.
*
* Post-condition: Delete nodes starting from the head.
*/
    ~ChunkList();

    // Add/remove elements

    /*
* Function: Append function adds a values to end position of an array inside a node.
*
* Precondition: N/A.
*
* Post-condition: Adds a value to the end of the list. If the node is full then it will create a new node.
*/
    void Append(T value);

/*
* Function: Remove function removes a values for the list and has basic error checking.
*
* Precondition: The list must not be empty.
*
* Post-condition: Deletes value from the list and readjust the values in the array.  If the list is empty
*     then the function will throw an error message.
*/
    void Remove(T value);

    // Stuff to find out about the ChunkList

/*
* Function: The function will return the length of the entire list.
*
* Precondition: The list length must constantly be updated.
*
* Post-condition: Returns the total length of the list.
*/
    int GetLength();

/*
* Function: LoadFactor returns how much space is being used to store items in the list.
*
* Precondition: The length of the list cannot be empty.
*
* Post-condition: Returns how much space is being used out of the space available in the list.
 *    An error message will pop up if the list is empty.
*/
    double LoadFactor();

/*
* Function: Contains determines whether a value exists in the list.
*
* Precondition: The list must contain at lease one value.
*
* Post-condition: Returns true or false whether the value is in the list. This function will
 *    throw an error message if the list is empty.
*/
    bool Contains(T value);

    // Accessing elements

/*
* Function: This function will return the value at index i and also does basic error checking.
*
* Precondition: The list must not be empty and the index must also be valid.
*
* Post-condition: Returns the value located at index i. An error message will be thrown if
 *   the list is empty and if the index i is invalid.
*/
    T GetIndex(int i);

/*
* Function: ResetIterator sets the iterator back to position 0 in the first node.
*
* Precondition: N/A
*
* Post-condition: The iterator is set to the 1st node and the first index.
*/
    void ResetIterator();

/*
* Function: GetNextItem returns the next item of the list.
*
* Precondition: There must be a next item to return.
*
* Post-condition: Returns the next item, throws an error message if there is not a next item.
*/
    T GetNextItem();

/*
* Function: IsEmpty determines whether the list is empty or not.
*
* Precondition: N/A
*
* Post-condition: Returns true if list is empty and false otherwise.
*/
    bool IsEmpty();
private:

    // Note we did not need to make this a template
    // since this struct is part of a template class.
    struct Node {
        Node* next;
        int len;
        T values[ARRAY_SIZE];
    };

    Node* head;
    Node* tail;

    // iterator
    Node* iterNode;     // What node are were currently on?
    int arrPos;         // Within the node, what element are we looking at?

    int listLen;        // Total elements
    int numChunks;      // Total chunks/nodes
};


#include "ChunkList.cpp"

#endif //CHUNKLIST_H

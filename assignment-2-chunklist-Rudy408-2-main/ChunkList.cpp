//
// Your code here
//

#include "ChunkList.h"

template<class T>
ChunkList<T>::ChunkList() {
    head = nullptr;
    tail = nullptr;
    iterNode = head;
    arrPos = 0;
    listLen = 0;
    numChunks = 0;
}

template<class T>
ChunkList<T>::ChunkList(T *arr, int arrLen) {
    head = nullptr;
    tail = nullptr;
    listLen = 0;
    iterNode = head;
    arrPos = 0;
    numChunks = 0;
    int i;
    if (arrLen < 0){
        throw InvalidArrayLength();
    }
    else{
        for (i = 0; i < arrLen; i++) {
            Append(arr[i]);
        }
    }
}

template<class T>
ChunkList<T>::~ChunkList() {

}

template<class T>
void ChunkList<T>::Append(T value) {
    if(head== nullptr && tail == nullptr){ // if the list is empty.
        Node *addedNode = new Node;
        addedNode->len = 0;
        addedNode->next = nullptr;
        head = addedNode;
        tail = addedNode;
        head->values[addedNode->len] = value;
        addedNode->len++;
        numChunks++;
        listLen++;
        return;
    }
    if (tail->len < ARRAY_SIZE) {  //if len is less than 8
        tail->values[tail->len] = value; //stick value into the array at position len.
        (tail->len)++;  //increase len
        listLen++;
        return;
    }
    if (tail->len >= ARRAY_SIZE) { //if the node is full, create a new node
        Node *anotherNode = new Node; // create new node.
        anotherNode->len = 0;
        anotherNode->next = nullptr;
        tail->next = anotherNode; // connects the entire list to the new node
        tail = anotherNode; // updates tail to point to the new node.
        anotherNode->values[tail->len] = value; // stick value into the array
        ++(tail->len); // increase len
        ++listLen;
        ++numChunks; //increase numChunks
        return;
    }

}

template<class T>
void ChunkList<T>::Remove(T value) {
    int i;
    if (head == nullptr) {
        throw EmptyList();
    }
    Node *curr = head;
    Node *prev = nullptr;
    while (curr != nullptr) {
        for (i = 0; i < curr->len; i++) {
            if (curr->values[i] == value) {// if found
                break; // if found then break out of for loop

            }
        }
        if (curr->values[i] == value) //if value was found break out of while loop
            break;
        else {
            prev = curr;
            curr = curr->next; // else move onto next node
        }
    }
    if (curr->len != 1) {  // if array len is not equal to one then just shift over all the elements in array
        for (int k = i + 1; k <= curr->len; k++) {
            curr->values[k - 1] = curr->values[k];
        }
        listLen--;
        curr->len--;

    } else if (curr->len == 1) { // if length is 1 then re-linking is required.
        if (curr == head) { //if curr is equal to head then head will have to move to next node
            head = head->next;
            numChunks--;
            listLen--;
            curr->len--;
            delete curr;

        } else if (curr == tail) { // if curr is equal tail then tail will have to move to previous node.
            tail = prev;
            prev->next = nullptr;
            numChunks--;
            listLen--;
            curr->len--;
            delete curr;


        } else if (curr != head && curr != tail) {  //if curr is in the middle.
            prev->next = curr->next;
            listLen--;
            numChunks--;
            delete curr;

        }


    }


}

template<class T>
int ChunkList<T>::GetLength() {
    return listLen;
}

template<class T>
double ChunkList<T>::LoadFactor() {
    if (head == nullptr) {
        throw EmptyList();
    } else {

        double loadFactor = double(listLen) / double(ARRAY_SIZE * numChunks);

        return loadFactor;
    }
}

template<class T>
bool ChunkList<T>::Contains(T value) {
    if (head == nullptr) {
        throw EmptyList();
    }
    Node *curr = head;
    while (curr != nullptr) {
        for (int i = 0; i < curr->len; i++) {
            if (curr->values[i] == value) {
                return true;
            }
        }
        curr = curr->next;
    }
    return false;
}

template<class T>
T ChunkList<T>::GetIndex(int i) {
    Node *curr = head;
    if (curr == nullptr) {
        throw EmptyList();
    }
    if (i < 0 || i > listLen)
        throw IndexOutOfBounds();
    while (curr != nullptr) {

        if (i < curr->len)
            return curr->values[i];
        if (i >= curr->len) {
            i = i - (curr->len);
            curr = curr->next;
        }
    }

}

template<class T>
void ChunkList<T>::ResetIterator() {
    arrPos = 0;
    iterNode = head;
}

template<class T>
T ChunkList<T>::GetNextItem() {
    if(iterNode== nullptr || arrPos < 0)
        throw IteratorOutOfBounds();
    T currentItem = iterNode->values[arrPos];
    arrPos++;

    if(arrPos >= iterNode->len){
        iterNode = iterNode->next;
        arrPos = 0;
    }
    return currentItem;
}



template<class T>
bool ChunkList<T>::IsEmpty() {
    if(head == nullptr){ // if the head points to null then the list is empty.
        return true;
    }else
        return false;
}

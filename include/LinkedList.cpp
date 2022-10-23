#ifndef LINKED_LIST
#include "LinkedList.hpp"
#endif


/*
*  Function Definitions for the LinkedList class
*/

// Default constructor
template <class T> LinkedList<T>::LinkedList() : LinkedList(1) { }

// specify length of LinkedList at instantiation
template <class T> LinkedList<T>::LinkedList(int length) {
    (*this).length = length;
    (*this).nextNode = nullptr;
    (*this).member = nullptr;
    
    // we need to create all of the other nodes in the list
    if ((*this).length > 1) {
        // create a temporary node that points to this LinkedList node
        LinkedList<T> *temp = this;
        
        // Iterate through the nodes to create the next node.
        // Variable "i" represents the index that we are currently on.
        // We create the node after "this", the first node, and then
        // iterate until we have reached the number of nodes that we need.
        for (int i = 1; i < length; i++) {
            // create the next node
            (*temp).nextNode = new LinkedList<T>();
            // set the temp node pointer to be the address of
            // the next node in the list
            temp = (*temp).nextNode;
        }
    }
}


template <class T> LinkedList<T>::LinkedList(const T& member) {
    (*this).length = 1;
    (*this).nextNode = nullptr;
    (*this).member = new T(member);
}

template <class T> LinkedList<T>::LinkedList(const LinkedList &list) {
    (*this).length = list.length;
    
    // dereference the nextNode pointer in list
    // so we can call the copy-constructor recursively
    // until it gets to the end
    (*this).nextNode = list.nextNode;
    
    // Once we are done recursively copying down
    // to the last element in the list, perform this
    // which should call the copy constructor
    // for the member
    (*this).member = list.member;
}


template <class T> LinkedList<T> LinkedList<T>::getNext() const {
    const LinkedList* const temp = (*this).nextNode;
    return *temp;
}

template <class T> T LinkedList<T>::getMember(const int index) const {
    const T* const temp = (*this).member;
    return *temp;
}

// Recursively calls a node from the end of a LinkedList object
// when you call the method, only input an index if you aren't
// starting from the beginning.
template <class T> LinkedList<T> LinkedList<T>::accessNodesRecursive(const int searchEnd, int index) {
    if (index == searchEnd) {
        return *this;
    }
    else {
        return (*this).accessNodesRecursive(searchEnd, index++);
    }
}
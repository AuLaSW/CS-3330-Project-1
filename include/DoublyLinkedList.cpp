// Make sure we have included the DoublyLinkedList header
#ifndef DOUBLY_LINKED_LIST
#include "DoublyLinkedList.hpp"
#endif


// I don't think that this is going to be possible 
// unless I have a doubly-linked list. I'll consider
// it a possibility
template <class T> LinkedList<T> LinkedList::getPrev() const {
    const LinkedList<T>* const temp = this.nextNode;
    return *temp;
}

// Make sure we include the LinkedList header file
#ifndef SET_INTERFACE
#include "SetInterface.hpp"
#endif

#ifndef DOUBLY_LINKED_LIST
#define DOUBLY_LINKED_LIST

template <typename T> DoublyLinkedList : public SetInterface<DoublyLinkedList, T> {
public:
	
private:
	int length;
	T member;
	DoublyLinkedList* nextNode;
	DoublyLinkedList* prevNode;
}


#endif
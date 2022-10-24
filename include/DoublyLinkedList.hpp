#ifndef DOUBLE_LINK_LIST
#define DOUBLE_LINK_LIST 

#include "Employee.hpp"
#include "Node.hpp"

/*
 * The DoublyLinkedList class creates a doubly-linked list
 * and has methods to interact with the list. The list is made
 * up of DoublyLinkedNode objects, which are defined as a nested
 * class within the main class.
 */
class DoublyLinkedList {
public:
    // constructors
    DoublyLinkedList();
    DoublyLinkedList(const DoublyLinkedList&);
    
    // destructors
    ~DoublyLinkedList();

    // checks if the list is empty or not
    bool empty() const;

    /*
     * Accessors
     */
    // get the length of the list
    const int size() const;

    // get the front node
    const Node& getFront() const;

    // get the back node
    const Node& getBack() const;

    // get the n'th node in the list
    const Node& getNode(int);

    // get the element of the given node
    const Employee& getElement(const Node&) const;
    
    // get the element of the n'th node
    const Employee& getElement(int);

    /*
     * Manipulators
     */

    // generic node removal
    void removeNode(const int);
    
    // generic node add
    void addNode(Employee&);

private:
    // Class for holding the nodes in the list

    // the header element of the list
    Node* header;
    
    // the tailer element of the list
    Node* trailer;

    // the number of elements in the list
    int length;

    Node& getNodeAt(int);
};

#endif /* ifndef DOUBLE_LINK_LIST */

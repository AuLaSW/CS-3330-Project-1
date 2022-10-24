#ifndef DOUBLE_LINK_LIST
#define DOUBLE_LINK_LIST 

#include "Employee.hpp"

/*
 * The DoublyLinkedList class creates a doubly-linked list
 * and has methods to interact with the list. The list is made
 * up of DoublyLinkedNode objects, which are defined as a nested
 * class within the main class.
 */
class DoublyLinkedList {
    template<typename T> class Node;
public:
    // constructors
    DoublyLinkedList();
    
    // destructors
    ~DoublyLinkedList();

    // checks if the list is empty or not
    bool empty() const;

    /*
     * Accessors
     */

    // get the front node
    const Node<Employee>& getFront() const;

    // get the back node
    const Node<Employee>& getBack() const;

    // get the n'th node in the list
    const Node<Employee>& getNode(int) const;

    // get the element of the given node
    const Employee getElement(Node<Employee>) const;
    
    // get the element of the n'th node
    const Employee getElement(int) const;

    /*
     * Manipulators
     */

    // generic node removal
    void removeNode();
    
    // generic node add
    void addNode(Employee);

private:
    // Class for holding the nodes in the list
    template<typename T> 
    class Node {
    private:
        Node* next;
        Node* prev;
        T element;
    };

    // the header element of the list
    Node<Employee>* header;
    
    // the tailer element of the list
    Node<Employee>* trailer;

    // the number of elements in the list
    int length;
};

#endif /* ifndef DOUBLE_LINK_LIST */

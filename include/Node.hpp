// Austin Swanlaw
#include "Employee.hpp"

/* 
 * A simple class for holding the nodes for a Doubled Linked List
 */
template<typename Element>
class Node {
public:
    Node();
    Node(Employee&);
    Node(Employee&, Node&, Node&);
    Node(const Node&);
private:
    // the next node
    Node* next;
    // the previous node
    Node* prev;
    // the element that the node is holding
    Element* element;

    friend class DoublyLinkedList;
};

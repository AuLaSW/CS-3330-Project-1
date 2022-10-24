#include "Employee.hpp"


/* 
 * A simple class for holding the nodes for a Doubled Linked List
 */
class Node {
public:
    Node();
    Node(Employee&);
    Node(Employee&, Node&, Node&);
    Node(const Node&);
private:
    Node* next;
    Node* prev;
    Employee* element;

    friend class DoublyLinkedList;
};

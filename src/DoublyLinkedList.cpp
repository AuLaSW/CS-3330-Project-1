#include <exception>
#include <stdexcept>
#include "../include/DoublyLinkedList.hpp"
#include "../include/Employee.hpp"

// Default constructor
DoublyLinkedList::DoublyLinkedList() {
    this->header = new Node();
    this->trailer = new Node();
    this->header->next = this->trailer;
    this->header->prev = nullptr;
    this->trailer->next = nullptr;
    this->trailer->prev = this->header;
    this->length = 0;
}

// copy constructor
DoublyLinkedList::DoublyLinkedList(const DoublyLinkedList& list) {
    // copy the header and trailer
    this->header = new Node(*list.header->element);
    this->trailer = new Node(*list.trailer->element);
    this->length = list.length;

    // we are creating two temporary nodes to loop over
    // all of the nodes in the list we are copying
    // and then point them to the elements
    Node *thisTemp = this->header->next;
    Node *listTemp = list.header->next;
    for (int i = 0; i < list.length; i++) {
        thisTemp = new Node(*listTemp->element);
        listTemp = listTemp->next;
        thisTemp = thisTemp->next;
    }
}

DoublyLinkedList::~DoublyLinkedList() {
    // temp variable to store nodes while we delete
    Node *temp = nullptr;

    // loop through until all of the nodes are deleted
    while (!(this->empty())) {
        // create a temporary node for the second node in the list
        temp = this->header->next->next;
        
        // delete the first node in the list
        delete this->header->next;
        
        // set the first node in the list to the previous 
        // second node in the list
        this->header->next = temp;
    }

    // delete the header and trailer nodes
    delete this->header;
    delete this->trailer;
}

// check if the list is empty or not
bool DoublyLinkedList::empty() const {
    // if the next node is the trailer, then
    // there are no nodes in the list.
    return this->header->next == this->trailer;
}

/*
 * Accessors
 */

// get the length of the list
const int DoublyLinkedList::size() const {
    return this->length;
}
// get the front node
const Node& DoublyLinkedList::getFront() const {
    Node const * temp = this->header;
    return *temp;
}

// get the back node
const Node& DoublyLinkedList::getBack() const {
    Node const * temp = this->trailer;
    return *temp;
}

// get the n'th node in the list
const Node& DoublyLinkedList::getNode(int index) {
    const Node * const temp = &(this->getNodeAt(index));

    return *(temp);
}

// get the n'th node at the list and let the node be editable
Node& DoublyLinkedList::getNodeAt(int index) {
    // if the index is outside of the range for valid indexes,
    // then throw an error.
    if (index >= this->length || index < 0) {
        throw std::invalid_argument("Index outside of range for List");
    }

    // here we are initializing a temporary node to point to the
    // first valid node in the list. If the node is not the first
    // node, then loop and set temp to the next node until the next
    // node is the node we are looking for.
    int i = 0;
    Node *temp = this->header->next;
    while (i < index) {
        temp = temp->next;
        i++;
    }

    return *(temp);
}

// get the element of the given node
const Employee& DoublyLinkedList::getElement(const Node& node) const {
    // set a temp employee variable
    return *node.element;
}

// get the element of the n'th node
const Employee& DoublyLinkedList::getElement(int index) {
    // get the element with the index and set the Employee
    // element to the temp variable here
    const Employee *temp = this->getNodeAt(index).element;

    return *temp;
}

/*
 * Manipulators
 */

// generic node removal
void DoublyLinkedList::removeNode(const int index) {
    try {
        Node *old = &(this->getNodeAt(index));

        // take the previous node's next and point it to the next node
        old->prev->next = old->next;

        // take the next node's previous and point it to the previous node
        old->next->prev = old->prev;

        this->length--;

        // delete the node
        delete old;
    }
    catch (std::exception){
    }
}

// generic node add
void DoublyLinkedList::addNode(Employee& employee) {
    Node *temp = this->header->next;
    if (this->length == 0) {
        // create a new node. Set the next node to the temp node
        // and the previous node to the node after temp
        Node *newNode = new Node(employee, *(temp), *(temp->prev));
        // the previous node should point to newNode
        temp->prev->next = newNode;
        // the temp node should point back to newNode
        temp->prev = newNode;

        this->length++;
    }
    else {
        for (int i = 0; i < this->length; i++) {
            if (employee.getEmployeeId() < temp->element->getEmployeeId()) {
                // create a new node. Set the next node to the temp node
                // and the previous node to the node after temp
                Node *newNode = new Node(employee, *(temp), *(temp->prev));
                // the previous node should point to newNode
                temp->prev->next = newNode;
                // the temp node should point back to newNode
                temp->prev = newNode;

                this->length++;
                // break the for loop so we don't have to keep doing it.
                i = this->length;
            }
            temp = temp->next;
        }
    }
}

#include "../include/Node.hpp"

Node::Node() {
    this->next = nullptr;
    this->prev = nullptr;
    this->element = nullptr;
}
// create a node with an eomployee
Node::Node(Employee& employee) : element(&employee) {
    this->next = nullptr;
    this->prev = nullptr;
}

// create a node with an employee, next node, and previous node
Node::Node(Employee& employee, Node& next, Node& prev) : 
    element(&employee), next(&next), prev(&prev) {
}

